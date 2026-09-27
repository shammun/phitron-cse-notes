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
  All inputs are read first; all outputs are printed afterward.

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

/* stdio.h ("standard input output") declares scanf and printf; #include
   pastes it in before compiling so the compiler knows those names. */
#include <stdio.h>

int main() {        /* the program starts running here */
    int t;              /* number of test cases (at most 15) */
    scanf("%d", &t);    /* %d = read a whole number; &t = where to put it */

    /* Since T <= 15, a small fixed-size array is plenty.
       We read everything first... */
    int inputs[15];             /* inputs[0..14]: each test's N */
    long long results[15];      /* results[i] = inputs[i]! */

    for (int i = 0; i < t; i++) {
        scanf("%d", &inputs[i]);   /* &inputs[i] = address of box i */
    }

    /* ...then compute everything... */
    for (int i = 0; i < t; i++) {
        long long fact = 1;     /* 0! = 1! = 1; fresh for every test */
        /* fact = 2 * 3 * ... * N. For N = 5: 2, 6, 24, 120. */
        for (int j = 2; j <= inputs[i]; j++) {
            fact *= j;          /* short for fact = fact * j */
        }
        results[i] = fact;      /* keep it for the printing loop */
    }

    /* ...then print everything. */
    for (int i = 0; i < t; i++) {
        printf("%lld\n", results[i]);   /* %lld = print a long long */
    }

    return 0;   /* 0 = the program finished normally */
}