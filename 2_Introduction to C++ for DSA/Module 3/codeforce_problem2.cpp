/*

Mathematical Expression
time limit per test: 0.25 seconds
memory limit per test: 256 MB

Given a mathematical expression. The expression will be one of the following expressions:

A + B = C, A - B = C and A * B = C

where A, B, C are three numbers, S is the sign between A and B, and Q the '=' sign

Print "Yes" If the expression is Right , Otherwise print the right answer of the expression.

Input
Only one line containing the expression: A, S, B, Q, C respectively (0 ≤ A, B ≤ 100,  - 105 ≤ C ≤ 105) and S can be ('+', '-', '*') without the quotation.

Output
Output either "Yes" (without the quotation) or the right answer depending on the statement.

Examples

Input
5 + 10 = 15
Output
Yes

Input
3 - 1 = 2
Output
Yes

Input
2 * 10 = 19
Output
20

*/

#include <iostream> // Include the iostream library for input/output operations
using namespace std; // Use the standard namespace to avoid prefixing 'std::' before standard library components

int main(){
    int a, b, c;
    char s, q;
    cin >> a >> s >> b >> q >> c;
    if(s == '+' && a + b == c){
        cout << "Yes";
    } else if(s == '-' && a - b == c){
        cout << "Yes";
    } else if(s == '*' && a * b == c){
        cout << "Yes";
    } else {
        if(s == '+'){
            cout << a + b;
        } else if(s == '-'){
            cout << a - b;
        } else if(s == '*'){
            cout << a * b;
        }
    }
}
