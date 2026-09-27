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

    /* x holds the address of a, y the address of b. From now on *x IS a and
       *y IS b: reading or writing through them touches the originals. */
    int *x = &a, *y = &b;

    /* The classic three-step swap, done through the pointers:
       keep a's value safe, copy b into a, then put the saved value into b.
       Without temp, the second line would overwrite a's value before it
       could be moved. */
    int temp = *x;
    *x = *y;
    *y = temp;

    /* a and b themselves are printed - and they have changed, which proves
       the writes through *x and *y reached the real variables. */
    printf("%d %d", a, b);
    return 0;
}
