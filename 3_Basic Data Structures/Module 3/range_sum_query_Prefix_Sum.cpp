/*

Range sum query

time limit per test: 1.5 seconds
memory limit per test: 256 megabytes

Given 2 numbers N and Q, an array A  of N number and Q  number of pairs L, R. For each
query Q print a single line that contains the summation of all numbers from index L to
index R.

Input
First line contains two numbers N, Q (1≤N,Q≤10^5) where N is number of elements in A and
Q is number of query pairs.

Second line contains N numbers(1≤Ai≤10^9).

Next Q lines contains L,R (1≤L≤R≤N).

Output
For each query Q print a single line that contains the summation of all numbers from
index L to index R.

Examples
Input
6 3
6 4 2 7 2 7
1 3
3 6
1 6
Output
12
18
28

Input
4 3
5 5 2 3
1 3
2 3
1 4
Output
12
7
15

*/

#include <iostream>  // cin and cout
#include <vector>    // vector
#include <algorithm> // not needed here, kept from the template
#include <string>    // not needed here
using namespace std; // lets us drop the std:: prefix

/*
 * Prefix sum: prefixSum[i] = a[1] + a[2] + ... + a[i].
 * Build it once with one loop (O(n)). Then the sum of a[l..r] is
 * "everything up to r" minus "everything before l":
 *     prefixSum[r] - prefixSum[l-1]
 * which is one subtraction, O(1) per query.
 * Whole program: O(n + q) instead of the brute force's O(n * q).
 *
 * Example: a = 6 4 2 7 2 7 -> prefixSum = 6 10 12 19 21 28.
 * Query 3 6: prefixSum[6] - prefixSum[2] = 28 - 10 = 18 (= 2+7+2+7).
 */
int main() { // the program starts running here
    int n, q; // n = number of values, q = number of queries
    cin >> n >> q; // read both

    // long long everywhere: the totals can reach 10^5 * 10^9 = 10^14.
    // Values are stored from index 1 to match the 1-based queries.
    // (long long int is just the full name of long long.)
    vector<long long int> a(n+1); // n+1 slots: index 0 unused, 1..n hold the values

    // Read the values into a[1..n].
    for(int i=1; i<=n; i++){
        cin >> a[i]; // read one value
    }

    // Each total is the previous total plus the next value.
    vector<long long int> prefixSum(n + 1); // all start at 0, including prefixSum[0]
    prefixSum[1] = a[1]; // total of the first value alone

    for(int i=2; i<=n; i++){ // fill the rest, left to right
        prefixSum[i] = prefixSum[i - 1] + a[i]; // total up to i
    }

    vector<long long int> results(q);   // not used: answers are printed at once

    // while(q--) runs exactly q times: test q, then subtract 1.
    while(q--){
        int l, r; // 1-based range ends
        cin >> l >> r; // read one query
        long long int sum = 0; // the answer for this query

        // When l is 1 there is nothing "before l" to subtract. (prefixSum[0]
        // is 0 anyway, because a new vector is filled with 0, so the else
        // branch alone would also work.)
        if(l==1){
            sum = prefixSum[r]; // everything from 1 to r
        } else{
            sum = prefixSum[r] - prefixSum[l-1]; // up to r, minus up to l-1
        }

        cout << sum << endl; // print it on its own line
    }

    return 0; // program finished successfully
}
