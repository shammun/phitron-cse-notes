"""Build the revision website in docs/ from the course folders and _build/notes/*.json.

    python _build/build.py            # compile + run every program, render every page
    python _build/build.py --serve    # ... then serve docs/ on http://localhost:8000

Every page uses relative links, so docs/index.html also works when opened straight from disk.
"""
import html
import json
import re
import sys
import urllib.parse
from concurrent.futures import ThreadPoolExecutor
from pathlib import Path

from pygments import highlight
from pygments.formatters import HtmlFormatter
from pygments.lexers import CLexer, CppLexer, PythonLexer

sys.path.insert(0, str(Path(__file__).parent))
import runner  # noqa: E402

ROOT = Path(__file__).resolve().parent.parent
DOCS = ROOT / "docs"
NOTES = ROOT / "_build" / "notes"
REPO = "shammun/phitron-cse-notes"
SITE_TITLE = "CSE Fundamentals — Revision Notes"
GITHUB_BLOB = f"https://github.com/{REPO}/blob/main/"
ASSET_V = "4"

COURSE_INFO = {
    "1_Introduction to Programming Language": ("c-programming", "Introduction to Programming", "C",
        "Variables, conditions, loops, arrays, strings, 2-D arrays, pointers, functions and recursion — the foundations, in C."),
    "2_Introduction to C++ for DSA": ("cpp-for-dsa", "Introduction to C++ for DSA", "C++",
        "Moving from C to C++: STL strings, references, dynamic memory, classes and objects, sorting with comparators."),
    "3_Basic Data Structures": ("data-structures", "Basic Data Structures", "C++",
        "Complexity, vectors, linked lists, stacks, queues, trees, binary search trees, heaps, priority queues, sets and maps."),
    "4_Introduction to Algorithms": ("algorithms", "Introduction to Algorithms", "C++",
        "Graphs (BFS, DFS, cycles, shortest paths), DSU, minimum spanning trees and dynamic programming, plus contest solutions."),
    "Software Engineering Track": ("software-engineering", "Software Engineering Track", "Python",
        "The first steps of the software engineering track, in Python."),
}
KIND_LABEL = {"lesson": "Lesson", "practice": "Practice", "problem": "Problem", "exam": "Exam",
              "variant": "Re-typed practice", "setup": "Setup"}


# ---------------------------------------------------------------- helpers
def esc(s):
    return html.escape(str(s), quote=True)


def md(s):
    """Tiny inline markdown: `code`, **bold**, bare URLs. Everything else is escaped."""
    if not s:
        return ""
    parts = re.split(r"(`[^`]+`)", str(s))
    out = []
    for p in parts:
        if p.startswith("`") and p.endswith("`") and len(p) > 1:
            out.append(f"<code>{esc(p[1:-1])}</code>")
        else:
            t = esc(p)
            t = re.sub(r"\*\*(.+?)\*\*", r"<strong>\1</strong>", t)
            t = re.sub(r"(https?://[^\s<)]+)", r'<a href="\1" target="_blank" rel="noopener">\1</a>', t)
            out.append(t)
    return "".join(out)


def slug(s):
    return re.sub(r"[^a-z0-9]+", "-", str(s).lower()).strip("-") or "x"


def natural_key(s):
    return [int(t) if t.isdigit() else t.lower() for t in re.split(r"(\d+)", s)]


def module_number(name):
    m = re.search(r"(\d+)", name)
    return int(m.group(1)) if m else None


def module_label(mod):
    """'Module 10', 'Module 12 · Mid-term', 'Final Contest' ..."""
    name = mod["name"]
    if name == "Course setup & extras":
        return "Getting started"
    name = name.replace("ternary_operator.cpp", "Ternary operator")
    parts = [re.sub(r"^Module\s*(\d+)(?:_(.*))?$", lambda m: f"Module {m.group(1)}", p) for p in name.split("/")]
    if parts[0] == "Book":
        parts = parts[1:] + ["Book exercises"]
        parts[0] = re.sub(r"Module(\d+)", r"Module \1", parts[0])
    return " · ".join(parts)


def gh_url(rel):
    return GITHUB_BLOB + urllib.parse.quote(rel)


LEXERS = {".c": CLexer, ".cpp": CppLexer, ".py": PythonLexer}


