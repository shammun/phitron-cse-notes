/*

Insert it

Problem Statement

You will given an integer array A of size N and another array B of size M. Also you will 
be given an index X. You need to insert the whole array B to the index X of array A.

Input Format

First line will contain N.
Second line will contain array A.
Third line will contain M.
Fourth line will contain array B.
The last line will contain X.
Constraints

1 <= N, M <= 10^3
1 <= A[i], B[j] <= 10^3; Where 0 <= i < N and 0 <= j < M
0 <= X <= N
Output Format

Output the final array A.
Sample Input 0

5
2 3 4 5 6
3
10 20 30
3
Sample Output 0

2 3 4 10 20 30 5 6 
Sample Input 1

5
2 3 4 5 6
3
10 20 30
0
Sample Output 1

10 20 30 2 3 4 5 6 
Sample Input 2

4
3 4 5 6
3
10 20 30
4
Sample Output 2

3 4 5 6 10 20 30 

*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int main() {
    int N;
    cin >> N;

    vector<int> A(N);
    for(int i=0; i<N; i++){
        cin >> A[i];
    }

    int M;
    cin >> M;

    vector<int> B(M);
    for(int i=0; i<M; i++){
        cin >> B[i];
    }

    int X;
    cin >> X;

    for(int i=0; i<M; i++){
        A.insert(A.begin() + X, B[i]);
        X++;
    }

    for(int i=0; i<N+M; i++){
        cout << A[i] << " ";
    }

    return 0;
}