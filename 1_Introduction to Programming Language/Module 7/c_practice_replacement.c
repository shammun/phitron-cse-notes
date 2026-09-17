/*
===============================================================================
  Problem C: Replacement
  Source: https://codeforces.com/group/MWSDmqGsZm/contest/219774/problem/C
===============================================================================

  Problem Statement
  -----------------
  Given a number N and an array A of N numbers, print the array after doing
  the following operations:
    - Replace every positive number by 1.
    - Replace every negative number by 2.
  (Zero stays as zero.)

  Input Format
  ------------
  First line contains a number N (2 <= N <= 1000), the number of elements.
  Second line contains N numbers (-10^5 <= A[i] <= 10^5).

  Output Format
  ------------
  Print the array after the replacement, values separated by space.

  Constraints
  -----------
    2 <= N <= 1000
    -10^5 <= A[i] <= 10^5

  A[i] fits comfortably in a 32-bit int.

  Sample Input 0         Sample Output 0
  --------------         ---------------
  5                      1 2 0 1 1
  1 -2 0 3 4

  Explanation:
       1 > 0   -> 1
      -2 < 0   -> 2
       0 == 0  -> 0
       3 > 0   -> 1
       4 > 0   -> 1
  Result: "1 2 0 1 1"
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

    /* Transform each element in place */
    for (int i = 0; i < n; i++) {
        if (a[i] > 0) {
            a[i] = 1;
        } else if (a[i] < 0) {
            a[i] = 2;
        }
        /* if a[i] == 0, leave it unchanged */
    }

    /* Print space-separated. To avoid a trailing space before the newline,
       print the first element alone, then " %d" for each subsequent one. */
    for (int i = 0; i < n; i++) {
        if (i == 0) {
            printf("%d", a[i]);
        } else {
            printf(" %d", a[i]);
        }
    }
    printf("\n");

    return 0;
}