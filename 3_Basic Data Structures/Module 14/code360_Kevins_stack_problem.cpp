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

#include <bits/stdc++.h> 
string kevinStackProblem(string &s)
{
	// Write your code here.
	stack<char> st;
	string result = "";
    // Push the characters left to right: the last one ends up on top.
    for (char c : s) {
		st.push(c);
	}
    // Pop them all, appending each: the top (last character) comes first.
    while (!st.empty()) {
		result += st.top();
		st.pop();
	}
	return result;
}