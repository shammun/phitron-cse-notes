/* Header files (pasted in by #include before compiling):
     stdio.h  - scanf and printf (the only one this program needs)
     string.h - text functions (unused here)
     math.h   - maths functions (unused here)
     stdlib.h - general utilities (unused here) */
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

/*

Problem Statement

You've learned about variables, right? Now its time to practice them.
You need to take an integer A, a very big integer B, a floating value C and
a character D as input and output them serially.

Input Format

First line will contain A
Second line will contain B
Third line will contain C
Fourth line will contain D
Constraints

-10^9 <= A <= 10^9
-10^18 <= B <= 10^18
-10^9 <= C <= 10^9
Output Format

Output them serially and put a new line after each value. Output the floating value 2 points after decimal.
Sample Input 0

100
1234567891234567
23.5675
A
Sample Output 0

100
1234567891234567
23.57
A

*/
/* The idea: pick for each value the type whose box is big enough, and use
   the matching format specifier (%d, %lld, %lf, %c) to read and print it. */
int main() {        /* the program starts here */
    int A;          /* int: whole number up to about 2.1e9 - enough for 1e9 */
    long long B;    /* long long: whole number up to about 9.2e18 - B can be 1e18 */
    double C;       /* double: a number with a decimal part, e.g. 23.5675 */
    char D;         /* char: exactly one character, e.g. A */

    /* Each scanf waits for input; the & gives the address of the
       variable so scanf can store the value in it. */
    scanf("%d", &A); // Input the integer A
    scanf("%lld", &B); // Input the long long integer B
    scanf("%lf", &C); // Input the floating value C (%lf = double in scanf)
    scanf(" %c", &D); // Input the character D (Note: the space before %c skips the newline left behind by the previous scanf, so D gets the real letter)
    /*
    The leading space tells scanf to skip any whitespace (spaces, tabs, newlines)
    before reading the character. This is a classic C beginner trap, and it only
    affects %c, the other format specifiers (%d, %lld, %lf) automatically skip
    leading whitespace.
    Without the space, D would receive the '\n' from pressing Enter after
    23.5675, and the letter A would never be read.
    */

    printf("%d\n", A); // Output the integer A (\n = newline after it)
    printf("%lld\n", B); // Output the long long integer B
    printf("%.2lf\n", C); // Output the floating value C with 2 decimal places
    /*
    .2 means "exactly 2 digits after the decimal point", rounded:
    23.5675 -> 23.57.
    lf (Specifier): Stands for long float (used for double). In modern
    C (C99 and later), both %f and %lf behave identically inside
    printf because float arguments are automatically promoted to double,
    but %lf explicitly signals that the variable is a double.
    */

    printf("%c\n", D); // Output the character D

    return 0;   /* 0 = the program finished normally */
}