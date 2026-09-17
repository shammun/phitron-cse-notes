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
int main() {
    int A;
    long long B;
    double C;
    char D;

    scanf("%d", &A); // Input the integer A
    scanf("%lld", &B); // Input the long long integer B
    scanf("%lf", &C); // Input the floating value C
    scanf(" %c", &D); // Input the character D (Note: This will read the newline character left by previous scanf, so we need to consume it first)
    /*
    The leading space tells scanf to skip any whitespace (spaces, tabs, newlines) 
    before reading the character. This is a classic C beginner trap, and it only 
    affects %c, the other format specifiers (%d, %lld, %lf) automatically skip 
    leading whitespace.
    */

    printf("%d\n", A); // Output the integer A
    printf("%lld\n", B); // Output the long long integer B
    printf("%.2lf\n", C); // Output the floating value C with 2 decimal places
    /*
    lf (Specifier): Stands for long float (used for double). In modern 
    C (C99 and later), both %f and %lf behave identically inside 
    printf because float arguments are automatically promoted to double, 
    but %lf explicitly signals that the variable is a double.
    */
    
    printf("%c\n", D); // Output the character D

    return 0;
}