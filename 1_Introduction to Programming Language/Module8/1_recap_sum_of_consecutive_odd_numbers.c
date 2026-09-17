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

#include <stdio.h>

int main() {
    int t;
    scanf("%d", &t);

    while (t--) {
        int x, y;
        scanf("%d %d", &x, &y);

        /* Ensure x < y so the loop bounds make sense. */
        if (x > y) {
            int tmp = x; x = y; y = tmp;
        }

        long long sum = 0;
        /* Strictly between: start at x+1, stop before y. */
        for (int i = x + 1; i < y; i++) {
            if (i % 2 != 0) {
                sum += i;
            }
        }

        printf("%lld\n", sum);
    }

    return 0;
}