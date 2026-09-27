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

/*
 * The idea: vector's insert(position, value) puts one value at that
 * position and shifts everything from there onwards one step right.
 * Insert B's elements one by one, moving the position forward each time
 * so they keep their order.
 *   A = 2 3 4 5 6, X = 3:
 *     insert 10 at 3 -> 2 3 4 10 5 6
 *     insert 20 at 4 -> 2 3 4 10 20 5 6
 *     insert 30 at 5 -> 2 3 4 10 20 30 5 6
 *
 * C++ pieces used:
 *   #include <iostream>  cin >> x reads; cout << x prints.
 *   #include <vector>    vector<int> A(N): a resizable array of N ints.
 *   <algorithm>, <string> - not used here.
 *   using namespace std; - write cin/cout/vector without std::.
 */
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int main() {        // the program starts here
    int N;          // size of A
    cin >> N;

    vector<int> A(N);           // A[0]..A[N-1]
    for(int i=0; i<N; i++){     // read A
        cin >> A[i];
    }

    int M;          // size of B
    cin >> M;

    vector<int> B(M);           // B[0]..B[M-1]
    for(int i=0; i<M; i++){     // read B
        cin >> B[i];
    }

    int X;          // the index in A where B must start
    cin >> X;

    /* A.begin() is the position of A's first element; A.begin() + X is the
       position X steps further on. insert places B[i] there, pushing the
       rest of A one place right, and A grows by one.
       X++ moves the target one step on, so the next B element goes AFTER
       the one just inserted (without it, B would come out reversed). */
    for(int i=0; i<M; i++){
        A.insert(A.begin() + X, B[i]);
        X++;
    }

    /* A now holds N + M elements. Print each followed by a space
       (the expected output also ends with a space and no newline). */
    for(int i=0; i<N+M; i++){
        cout << A[i] << " ";
    }

    return 0;       // 0 = finished normally
}