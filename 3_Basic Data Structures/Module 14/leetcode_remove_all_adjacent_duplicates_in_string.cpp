/*

https://leetcode.com/problems/remove-all-adjacent-duplicates-in-string/description/

*/

class Solution {
public:
    string removeDuplicates(string s) {
        stack<char> st;
        if(s.empty()){
            return "";
        }

        for(char c : s){
            if(!st.empty() && st.top() == c){
                st.pop();
            } else{
                st.push(c);
            }
        }

        string newS = "";
        while(!st.empty()){
            newS += st.top();
            st.pop();
        }
        reverse(newS.begin(), newS.end());
        return newS;
    }
};