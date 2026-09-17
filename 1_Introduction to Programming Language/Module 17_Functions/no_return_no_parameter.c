/*
This program demonstrates functions that:
1. Don't return any value (void return type)
2. Don't take any parameters (empty parameter list)

Such functions are useful when:
- We want to perform some tasks without needing to return data
- We want to handle input/output within the function itself
*/

#include <stdio.h>

/* 
Function: add()
- Return type: void (doesn't return any value)
- Parameters: none 
- Purpose: Takes two numbers from user, adds them and prints the sum
- Note: Uses scanf() to get input inside function rather than through parameters
*/
void add(){
    int a,b;  // Variables to store the two numbers
    printf("Enter two numbers: ");  // Prompt user for input
    scanf("%d %d", &a, &b);        // Read two integers from user
    printf("Function called\n");    // Confirmation message
    int sum = a + b;               // Calculate sum
    printf("Sum: %d\n", sum);      // Display result
}

/*
Function: greetings()
- Return type: void (doesn't return any value)
- Parameters: none
- Purpose: Simply prints a greeting message
- Note: Demonstrates simplest form of function with no input/output
*/
void greetings(){
    printf("Hello\n");
}

/*
Function: main()
- Return type: int (returns 0 for successful execution)
- Purpose: Entry point of program
- Demonstrates calling functions that:
  1. Just print something (greetings)
  2. Handle their own input/output (add)
*/
int main(){
    greetings();  // Call function that just prints
    add();        // Call function that handles input/output
    return 0;     // Return 0 to indicate successful execution
}