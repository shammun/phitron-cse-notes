/*
===============================================================================
  Problem D: Positions in array
  Source: https://codeforces.com/group/MWSDmqGsZm/contest/219774/problem/D
===============================================================================

  Problem Statement
  -----------------
  Given a number N and an array A of N numbers, print all array positions
  that store a number less than or equal to 10, along with the number stored
  in that position.

  Input Format
  ------------
  First line contains a number N (2 <= N <= 1000), the number of elements.
  Second line contains N numbers (-10^5 <= A[i] <= 10^5).
  It is guaranteed that there is at least one number in the array less than
  or equal to 10.

  Output Format
  ------------
  For each number in the array that is less than or equal to 10, print a
  single line containing "A[i] = X", where i is the position in the array
  (0-indexed) and X is the number stored at that position.

  Constraints
  -----------
    2 <= N <= 1000
    -10^5 <= A[i] <= 10^5
    At least one A[i] satisfies A[i] <= 10.

  A[i] fits comfortably in a 32-bit int.

  Sample Input 0         Sample Output 0
  --------------         ---------------
  5                      A[0] = 1
  1 2 100 0 30           A[1] = 2
                         A[3] = 0

  Explanation:
    Position 0: value 1   <= 10  -> print "A[0] = 1"
    Position 1: value 2   <= 10  -> print "A[1] = 2"
    Position 2: value 100 >  10  -> skip
    Position 3: value 0   <= 10  -> print "A[3] = 0"
    Position 4: value 30  >  10  -> skip
===============================================================================
*/

#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);

    int a[n];

    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    for (int i = 0; i < n; i++) {
        if (a[i] <= 10) {
            printf("A[%d] = %d\n", i, a[i]);
        }
    }

    return 0;
}