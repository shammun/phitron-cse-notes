/* This program demonstrates the usage of global variables in C
 * Global variables are declared outside any function and can be accessed by all functions
 * Here we declare two global variables 'a' and 'b' that will be used for addition
 *
 * Output:
 *   Before calling the function
 *   After calling the function
 *   Function called
 *   Sum is 30
 *   After calling the function
 *   Function called
 *   Sum is 70
 * Note the order: "After calling the function" is printed BEFORE add() runs,
 * because add() is only called inside the printf on the line after it.
 * printf must call add() first to get the number to print, so "Function called"
 * appears just before "Sum is ...".
 */
#include <stdio.h> // standard input/output library: printf

// Declaring global variables that can be accessed by both add() and main() functions
// (they live for the whole program and, being global, start at 0)
int a, b;

/* Function: add()
 * Purpose: Adds two global variables a and b
 * Parameters: None (uses global variables)
 * Returns: Sum of a and b
 * "int" before the name is the return type: the function hands back an int.
 */
int add(){
    printf("Function called\n");    // Prints when function is called
    int sum = a + b;               // Uses global variables for calculation
    return sum;                    // Returns the calculated sum
}

/* Function: main()
 * Purpose: Entry point of program, demonstrates how global variables
 *         can be modified and used across function calls
 */
int main(){
    // First printf to show program flow
    printf("Before calling the function\n");

    // First set of values for global variables
    a = 10;    // Assigning first value to global variable 'a'
    b = 20;    // Assigning first value to global variable 'b'
    printf("After calling the function\n"); // printed before add() actually runs (see the note at the top)
    printf("Sum is %d\n", add());  // First function call, will add 10 + 20; the returned 30 fills %d

    // Second set of values for global variables
    a = 30;    // Modifying global variable 'a' with new value
    b = 40;    // Modifying global variable 'b' with new value
    printf("After calling the function\n"); // again printed before the call below
    printf("Sum is %d\n", add());  // Second function call, will add 30 + 40; add() sees the new values because a and b are shared

    return 0;  // Program completed successfully
}
