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
 * First answer: add up the range again for every query.
 * It is correct, but one query can cost n additions, so q queries cost
 * O(n*q). At the limits (10^5 each) that is 10^10 steps -> Time Limit
 * Exceeded. range_sum_query_Prefix_Sum.cpp removes the inner loop.
 */
int main() { // the program starts running here
    int n, q; // n = number of values, q = number of queries
    cin >> n >> q; // read both

    // Size n+1 so the values can sit at indexes 1..n, the same numbering
    // the queries use. Index 0 is simply left unused.
    vector<int> a(n+1);

    // Read the values into a[1..n]. Each value (<= 10^9) fits in an int.
    for(int i=1; i<=n; i++){
        cin >> a[i]; // read one value
    }

    // while(q--) runs exactly q times: it tests q, then decreases it.
    while(q--){
        int l, r; // range ends, 1-based
        cin >> l >> r; // read one query

        // Up to 10^5 values of up to 10^9 each: the sum can reach 10^14,
        // so it needs long long (int stops near 2 * 10^9).
        long long sum = 0;
        for(int i=l; i<=r; i++){ // visit every index from l to r
            sum += a[i];      // the slow part: walk the whole range each time
        }
        cout << sum << endl; // print this query's answer
    }

    return 0; // program finished successfully
}
