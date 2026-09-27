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

/* stdio.h ("standard input output") declares scanf and printf; #include
   pastes it in before compiling so the compiler knows those names. */
#include <stdio.h>
/* stdlib.h declares llabs (absolute value of a long long), used below. */
#include <stdlib.h>

int main() {                /* the program starts running here */
    int n;                  /* how many numbers are coming */
    scanf("%d", &n);        /* %d = read a whole number; &n = where to put it */

    /* The running total starts at 0 and must be long long (see the overflow
       note above). x holds one number at a time, so %lld reads it. */
    long long sum = 0;
    long long x;

    /* No array needed: each number is added the moment it is read and never
       looked at again. Negative numbers simply pull the total down. */
    for (int i = 0; i < n; i++) {
        scanf("%lld", &x);    /* read the next number into x */
        sum += x;             /* short for sum = sum + x */
    }

    /* llabs() from <stdlib.h> returns |sum| as a long long.
       Using abs() here would be wrong because abs() takes int,
       silently truncating a long long value.
       %lld is the printf placeholder for a long long; \n ends the line.
       Trace for -1 2 -3: sum = -1, then 1, then -2; llabs(-2) = 2. */
    printf("%lld\n", llabs(sum));

    return 0;   /* 0 = the program finished normally */
}