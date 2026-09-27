/*

Problem Statement

You will be given a binary string  (A binary string is a string which contains only 0 and 1) in which every  will eliminate its previously adjacent  and itself. After an elimination, if another elimination is possible, it will continue until no further eliminations can be made.

For example, if the sequence is , then the  and  elements, as well as the  and  elements, will be eliminated, resulting in the string  (10 01 1 01 10 - Bold values are eliminated). After that, the 2nd and 3rd elements will be eliminated, resulting in the string 110 (1 01 10 - Bold values are eliminated). After that, no further eliminations can occur.

You need to determine whether the string will be empty after all eliminations.

Note: You need to solve it using STL Stack or Queue only.

(The blanks above lost their symbols when copied: every '1' eliminates the
'0' right before it, together with itself.)

Input Format

First line will contain , the number of test cases.
Each test case will contain the string .
Constraints

Output Format

For each test case output YES if the string is empty after all eliminations, NO otherwise.
Sample Input 0

7
01
10
0011
0101
01001110
000111010011
00011
Sample Output 0

YES
NO
YES
YES
NO
YES
NO

*/

/*
 * Idea
 *
 * A '1' eliminates a '0' standing right before it, together with itself.
 * Unlike the "Is it valid?" problem, only this order counts: "01" vanishes,
 * "10" does not. After a pair vanishes, its neighbours meet and may vanish
 * too.
 *
 * Stack again: the top is the nearest surviving character to the left.
 *   - new '1' and the top is '0' -> the pair is eliminated, pop
 *   - anything else -> push
 * The answer is YES when the stack ends up empty.
 *
 *   "0011":  0 | 00 | 1 kills a 0 -> 0 | 1 kills the 0 -> empty   -> YES
 *   "10":    1 | 10 (a 0 after a 1 does nothing)                  -> NO
 */

#include <iostream>     // cin and cout
#include <vector>       // not used here
#include <algorithm>    // not used here
#include <string>       // string, for the binary string
#include <stack>        // STL stack

using namespace std;    // write cout, stack, string without std::

int main() {
    int n;              // number of test cases
    cin >> n;

    // while(n--) runs the body n times; one pass = one test case.
    while(n--){
        stack<char> st;     // survivors so far; a fresh empty stack for every test
        string s;
        cin >> s;           // reads one word: the binary string

        // Range-for: c is each character of s, left to right.
        for(char c : s){
            // Nothing to the left: c survives for now.
        if(st.empty()){
                st.push(c);
                continue;   // skip the rest of this pass, go to the next character
            }

            // Only a '0' followed by a '1' is eliminated.
            if(st.top() == '0' && c == '1'){
                st.pop();           // the 0 disappears, and the 1 is never pushed
            } else {
                st.push(c);         // no elimination: c survives
            }
        }

        // Everything eliminated -> YES.
        if(st.empty()){
            cout << "YES" << endl;  // endl = newline + flush
        } else {
            cout << "NO" << endl;
        }
    }



    return 0;           // program finished normally
}
