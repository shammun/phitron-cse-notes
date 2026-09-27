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

/* stdio.h ("standard input output") declares scanf and printf; #include
   pastes it in before compiling so the compiler knows those names. */
#include <stdio.h>

int main() {                /* the program starts running here */
    int n;                  /* how many numbers are coming */
    scanf("%d", &n);        /* %d = read a whole number; &n = where to put it */

    /* An array of n ints: n boxes a[0] .. a[n-1] under one name. The size
       comes from the input, which C allows since C99 (a "variable-length
       array"); n must already be read before this line runs. */
    int a[n];

    /* Fill the boxes: pass i reads the next number into a[i]. &a[i] is the
       address of box i, which scanf needs in order to write into it.
       i goes 0, 1, ..., n-1 and the loop stops when i reaches n. */
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    /* Transform each element in place (the array itself is changed; no
       second array is needed). One pass looks at one box. */
    for (int i = 0; i < n; i++) {
        if (a[i] > 0) {
            a[i] = 1;       /* positive -> 1 */
        } else if (a[i] < 0) {
            a[i] = 2;       /* negative -> 2 */
        }
        /* if a[i] == 0, leave it unchanged */
    }

    /* Print space-separated. To avoid a trailing space before the newline,
       print the first element alone, then " %d" for each subsequent one. */
    for (int i = 0; i < n; i++) {
        if (i == 0) {
            printf("%d", a[i]);     /* first value: no space before it */
        } else {
            printf(" %d", a[i]);    /* every later value: a space, then it */
        }
    }
    printf("\n");      /* end the output line */

    return 0;   /* 0 = the program finished normally */
}