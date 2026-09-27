/*
Given two numbers X and Y, Print their summation.

Note: Solve this problem using function.

Input
Only one line contains two numbers X and Y (0 <= X, Y <= 10^5).

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

Reading the first line of a function:  int sum(int x, int y)
    int        - the type of value the function gives back (a whole number)
    sum        - the function's name
    (int x, int y) - its inputs. When main calls sum(5, 2), x becomes a COPY
                 of 5 and y a copy of 2 inside this function.
The function is written above main, so the compiler already knows it by the
time main calls it.
*/
int sum(int x, int y){
    // Simply return the addition of x and y
    // (return sends the value back to the line that called sum)
    return x + y;
}   // end of sum

/*
Function name: main
Parameters: None
Return value: 0 on successful execution
Purpose: This is the entry point of the program that:
    1. Takes two numbers as input from user
    2. Calls sum function to calculate their sum
    3. Prints the result
Every C program starts running at main.
*/
int main(){
    // Declare two integer variables to store input numbers
    int x, y;
    
    // Prompt user to enter two numbers
    // (Fine for a human; but an online judge compares ALL output, so this
    // extra text would make the answer "wrong" there - remove it to submit.)
    printf("Enter two numbers: ");
    
    // Read two integers from user using scanf
    // %d is format specifier for integer
    // &x and &y are addresses where the numbers will be stored
    scanf("%d %d", &x, &y);

    // Call sum function with x and y, store result in 'result' variable
    // e.g. input 5 2: sum(5, 2) returns 7, so result = 7.
    int result = sum(x, y);
    
    // Print the result followed by newline
    // %d will be replaced by value of result
    printf("%d\n", result);

    // Return 0 to indicate successful program execution
    return 0;
}