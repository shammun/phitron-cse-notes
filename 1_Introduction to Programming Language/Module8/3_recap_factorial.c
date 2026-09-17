/*
===============================================================================
  Problem G: Factorial
  Source: https://codeforces.com/group/MWSDmqGsZm/contest/219432/problem/G
===============================================================================

  Problem Statement
  -----------------
  Given a number N, print the factorial of N.

  Factorial in mathematics is the product of all positive integers less than
  or equal to a given positive integer, denoted by that integer followed by
  an exclamation point:
      N! = 1 * 2 * 3 * ... * N
  By convention, 0! = 1.

  Input Format
  ------------
  First line contains a number T (1 <= T <= 15), the number of test cases.
  Next T lines will each contain a single number N (0 <= N <= 20).

  Output Format
  ------------
  For each test case, print a single line containing the factorial of N.

  Constraints
  -----------
    1 <= T <= 15
    0 <= N <= 20

  Why long long is required:
    20! = 2,432,902,008,176,640,000 ~ 2.43 * 10^18
    This fits in an unsigned 64-bit integer (max ~1.84 * 10^19) and also in
    a signed long long (max ~9.22 * 10^18). A 32-bit int maxes at ~2.15*10^9
    and would overflow at N=13 or so. So long long is MANDATORY here.

  Examples from the Codeforces page:
    5! = 1 * 2 * 3 * 4 * 5 = 120
    3! = 1 * 2 * 3 = 6
===============================================================================
*/

#include <stdio.h>

int main() {
    int t;
    scanf("%d", &t);

    while (t--) {
        int n;
        scanf("%d", &n);

        /* Compute n! iteratively. Starts at 1 (correct for n=0). */
        long long fact = 1;
        for (int i = 2; i <= n; i++) {
            fact *= i;
        }

        printf("%lld\n", fact);
    }

    return 0;
}