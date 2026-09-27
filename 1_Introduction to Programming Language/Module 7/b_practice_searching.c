/*
===============================================================================
  Problem B: Searching
  Source: https://codeforces.com/group/MWSDmqGsZm/contest/219774/problem/B
===============================================================================

  Problem Statement
  -----------------
  Given a number N and an array A of N numbers, determine if the number X
  exists in array A or not, and print its position (0-indexed).

  Note: X may be found once, more than once, or not at all.

  Input Format
  ------------
  First line contains a number N (1 <= N <= 10^5), the number of elements.
  Second line contains N numbers (0 <= A[i] <= 10^9).
  Third line contains a number X (0 <= X <= 10^9).

  Output Format
  ------------
  Print the position of X the FIRST time you find it (0-indexed).
  If it does not exist, print -1.

  Constraints
  -----------
    1 <= N <= 10^5
    0 <= A[i] <= 10^9
    0 <= X <= 10^9

  A[i] and X fit in a 32-bit int (max 10^9 < 2.1 * 10^9), so int is fine.

  Sample Input 0     Sample Output 0
  --------------     ---------------
  3                  1
  3 0 1
  0

  Explanation: Array = [3, 0, 1]. X = 0 is at 0-indexed position 1.

  Sample Input 1     Sample Output 1
  --------------     ---------------
  5                  -1
  1 3 0 4 5
  10

  Explanation: X = 10 is not in the array, so print -1.

  Sample Input 2     Sample Output 2
  --------------     ---------------
  4                  0
  2 3 2 1
  2

  Explanation: Array = [2, 3, 2, 1]. X = 2 appears twice; the first
  occurrence is at 0-indexed position 0.
===============================================================================
*/

/* stdio.h ("standard input output") declares scanf and printf; #include
   pastes it in before compiling so the compiler knows those names. */
#include <stdio.h>

int main() {                /* the program starts running here */
    int n;                  /* how many numbers are coming */
    scanf("%d", &n);        /* %d = read a whole number; &n = where to put it */

    /* n boxes a[0] .. a[n-1]; the size comes from the input, which C allows
       since C99 (a "variable-length array"). */
    int a[n];   /* variable-length array, C99 */

    /* Pass i reads one number into a[i]; &a[i] is that box's address. */
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    int x;              /* the value to look for */
    scanf("%d", &x);

    /* Linear search. Stop at the first match so we get the earliest index.
       pos starts at -1, meaning "not found yet"; if no box matches, it is
       still -1 at the end, which is exactly what the problem wants printed.
       Trace 3 0 1, x = 0: i=0: 3 != 0; i=1: 0 == 0 -> pos = 1, break. */
    int pos = -1;
    for (int i = 0; i < n; i++) {
        if (a[i] == x) {
            pos = i;    /* remember where it was found */
            break;      /* leave the loop now: later matches do not matter */
        }
    }

    printf("%d\n", pos);    /* the index, or -1 */

    return 0;   /* 0 = the program finished normally */
}