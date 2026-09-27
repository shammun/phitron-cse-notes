/*

Problem Statement

Given a string  containing just the characters  and , determine if the input string is valid.

An input string is valid if the string is empty after doing some operatios. The available operations are:

 can delete its previous available character  along with itself. If there is no  available to delete, it will not delete itself.
 can delete its previous available character  along with itself. If there is no  available to delete, it will not delete itself.
Note: You need to solve it using STL Stack or Queue only.

Input Format

First line will contain , the number of test cases.
Next  lines will contain the string .
Constraints

. Here  means the length of the string.
Output Format

Output YES if the string is valid, otherwise NO.
Sample Input 0

10
0011
1010
1100
0101
0001
0111
0110
100101
1110010
0001011011
Sample Output 0

YES
YES
YES
YES
NO
NO
YES
YES
NO
YES

*/

/*
 * Idea
 *
 * Only '0' and '1' appear. A '0' deletes the nearest '1' still standing just
 * before it (and itself), and a '1' deletes the nearest '0' before it. So
 * any "01" or "10" pair of neighbours cancels, and removing a pair can bring
 * two more characters next to each other.
 *
 * A stack handles this naturally: its top is the nearest character still
 * standing on the left. For each new character:
 *   - top is the opposite digit -> they cancel, pop the top
 *   - otherwise (empty stack or same digit) -> push the character
 * The string is valid when nothing is left.
 *
 *   "0110":  0 | 01 cancel -> empty | 1 | 10 cancel -> empty   -> YES
 *   "0001":  0 | 00 | 000 | 1 cancels one 0 -> 00 left          -> NO
 */

#include <iostream>
#include <vector>
#include <algorithm>    
#include <string>
#include <stack>

using namespace std;

int main(){
    int t;
    cin >> t;

    while(t--){
        string s;
        cin >> s;

        stack<char> st;   // characters still standing; top = nearest one on the left

        for(char c : s){
            // Valid means everything got deleted.
        if(st.empty()){
                // Nothing to delete: c stays.
                st.push(c);
            } else{
                // Opposite digits next to each other delete each other.
                if(c == '0' && st.top() == '1'){
                    st.pop();
                } else if(c == '1' && st.top() == '0'){
                    st.pop();
                } else{
                    // Same digit: no deletion, c stays.
                    st.push(c);
                }
            }
        }

        if(st.empty()){
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }

    return 0;
}