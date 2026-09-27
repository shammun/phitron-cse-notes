/* Self-practice: a pointer to a pointer.
 *
 * basic.c printed the address of each matrix cell with & and %p. This file
 * takes the next step (the topic of Module 15, pointers_of_pointer.c): an
 * address can itself be stored in a variable, and the address of THAT
 * variable can be stored again.
 *
 *     a  holds 5
 *     x  holds the address of a      (int *  : "pointer to int")
 *     y  holds the address of x      (int ** : "pointer to pointer to int")
 *
 * Each * in front of a name follows one arrow: *y goes from y to x, and
 * **y goes on from x to a.
 */

#include <stdio.h>

int main(){
    int a = 5;

    /* x points at a. */
    int *x = &a;

    /* y points at x. The type needs two stars because x is itself a pointer. */
    int **y = &x;

    // Here value of y is the address of x.
    printf("Value of y and address of x: %p and %p\n", y, &x);

    // Here value of *y is the address of a or the value of x. 
    printf("Value of *y and address of a or x are the same: %p %p\n", *y, x);
    
    // Here value of **y is the value of a.
    printf("Value of **y and the value of a are the same: %d and %d\n", **y, a);
   
    // Here value of **y is the value of *x, which is the value of a.
    printf("Value of **y and the value of *x are the same: %d and %d\n", **y, *x);


    
    return 0;
    
}