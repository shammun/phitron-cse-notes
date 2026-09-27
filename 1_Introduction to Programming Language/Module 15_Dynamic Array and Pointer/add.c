/*

Given two numbers X and Y, Print their summation.

Note: Solve this problem using function.

Input
Only one line contains two numbers X and Y (0 ≤ X, Y ≤ 105).

Output
Print the summation value.

Example
InputCopy
5 2
OutputCopy
7

*/

/* Note on the statement: "105" is 10^5 (the exponent lost its formatting when
   it was copied). The task says "using function", but this solution does the
   addition directly in main; the version with a separate function comes with
   the functions module (Module 17). */

#include <stdio.h> // standard input/output library: scanf and printf

int main(){ // program execution starts here
    /* Read the two numbers. & hands scanf the address of each variable -
       the same & that the pointer lessons are built on. */
    int x,y; // the two numbers
    scanf("%d %d", &x, &y); // %d = read an int; &x, &y = where to store them

    /* The sum is computed right inside printf. The values are small
       (at most 10^5 each), so an int holds the result easily. */
    printf("%d", x+y); // e.g. 5 2 -> 7
    return 0; // program ended successfully
}
