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
    long long n;
    cin >> n;
    long long sum = (n * (n + 1)) / 2;
    cout << sum << endl;

    return 0;
}