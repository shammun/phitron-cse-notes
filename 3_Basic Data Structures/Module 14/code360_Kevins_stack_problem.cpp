/*

https://www.naukri.com/code360/problems/kevin-s-stack-problem_1169465?leftPanelTabValue=PROBLEM

*/

#include <bits/stdc++.h> 
string kevinStackProblem(string &s)
{
	// Write your code here.
	stack<char> st;
	string result = "";
    for (char c : s) {
		st.push(c);
	}
    while (!st.empty()) {
		result += st.top();
		st.pop();
	}
	return result;
}