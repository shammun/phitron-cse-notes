/*

Kevin's Stack Problem (Code360)
https://www.naukri.com/code360/problems/kevin-s-stack-problem_1169465

The problem, in my own words
  Kevin wants a string written backwards, and he wants it done with a stack.
  Given a string s, return the reverse of s.

Function to write (Code360 signature)
  string kevinStackProblem(string &s)

Input used by the test driver
  first line t (test cases), then one string per line (no spaces).

Sample
  abc    -> cba
  stack  -> kcats

*/

/*
 * The idea: a stack hands things back in the opposite order to how they went
 * in. Push every character from left to right; the last character ends up on
 * top. Then pop them all into the answer: the last character comes out first.
 *
 *   push a, b, c  ->  stack (bottom) a b c (top)  ->  pop gives c, b, a
 */

string kevinStackProblem(string &s)
{
    stack<char> st;

    // First character goes to the bottom, last character ends on top.
    for(char c : s){
        st.push(c);
    }

    // Pop from the top: characters come out last-first, i.e. reversed.
    string ans = "";
    while(!st.empty()){
        ans += st.top();
        st.pop();
    }

    return ans;
}
