#include <stdio.h>  /* For input/output functions like scanf, printf */
#include <math.h>   /* For mathematical functions (not actually used below; abs comes from stdlib.h) */
#include <stdlib.h> /* For abs() function to get absolute value */

/* Task: in an n x n matrix, add up the main diagonal (top-left to bottom-right)
 * and the secondary diagonal (top-right to bottom-left), then print the
 * absolute difference of the two sums.
 * Example (n = 3):
 *     1 2 3
 *     4 5 6
 *     9 8 9
 * main = 1 + 5 + 9 = 15, secondary = 3 + 5 + 9 = 17, |15 - 17| = 2.
 */

int main(){ // program execution starts here
    /* Declare variable n to store the dimension of square matrix
     * The matrix will have n rows and n columns
     */
    int n;
    /* Read matrix dimension from user using scanf
     * %d format specifier is used for reading integer value
     * &n gives the address where the input value will be stored
     */
    scanf("%d", &n);

    /* Declare a 2D array m of size nxn to store matrix elements
     * This creates a square matrix with n rows and n columns
     * Array indices will go from 0 to n-1 for both rows and columns
     * (the size is read at run time, so this is a C99 variable length array)
     */
    int m[n][n];

    /* Read matrix elements using nested loops
     * Outer loop (i) iterates through rows (0 to n-1)
     * Inner loop (j) iterates through columns (0 to n-1)
     * scanf("%d", &m[i][j]) reads each element into matrix position [i][j]
     */
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            scanf("%d", &m[i][j]);
        }
    }

    /* Initialize variables to store sum of diagonals
     * main_diagonal: stores sum of elements where row index equals column index (i==j)
     * sec_diagonal: stores sum of elements where row + column = n-1 (i+j==n-1)
     * (for n = 3 the secondary cells are [0][2], [1][1], [2][0]: each pair adds to 2)
     */
    int main_diagonal = 0, sec_diagonal = 0;

    /* Calculate sums of both diagonals using nested loops
     * Main diagonal: elements where row index equals column index (i==j)
     * Secondary diagonal: elements where row index + column index = n-1 (i+j==n-1)
     * The two ifs are separate (not else-if) on purpose: when n is odd the
     * centre cell is on BOTH diagonals and must be added to both sums.
     */
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            /* Add element to main diagonal sum if it's on main diagonal */
            if(i == j){
                main_diagonal += m[i][j]; // "+=" means main_diagonal = main_diagonal + m[i][j]
            }
            /* Add element to secondary diagonal sum if it's on secondary diagonal */
            if(i+j == n-1){
                sec_diagonal += m[i][j];
            }
        }
    }

    /* Calculate absolute difference between diagonal sums
     * abs() function from stdlib.h is used to get positive difference
     * printf with %d format specifier prints the integer result
     * (abs(-2) is 2, abs(2) is 2: the order of subtraction no longer matters)
     */
    int diff = abs(main_diagonal - sec_diagonal);
    printf("%d", diff);

    return 0; // program ended successfully
}
