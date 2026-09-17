/*
 * This program demonstrates two different ways of passing parameters to functions:
 * 1. Call by Value: A copy of the value is passed to the function
 * 2. Call by Reference: The memory address (reference) of the variable is passed
 */

#include <stdio.h>

/* Function that takes two parameters:
 * x: Called by value - receives a copy of the original value
 * y: Called by reference - receives the memory address of the original variable
 */
void fun(int x, int *y){
    /* When we modify 'x', we're only changing the local copy.
     * The original variable 'a' in main() remains unchanged */
    x *= 10;  // Same as: x = x * 10
    
    /* When we modify '*y', we're changing the value at the memory address
     * that y points to. This affects the original variable 'b' in main() */
    *y *= 10; // Same as: *y = *y * 10
    
    /* Prints: x = 100, *y = 200
     * Shows the local values inside the function */
    printf("Inside function: x = %d, *y = %d\n", x, *y);
}

int main(){
    /* Initialize two variables:
     * a will be passed by value
     * b will be passed by reference */
    int a = 10, b = 20;
    
    /* Function call:
     * a is passed by value - only its value (10) is sent
     * &b passes the memory address of b - allows function to modify original b */
    fun(a, &b);
    
    /* Prints: a = 10, b = 200
     * a remains unchanged because it was passed by value
     * b is modified because it was passed by reference */
    printf("After function call: a = %d, b = %d\n", a, b);
    return 0;
}