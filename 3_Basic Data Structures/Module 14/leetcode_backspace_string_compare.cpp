/*

https://leetcode.com/problems/backspace-string-compare/

Backspace String Compare (LeetCode 844)

Two strings are typed into two text boxes, where '#' means "backspace"
(delete the last character, if there is one). Do both boxes end up with the
same text?

Example: s = "ab#c", t = "ad#c" -> both become "ac" -> true.

*/

/*
 * Idea
 *
 * A backspace always deletes the character typed MOST RECENTLY. That is a
 * stack: push each normal character, and pop on '#'. What is left in the
 * stack is the final text (read bottom to top).
 *
 *   "ab#c":  push a, push b, '#' pops b, push c   -> stack a c
 *
 * Build one stack for each string and compare them. Two STL stacks can be
 * compared with ==: they are equal when they hold the same values in the
 * same order.
 *
 * Note: no #include here - LeetCode's hidden code already includes the
 * standard library and `using namespace std;`, so string and stack just work.
 */

// LeetCode's answer class.
class Solution {
public:     // the judge calls this from outside the class
    // s and t are copies (passed by value); returns true if both type the same text.
    bool backspaceCompare(string s, string t) {
        // Type string s into stack st.
        stack<char> st;         // a stack of single characters
        // Range-for: c takes each character of s, left to right.
        for(char c : s){
            if(c == '#'){       // '#' in single quotes is one char
                // Backspace on an empty box does nothing, so only pop when
                // there is something to delete (popping an empty stack crashes).
                if(!st.empty()){
                    st.pop();
                }
            } else {
                st.push(c);     // a normal character is typed
            }
        }

        // Type string t into stack st2, exactly the same way.
        stack<char> st2;
        for(char c : t){
            if(c == '#'){
                if(!st2.empty()){
                    st2.pop();
                }
            } else {
                st2.push(c);
            }
        }

        // Same final text <=> same stacks.
        // Example: "ab#c" -> a c, "ad#c" -> a c -> equal -> true.
        return st == st2;
    }
};