def code_html(path):
    text = path.read_text(encoding="utf-8", errors="replace").replace("\t", "    ")
    lexer = LEXERS[path.suffix.lower()]()
    fmt = HtmlFormatter(linenos="table", cssclass="hl", lineanchors=None, wrapcode=True)
    return highlight(text, lexer, fmt), text.count("\n") + 1


def rel_prefix(depth):
    return "../" * depth


# ---------------------------------------------------------------- page shell
def page(title, body, depth, description="", crumbs=()):
    p = rel_prefix(depth)
    crumb_html = "".join(
        f'<a href="{esc(h)}">{esc(t)}</a><span aria-hidden="true">›</span>' if h else f"<span>{esc(t)}</span>"
        for t, h in crumbs)
    return f"""<!DOCTYPE html>
<html lang="en">
<head>
<meta charset="utf-8">
<meta name="viewport" content="width=device-width, initial-scale=1">
<title>{esc(title)}</title>
<meta name="description" content="{esc(description or SITE_TITLE)}">
<meta name="theme-color" content="#0f766e">
<link rel="icon" href="data:image/svg+xml,<svg xmlns='http://www.w3.org/2000/svg' viewBox='0 0 100 100'><text y='.9em' font-size='90'>📘</text></svg>">
<link rel="stylesheet" href="{p}assets/site.css?v={ASSET_V}">
<script>try{{var t=localStorage.getItem('theme');if(t)document.documentElement.dataset.theme=t;if(localStorage.getItem('recall')==='1')document.documentElement.classList.add('recall');}}catch(e){{}}</script>
</head>
<body>
<header class="topbar">
  <a class="brand" href="{p}index.html"><span aria-hidden="true">📘</span> <span>CSE Revision</span></a>
  <nav class="crumbs" aria-label="Breadcrumb">{crumb_html}</nav>
  <div class="tools">
    <button class="tbtn" id="searchBtn" type="button" aria-label="Search programs" title="Search (/)">🔍</button>
    <button class="tbtn" id="recallBtn" type="button" aria-pressed="false" title="Recall mode: hide code so you can write it from memory">🧠<span class="lbl"> Recall</span></button>
    <button class="tbtn" id="themeBtn" type="button" aria-label="Switch light/dark theme" title="Theme">🌓</button>
  </div>
</header>
<div class="search" id="search" hidden>
  <div class="search-box">
    <input id="q" type="search" placeholder="Search programs, topics, problems…" autocomplete="off" aria-label="Search">
    <button class="tbtn" id="searchClose" type="button" aria-label="Close search">✕</button>
  </div>
  <ol id="results" class="results"></ol>
</div>
<main class="wrap">
{body}
</main>
<footer class="foot">
  <p>Shammunul's revision notes from the Phitron CSE program. Code written while taking the course; outputs are real runs
  (GCC 8.1, C11 / GNU C++14). <a href="https://github.com/{REPO}">Source on GitHub</a> · <a href="{p}index.html">All modules</a></p>
</footer>
<script>window.SITE_ROOT="{p}";</script>
<script src="{p}assets/search-index.js?v={ASSET_V}" defer></script>
<script src="{p}assets/site.js?v={ASSET_V}" defer></script>
</body>
</html>
"""


# ---------------------------------------------------------------- module page
def run_file(job):
    mod, entry = job
    src = ROOT / mod["rel"] / entry["file"]
    return runner.run(src, entry.get("input"), entry.get("prelude"), entry.get("driver"))


def render_output(res):
    st = res["status"]
    if st == "compile_error" and "WinMain" in res["compiler"] and "error:" not in res["compiler"]:
        return ('<div class="io out"><div class="io-h">Output</div>'
                '<p class="io-note">Nothing to run: this file has no <code>main</code> function.</p></div>')
    if st == "compile_error":
        return ('<div class="io out bad"><div class="io-h">Compiler says <span class="tag bad">does not compile</span></div>'
                f'<pre>{esc(res["compiler"].strip())}</pre></div>')
    note = ""
    if st == "timeout":
        note = '<span class="tag warn">stopped after 5 s</span>'
    elif st != "ok":
        note = f'<span class="tag warn">ended with {esc(st.replace("exit_", "exit code "))}</span>'
    out = res["stdout"]
    body = esc(out) if out.strip() else '<span class="muted">(prints nothing)</span>'
    extra = ""
    if res.get("stderr", "").strip():
        extra = f'<div class="io-h sub">stderr</div><pre>{esc(res["stderr"].strip())}</pre>'
    return f'<div class="io out"><div class="io-h">Output {note}</div><pre>{body}</pre>{extra}</div>'


