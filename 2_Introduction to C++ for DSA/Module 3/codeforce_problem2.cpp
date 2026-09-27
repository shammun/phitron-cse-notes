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

// Idea: read A, the operator, B, the '=' sign and C. Work out A op B ourselves.
// If it equals C, print "Yes"; otherwise print the correct value.

#include <iostream> // Include the iostream library for input/output operations (cin, cout)
using namespace std; // Use the standard namespace to avoid prefixing 'std::' before standard library components

int main(){
    int a, b, c; // A and B are 0..100, so even A*B (at most 10000) fits in an int; C is the claimed answer
    char s, q; // s is the operator (+, - or *), q just swallows the '=' sign
    // "2 * 10 = 19" is read as a=2, s='*', b=10, q='=', c=19 (cin skips the spaces)
    // Reading into a char takes exactly one non-space character, so '*' and '=' are read as chars.
    cin >> a >> s >> b >> q >> c;

    // First: is the written answer c correct for this operator?
    // Each test says "the operator is X AND the X-result equals c" (&& = both must be true).
    if(s == '+' && a + b == c){ // "5 + 10 = 15": 5+10 is 15 -> Yes
        cout << "Yes";
    } else if(s == '-' && a - b == c){ // "3 - 1 = 2": 3-1 is 2 -> Yes
        cout << "Yes";
    } else if(s == '*' && a * b == c){
        cout << "Yes";
    } else {
        // Wrong answer: print the correct result instead, worked out with the same operator
        // "2 * 10 = 19": 2*10 = 20, not 19 -> we land here and print 20
        if(s == '+'){
            cout << a + b; // correct sum
        } else if(s == '-'){
            cout << a - b; // correct difference (may be negative, e.g. 1 - 5 = -4)
        } else if(s == '*'){
            cout << a * b; // correct product
        }
    }
    // No "return 0;" here: main is special, and reaching its closing brace
    // automatically returns 0 (success). Other functions do not get this rule.
}
