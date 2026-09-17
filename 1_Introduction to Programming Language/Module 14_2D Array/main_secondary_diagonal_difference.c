#include <stdio.h>  /* For input/output functions like scanf, printf */
#include <math.h>   /* For mathematical functions */
#include <stdlib.h> /* For abs() function to get absolute value */

int main(){
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
     */
    int main_diagonal = 0, sec_diagonal = 0;

    /* Calculate sums of both diagonals using nested loops
     * Main diagonal: elements where row index equals column index (i==j)
     * Secondary diagonal: elements where row index + column index = n-1 (i+j==n-1)
     */
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            /* Add element to main diagonal sum if it's on main diagonal */
            if(i == j){
                main_diagonal += m[i][j];
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
     */
    int diff = abs(main_diagonal - sec_diagonal);
    printf("%d", diff);

    return 0;
}