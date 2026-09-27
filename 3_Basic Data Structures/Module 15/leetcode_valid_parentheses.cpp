/*

Valid Parentheses (LeetCode 20)
https://leetcode.com/problems/valid-parentheses/

The problem, in my own words
  You get a string made only of the six bracket characters ( ) [ ] { }.
  Say whether it is "valid": every opening bracket is closed by a bracket of
  the same type, the closings happen in the right order (the most recent
  open bracket is closed first), and no closing bracket appears without an
  opening one before it.

Function to write (LeetCode signature)
  bool isValid(string s)   ->  true or false

Sample
  "()[]{}"  -> true
  "(]"      -> false      ( is closed by the wrong type
  "([)]"    -> false      [ is still open when ) arrives
  "{[]}"    -> true
  "(("      -> false      two brackets never closed

*/

/*
 * The idea: a closing bracket must match the MOST RECENT opening bracket
 * that is still waiting. "Most recent first" is exactly what a stack gives.
 *
 *   - opening bracket  -> push it; it waits for its partner.
 *   - closing bracket  -> the top of the stack must be its partner.
 *                         If the stack is empty (nothing to close) or the top
 *                         is a different type, the string is broken.
 *                         Otherwise pop: that pair is finished.
 *   - at the end       -> the stack must be empty, or something was left open.
 *
 * Trace "{[]}":  push { -> [{], push [ -> [{ [], ] matches [ -> pop -> [{],
 *                } matches { -> pop -> [] ; empty at the end -> true
 *
 * Note: no #include or main() - LeetCode's hidden code includes the STL,
 * creates a Solution object and calls isValid.
 */

class Solution {
public:   // LeetCode calls isValid from outside the class
    bool isValid(string s) {
        stack<char> st;   // opening brackets still waiting to be closed

        // Range-for: c is each character of s, left to right.
        for(char c : s){
            if(c == '(' || c == '[' || c == '{'){   // an opening bracket (|| means "or")
                st.push(c);            // remember it, the newest one is on top
            }
            else{
                // A closing bracket with nothing open before it can never match.
                if(st.empty()){
                    return false;
                }

                // The top is the bracket this one has to close.
                char open = st.top();
                // Each bracket in parentheses is one allowed pair; any one of
                // the three being true means c closes `open` correctly.
                if((c == ')' && open == '(') ||
                   (c == ']' && open == '[') ||
                   (c == '}' && open == '{')){
                    st.pop();          // matched pair, forget it
                }
                else{
                    return false;      // wrong type, e.g. "(]" or "([)]"
                }
            }
        }

        // Anything still on the stack was opened but never closed, e.g. "((".
        return st.empty();
    }
};
