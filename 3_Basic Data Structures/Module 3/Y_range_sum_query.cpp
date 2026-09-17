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
    int n, q;
    cin >> n >> q;
    vector<int> a(n+1);

    for(int i=1; i<=n; i++){
        cin >> a[i];
    }

    while(q--){
        int l, r;
        cin >> l >> r;
        int sum = 0;
        for(int i=l; i<=r; i++){
            sum += a[i];
        }
        cout << sum << endl;
    }

    return 0;
}