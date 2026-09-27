/*

Max and Min
time limit per test: 0.25 seconds
memory limit per test: 64 megabytes
Given 3 numbers A, B and C, Print the minimum and the maximum numbers.

Input
Only one line containing 3 numbers A, B and C ( - 105 ≤ A, B, C ≤ 105)

Output
Print the minimum number followed by a single space then print the maximum number.

Examples
Input
1 2 3
Output
1 3
Input
-1 -2 -3
Output
-3 -1
Input
10 20 -5
Output
-5 20

*/

// (In the statement above, "105" means 10^5 - the superscript was lost in copying.
//  Values up to 100000 fit easily in an int.)

#include <iostream> // gives cin (read from keyboard) and cout (print to screen)
using namespace std; // lets us write cin/cout instead of std::cin/std::cout

int main(){ // the program starts running here
    int a, b, c; // three whole numbers (can be negative)
    cin >> a >> b >> c; // the three numbers, separated by spaces; cin reads them left to right

    // Minimum: assume a is the smallest, then let b and c challenge it.
    // Each if replaces the champion only when the challenger is smaller.
    // Trace with 10 20 -5: min=10 -> 20<10? no -> -5<10? yes, min=-5
    int min = a;
    if(b < min){ // is b smaller than the current minimum?
        min = b; // yes - b is the new minimum
    }
    if(c < min){ // is c smaller than the current minimum?
        min = c; // yes - c is the new minimum
    }

    // Maximum: the same idea with > instead of <
    // Trace with 10 20 -5: max=10 -> 20>10? yes, max=20 -> -5>20? no -> 20
    int max = a;
    if(b > max){ // is b bigger than the current maximum?
        max = b;
    }
    if(c > max){ // is c bigger than the current maximum?
        max = c;
    }

    cout << min << " " << max << endl; // minimum, one space, maximum, then newline

    return 0; // the program ended fine
}