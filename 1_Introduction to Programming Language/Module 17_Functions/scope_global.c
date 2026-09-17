/*
This program demonstrates the use of global variables to swap values.
Key concepts illustrated:
1. Global variables: Accessible throughout the program
2. Memory addresses: Shows how global variables maintain same address
3. Successful swapping: Unlike local variables, changes affect the same memory
*/

#include <stdio.h>

// Declare global variables a and b
// Global variables:
// - Are declared outside all functions
// - Can be accessed by any function in the program
// - Have program lifetime (exist for entire program execution)
// - Have file scope (accessible throughout this file)
int a, b;

/*
Function: swap()
- Purpose: Swaps values of global variables a and b
- No parameters needed since it uses global variables
- Changes made here affect the actual variables (not copies)
- Uses standard swap algorithm with temporary variable
*/
void swap(){
    // Print to show we're inside swap function
    printf("Inside swap function\n");
    
    // Print addresses to prove these are the SAME variables as main's
    // Unlike local variables, these addresses will match main's addresses
    printf("Inside swap function: %p %p\n", &a, &b);
    
    // Perform swap using temporary variable
    // Since these are global variables, changes here affect the actual values
    int temp = a;  // Store a's value temporarily
    a = b;         // Copy b's value to a
    b = temp;      // Copy original a's value (from temp) to b
}

/*
int a, b;
// Declaring a and b as global variables here will not work.
// Because they are called in the swap function, and so needs to be declared 
// before the swap function is called.
*/

/*
Function: main()
- Purpose: Demonstrates how global variables enable successful swapping
- Shows that:
  1. Addresses are same in both functions (shared variables)
  2. Changes in swap() function affect the actual values
  3. Global variables allow cross-function modifications
*/
int main(){
    // Print to show we're in main function
    printf("Inside main function\n");
    
    // Print addresses to compare with swap function's addresses
    // These will match swap function's addresses (same variables)
    printf("Inside main function: %p %p\n", &a, &b);
    
    // Show values before swap
    // Note: Global variables are automatically initialized to 0
    printf("Before calling swap function: a = %d, b = %d\n", a, b);
    
    // Call swap - this will actually work because it modifies global variables
    swap(a, b);
    
    // Values will be swapped because swap() modified the actual global variables
    printf("After calling swap function: a = %d, b = %d\n", a, b);
    return 0;
}