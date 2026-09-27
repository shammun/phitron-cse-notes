/*

Problem Statement

Given a string  containing just the characters  and , determine if the input string is valid.

An input string is valid if the string is empty after doing some operatios. The available operations are:

 can delete its previous available character  along with itself. If there is no  available to delete, it will not delete itself.
 can delete its previous available character  along with itself. If there is no  available to delete, it will not delete itself.
Note: You need to solve it using STL Stack or Queue only.

(The blanks above lost their symbols when copied: the string S has only
'0' and '1'; a '0' can delete the '1' just before it, and a '1' can delete
the '0' just before it.)

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

#include <iostream>     // cin and cout
#include <vector>       // not used here
#include <algorithm>    // not used here
#include <string>       // string, to hold each test's text
#include <stack>        // STL stack

using namespace std;    // write cout, string, stack without the std:: prefix

int main(){
    int t;              // number of test cases
    cin >> t;

    // while(t--): checks t, then lowers it by 1, so the body runs exactly
    // t times (it stops when t reaches 0). One pass = one test case.
    while(t--){
        string s;
        cin >> s;       // cin >> reads one word (stops at a space or newline)

        stack<char> st;   // characters still standing; top = nearest one on the left
                          // (created inside the loop, so every test starts with an empty stack)

        // Range-for: c is each character of s, left to right.
        for(char c : s){
        if(st.empty()){
                // Nothing to delete: c stays.
                st.push(c);
            } else{
                // Opposite digits next to each other delete each other.
                if(c == '0' && st.top() == '1'){          // a 0 right after a surviving 1
                    st.pop();                             // both vanish: drop the 1, never push the 0
                } else if(c == '1' && st.top() == '0'){   // a 1 right after a surviving 0
                    st.pop();
                } else{
                    // Same digit: no deletion, c stays.
                    st.push(c);
                }
            }
        }

        // Valid means everything got deleted.
        if(st.empty()){
            cout << "YES" << endl;   // endl = newline + flush
        } else {
            cout << "NO" << endl;
        }
    }

    return 0;           // program finished normally
}
