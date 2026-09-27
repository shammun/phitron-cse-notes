/*

https://leetcode.com/problems/valid-parentheses/

Valid Parentheses (LeetCode 20)
A string holds only the six characters ( ) { } [ ]. It is valid when every
opening bracket is closed by a bracket of the same type, and brackets close
in the right order (the one opened last is closed first). Return true or
false.

Input (LeetCode): the string s.
Output: true / false.

Example
"()"      -> true
"()[]{}"  -> true
"(]"      -> false
"([)]"    -> false      (the ( is closed while [ is still open)
"{[]}"    -> true

*/

/*
 * Idea: the bracket opened LAST must be closed FIRST. "Last in, first out"
 * is exactly a stack (Module 13).
 *
 * Walk the string:
 *   - an opening bracket: push it; it now waits to be closed.
 *   - a closing bracket: it must close the bracket on top of the stack.
 *       stack empty       -> nothing to close          -> false
 *       top is the pair   -> that pair is done, pop it
 *       top is different  -> wrong order or type       -> false
 * At the end every opening bracket must have been closed, so the stack must
 * be empty. "((" leaves two brackets on the stack -> false.
 */
// (LeetCode's hidden main includes <stack> and <string> and calls isValid.)
class Solution {
public:   // LeetCode calls isValid from outside the class
    // Is `open` the opening partner of the closing bracket `close`?
    bool isPair(char open, char close) {
        return (open == '(' && close == ')') ||
               (open == '{' && close == '}') ||
               (open == '[' && close == ']');
    }

    bool isValid(string s) {
        stack<char> st;   // opening brackets still waiting for their partner

        // Range-for: c is each character of s, left to right.
        for (char c : s) {
            if (c == '(' || c == '{' || c == '[') {
                st.push(c);            // wait for its closing bracket
            }
            else {
                // A closing bracket with nothing open, e.g. ")(".
                if (st.empty()) {
                    return false;
                }
                // It must close the most recent opening bracket.
                if (!isPair(st.top(), c)) {
                    return false;
                }
                st.pop();              // this pair is matched
            }
        }

        // Anything still on the stack was opened but never closed.
        return st.empty();
    }
};
