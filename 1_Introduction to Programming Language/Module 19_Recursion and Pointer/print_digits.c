/*
 * This program prints individual digits of numbers using recursion
 * Important concepts shown:
 * 1. Recursive function to break down number into digits
 * 2. Use of modulo (%) operator to extract last digit
 * 3. Integer division (/) to remove last digit
 * 4. Different format specifiers in scanf/printf
 *
 * Example input:
 *   2
 *   123
 *   0
 * Output:
 *   1 2 3
 *   0
 * (the numbers are assumed to be 0 or positive)
 */

#include <stdio.h> // standard input/output library: scanf and printf

/* Function that prints digits of a number recursively:
 * Parameter:
 * n: Integer number whose digits need to be printed
 *
 * Uses recursion by:
 * 1. Getting last digit using n % 10
 * 2. Removing last digit using n / 10
 * 3. Recursively calling with remaining digits
 * 4. Printing current digit after recursive call returns
 *
 * For example: printDigits(123)
 * First gets 3 (123 % 10), calls printDigits(12)
 * Then gets 2 (12 % 10), calls printDigits(1)
 * Then gets 1 (1 % 10), calls printDigits(0)
 * Base case reached, starts printing: 1 2 3
 * (the printing happens after each call returns, so the deepest call - the
 * one holding the first digit - prints first)
 */
void printDigits(int n){
    if(n == 0){
        return;  // Base case: when no digits left
    }
    int digit = n % 10;  // Get rightmost digit
    printDigits(n / 10); // Recursive call with remaining digits
    printf("%d ", digit); // Print digit with space using %d formatter
}

int main(){ // program execution starts here
    int t; // number of test cases
    /* First scanf reads number of test cases
     * %d format specifier used for reading integer input
     * &t passes address where input should be stored
     */
    scanf("%d", &t);

    /* Loop runs t times for t test cases
     * For each test case:
     * 1. Read a number using scanf with %d
     * 2. Call printDigits to print its digits
     * 3. Print newline to separate test cases
     */
    for(int i=0; i<t; i++){
        int n; // the number for this test case
        scanf("%d", &n);

        if(n == 0){ // printDigits(0) would print nothing (base case at once), so 0 is handled here
            printf("0\n");
        } else{
            printDigits(n);
            printf("\n");  // Add newline after printing all digits
        }

    }

    return 0; // program ended successfully
}
