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

/* Note on the statement: "105" is 10^5 (the exponent lost its formatting when
   it was copied). The task says "using function"; this version does the swap
   with pointers inside main. The same swap moved into its own function (which
   needs pointers even more) is Module 17's swap_pointer.c. */

#include <stdio.h> // standard input/output library: scanf and printf
int main(){ // program execution starts here
    int a, b; // X and Y
    scanf("%d %d", &a, &b); // & gives scanf the addresses of a and b

    /* x holds the address of a, y the address of b. From now on *x IS a and
       *y IS b: reading or writing through them touches the originals. */
    int *x = &a, *y = &b;

    /* The classic three-step swap, done through the pointers:
       keep a's value safe, copy b into a, then put the saved value into b.
       Without temp, the second line would overwrite a's value before it
       could be moved.
       Trace with 5 2: temp = 5, a = 2, b = 5. */
    int temp = *x; // temp = a
    *x = *y; // a = b
    *y = temp; // b = old a

    /* a and b themselves are printed - and they have changed, which proves
       the writes through *x and *y reached the real variables. */
    printf("%d %d", a, b);
    return 0; // program ended successfully
}
