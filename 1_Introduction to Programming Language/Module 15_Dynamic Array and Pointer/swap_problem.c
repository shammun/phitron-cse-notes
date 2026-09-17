/*
Given two numbers X and Y. Print X and Y after swapping them.

Note: Solve this problem using function.

Input
Only one line contains two numbers X and Y (0 ≤ X, Y ≤ 105).

Output
Print X and Y separated by a space after swapping.

Example
InputCopy
5 2
OutputCopy
2 5
*/

#include <stdio.h>
int main(){
    int a, b;
    scanf("%d %d", &a, &b);
    int *x = &a, *y = &b;
    int temp = *x;
    *x = *y;
    *y = temp;
    printf("%d %d", a, b);
    return 0;
}