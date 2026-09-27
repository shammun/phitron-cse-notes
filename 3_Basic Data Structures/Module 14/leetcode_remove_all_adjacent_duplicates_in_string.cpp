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
 *
 * (No #include: LeetCode already includes the standard library and
 *  `using namespace std;`.)
 */

// LeetCode's answer class.
class Solution {
public:     // callable by the judge
    // s is a copy (by value); returns the string left after all cancellations.
    string removeDuplicates(string s) {
        stack<char> st;   // the letters kept so far; top = the last kept letter
        if(s.empty()){    // nothing to do for an empty string
            return "";
        }

        // Range-for: c takes each letter of s, left to right.
        for(char c : s){
            // Check empty() first: top() on an empty stack would crash.
            // (&& stops early, so top() is only reached when the stack has something.)
            if(!st.empty() && st.top() == c){
                st.pop();        // c and the top are an adjacent pair: remove both
            } else{
                st.push(c);      // no pair: keep c
            }
        }

        // Pop the letters out. They come out last-to-first ...
        string newS = "";
        while(!st.empty()){
            newS += st.top();   // append the top letter
            st.pop();
        }
        // "abbaca": stack c a (a on top)... pops give "ac".
        // ... so flip the string to get them back in reading order.
        // reverse(first, last) from <algorithm> reverses the range in place.
        reverse(newS.begin(), newS.end());
        return newS;            // "ca"
    }
};