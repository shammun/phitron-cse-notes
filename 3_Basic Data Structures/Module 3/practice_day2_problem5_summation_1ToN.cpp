/*

Summation from 1 to N
time limit per test: 0.25 seconds
memory limit per test: 256 megabytes
Given a number N. Print the summation of the numbers that is between 1 and N (inclusive).

Note: Solve this problem in O(1) Complexity.

*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int main() {
    /*
     * Adding 1 + 2 + ... + n with a loop is O(n). The formula n(n+1)/2 gives
     * the same answer with one multiplication: O(1).
     * Why it works: pair the first and last numbers. 1 + n, 2 + (n-1), ...
     * every pair adds up to n + 1, and there are n/2 pairs.
     * n = 4: 4 * 5 / 2 = 10 = 1 + 2 + 3 + 4.
     */
    // n can be up to 10^9, so n * (n + 1) is about 10^18: long long is needed.
    long long n;
    cin >> n;
    long long sum = (n * (n + 1)) / 2;
    cout << sum << endl;

    return 0;
}