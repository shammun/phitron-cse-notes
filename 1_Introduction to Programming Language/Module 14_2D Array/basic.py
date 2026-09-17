#include <stdio.h>

/* This is a C program that demonstrates the use of 2D arrays and memory addressing */

int main() {
    /* Declaring and initializing a 2D array of size 3x5
     * - First dimension (3) represents rows
     * - Second dimension (5) represents columns
     * The array is initialized with values in a structured format:
     * Row 1: 1,2,3,4,5
     * Row 2: 6,7,8,9,10 
     * Row 3: 11,12,14,14,15
     */
    int arr[3][5] = {
        {1, 2, 3, 4, 5},    /* Row 0 values */
        {6, 7, 8, 9, 10},   /* Row 1 values */
        {11, 12, 14, 14, 15} /* Row 2 values */
    };

    /* Using nested loops to iterate through the 2D array
     * - Outer loop (i) iterates through rows (0 to 2)
     * - Inner loop (j) iterates through columns (0 to 4)
     */
    for(int i=0; i < 3; i++){
        for(int j=0; j<5; j++){
            /* For each element, we print:
             * i = current row index
             * j = current column index
             * &arr[i][j] = memory address of current element
             * arr[i][j] = value stored at current element
             * The %p formatter is used for printing memory addresses
             * The %d formatter is used for printing integer values
             */
            printf("%i = %d, j = %d, address = %p, value = %d || ", i, j, &arr[i][j], arr[i][j]);
        }
        /* Print newline after each row for better formatting */
        printf("\n");
    }
}