def render_program(i, mod, e, res, page_depth):
    src = ROOT / mod["rel"] / e["file"]
    code, nlines = code_html(src)
    rel = f'{mod["rel"]}/{e["file"]}'
    fid = "p-" + slug(Path(e["file"]).stem)
    kind = e.get("kind", "lesson")
    badges = f'<span class="badge k-{esc(kind)}">{esc(KIND_LABEL.get(kind, kind))}</span>'
    if e.get("complexity"):
        badges += f'<span class="badge cx">{md(e["complexity"])}</span>'
    prob = ""
    if e.get("problem") and e["problem"].get("url"):
        prob = (f'<a class="prob" href="{esc(e["problem"]["url"])}" target="_blank" rel="noopener">'
                f'↗ {esc(e["problem"].get("name") or "Problem statement")}</a>')
    same = ""
    if e.get("same_as"):
        same = f'<p class="same">Re-typed version of <a href="#p-{slug(Path(e["same_as"]).stem)}"><code>{esc(e["same_as"])}</code></a>.</p>'
    long_cls = " long" if nlines > 45 else ""
    inp = e.get("input")
    if inp:
        inp_html = (f'<div class="io in"><div class="io-h">Input (stdin)</div><pre>{esc(inp.rstrip())}</pre>'
                    + (f'<p class="io-note">{md(e["input_note"])}</p>' if e.get("input_note") else "") + "</div>")
    else:
        inp_html = '<div class="io in"><div class="io-h">Input</div><p class="io-note">This program reads no input.</p></div>'
    harness = ""
    if e.get("prelude") or e.get("driver"):
        parts = []
        if e.get("prelude"):
            parts.append('<div class="io-h sub">Added before the file</div>' + highlight(e["prelude"], CppLexer(), HtmlFormatter(cssclass="hl")))
        if e.get("driver"):
            parts.append('<div class="io-h sub">Added after the file</div>' + highlight(e["driver"], CppLexer(), HtmlFormatter(cssclass="hl")))
        harness = ('<details class="harness"><summary>🧪 Test driver — this file has no <code>main</code> (judge-style), '
                   'so this page wraps it with a small harness to run it</summary>' + "".join(parts) + "</details>")
    steps = "".join(f"<li>{md(s)}</li>" for s in e.get("steps") or [])
    watch = f'<div class="callout warn"><b>Watch out.</b> {md(e["watch_out"])}</div>' if e.get("watch_out") else ""
    readout = f'<p class="readout"><b>Reading the output.</b> {md(e["output_note"])}</p>' if e.get("output_note") else ""
    chk = e.get("check") or {}
    check = ""
    if chk.get("q"):
        check = (f'<details class="check"><summary><span>✅ Check yourself:</span> {md(chk["q"])}</summary>'
                 f'<div>{md(chk.get("a", ""))}</div></details>')
    return f"""
<section class="prog" id="{fid}">
  <div class="prog-h">
    <span class="num">{i}</span>
    <div class="prog-t">
      <h3>{md(e.get("title") or e["file"])}</h3>
      <div class="meta"><code class="fname">{esc(e["file"])}</code>{badges}{prob}</div>
    </div>
  </div>
  <p class="what">{md(e.get("what"))}</p>{same}
  <div class="codebox-wrap{long_cls}">
    <div class="code-bar">
      <span>{esc(Path(e["file"]).suffix[1:].upper())} · {nlines} lines</span>
      <span class="code-actions">
        <button type="button" class="cbtn copy">Copy</button>
        <a class="cbtn" href="{esc(gh_url(rel))}" target="_blank" rel="noopener">GitHub</a>
      </span>
    </div>
    <div class="recall-cover"><p>🧠 Recall mode — try writing this program yourself first.</p><button type="button" class="cbtn reveal">Show code</button></div>
    <div class="codebox">{code}</div>
    <button type="button" class="expand">Show all {nlines} lines ▾</button>
  </div>
  {harness}
  <div class="io-grid">{inp_html}{render_output(res)}</div>
  {readout}
  <details class="how" open><summary>How it works, step by step</summary><ol>{steps}</ol></details>
  {watch}
  {check}
</section>"""


