"""Compile and run one program with a given stdin, returning what a learner would see.

Usage (command line):
    python _build/runner.py "<path/to/file.cpp>" [input.txt | -]      # '-' reads stdin text from this process
    python _build/runner.py "<path/to/file.cpp>" --text "5\n1 2 3 4 5"

Binaries are cached in _build/cache (ignored by git), keyed by the source's hash.
"""
import hashlib
import json
import os
import subprocess
import threading
import uuid
import sys
from pathlib import Path

ROOT = Path(__file__).resolve().parent.parent
CACHE = ROOT / "_build" / "cache"
TIMEOUT = 5          # seconds a program may run
MAX_OUT = 20_000     # characters kept from stdout
FLAGS_VERSION = "c11-cpp14-permissive-stack256-cstring"  # change when compiler flags change


_LOCKS = {}
_LOCKS_GUARD = threading.Lock()


def _lock(key):
    with _LOCKS_GUARD:
        return _LOCKS.setdefault(key, threading.Lock())


def _compile(src: Path, prelude=None, driver=None):
    """Return (exe_path or None, compiler_messages).

    prelude/driver: optional code placed before/after the untouched source (a test harness for
    LeetCode-style files that only contain a `class Solution`). `#line` keeps error line numbers right.
    """
    CACHE.mkdir(parents=True, exist_ok=True)
    data = src.read_bytes()
    ext = src.suffix.lower()
    if prelude or driver:
        head = (prelude or "") + f'\n#line 1 "{src.name}"\n'
        tail = '\n#line 1 "test driver"\n' + (driver or "") + "\n"
        data = head.encode() + data + tail.encode()
    key = hashlib.sha1(data + ext.encode() + FLAGS_VERSION.encode()).hexdigest()[:16]
    with _lock(key):
        return _compile_locked(src, data, ext, key, prelude or driver)


def _compile_locked(src, data, ext, key, harness):
    exe = CACHE / f"{key}.exe"
    log = CACHE / f"{key}.log"
    if exe.exists() or log.exists():
        msg = log.read_text(encoding="utf-8", errors="replace") if log.exists() else ""
        return (exe if exe.exists() else None), msg
    srcfile = src
    tmp = CACHE / f"{key}.{uuid.uuid4().hex[:8]}.tmp.exe"
    if harness:
        srcfile = CACHE / f"{key}.{uuid.uuid4().hex[:8]}{ext}"
        srcfile.write_bytes(data)
    if ext == ".c":
        cmd = ["gcc", "-std=gnu11", "-O1", "-x", "c", str(srcfile), "-o", str(tmp), "-lm", "-Wl,--stack,268435456"]
    else:
        # GCC 8.1 (MinGW) breaks <bits/stdc++.h> under C++17, so use GNU C++14.
        cmd = ["g++", "-std=gnu++14", "-O1", "-fpermissive", "-include", "cstring", "-x", "c++", str(srcfile), "-o", str(tmp), "-Wl,--stack,268435456"]
    p = subprocess.run(cmd, capture_output=True, text=True, errors="replace")
    msg = (p.stderr or "").replace(str(srcfile), src.name).replace(str(src), src.name)
    if p.returncode == 0 and tmp.exists():
        try:
            os.replace(tmp, exe)
        except OSError:  # another process finished the same binary first
            tmp.unlink(missing_ok=True)
    if p.returncode != 0 or not exe.exists():
        log.write_text(msg or "compilation failed", encoding="utf-8")
        return None, msg or "compilation failed"
    if msg.strip():
        log.write_text(msg, encoding="utf-8")
    return exe, msg


def run(src, stdin_text=None, prelude=None, driver=None):
    """Compile (if needed) and run. Returns a dict with status, output and messages."""
    src = Path(src)
    if not src.is_absolute():
        src = ROOT / src
    if src.suffix.lower() == ".py":
        cmd, cmsg = [sys.executable, str(src)], ""
    else:
        exe, cmsg = _compile(src, prelude, driver)
        if exe is None:
            return {"status": "compile_error", "stdout": "", "stderr": cmsg, "compiler": cmsg}
        cmd = [str(exe)]
    try:
        p = subprocess.run(cmd, input=(stdin_text or ""), capture_output=True, text=True,
                           errors="replace", timeout=TIMEOUT, cwd=str(src.parent))
        status = "ok" if p.returncode == 0 else f"exit_{p.returncode & 0xFFFFFFFF:#x}" if p.returncode < 0 or p.returncode > 255 else f"exit_{p.returncode}"
        out, err = p.stdout, p.stderr
    except subprocess.TimeoutExpired as e:
        status = "timeout"
        out = e.stdout.decode(errors="replace") if isinstance(e.stdout, bytes) else (e.stdout or "")
        err = ""
    if len(out) > MAX_OUT:
        out = out[:MAX_OUT] + "\n... (output truncated)"
    return {"status": status, "stdout": out, "stderr": err[:4000], "compiler": cmsg}


if __name__ == "__main__":
    sys.stdout.reconfigure(encoding="utf-8", errors="replace")
    import argparse
    ap = argparse.ArgumentParser()
    ap.add_argument("path")
    ap.add_argument("input", nargs="?", help="file with stdin text, or '-' for this process's stdin")
    ap.add_argument("--text", help="stdin text; \n means newline")
    ap.add_argument("--prelude", help="file with code to put BEFORE the source (harness)")
    ap.add_argument("--driver", help="file with code to put AFTER the source (harness main)")
    ap.add_argument("--notes", help="module id: take input/prelude/driver from _build/notes/<id>.json")
    a = ap.parse_args()
    text = pre = drv = None
    if a.notes:
        d = json.loads((ROOT / "_build/notes" / f"{a.notes}.json").read_text(encoding="utf-8"))
        e = next(x for x in d["files"] if x["file"] == Path(a.path).name)
        text, pre, drv = e.get("input"), e.get("prelude"), e.get("driver")
    if a.text is not None:
        text = a.text.encode("latin-1", "backslashreplace").decode("unicode_escape")
    elif a.input == "-":
        text = sys.stdin.read()
    elif a.input:
        text = Path(a.input).read_text(encoding="utf-8")
    if a.prelude:
        pre = Path(a.prelude).read_text(encoding="utf-8")
    if a.driver:
        drv = Path(a.driver).read_text(encoding="utf-8")
    r = run(a.path, text, pre, drv)
    print(f"[status] {r['status']}")
    if r["compiler"].strip():
        print("[compiler]\n" + r["compiler"][:3000])
    print("[stdout]\n" + r["stdout"])
    if r["stderr"].strip():
        print("[stderr]\n" + r["stderr"])
