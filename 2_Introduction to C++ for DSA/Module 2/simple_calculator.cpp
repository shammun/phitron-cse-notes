/*

Simple Calculator
time limit per test: 1 second
memory limit per test: 256 megabytes
Given two numbers X and Y. Print the summation and multiplication and subtraction of these 2 numbers.

Input
Only one line containing two separated numbers X, Y (1  ≤  X, Y  ≤  105).

Output
Print 3 lines that contain the following in the same order:

"X + Y = summation result" without quotes.
"X * Y = multiplication result" without quotes.
"X - Y = subtraction result" without quotes.

Example
Input
5 10
Output
5 + 10 = 15
5 * 10 = 50
5 - 10 = -5
Note
Be careful with spaces.

*/

#include <iostream> // cin and cout
using namespace std; // write cin/cout instead of std::cin/std::cout

int main(){
    // X and Y go up to 10^5, so X * Y can reach 10^10. An int stops at about
    // 2.1 * 10^9 and would overflow, so both are long long (up to about 9 * 10^18).
    long long x, y;
    cin >> x >> y; // one cin reads both numbers, in order

    // cout prints the pieces one after another: the number, the text " + ",
    // the other number, " = ", then the result. The spaces live inside the
    // quoted text, and they must match the judge's format exactly.
    cout << x << " + " << y << " = " << x + y << endl;
    cout << x << " * " << y << " = " << x * y << endl;
    cout << x << " - " << y << " = " << x - y << endl; // can be negative, that is fine

    return 0; // the program ended fine
}