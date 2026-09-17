# Brief: write revision notes for course modules (Shammunul's teaching style)

The repository `G:\Phitron` holds the code Shammunul wrote while taking Phitron's CSE program (C, C++, data
structures, algorithms). We are turning every module folder into a phone-friendly HTML revision page showing, for
every program: the code, a sample input, the **real** output, and a plain-words explanation. A build script
(`_build/build.py`) renders the pages; your job is the **notes** (one JSON file per module) that it renders.

## Teaching style (Shammunul's)
* Plain words first, then the idea step by step. Short sentences. Explain *why* each move is made, not only *what*.
* Tiny concrete examples with real numbers ("with input `5` and `1 2 3 4 5` the loop …").
* Say how to read the output. Point out pitfalls ("Watch out"). End with check-yourself questions.
* Written for a learner who is **revising**: they want to recall the pattern quickly and practise it again.
* English. You may keep an occasional well-known Bangla term, but the notes are English.

## Content rules (the repo is public)
* The `.docx` files and screenshots are Phitron's material. You MAY read the `.docx` files
  (`pandoc "<file>.docx" -t plain`) to learn the module's topics and to collect **practice problem links** (name + URL).
  Do NOT copy their text, tables, quiz questions or quiz answers. Write everything in your own words.
* Check-yourself questions must be your own, about the concepts in the code.
* Do NOT modify any source file. Do NOT create files anywhere except `_build/notes/<module-id>.json`
  (and throwaway files in your own temp folder).

## For every code file in your modules
1. Read the file.
2. Decide a realistic **sample input** (exact stdin text, with a trailing newline) that exercises the program well,
   or `null` when the program reads nothing. For online-judge problems use input in the judge's format
   (a small interesting case). Programs with loops over test cases: use 2–3 cases.
3. **Run it** and look at the real output:
   `python _build/runner.py "<relative path>" --text "5\n1 2 3 4 5\n"`  (from `G:\Phitron`; `\n` is a newline)
   The input must make the program finish (status `ok`, no `timeout`) and produce sensible output. If the program
   has a bug, crashes, or doesn't compile, do not fix the code — keep a reasonable input and explain the problem in
   `watch_out` (what goes wrong and the one-line fix). Interactive menus: feed a sequence that exercises the options and exits.
4. Write the entry (schema below).

Files named `something_p.cpp` (or near-identical copies) are usually Shammunul's practice re-typing of another file:
give them `"kind": "variant"`, `"same_as": "<original file>"`, and keep their notes short (what differs, if anything),
but still give them an input and a check question.

## Files without a `main` (LeetCode / Code360 / GFG "class Solution" style)
Don't leave these as "does not compile". Add a small **test harness** to the entry — the source file stays untouched:
* `"prelude"`: code placed before the file — usually `#include <bits/stdc++.h>` + `using namespace std;` plus the
  judge's hidden definitions (e.g. `struct TreeNode {...};`, `struct ListNode {...};`, `class Node {...};`).
* `"driver"`: code placed after the file — a `main()` that reads the sample `input` from stdin, builds the structure,
  calls the solution and prints the result clearly (e.g. `cout << "rangeSumBST = " << ans << endl;`).
Keep harnesses short and readable (they are shown on the page under "Test driver"). Use the judge's own example
as the input when the file quotes one, so the output can be compared with the expected answer (say so in `output_note`).
Test with the notes file itself once written: `python _build/runner.py "<path>" --notes <module-id>`
(reads input/prelude/driver from your JSON), or pass `--prelude file --driver file --text "..."` while drafting.
If the file has its own `main`, never add a harness. If a file with `main` fails to compile because of a genuine
mistake, leave it and explain in `watch_out`.

## Schema: `_build/notes/<module-id>.json`  (UTF-8, valid JSON)
```json
{
  "module_id": "3-basic-data-structures--module-10",
  "title": "Doubly linked lists & the STL list",          // short, descriptive: what this module is about
  "overview": "2-4 sentences: what the module teaches and why it matters.",
  "concepts": [                                            // 3-8 key ideas of the module, in teaching order
    {"term": "Fast & slow pointers", "explain": "1-3 sentences, plain words.", "snippet": "optional tiny code or null"}
  ],
  "files": [                                               // EVERY code file of the module, in a sensible learning order
    {
      "file": "reverse_doubly_linked_list.cpp",           // exact filename as in the folder
      "title": "Reverse a doubly linked list",
      "kind": "lesson",                                    // lesson | practice | problem | exam | variant | setup
      "same_as": null,                                     // for kind=variant: the original filename
      "problem": {"name": "Codeforces 1234A - ...", "url": "https://..."},   // or null if not a judge problem
      "what": "1-3 sentences: what the program does and the idea it uses.",
      "steps": ["Step-by-step walkthrough of the logic, 3-8 items, each one sentence or two, mention variables/functions in `backticks`."],
      "complexity": "Time O(n) · Space O(1)",             // or null when meaningless (e.g. hello world)
      "input": "5\n1 2 3 4 5\n",                           // exact stdin, or null
      "input_note": "First line n, then n values.",         // or null
      "output_note": "How to read the output you'll see (refer to the real output).",
      "watch_out": null,                                   // pitfall / bug note, or null
      "prelude": null, "driver": null,                     // only for files without main (see above)
      "check": {"q": "A recall question about this program", "a": "Its answer"}
    }
  ],
  "practice_links": [ {"name": "Detect cycle in an undirected graph", "url": "https://...", "site": "GeeksforGeeks"} ],
  "recap": ["3-6 one-line takeaways to remember"],
  "check_yourself": [ {"q": "Concept question", "a": "Answer"} ]      // 2-4 items
}
```
Text fields may use `backticks` for code and `**bold**`; no HTML. Modules with no code (only notes) still get
title, overview, concepts, recap, check_yourself, practice_links and `"files": []` — build them from the `.docx` topics
in your own words.

When all your modules are done, run `python _build/validate_notes.py <module-id> <module-id> ...` and fix every error.
Your final reply: one line per module (`id — N files — any programs that fail to compile/crash`), nothing else.
