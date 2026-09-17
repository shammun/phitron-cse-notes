/*
Given two numbers X and Y, Print their summation.

Note: Solve this problem using function.

Input
Only one line contains two numbers X and Y (0 ≤ X, Y ≤ 105).

Output
Print the summation value.

Example
InputCopy
5 2
OutputCopy
7
*/

// Include the standard input/output library to use printf and scanf functions
#include <stdio.h>

/* 
Function name: sum
Parameters: 
    - x: First integer number
    - y: Second integer number
Return value: Sum of x and y
Purpose: This function takes two integer parameters and returns their sum
*/
int sum(int x, int y){
    // Simply return the addition of x and y
    return x + y;
}

/*
Function name: main
Parameters: None
Return value: 0 on successful execution
Purpose: This is the entry point of the program that:
    1. Takes two numbers as input from user
    2. Calls sum function to calculate their sum
    3. Prints the result
*/
int main(){
    // Declare two integer variables to store input numbers
    int x, y;
    
    // Prompt user to enter two numbers
    printf("Enter two numbers: ");
    
    // Read two integers from user using scanf
    // %d is format specifier for integer
    // &x and &y are addresses where the numbers will be stored
    scanf("%d %d", &x, &y);

    // Call sum function with x and y, store result in 'result' variable
    int result = sum(x, y);
    
    // Print the result followed by newline
    // %d will be replaced by value of result
    printf("%d\n", result);

    // Return 0 to indicate successful program execution
    return 0;
}