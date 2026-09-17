/*

V. Comparison
time limit per test:1 second
memory limit per test: 256 megabytes

Given a comparison symbol S between two numbers A and B. Determine whether it is Right or Wrong.

The comparison is as follows: A < B, A > B, A = B.

Where A, B are two integer numbers and S refers to the sign between them.

Input
Only one line containing A, S and B respectively (-100  ≤  A, B  ≤  100), S can be ('<', '>','=') without the quotes.

Output
Print "Right" if the comparison is true, "Wrong" otherwise.

Examples

Input
5 > 4
Output
Right

Input
9 < 1
Output
Wrong

Input
4 = 4
Output
Right

*/

#include <iostream> // Include the iostream library for input/output operations
using namespace std; // Use the standard namespace to avoid prefixing 'std::' before standard library components

int main(){
    int a, b;
    char s;
    cin >> a >> s >> b;
    if(s == '<' && a < b){
        cout << "Right";
    } else if(s == '>' && a > b){
        cout << "Right";
    } else if(s == '=' && a == b){
        cout << "RIght";
    } else {
        cout << "Wrong";
    }
    return 0;
}