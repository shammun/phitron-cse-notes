#include <stdio.h>

/* This is a C program that demonstrates the use of 2D arrays and memory addressing.
 *
 * Note on the name: this file used to be saved as basic.py by mistake. It was
 * always C code - Python could never run it - so it is basic.c now.
 */

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
        {11, 12, 14, 14, 15} /* Row 2 values - the third one is a typo for 13, left as it is */
    };

    /* Using nested loops to iterate through the 2D array
     * - Outer loop (i) iterates through rows (0 to 2)
     * - Inner loop (j) iterates through columns (0 to 4)
     */
    for(int i=0; i < 3; i++){
        for(int j=0; j<5; j++){
            /* For each element, the plan is to print:
             * i = current row index
             * j = current column index
             * &arr[i][j] = memory address of current element
             * arr[i][j] = value stored at current element
             * The %p formatter is for printing memory addresses
             * The %d formatter is for printing integer values
             */
            /* Careful - this line has a bug, and the output below shows it.
             * The format string holds FIVE placeholders: %i, %d, %d, %p, %d.
             * Only FOUR values are passed: i, j, &arr[i][j], arr[i][j].
             * The intention was `"i = %d, ..."` - a plain letter i as a label -
             * but it was typed as `%i`, which is another way of writing %d, so
             * it eats the first value and everything after it shifts one place:
             *   %i  gets i               -> right, but it is standing where the
             *                               label "i" was meant to be
             *   %d  after "= " gets j    -> so "0 = 0" is really i = 0, j = 0
             *   %d  after "j = " gets the address, printed as a plain number
             *   %p  after "address = " gets the value, printed as an address
             *   %d  after "value = " gets nothing at all -> whatever happens to
             *                               be left in memory, which is why the
             *                               value column is the same 16 every time
             * Passing fewer values than the format asks for is undefined
             * behaviour: the program still compiles and runs, and nothing warns
             * you unless you compile with -Wall.
             * To fix it, write `"i = %d, j = %d, address = %p, value = %d || "`
             * and pass `i, j, (void*)&arr[i][j], arr[i][j]`.
             * Reading the numbers under "j =" is still worth it: they are the
             * real addresses, and they go up by 4 (one int) every cell, straight
             * across the end of each row. That is the point of the program.
             */
            printf("%i = %d, j = %d, address = %p, value = %d || ", i, j, &arr[i][j], arr[i][j]);
        }
        /* Print newline after each row for better formatting */
        printf("\n");
    }
}