def render_module(mod, notes, results, prev_mod, next_mod, course_slug, course_title):
    depth = 1
    files = notes.get("files", [])
    label = module_label(mod)
    title = notes.get("title") or label
    toc = "".join(
        f'<li><a href="#p-{slug(Path(e["file"]).stem)}"><span class="n">{i}</span>{md(e.get("title") or e["file"])}'
        f'{" <em>(re-typed)</em>" if e.get("kind") == "variant" else ""}</a></li>'
        for i, e in enumerate(files, 1))
    concepts = "".join(
        f'<div class="concept"><h4>{md(c.get("term"))}</h4><p>{md(c.get("explain"))}</p>'
        + (f'<pre class="snip">{esc(c["snippet"])}</pre>' if c.get("snippet") else "") + "</div>"
        for c in notes.get("concepts", []))
    walk = "".join(
        f'<div class="wstep"><h3>{md(w.get("heading"))}</h3>'
        + "".join(f"<p>{md(p)}</p>" for p in w.get("body", []))
        + (f'<pre class="snip">{esc(w["snippet"])}</pre>' if w.get("snippet") else "")
        + (f'<pre class="trace">{esc(w["trace"])}</pre>' if w.get("trace") else "") + "</div>"
        for w in notes.get("walkthrough", []))
    progs = "".join(render_program(i, mod, e, results[(mod["id"], e["file"])], depth) for i, e in enumerate(files, 1))
    links = notes.get("practice_links") or []
    links_html = ""
    if links:
        links_html = ('<section class="block" id="practice"><h2>🏋️ Practice problems</h2><ul class="plinks">'
                      + "".join(f'<li><a href="{esc(l["url"])}" target="_blank" rel="noopener">{esc(l.get("name") or l["url"])}</a>'
                                f'<span class="site">{esc(l.get("site") or "")}</span></li>' for l in links if l.get("url"))
                      + "</ul></section>")
    recap = "".join(f"<li>{md(r)}</li>" for r in notes.get("recap", []))
    cy = "".join(f'<details class="check"><summary>{md(q.get("q"))}</summary><div>{md(q.get("a"))}</div></details>'
                 for q in notes.get("check_yourself", []))

    def navlink(m, cls, arrow):
        if not m:
            return f'<span class="{cls} empty"></span>'
        href = f'../{COURSE_INFO[m["course_dir"]][0]}/{m["slug"]}.html'
        return (f'<a class="{cls}" href="{href}"><small>{arrow}</small>'
                f'<b>{esc(module_label(m))}</b><span>{esc(m["title"])}</span></a>')

    body = f"""
<article class="module">
  <header class="mhead">
    <p class="eyebrow"><a href="index.html">{esc(course_title)}</a> · {esc(label)}</p>
    <h1>{md(title)}</h1>
    <p class="lead">{md(notes.get("overview"))}</p>
    <p class="chips"><span>{len(files)} program{"s" if len(files) != 1 else ""}</span>{f'<span>{len(links)} practice links</span>' if links else ''}<a href="{esc(gh_url(mod["rel"]).replace("/blob/", "/tree/"))}" target="_blank" rel="noopener">Folder on GitHub ↗</a></p>
  </header>
  {f'<nav class="toc" aria-label="Programs on this page"><details open><summary>On this page</summary><ol>{toc}</ol></details></nav>' if files else ''}
  {f'<section class="block" id="ideas"><h2>💡 Key ideas</h2><div class="concepts">{concepts}</div></section>' if concepts else ''}
  {f'<section class="block" id="walkthrough"><h2>🔍 Worked examples</h2><div class="walk">{walk}</div></section>' if walk else ''}
  {f'<section class="block" id="programs"><h2>🧑‍💻 Programs</h2>{progs}</section>' if files else ''}
  {links_html}
  <section class="block recap" id="recap"><h2>📌 Remember</h2><ul>{recap}</ul></section>
  {f'<section class="block" id="quiz"><h2>✅ Check yourself</h2>{cy}</section>' if cy else ''}
  <nav class="pager">{navlink(prev_mod, "prev", "← Previous")}{navlink(next_mod, "next", "Next →")}</nav>
</article>"""
    return page(f"{label}: {notes.get('title', '')} · {course_title}", body, depth,
                description=notes.get("overview", ""),
                crumbs=[(course_title, "index.html"), (label, None)])


