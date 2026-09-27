/*

Summation from 1 to N
time limit per test: 0.25 seconds
memory limit per test: 256 megabytes
Given a number N. Print the summation of the numbers that is between 1 and N (inclusive).

Note: Solve this problem in O(1) Complexity.

*/

#include <iostream>  // cin and cout
#include <vector>    // not needed here, kept from the template
#include <algorithm> // not needed here
#include <string>    // not needed here
using namespace std; // lets us drop the std:: prefix

int main() { // the program starts running here
    /*
     * Adding 1 + 2 + ... + n with a loop is O(n). The formula n(n+1)/2 gives
     * the same answer with one multiplication: O(1).
     * Why it works: pair the first and last numbers. 1 + n, 2 + (n-1), ...
     * every pair adds up to n + 1, and there are n/2 pairs.
     * n = 4: 4 * 5 / 2 = 10 = 1 + 2 + 3 + 4.
     */
    // n can be up to 10^9, so n * (n + 1) is about 10^18: long long is needed.
    // (long long holds up to about 9.2 * 10^18; int only about 2.1 * 10^9.)
    long long n;
    cin >> n; // read N
    // Multiply first, then divide: n * (n + 1) is always even (one of two
    // neighbours is even), so dividing by 2 is exact.
    long long sum = (n * (n + 1)) / 2;
    cout << sum << endl; // print the answer

    return 0; // program finished successfully
}
