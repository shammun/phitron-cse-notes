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

// Idea: read the number, the sign character, and the number. The statement is
// "Right" only if the sign that was written really matches how a and b compare.

#include <iostream> // Include the iostream library for input/output operations (cin, cout)
using namespace std; // Use the standard namespace to avoid prefixing 'std::' before standard library components

int main(){
    int a, b; // the two numbers on either side of the sign (-100..100 fits easily in int)
    char s;   // the sign itself: one character, '<', '>' or '='
    // cin skips the spaces, so "5 > 4" puts 5 in a, '>' in s and 4 in b
    // (cin >> into a char reads exactly one non-space character.)
    cin >> a >> s >> b;

    // Each branch checks two things: which sign was written, and whether that
    // comparison really holds. If no branch matches, the sign was a lie.
    // && means "and": both sides must be true. Note '<' in single quotes is a char;
    // == compares; a single = would be assignment.
    if(s == '<' && a < b){ // written "<" and a really is smaller
        cout << "Right";
    } else if(s == '>' && a > b){ // written ">" and a really is bigger
        cout << "Right";
    } else if(s == '=' && a == b){ // written "=" and they really are equal (== tests equality)
        cout << "Right";
    } else {
        // e.g. "9 < 1": s is '<' but 9 < 1 is false, and the other two signs were not written
        cout << "Wrong"; // the written sign does not match the numbers
    }
    return 0; // the program ended fine
}