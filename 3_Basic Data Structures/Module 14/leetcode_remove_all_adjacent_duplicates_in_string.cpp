/*

https://leetcode.com/problems/remove-all-adjacent-duplicates-in-string/description/

Remove All Adjacent Duplicates In String (LeetCode 1047)

Keep deleting two equal letters that sit next to each other until no such
pair is left, and return what remains.

Example: "abbaca" -> delete "bb" -> "aaca" -> delete "aa" -> "ca".

*/

/*
 * Idea
 *
 * When a letter arrives, the only letter it can pair with is the last letter
 * that is still kept -- the top of a stack.
 *  - same as the top: the two cancel, so pop the top (and don't push).
 *  - otherwise: push the letter.
 *
 *   "abbaca":  a | ab | a (b cancels b) | empty (a cancels a) | c | ca
 *
 * At the end the stack holds the answer, but popping reads it backwards
 * (top first), so the built string is reversed once at the end.
 */

class Solution {
public:
    string removeDuplicates(string s) {
        stack<char> st;   // the letters kept so far; top = the last kept letter
        if(s.empty()){
            return "";
        }

        for(char c : s){
            // Check empty() first: top() on an empty stack would crash.
            if(!st.empty() && st.top() == c){
                st.pop();        // c and the top are an adjacent pair: remove both
            } else{
                st.push(c);      // no pair: keep c
            }
        }

        // Pop the letters out. They come out last-to-first ...
        string newS = "";
        while(!st.empty()){
            newS += st.top();
            st.pop();
        }
        // ... so flip the string to get them back in reading order.
        reverse(newS.begin(), newS.end());
        return newS;
    }
};