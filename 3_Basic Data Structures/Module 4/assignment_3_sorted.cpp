/*

Sorted

Problem Statement

You will given an array A of size N. You need to tell if the array is already sorted or 
not. If the array is sorted in ascending order print "YES", otherwise print "NO".

Input Format

First line will contain T, the number of test cases.
The first line of each test case will contain N.
The second line of each test case will contain the array A.
Constraints

1 <= T <= 1000
1 <= N <= 1000
0 <= A[i] <= 1000; Where 0 <= i < N
Output Format

Output "YES" or "NO" without the quotation marks according to the problem statement.
Sample Input 0

3
5
2 4 6 7 10
8
1 100 101 120 120 121 1000 1000
4
100 1 102 12
Sample Output 0

YES
YES
NO

*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int main() {
    int T;
    cin >> T;

    // Each round of this loop handles one whole test case.
    for(int i=0; i<T; i++){
        int N;
        cin >> N;
        // A fresh vector for every test case, sized for this case's N.
        vector<int> A(N);
        for(int j=0; j<N; j++){
            cin >> A[j];
        }

        /*
         * An array is sorted in ascending order when no element is smaller
         * than the one before it. Equal neighbours are allowed
         * (120 120 is fine). One "going down" step is enough to say NO.
         */
        bool flag = true;               // assume sorted until proven wrong
        for(int j=1; j<N; j++){
            if(A[j] < A[j-1]){
                flag = false;           // found a step down: 100 1 ...
                break;                  // no need to look further
            }
        }

        if(flag){
            cout << "YES" << endl;
        }
        else{
            cout << "NO" << endl;
        }
    }

    return 0;
}