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

#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);

    int a[n];

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
            min_val = a[i];
            min_pos = i;
        }
    }

    /* Convert to 1-indexed position for output */
    printf("%d %d\n", min_val, min_pos + 1);

    return 0;
}