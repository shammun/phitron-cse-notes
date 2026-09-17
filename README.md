# CSE Fundamentals — code, output & explanations

My code from **Phitron's CSE program**, turned into a website for revising on any device, including a phone.
There is one page per module. Each program shows its code, the input it was run with, its **real output**, and a
plain-words, step-by-step explanation.

**Read online: https://shammun.github.io/phitron-cse-notes/**

| Course | Language | What it covers |
|---|---|---|
| [Introduction to Programming](https://shammun.github.io/phitron-cse-notes/c-programming/) | C | variables, conditions, loops, arrays, strings, 2-D arrays, pointers, functions, recursion |
| [Introduction to C++ for DSA](https://shammun.github.io/phitron-cse-notes/cpp-for-dsa/) | C++ | STL strings, references, dynamic memory, classes & objects, sorting with comparators |
| [Basic Data Structures](https://shammun.github.io/phitron-cse-notes/data-structures/) | C++ | complexity, vectors, linked lists, stacks, queues, trees, BSTs, heaps, sets & maps |
| [Introduction to Algorithms](https://shammun.github.io/phitron-cse-notes/algorithms/) | C++ | BFS/DFS, cycles, shortest paths, DSU, MST, dynamic programming, contests |

## How to use the site
* **📖 Read**: open a module. Each program has its code, its input and its output, followed by *How it works, step by step*.
* **🧠 Rehearse**: switch on **Recall** in the top bar. Code is hidden, so write each program from memory, then reveal it and compare.
* **✅ Check**: answer the *Check yourself* questions (tap to reveal), then try the linked practice problems.
* **🔍 Search**: find any program, topic or judge problem across all courses (press `/` on a keyboard).

## Layout
| Path | What |
|---|---|
| `1_…/`, `2_…/`, `3_…/`, `4_…/` | the source code, one folder per module, exactly as written during the course |
| `docs/` | the generated website (served by GitHub Pages) |
| `_build/notes/<module>.json` | the explanations, sample inputs and test drivers for every program |
| `_build/build.py` | compiles and runs every program and renders `docs/` |
| `_build/runner.py` | compiles and runs one program with a given input |

Some solutions were written for LeetCode, Code360 or GeeksforGeeks and have no `main`. For those, the page wraps the
untouched file in a small **test driver**, shown on the page, so it can run.
Programs with a known bug are kept as written. A *Watch out* note explains what goes wrong and how to fix it.

## Rebuild
Requires GCC/G++ on `PATH` (built with MinGW-w64 GCC 8.1: C11 and GNU C++14) and Python 3 with `pygments`.
```bash
python _build/manifest.py      # rescan the module folders
python _build/build.py         # run every program and regenerate docs/
python _build/build.py --serve # ... and preview on http://localhost:8000
```

## Note
Course material that belongs to Phitron (videos, quiz screenshots, practice sheets) is not included. The explanations
are my own. Practice problems link to the judges where they live.
