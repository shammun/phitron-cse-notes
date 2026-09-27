/*
===============================================================================
  Problem W: Shape 3
  Source: https://codeforces.com/group/MWSDmqGsZm/contest/219432/problem/W
===============================================================================

  Problem Statement
  -----------------
  Given a number N, print a diamond that has 2N rows.
  (The diamond is drawn with the character '*'.)

  Input Format
  ------------
  Only one line containing a number N (1 <= N <= 99).

  Output Format
  ------------
  Print the diamond pattern described above. Do NOT print any extra spaces
  after the last '*' on a line.

  Constraints
  -----------
    1 <= N <= 99

  Shape of the diamond
  --------------------
  The diamond has 2N rows total: an upper half of N rows (widening) and a
  lower half of N rows (narrowing).

  Row widths follow this pattern (row index i starts at 0 within each half):

  UPPER HALF, for i = 0, 1, ..., N-1:
      leading spaces : N - i - 1
      stars          : 2*i + 1          (i.e. 1, 3, 5, ..., 2N-1)

  LOWER HALF, for i = 0, 1, ..., N-1:
      leading spaces : i
      stars          : 2*(N - i) - 1    (i.e. 2N-1, 2N-3, ..., 3, 1)

  So the total width of the widest row (middle two rows) is 2N - 1 stars.

  Example for N = 3 (2N = 6 rows total):
  --------------------------------------
      *
     ***
    *****
    *****
     ***
      *

  Example for N = 1 (2 rows total):
  ---------------------------------
    *
    *

  Why this works / how it matches the reference:
  The accepted solution uses two separate star-printing loops per row
  (of length i+1 and i in the upper half, of length N-i and N-i-1 in the
  lower half). That's equivalent to a single star loop of length 2*i+1
  (upper) or 2*(N-i)-1 (lower), which is what this solution does.
===============================================================================
*/

/* stdio.h ("standard input output") declares scanf and printf; #include
   pastes it in before compiling so the compiler knows those names. */
#include <stdio.h>
/* putchar(c), used below, also comes from stdio.h: it prints exactly one
   character, e.g. putchar('*'). It is a lighter printf("%c", c). */

int main() {            /* the program starts running here */
    int n;              /* the input number N */
    scanf("%d", &n);    /* %d = read a whole number; &n = where to put it */

    /* Upper half: N rows with widths 1, 3, 5, ..., 2N-1. */
    for (int i = 0; i < n; i++) {
        /* leading spaces */
        for (int j = 0; j < n - i - 1; j++) {
            putchar(' ');       /* one space */
        }
        /* stars: 2*i + 1 of them */
        int stars = 2 * i + 1;
        for (int k = 0; k < stars; k++) {
            putchar('*');       /* one star */
        }
        putchar('\n');          /* end the row: '\n' is the newline character */
    }

    /* Lower half: N rows with widths 2N-1, 2N-3, ..., 3, 1. */
    for (int i = 0; i < n; i++) {
        /* leading spaces */
        for (int j = 0; j < i; j++) {
            putchar(' ');       /* i leading spaces */
        }
        /* stars: 2*(N - i) - 1 of them */
        int stars = 2 * (n - i) - 1;
        for (int k = 0; k < stars; k++) {
            putchar('*');       /* one star */
        }
        putchar('\n');          /* end the row */
    }

    return 0;   /* 0 = the program finished normally */
}