# ---------------------------------------------------------------- course + home
def module_card(m, href):
    n = len(m["notes"].get("files", []))
    count = f'{n} program{"s" if n != 1 else ""}' if n else "notes only"
    return (f'<a class="mcard" href="{href}"><span class="mlabel">{esc(module_label(m))}</span>'
            f'<b>{md(m["title"])}</b><span class="mdesc">{md(m["notes"].get("overview", ""))}</span>'
            f'<span class="mcount">{count}</span></a>')


def render_course(cdir, mods):
    cslug, ctitle, lang, blurb = COURSE_INFO[cdir]
    cards = "".join(module_card(m, f'{m["slug"]}.html') for m in mods)
    n = sum(len(m["notes"].get("files", [])) for m in mods)
    body = f"""
<header class="mhead">
  <p class="eyebrow">Course · {esc(lang)}</p>
  <h1>{esc(ctitle)}</h1>
  <p class="lead">{esc(blurb)}</p>
  <p class="chips"><span>{len(mods)} modules</span><span>{n} programs</span></p>
</header>
<div class="mgrid">{cards}</div>"""
    return page(f"{ctitle} · {SITE_TITLE}", body, 1, blurb, crumbs=[(ctitle, None)])


def render_home(courses):
    total_p = sum(len(m["notes"].get("files", [])) for _, ms in courses for m in ms)
    total_m = sum(len(ms) for _, ms in courses)
    secs = []
    for cdir, mods in courses:
        cslug, ctitle, lang, blurb = COURSE_INFO[cdir]
        items = "".join(
            f'<li><a href="{cslug}/{m["slug"]}.html"><span class="mlabel">{esc(module_label(m))}</span>'
            f'<span class="mt">{md(m["title"])}</span><span class="mcount">{len(m["notes"].get("files", [])) or "notes"}</span></a></li>'
            for m in mods)
        n = sum(len(m["notes"].get("files", [])) for m in mods)
        secs.append(f"""
<section class="course" id="{cslug}">
  <div class="course-h">
    <div><p class="eyebrow">{esc(lang)} · {len(mods)} modules · {n} programs</p>
    <h2><a href="{cslug}/index.html">{esc(ctitle)}</a></h2>
    <p>{esc(blurb)}</p></div>
  </div>
  <ol class="mlist">{items}</ol>
</section>""")
    jump = "".join(f'<a href="#{COURSE_INFO[c][0]}">{esc(COURSE_INFO[c][1])}</a>' for c, _ in courses)
    body = f"""
<header class="hero">
  <h1>CSE Fundamentals — code, output &amp; explanations</h1>
  <p class="lead">Every program I wrote in Phitron's CSE program, one page per module: the code, a sample input,
  the <b>real output</b>, and a plain-words, step-by-step explanation. Made for revising on a phone.</p>
  <p class="chips"><span>{len(courses)} courses</span><span>{total_m} modules</span><span>{total_p} programs</span></p>
  <div class="how3">
    <div><b>📖 Read</b>Open a module. Each program shows its code, the input it was run with, and what it printed.</div>
    <div><b>🧠 Rehearse</b>Turn on <em>Recall</em> (top bar). Code is hidden — write it yourself, then reveal and compare.</div>
    <div><b>✅ Check</b>Answer the check-yourself questions, then try the linked practice problems.</div>
  </div>
  <button type="button" class="bigsearch" id="heroSearch">🔍 Search all {total_p} programs…</button>
  <nav class="jump">{jump}</nav>
</header>
{"".join(secs)}"""
    return page(SITE_TITLE, body, 0, "Code, real output and step-by-step explanations for every module of Phitron's CSE program.")


