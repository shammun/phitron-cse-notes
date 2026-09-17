#include <stdio.h>

int main(){
    /* Declare variable n to store the dimension of square matrix
     * A scalar matrix must be a square matrix (same number of rows and columns)
     */
    int n;
    
    /* Read the dimension from user input using scanf
     * %d format specifier is used for reading integer value
     * &n gives the address where the input value will be stored
     */
    scanf("%d", &n);

    /* Declare a 2D array m of size nxn to store the matrix elements
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

    /* Store the first diagonal element (m[0][0]) as reference
     * In a scalar matrix, all diagonal elements must be equal
     * Initialize flag as 1 (assuming matrix is scalar until proven otherwise)
     */
    int element = m[0][0];
    int flag = 1;

    /* Check if matrix is scalar using nested loops
     * A scalar matrix has two properties:
     * 1. All diagonal elements (i==j) must be equal
     * 2. All non-diagonal elements (i!=j) must be zero
     */
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(i == j){
                /* Check diagonal elements
                 * If any diagonal element doesn't match the first element,
                 * matrix is not scalar - set flag to 0 and break
                 */
                if(m[i][j] != element){
                    flag = 0;
                    break;
                }
            } else{
                /* Check non-diagonal elements
                 * If any non-diagonal element is not zero,
                 * matrix is not scalar - set flag to 0 and break
                 */
                if(m[i][j] != 0){
                    flag = 0;
                    break;
                }
            }
        }
    }

    /* Print result based on flag value
     * If flag is still 1, matrix satisfies scalar matrix properties
     * If flag is 0, matrix failed one of the scalar matrix tests
     */
    if(flag == 1){
        printf("Scaler");
    } else {
        printf("Not Scaler");
    }

    return 0;
}