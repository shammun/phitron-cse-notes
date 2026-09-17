"""Scan the course folders and list every 'module' (a folder that holds code or notes)."""
import json, os, re, sys
from pathlib import Path

ROOT = Path(__file__).resolve().parent.parent
COURSES = [
    ("1_Introduction to Programming Language", "Introduction to Programming (C)"),
    ("2_Introduction to C++ for DSA", "Introduction to C++ for DSA"),
    ("3_Basic Data Structures", "Basic Data Structures"),
    ("4_Introduction to Algorithms", "Introduction to Algorithms"),
    ("Software Engineering Track", "Software Engineering Track"),
]
CODE_EXT = {".c", ".cpp", ".py"}
SKIP_DIRS = {"MinGW", "output", "New folder"}


def slug(s):
    return re.sub(r"[^a-z0-9]+", "-", s.lower()).strip("-")


def modules():
    out = []
    for cdir, ctitle in COURSES:
        base = ROOT / cdir
        for dirpath, dirnames, filenames in os.walk(base):
            dirnames[:] = sorted(d for d in dirnames if d not in SKIP_DIRS)
            p = Path(dirpath)
            code = sorted(f for f in filenames if Path(f).suffix.lower() in CODE_EXT)
            docx = sorted(f for f in filenames if f.lower().endswith(".docx") and not f.startswith("~$"))
            if not code and not docx:
                continue
            rel = p.relative_to(ROOT).as_posix()
            sub = p.relative_to(base).as_posix()
            out.append({
                "id": slug(cdir) + "--" + (slug(sub) if sub != "." else "course-root"),
                "course_dir": cdir, "course": ctitle, "rel": rel,
                "name": sub if sub != "." else "Course setup & extras",
                "code": code, "docx": docx,
            })
    return out


if __name__ == "__main__":
    m = modules()
    (ROOT / "_build" / "manifest.json").write_text(json.dumps(m, indent=1, ensure_ascii=False), encoding="utf-8")
    for x in m:
        print(f'{x["id"]:75s} code={len(x["code"]):3d} docx={len(x["docx"])}')
    print(len(m), "modules", sum(len(x["code"]) for x in m), "code files")
