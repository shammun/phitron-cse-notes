#include <stdio.h>

int main(){
    // Declare an integer variable 'a' and initialize it with value 5
    int a = 5;

    // Declare a pointer 'x' that stores the address of 'a'
    // x is a single pointer (one level of indirection)
    int *x = &a;

    // Declare a pointer 'y' that stores the address of pointer 'x'
    // y is a pointer to pointer (two levels of indirection)
    // This creates a chain: y -> x -> a
    int **y = &x;

    // Using %p format specifier to print addresses (in hexadecimal)
    // y contains address of x, so y and &x print the same address
    printf("Value of y and address of x: %p and %p\n", y, &x);
    // Value of y and address of x: 0x7fffaa2cb8f8 and 0x7fffaa2cb8f8

    // *y dereferences y once to get value stored in x (which is address of a)
    // &a gives the address of a directly
    // So *y and &a print the same address
    printf("Value of *y and address of a are the same: %p and %p\n", *y, &a);
    // Value of *y and address of a are the same: 0x7ffe5995a7c4 and 0x7ffe5995a7c4

    // Using %d format specifier because we're printing integer values now
    // **y dereferences y twice: first * gets to x, second * gets to value of a
    // So **y and a print the same integer value
    printf("Value of **y and the value of a are the same: %d and %d\n", **y, a);
    // Value of **y and the value of a are the same: 5 and 5

    // **y dereferences y twice to get to value of a
    // *x dereferences x once to get to value of a
    // Both print the same integer value
    printf("Value of **y and *x are the same: %d and %d\n", **y, *x);
    // Value of **y and *x are the same: 5 and 5
    
    return 0;
}