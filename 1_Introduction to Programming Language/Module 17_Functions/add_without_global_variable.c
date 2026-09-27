/*
This program demonstrates a function that:
1. Takes input from user inside the function
2. Returns a value (unlike void functions)
3. Can be called multiple times to get different results

Key differences from previous examples:
- Returns sum instead of printing it (more flexible)
- Can store result in variables for later use
- Shows function reusability with multiple calls

Example run (input "2 3" and then "10 20"):
  Before calling function sum()
  function called
  After calling function sum()
  Result: 5
  function called
  After calling function sum()
  Result: 30
(The messages say "sum()", but the function is actually named add().)
*/

#include <stdio.h> // standard input/output library: scanf and printf

/*
Function: add()
- Return type: int (returns the calculated sum)
- Parameters: none (gets input inside function)
- Purpose: Gets two numbers from user and returns their sum
- Flow:
  1. Declares variables to store input
  2. Gets two numbers from user using scanf
  3. Prints confirmation message
  4. Calculates and returns sum
- a and b here are LOCAL variables: they exist only while add() runs and
  are created fresh on every call.
*/
int add(){
    int a, b;                      // Variables for storing user input
    scanf("%d %d", &a, &b);        // Get two numbers from user (& = address, so scanf can fill them)
    printf("function called\n");    // Confirmation of function execution
    int sum = a + b;               // Calculate sum
    return sum;                    // Return result to caller (the call add() is replaced by this value)
}

/*
Function: main()
- Return type: int (returns 0 for successful execution)
- Purpose: Demonstrates:
  1. How to call a function that returns value
  2. How to store and use returned value
  3. How same function can be called multiple times
- Flow:
  1. Prints message before function call
  2. Calls add() and stores result
  3. Prints message after function call
  4. Shows result
  5. Repeats process to demonstrate reusability
*/
int main(){
    printf("Before calling function sum()\n");
    int result = add();            // First call to add(), storing result
    printf("After calling function sum()\n");
    printf("Result: %d\n", result); // print the stored sum

    int result2 = add();           // Second call to add(), storing in different variable
    printf("After calling function sum()\n");
    printf("Result: %d\n", result2);

    return 0; // program ended successfully
}
