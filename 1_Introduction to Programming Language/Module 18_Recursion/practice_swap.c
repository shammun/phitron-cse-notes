/*
Swap
time limit per test1 second
memory limit per test64 megabytes
Given two numbers X and Y. Print X and Y after swapping them.

Note: Solve this problem using function.

Input
Only one line contains two numbers X and Y (0 ≤ X, Y ≤ 105).

Output
Print X and Y separated by a space after swapping.

Example
InputCopy
5 2
OutputCopy
2 5
*/

// Include standard input/output library for printf and scanf functions
#include <stdio.h>

/*
Function name: swap
Parameters:
    - x: Pointer to first integer
    - y: Pointer to second integer
Purpose: Swaps the values of two integers using pointers
How it works:
    1. Takes pointers (memory addresses) as parameters to directly modify original values
    2. Uses a temporary variable to store one value while swapping
    3. Performs the swap through pointer dereferencing
Note: We use pointers because:
    - Functions in C pass arguments by value (make copies)
    - To modify original values, we need their memory addresses
    - Pointers allow us to access and modify values at those addresses
*/
void swap(int *x, int *y){
    // Store first number in temporary variable
    int temp = *x;  // *x means "value at address x"
    
    // Copy second number to first position
    *x = *y;        // Now first number becomes second number
    
    // Copy temporary (original first number) to second position
    *y = temp;      // Now second number becomes first number
}

/*
Function name: main
Parameters: None
Return value: 0 for successful execution
Purpose: Entry point of program that:
    1. Takes two numbers as input
    2. Calls swap function to exchange their values
    3. Prints the swapped numbers
*/
int main(){
    // Declare variables to store the two numbers
    int x, y;
    
    // Read two integers from user
    // &x and &y give the memory addresses where values should be stored
    scanf("%d %d", &x, &y);
    
    // Call swap function with addresses of x and y
    // & operator gets the memory address of a variable
    swap(&x, &y);
    
    // Print the swapped values
    // After swap, x contains original y and y contains original x
    printf("%d %d\n", x, y);

    // Return 0 to indicate successful execution
    return 0;
}