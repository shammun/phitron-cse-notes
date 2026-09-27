/*

Problem (Phitron practice, in my own words)

Read two whole numbers A and B from one line and print their sum.
The numbers can be very large, bigger than an int can hold.

Sample input
3 5

Sample output
8

*/

/* The four #include lines paste in "header" files before compiling.
   Each header tells the compiler about a group of ready-made functions:
     stdio.h  - standard input/output: scanf (read), printf (print)
     string.h - text functions such as strlen (not used here)
     math.h   - maths functions such as sqrt, pow (not used here)
     stdlib.h - general tools such as abs, malloc (not used here)
   Only stdio.h is needed; the other three are a habit from a template
   and cost nothing. */
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {    /* the program starts running here */

    /* long long instead of int: an int stops at about 2.1 * 10^9, a long long
       reaches about 9.2 * 10^18, so a big A or B (and their sum) still fits. */
    long long A, B;

    /* %lld is the placeholder for a long long, in scanf and in printf alike.
       The space between the two %lld lets the numbers be separated by any
       spaces or newlines. & gives scanf the address of each variable. */
    scanf("%lld %lld", &A, &B); // Input the two numbers separated by space

    /* The sum is worked out right inside printf; no extra variable needed.
       With 3 5: A + B = 8, %lld is replaced by 8, \n ends the line. */
    printf("%lld\n", A + B);
    return 0;   /* 0 = the program finished normally */
}