# ---------------------------------------------------------------- main
def main():
    manifest = json.loads((ROOT / "_build/manifest.json").read_text(encoding="utf-8"))
    missing = []
    mods_by_course = {c: [] for c in COURSE_INFO}
    for m in manifest:
        nf = NOTES / f'{m["id"]}.json'
        if not nf.exists():
            missing.append(m["id"])
            continue
        m["notes"] = json.loads(nf.read_text(encoding="utf-8"))
        m["title"] = re.sub(r"[`*]", "", m["notes"].get("title") or module_label(m))
        m["slug"] = slug(module_label(m))
        mods_by_course[m["course_dir"]].append(m)
    if missing:
        print("WARNING: no notes yet for", len(missing), "modules:", ", ".join(missing))

    def order(m):
        name = m["name"]
        if name == "Course setup & extras":
            return (-1, [])
        if name.startswith("Book"):
            return (9999, natural_key(name))
        if "Contest" in name:
            return (5000 + (0 if "Mock" in name else 1), [])
        return (module_number(name) or 0, natural_key(name))

    courses = []
    for c, ms in mods_by_course.items():
        ms.sort(key=order)
        if ms:
            courses.append((c, ms))

    jobs = [(m, e) for _, ms in courses for m in ms for e in m["notes"].get("files", [])]
    print(f"running {len(jobs)} programs ...")
    with ThreadPoolExecutor(max_workers=8) as ex:
        res = list(ex.map(run_file, jobs))
    results = {(m["id"], e["file"]): r for (m, e), r in zip(jobs, res)}
    bad = [(m["rel"], e["file"], r["status"]) for (m, e), r in zip(jobs, res) if r["status"] != "ok"]

    DOCS.mkdir(exist_ok=True)
    (DOCS / ".nojekyll").write_text("", encoding="utf-8")
    search = []
    for cdir, ms in courses:
        cslug, ctitle = COURSE_INFO[cdir][0], COURSE_INFO[cdir][1]
        cdirp = DOCS / cslug
        cdirp.mkdir(parents=True, exist_ok=True)
        (cdirp / "index.html").write_text(render_course(cdir, ms), encoding="utf-8")
        for i, m in enumerate(ms):
            prev_m = ms[i - 1] if i > 0 else None
            next_m = ms[i + 1] if i + 1 < len(ms) else None
            (cdirp / f'{m["slug"]}.html').write_text(
                render_module(m, m["notes"], results, prev_m, next_m, cslug, ctitle), encoding="utf-8")
            search.append({"t": m["title"], "s": f"{ctitle} · {module_label(m)}", "u": f'{cslug}/{m["slug"]}.html', "k": "m",
                           "x": " ".join(c.get("term", "") for c in m["notes"].get("concepts", []))})
            for e in m["notes"].get("files", []):
                search.append({"t": re.sub(r"[`*]", "", e.get("title") or e["file"]),
                               "s": f"{module_label(m)} · {e['file']}",
                               "u": f'{cslug}/{m["slug"]}.html#p-{slug(Path(e["file"]).stem)}', "k": "p",
                               "x": ((e.get("problem") or {}).get("name") or "") + " " + re.sub(r"[`*]", "", e.get("what") or "")})
    (DOCS / "index.html").write_text(render_home(courses), encoding="utf-8")
    assets = DOCS / "assets"
    assets.mkdir(exist_ok=True)
    (assets / "search-index.js").write_text("window.SEARCH_INDEX=" + json.dumps(search, ensure_ascii=False) + ";\n",
                                            encoding="utf-8")
    light = HtmlFormatter(style="default").get_style_defs(".hl")
    dark = HtmlFormatter(style="github-dark").get_style_defs(":root[data-theme=dark] .hl")
    dark_auto = HtmlFormatter(style="github-dark").get_style_defs(":root:not([data-theme=light]) .hl")
    css = (ROOT / "_build/site.css").read_text(encoding="utf-8")
    (assets / "site.css").write_text(
        css + "\n/* ---- syntax colours (pygments) ---- */\n" + light + "\n" + dark
        + "\n@media (prefers-color-scheme: dark){\n" + dark_auto + "\n}\n", encoding="utf-8")
    (assets / "site.js").write_text((ROOT / "_build/site.js").read_text(encoding="utf-8"), encoding="utf-8")

    report = ["# Build report", "", f"{len(jobs)} programs, {len(bad)} not clean:", ""]
    report += [f"- `{r}/{f}` — {s}" for r, f, s in bad]
    (ROOT / "_build/build_report.md").write_text("\n".join(report) + "\n", encoding="utf-8")
    print(f"built {sum(len(ms) for _, ms in courses)} module pages; {len(bad)} programs not clean (see _build/build_report.md)")

    if "--serve" in sys.argv:
        import http.server, functools
        h = functools.partial(http.server.SimpleHTTPRequestHandler, directory=str(DOCS))
        print("serving on http://localhost:8000")
        http.server.ThreadingHTTPServer(("", 8000), h).serve_forever()


if __name__ == "__main__":
    main()
