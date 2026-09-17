/*
This program demonstrates pointer-based swapping of values between functions.
Key concepts illustrated:
1. Pointers: Allow functions to modify original variables
2. Memory addresses: Shows how pointers enable access to main's variables
3. Dereferencing: How to access and modify values through pointers
*/

#include <stdio.h>

/*
Function: swap()
Parameters:
- x: Pointer to first integer
- y: Pointer to second integer
Purpose: Swaps values that x and y point to

How it works:
1. Takes addresses of variables as parameters (not copies of values)
2. Uses pointer dereferencing (*) to access/modify original values
3. Successfully swaps because it modifies memory locations directly
*/
void swap(int *x, int *y){
    // Print to show we're inside swap function
    printf("Inside swap function\n");
    
    // Print addresses to demonstrate pointer behavior:
    // &x, &y print addresses of pointer variables themselves
    // x, y would print addresses they point to (main's variables)
    // *x, *y would print values they point to (main's values)
    printf("Inside swap function: %p %p\n", &x, &y);
    
    // Perform swap using pointer dereferencing:
    // *x means "value at address x points to"
    // *y means "value at address y points to"
    int temp = *x;    // Save value pointed to by x
    *x = *y;          // Put y's value where x points
    *y = temp;        // Put saved value where y points
}

/*
Function: main()
Purpose: Demonstrates successful swapping using pointers
Shows how:
1. Addresses can be passed to functions using &
2. Pointers allow functions to modify original variables
3. Changes in swap() affect main's variables directly
*/
int main(){
    // Declare and initialize variables to be swapped
    int a = 10, b = 20;
    
    // Print to show we're in main function
    printf("Inside main function\n");
    
    // Print addresses of original variables
    // These addresses will be passed to swap function
    printf("Inside main function: %p %p\n", &a, &b);
    
    // Call swap with addresses of a and b
    // &a creates pointer to a's memory location
    // &b creates pointer to b's memory location
    swap(&a, &b);
    
    // Values are now swapped because swap() modified original memory locations
    printf("a = %d, b = %d\n", a, b);
    return 0;
}