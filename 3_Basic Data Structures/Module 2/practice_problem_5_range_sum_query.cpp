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

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int main() {
    /*
     * Brute force: for every query add up a[l-1] .. a[r-1] with a loop.
     * One query can cost up to n steps, so q queries cost O(n*q). With
     * n = q = 10^5 that is 10^10 steps: Time Limit Exceeded. The practice
     * sheet expects this; Module 3 fixes it with a prefix sum.
     */
    int n, q;
    cin >> n >> q;
    vector<int> a(n);

    for(int i=0; i<n; i++){
        cin >> a[i];
    }

    // Each answer can reach 10^5 * 10^9 = 10^14, far above the int limit
    // (about 2 * 10^9), so answers are stored as long long.
    vector<long long> results(q);

    // Run loops for q times
    for(int i=0; i<q; i++){
        int l, r;
        cin >> l >> r;

        // The judge counts from 1, the vector from 0: shift both ends by 1.
        long long sum = 0;
        for(int j=l-1; j<= r-1; j++){
            sum += a[j];
        }

        results[i] = sum;
    }

    // Print all answers at the end, one per line.
    for(int i=0; i<q; i++){
        cout << results[i] << endl;
    }

    return 0;
}