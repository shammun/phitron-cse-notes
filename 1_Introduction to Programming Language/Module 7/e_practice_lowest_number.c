/*
===============================================================================
  Problem E: Lowest Number
  Source: https://codeforces.com/group/MWSDmqGsZm/contest/219774/problem/E
===============================================================================

  Problem Statement
  -----------------
  Given a number N and an array A of N numbers, print the lowest number and
  its position.

  Note: If there is more than one occurrence of the lowest number, print the
  position of the FIRST one.

  Input Format
  ------------
  First line contains a number N (2 <= N <= 1000), the number of elements.
  Second line contains N numbers (the problem guarantees typical int ranges).

  Output Format
  ------------
  Print two numbers separated by a space on a single line:
    <lowest value> <position of its first occurrence>
  Position is 1-indexed (see samples).

  Constraints
  -----------
    2 <= N <= 1000

  Sample Input 0         Sample Output 0
  --------------         ---------------
  3                      1 1
  1 2 3

  Explanation: Array = [1, 2, 3]. Lowest = 1, at 1-indexed position 1.

  Sample Input 1         Sample Output 1
  --------------         ---------------
  5                      2 3
  5 6 2 3 2

  Explanation: Array = [5, 6, 2, 3, 2]. Lowest = 2. It appears at 1-indexed
  positions 3 and 5; we print the FIRST occurrence, so position = 3.
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

    /* Initialize with the first element. This is cleaner and safer than
       using INT_MAX because it works no matter what integer range the
       problem uses, and it guarantees the position we record is a real
       index into the array. */
    int min_val = a[0];
    int min_pos = 0;   /* 0-indexed internally; we'll +1 when printing */

    /* Scan from index 1 onward. Use strict '<' (not '<=') so that on ties
       we keep the EARLIEST position, which is what the problem asks for. */
    for (int i = 1; i < n; i++) {
        if (a[i] < min_val) {
            min_val = a[i];     /* a new smallest value... */
            min_pos = i;        /* ...and where it is */
        }
    }

    /* Convert to 1-indexed position for output
       Trace 5 6 2 3 2: min 5@0 -> 6 no -> 2@2 -> 3 no -> 2 not < 2, keep 2@2.
       Printed: 2 3 */
    printf("%d %d\n", min_val, min_pos + 1);

    return 0;   /* 0 = the program finished normally */
}