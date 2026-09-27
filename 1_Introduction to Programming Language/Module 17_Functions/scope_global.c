/*
This program demonstrates the use of global variables to swap values.
Key concepts illustrated:
1. Global variables: Accessible throughout the program
2. Memory addresses: Shows how global variables maintain same address
3. Successful swapping: Unlike local variables, changes affect the same memory

Output of one run (the addresses change from run to run, but the two lines
of addresses always match each other):
  Inside main function
  Inside main function: 0000000000407974 0000000000407970
  Before calling swap function: a = 0, b = 0
  Inside swap function
  Inside swap function: 0000000000407974 0000000000407970
  After calling swap function: a = 0, b = 0
Because a and b are never given values, both are 0, so the swap really
happens but cannot be SEEN in the output (0 and 0 swapped is still 0 and 0).
The matching addresses are the proof here that swap() and main() use the
same two variables.
*/

#include <stdio.h> // standard input/output library: printf

// Declare global variables a and b
// Global variables:
// - Are declared outside all functions
// - Can be accessed by any function in the program
// - Have program lifetime (exist for entire program execution)
// - Have file scope (accessible throughout this file, from this line downwards)
// - Start at 0 automatically when they are not given a value
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
    // (%p prints an address in hexadecimal; &a = address of a)
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
// (More exactly: a name must be declared ABOVE the first line that uses it.
// swap() uses a and b, so they must be declared before swap() is written.)
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

    // Call swap - it works on the global variables themselves.
    // swap() was written with empty brackets "()", which in C means "no
    // parameter list given", so passing a and b here still compiles, but the
    // two values are simply ignored by swap(). swap() would do the same with swap().
    swap(a, b);

    // swap() exchanged the global variables themselves; here both are still 0
    // only because they were both 0 to begin with (see the note at the top).
    printf("After calling swap function: a = %d, b = %d\n", a, b);
    return 0; // program ended successfully
}
