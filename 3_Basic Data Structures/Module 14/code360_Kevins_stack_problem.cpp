/*

https://www.naukri.com/code360/problems/kevin-s-stack-problem_1169465?leftPanelTabValue=PROBLEM

Kevin's Stack Problem (Code360)

Return the given string written backwards, using a stack.

Example: "abcde" -> "edcba".

*/

/*
 * Idea
 *
 * A stack gives values back in the opposite order they went in. Push every
 * character of s, then pop them all: the last character comes out first,
 * so the popped characters spell s in reverse. O(n) time and space.
 */

// <bits/stdc++.h> = GCC's "include everything" header (string, stack, ...).
// Code360's hidden template adds `using namespace std;` and main().
#include <bits/stdc++.h>
// s is passed by reference (&) to avoid copying it; the function returns a NEW string.
string kevinStackProblem(string &s)
{
	// Write your code here.
	stack<char> st;         // a stack of single characters
	string result = "";     // the answer, built one character at a time
    // Push the characters left to right: the last one ends up on top.
    // Range-for: c takes each character of s in turn.
    for (char c : s) {
		st.push(c);
	}
    // Pop them all, appending each: the top (last character) comes first.
    while (!st.empty()) {
		result += st.top();     // += on a string appends one char at the end
		st.pop();
	}
	// Trace "abc": stack a,b,c (c on top) -> result "c", "cb", "cba".
	return result;
}