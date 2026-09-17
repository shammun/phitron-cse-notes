/*
===============================================================================
  Problem D: Fixed Password
  Source: https://codeforces.com/group/MWSDmqGsZm/contest/219432/problem/D
===============================================================================

  Problem Statement
  -----------------
  You are given multiple lines, each containing a number X which is a
  password attempt. Print "Wrong" if the password is incorrect. Otherwise,
  print "Correct" and terminate the program immediately.

  Note: the "Correct" password is the number 1999.

  Input Format
  ------------
  The input contains several passwords. Each line contains a number X
  (10^3 <= X <= 10^4 - 1), i.e., a 4-digit number from 1000 to 9999.

  Output Format
  ------------
  For each attempt that is wrong, print "Wrong". When the correct password
  (1999) is entered, print "Correct" and stop reading any further input.

  Constraints
  -----------
    1000 <= X <= 9999  (four-digit integer)
    The correct password is exactly 1999.
    The input is guaranteed to eventually contain 1999, so the loop
    always terminates normally via the 'break'.

  Why int is enough:
    X is at most 9999, which fits trivially in a 32-bit int. No long long
    needed here.
===============================================================================
*/

#include <stdio.h>

int main() {
    const int CORRECT = 1999;
    int x;

    /* Keep reading attempts until we see the correct password. */
    while (scanf("%d", &x) == 1) {
        if (x == CORRECT) {
            printf("Correct\n");
            break;                  /* stop on first correct entry */
        } else {
            printf("Wrong\n");
        }
    }

    return 0;
}