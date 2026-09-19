// This file is a note about one line, not a program: it has no main(), so on its own
// there is nothing to run.
//
// So far every C++ file here started with a list of headers: <iostream> for cin and cout,
// <algorithm> for min, max and swap, <string> for string. Each header is a separate line,
// and you have to remember which name lives in which header.
//
// GCC ships one header that includes almost the whole standard library at once:
#include <bits/stdc++.h>
// After this single line, cout, string, vector, sort, min and max are all available -
// no other #include is needed. That is why contest code almost always begins with it.
//
// Two things to know before you use it everywhere:
//   1. It is a GCC extension. Other compilers (MSVC, clang on macOS) do not have it,
//      so code written with it may not compile there.
//   2. It really does pull in everything, so compiling gets a little slower.
// For practice and contests it is fine; in real projects list the headers you use.
