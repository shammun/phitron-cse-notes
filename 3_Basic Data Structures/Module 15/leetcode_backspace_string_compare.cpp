/*

Backspace String Compare (LeetCode 844)
https://leetcode.com/problems/backspace-string-compare/

The problem, in my own words
  Two strings s and t were typed into two text boxes. Every '#' in them is a
  press of the backspace key: it deletes the character typed just before it
  (on an empty box it deletes nothing). Say whether the two boxes end up
  showing the same text.

Function to write (LeetCode signature)
  bool backspaceCompare(string s, string t)   ->  true or false

Sample
  s = "ab#c",  t = "ad#c"   -> true    both become "ac"
  s = "ab##",  t = "c#d#"   -> true    both become ""
  s = "a#c",   t = "b"      -> false   "c" versus "b"

*/

/*
 * The idea: backspace always removes the LAST character typed, so the text
 * in the box behaves like a stack.
 *   - a normal letter -> push it
 *   - a '#'           -> pop the top letter, if there is one
 * Do this for both strings, then compare the two stacks letter by letter.
 * Two stacks of chars can be compared with ==, which checks size and every
 * element, so no extra loop is needed.
 */

class Solution {
public:
    // Types the string into a stack and returns what is left on screen.
    stack<char> typed(string s){
        stack<char> st;
        for(char c : s){
            if(c == '#'){
                // Backspace on an empty box does nothing, so check first:
                // pop() on an empty stack is undefined behaviour.
                if(!st.empty()){
                    st.pop();
                }
            }
            else{
                st.push(c);
            }
        }
        return st;
    }

    bool backspaceCompare(string s, string t) {
        // Same final text <=> same letters in the same order in both stacks.
        return typed(s) == typed(t);
    }
};
