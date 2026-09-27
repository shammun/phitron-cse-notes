/*

https://leetcode.com/problems/valid-parentheses/

Valid Parentheses (LeetCode 20)

A string holds only the brackets ( ) { } [ ]. It is valid when every
closing bracket closes the most recent bracket still open, and of the same
type, and nothing is left open at the end.

Example: "([]{})" -> true, "(]" -> false, "([)]" -> false.

*/

/*
 * Idea
 *
 * A closing bracket must match the MOST RECENT opening bracket that is still
 * waiting. "Most recent first" is exactly what a stack gives: push every
 * opening bracket; on a closing bracket, look at the top.
 *
 *   "( [ ] )"   push (   push [   ']' matches [ -> pop   ')' matches ( -> pop
 *               stack empty at the end -> valid
 *
 * Each character is pushed or popped at most once: O(n).
 * (No #include: LeetCode supplies the standard library and `using namespace std;`.)
 */

// LeetCode's answer class.
class Solution {
public:     // callable by the judge
    // Returns true if every bracket in s is properly matched and nested.
    bool isValid(string s) {
        stack<char> st;   // opening brackets that are still waiting for a partner
        // Range-for: c takes each character of s, left to right.
        for(char c : s){
            // || = "or": any of the three opening brackets.
            if(c == '(' || c == '{' || c == '['){
                // An opening bracket: remember it until its partner arrives.
                st.push(c);
            } else{
                // A closing bracket with nothing open, e.g. ")(": invalid.
                if(st.empty()){
                    return false;
                } else{
                    // It must match the top (the latest open bracket).
                    // If it does, that pair is done: pop it.
                    if(c == ')' && st.top() =='('){
                        st.pop();
                    } else if(c == '}' && st.top() == '{'){
                        st.pop();
                    } else if(c == ']' && st.top() == '['){
                        st.pop();
                    } else {
                        // Wrong type, e.g. "(]": invalid.
                        // "([)]": at ')' the top is '[' -> false here.
                        return false;
                    }

                }
            }
        }
        // Valid only if every opening bracket got closed, e.g. "((" fails here.
        return st.empty();
    }
};