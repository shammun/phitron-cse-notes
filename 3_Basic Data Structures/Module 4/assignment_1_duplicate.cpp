/*

Problem Statement

You will be given an array A of size N. Print "YES" if there is any duplicate value in 
the array, "NO" otherwise.

Input Format

First line will contain N.
Second line will contain the array A.
Constraints

1 <= N <= 100000
0 <= A[i] <= 10^9; Where 0 <= i < N
Output Format

Output "YES" or "NO" without the quotation marks according to the problem statement.
Sample Input 0

5
1 2 3 4 5
Sample Output 0

NO
Sample Input 1

6
2 1 3 5 2 1 
Sample Output 1

YES

*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> A(n);
    for(int i=0; i<n; i++){
        cin >> A[i];
    }

    /*
     * Idea: after sorting, equal values sit right next to each other.
     * So one look at every neighbouring pair is enough.
     * 2 1 3 5 2 1 sorted is 1 1 2 2 3 5: A[1] == A[0] -> YES.
     * Comparing every pair with two loops would be O(n^2) = 10^10 for
     * n = 10^5; sorting first costs only O(n log n).
     */
    sort(A.begin(), A.end());

    for(int i=1; i<n; i++){
        // Start at 1 so that A[i-1] is always a real element.
        if(A[i] == A[i-1]){
            cout << "YES" << endl;
            return 0;        // one duplicate is enough, stop here
        }
    }

    // No two neighbours were equal, so every value is different.
    cout << "NO" << endl;
    return 0;
}