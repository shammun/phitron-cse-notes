"""Check that notes/<module-id>.json files are complete.  Usage: python _build/validate_notes.py [module-id ...]"""
import json, sys
from pathlib import Path

ROOT = Path(__file__).resolve().parent.parent
man = {m["id"]: m for m in json.loads((ROOT / "_build/manifest.json").read_text(encoding="utf-8"))}
ids = sys.argv[1:] or list(man)
FILE_KEYS = ["file", "title", "kind", "what", "steps", "input", "output_note", "check"]
bad = 0
for mid in ids:
    m = man[mid]
    f = ROOT / "_build/notes" / f"{mid}.json"
    errs = []
    if not f.exists():
        print(f"MISSING  {mid}"); bad += 1; continue
    try:
        d = json.loads(f.read_text(encoding="utf-8"))
    except Exception as e:
        print(f"BADJSON  {mid}: {e}"); bad += 1; continue
    for k in ["title", "overview", "concepts", "files", "recap", "check_yourself"]:
        if k not in d: errs.append(f"missing key {k}")
    names = [x.get("file") for x in d.get("files", [])]
    for c in m["code"]:
        if c not in names: errs.append(f"no entry for {c}")
    for n in names:
        if n not in m["code"]: errs.append(f"unknown file {n}")
    for x in d.get("files", []):
        for k in FILE_KEYS:
            if k not in x: errs.append(f"{x.get('file')}: missing {k}")
        if x.get("kind") not in {"lesson", "practice", "problem", "exam", "variant", "setup"}:
            errs.append(f"{x.get('file')}: bad kind {x.get('kind')}")
        if not isinstance(x.get("steps"), list): errs.append(f"{x.get('file')}: steps must be a list")
    if errs:
        bad += 1
        print(f"ERRORS   {mid}"); [print("   -", e) for e in errs]
    else:
        print(f"OK       {mid}  ({len(names)} files)")
sys.exit(1 if bad else 0)
