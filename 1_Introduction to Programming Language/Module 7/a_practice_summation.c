/*
===============================================================================
  Problem A: Summation
  Source: https://codeforces.com/group/MWSDmqGsZm/contest/219774/problem/A
===============================================================================

  Problem Statement
  -----------------
  Given a number N and an array A of N numbers, print the absolute summation
  of these numbers.

  Absolute value means to remove any negative sign in front of a number.

  Input Format
  ------------
  First line contains a number N (1 <= N <= 10^5), the number of elements.
  Second line contains N numbers (-10^9 <= A[i] <= 10^9).

  Output Format
  ------------
  Print the absolute value of the summation of these numbers.

  Constraints
  -----------
    1 <= N <= 10^5
    -10^9 <= A[i] <= 10^9

  Worst-case sum magnitude:
    |sum| <= N * max(|A[i]|) = 10^5 * 10^9 = 10^14
  This overflows a 32-bit int (~2.1 * 10^9), so we MUST use long long.

  Sample Input 0     Sample Output 0
  --------------     ---------------
  4                  13
  7 2 1 3

  Explanation: 7 + 2 + 1 + 3 = 13, |13| = 13.

  Sample Input 1     Sample Output 1
  --------------     ---------------
  3                  2
  -1 2 -3

  Explanation: (-1) + 2 + (-3) = -2, |-2| = 2.
===============================================================================
*/

#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    scanf("%d", &n);

    long long sum = 0;
    long long x;

    for (int i = 0; i < n; i++) {
        scanf("%lld", &x);
        sum += x;
    }

    /* llabs() from <stdlib.h> returns |sum| as a long long.
       Using abs() here would be wrong because abs() takes int,
       silently truncating a long long value. */
    printf("%lld\n", llabs(sum));

    return 0;
}