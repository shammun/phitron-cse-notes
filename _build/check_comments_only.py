"""Check that edits to code files only touched comments and whitespace.

Usage: python _build/check_comments_only.py [path-prefix ...]
Compares every changed .c/.cpp file (working tree vs HEAD) after stripping comments
with gcc's preprocessor (-fpreprocessed keeps #include lines and macros as they are).
Prints CHANGED for any file whose code differs, OK otherwise."""
import subprocess, sys, re, os, tempfile
from pathlib import Path

ROOT = Path(__file__).resolve().parent.parent


def strip(src: str) -> str:
    with tempfile.TemporaryDirectory() as d:
        p = Path(d) / "x.cpp"
        p.write_text(src, encoding="utf-8", errors="replace")
        r = subprocess.run(["gcc", "-fpreprocessed", "-dD", "-E", "-P", "-x", "c++", str(p)],
                           capture_output=True, text=True, encoding="utf-8", errors="replace")
        out = r.stdout if r.returncode == 0 else src
    return re.sub(r"\s+", "", out)


def main():
    prefixes = sys.argv[1:]
    names = subprocess.run(["git", "diff", "--name-only", "HEAD", "--", "*.c", "*.cpp"], cwd=ROOT,
                           capture_output=True, text=True, encoding="utf-8").stdout.splitlines()
    bad = 0
    for n in names:
        n = n.strip('"')
        if prefixes and not any(n.startswith(p) for p in prefixes):
            continue
        new_p = ROOT / n
        if not new_p.exists():
            continue
        old = subprocess.run(["git", "show", f"HEAD:{n}"], cwd=ROOT, capture_output=True).stdout.decode("utf-8", "replace")
        new = new_p.read_text(encoding="utf-8", errors="replace")
        if strip(old) != strip(new):
            bad += 1
            print("CHANGED ", n)
        else:
            print("OK      ", n)
    sys.exit(1 if bad else 0)


if __name__ == "__main__":
    main()
