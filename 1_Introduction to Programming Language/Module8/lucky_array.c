/*
===============================================================================
  Problem J: Lucky Array
  time limit per test: 1 second
  memory limit per test: 256 megabytes

  Problem Statement
  -----------------
  Given a number N and an array A of N numbers, determine if the array is
  "lucky" or not.

  Note: the array is LUCKY if the frequency (number of occurrences) of the
  MINIMUM element is ODD.

  Input Format
  ------------
  First line contains a number N (2 <= N <= 1000), the number of elements.
  Second line contains N numbers (-10^5 <= A[i] <= 10^5).

  Output Format
  ------------
  Print "Lucky" (without quotes) if the frequency of the minimum element
  is odd.
  Otherwise, print "Unlucky" (without quotes).

  Constraints
  -----------
    2 <= N <= 1000
    -10^5 <= A[i] <= 10^5

  A[i] fits comfortably in a 32-bit int (max |A[i]| = 100,000).

  Algorithm
  ---------
    1. Read all N values into an array.
    2. Find the minimum value by scanning once.
    3. Count how many times that minimum value appears.
    4. Print "Lucky" if the count is odd, "Unlucky" if even.

  Example from the problem
  ------------------------
    Input:
      5
      8 8 9 5 9

    Trace:
      Array = [8, 8, 9, 5, 9]
      Minimum = 5
      Count of 5 in the array = 1
      1 is odd -> "Lucky"

    Expected output (based on the rule):
      Lucky
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

    /* Step 1: find the minimum value.
       Initialize with the first element; it is guaranteed to exist
       because N >= 2. */
    int min_val = a[0];
    for (int i = 1; i < n; i++) {
        if (a[i] < min_val) {
            min_val = a[i];
        }
    }

    /* Step 2: count how many times min_val appears in the array. */
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] == min_val) {
            count++;
        }
    }

    /* Step 3: odd count -> Lucky, even count -> Unlucky.
       We use count % 2 != 0 (equivalently count & 1) to test for odd. */
    if (count % 2 != 0) {
        printf("Lucky\n");
    } else {
        printf("Unlucky\n");
    }

    return 0;
}