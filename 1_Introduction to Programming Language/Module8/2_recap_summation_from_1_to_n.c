/*
===============================================================================
  Problem G: Summation from 1 to N
  Source: https://codeforces.com/group/MWSDmqGsZm/contest/219158/problem/G
===============================================================================

  Problem Statement
  -----------------
  Given a number N, print the summation of all numbers between 1 and N
  (inclusive).

  That is, compute S = 1 + 2 + 3 + ... + N.

  Input Format
  ------------
  Only one line containing a number N.

  Output Format
  ------------
  Print the summation of the numbers between 1 and N (inclusive).

  Constraints
  -----------
  The Codeforces page lists only "Given a number N", without an explicit
  bound. Since the accepted reference solution reads N as 'long long' and
  uses the closed-form formula, we do the same defensively. This handles
  N up to about 4.2 * 10^9 safely (beyond that, N*(N+1) itself overflows
  even long long).

  Math
  ----
  We use Gauss's closed-form for the arithmetic series:

          N
          Sum of k = N * (N + 1) / 2
         k=1

  This is O(1) instead of the O(N) loop approach. For very large N,
  this is the only practical way.

  Overflow note: N * (N + 1) must fit in long long before dividing by 2.
  long long (64-bit signed) max ~ 9.22 * 10^18, so N can go up to
  roughly sqrt(9.22 * 10^18) ~ 3.04 * 10^9 without overflow. Well beyond
  typical test inputs.
===============================================================================
*/

#include <stdio.h>

int main() {
    long long n;
    scanf("%lld", &n);

    /* Closed-form sum: N*(N+1)/2. Always an integer because exactly one
       of N and N+1 is even, so the division by 2 is exact. */
    long long sum = n * (n + 1) / 2;

    printf("%lld\n", sum);

    return 0;
}