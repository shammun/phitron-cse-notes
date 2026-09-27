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

#include <stdio.h>

int main(){
    /* Read the two numbers. & hands scanf the address of each variable -
       the same & that the pointer lessons are built on. */
    int x,y;
    scanf("%d %d", &x, &y);

    /* The sum is computed right inside printf. The values are small
       (at most 10^5 each), so an int holds the result easily. */
    printf("%d", x+y);
    return 0;
}
