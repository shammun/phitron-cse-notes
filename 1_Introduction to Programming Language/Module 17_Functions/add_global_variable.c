/* This program demonstrates the usage of global variables in C
 * Global variables are declared outside any function and can be accessed by all functions
 * Here we declare two global variables 'a' and 'b' that will be used for addition
 */
#include <stdio.h>

// Declaring global variables that can be accessed by both add() and main() functions
int a, b;

/* Function: add()
 * Purpose: Adds two global variables a and b
 * Parameters: None (uses global variables)
 * Returns: Sum of a and b
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
    printf("After calling the function\n");
    printf("Sum is %d\n", add());  // First function call, will add 10 + 20

    // Second set of values for global variables
    a = 30;    // Modifying global variable 'a' with new value
    b = 40;    // Modifying global variable 'b' with new value
    printf("After calling the function\n");
    printf("Sum is %d\n", add());  // Second function call, will add 30 + 40

    return 0;  // Program completed successfully
}