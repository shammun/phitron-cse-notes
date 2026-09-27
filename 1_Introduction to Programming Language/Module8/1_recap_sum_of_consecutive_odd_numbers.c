/*
===============================================================================
  Problem S: Sum of Consecutive Odd Numbers
  Source: https://codeforces.com/group/MWSDmqGsZm/contest/219432/problem/S
===============================================================================

  Problem Statement
  -----------------
  Given two numbers X and Y, print the sum of all odd numbers between them,
  EXCLUDING X and Y themselves.

  Input Format
  ------------
  First line contains a number T (1 <= T <= 10), the number of test cases.
  Next T lines will each contain two numbers X and Y (0 <= X, Y <= 10^4).

  Output Format
  ------------
  For each test case, print the sum of all odd numbers strictly between X and Y
  (i.e., exclusive on both ends), on its own line.

  Constraints
  -----------
    1 <= T <= 10
    0 <= X, Y <= 10^4

  Notes on edge cases:
    - The problem does NOT say X < Y, so Y could be smaller than X.
      We must sort so that we iterate from min+1 to max-1.
    - "Between X and Y excluding X and Y" means the range (min(X,Y), max(X,Y)),
      i.e., strictly greater than the smaller and strictly less than the larger.
    - If the two numbers are equal or adjacent, the range is empty and the
      answer is 0.

  Overflow analysis:
    Max possible sum: all odd numbers in (0, 10000) is 1+3+...+9999 = 25,000,000
    which fits comfortably in a 32-bit int. A 'long long' sum is safer and
    costs nothing here.
===============================================================================
*/

/* stdio.h ("standard input output") declares scanf and printf; #include
   pastes it in before compiling so the compiler knows those names. */
#include <stdio.h>

int main() {        /* the program starts running here */
    int t;              /* number of test cases */
    scanf("%d", &t);    /* %d = read a whole number; &t = where to put it */

    /* while (t--) runs the body exactly t times: the test uses the CURRENT
       t (true while it is not 0) and then subtracts 1. With t = 2: test 2
       (true) -> body, test 1 (true) -> body, test 0 (false) -> stop. */
    while (t--) {
        int x, y;                   /* the two ends of the range */
        scanf("%d %d", &x, &y);

        /* Ensure x < y so the loop bounds make sense. */
        if (x > y) {
            /* Swap via a temporary box: keep x in tmp, copy y into x, then
               put the saved value into y. e.g. x=9,y=5 -> tmp=9, x=5, y=9. */
            int tmp = x; x = y; y = tmp;
        }

        long long sum = 0;      /* running total; must start at 0 */
        /* Strictly between: start at x+1, stop before y. */
        for (int i = x + 1; i < y; i++) {
            if (i % 2 != 0) {       /* remainder 1 when divided by 2: odd */
                sum += i;           /* short for sum = sum + i */
            }
        }

        /* %lld = print a long long. Trace x=5, y=12: odd numbers 7,9,11 -> 27. */
        printf("%lld\n", sum);
    }

    return 0;   /* 0 = the program finished normally */
}