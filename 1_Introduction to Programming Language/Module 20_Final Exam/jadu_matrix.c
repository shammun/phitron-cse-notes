/*
Problem Statement

You will be given a matrix of size N * M. You need to tell if it is Jadu Matrix or not.

Note: A Jadu Matrix is a square matrix, where the values of primary diagonal and secondary diagonal are 1. Rest of the cell will contain only 0.

Input Format

First line will contain N, the row and M, the column of the matrix.
Then the N * M sized matrix will be given.
Constraints

1 <= N, M <= 100
0 <= Values <= 100
Output Format

Ouput "YES" if the matrix is Jadu Matrix, otherwise output "NO" without the quotation marks.
Sample Input 0

5 5
1 0 0 0 1
0 1 0 1 0
0 0 1 0 0
0 1 0 1 0
1 0 0 0 1
Sample Output 0

YES
Sample Input 1

5 5
1 0 0 0 1
0 1 0 1 0
0 0 0 0 0
0 1 0 1 0
1 0 0 0 1
Sample Output 1

NO
Sample Input 2

5 5
1 0 0 0 1
0 1 0 1 0
0 0 1 0 1
0 1 0 1 0
1 0 0 0 1
Sample Output 2

NO
Sample Input 3

5 5
2 0 0 0 1
0 1 0 1 0
0 0 1 0 0
0 1 0 1 0
1 0 0 0 1
Sample Output 3

NO
Sample Input 4

6 6
1 0 0 0 0 1 
0 1 0 0 1 0 
0 0 1 1 0 0 
0 0 1 1 0 0 
0 1 0 0 1 0 
1 0 0 0 0 1 
Sample Output 4

YES
*/

#include <stdio.h>

/*
 * This function checks if a given matrix is a "Jadu Matrix"
 * A Jadu Matrix must satisfy these conditions:
 * 1. Must be a square matrix (N x N)
 * 2. Primary diagonal (top-left to bottom-right) must contain only 1's
 * 3. Secondary diagonal (top-right to bottom-left) must contain only 1's
 * 4. All other positions must contain 0's
 *
 * Parameters:
 *   matrix: 2D array containing the input matrix
 *   N: Number of rows
 *   M: Number of columns
 * Returns:
 *   1 if matrix is a Jadu Matrix, 0 otherwise
 */
int jaduMatrix(int matrix[105][105], int N, int M) {
    // First check: Matrix must be square (N x N)
    if(N != M) {
        return 0;  // Not square, so return false
    }

    // Iterate through each element of the matrix
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            // Check elements on primary diagonal (i == j) 
            // and secondary diagonal (i + j == N - 1)
            // For example: In a 3x3 matrix
            // Primary diagonal: (0,0), (1,1), (2,2)
            // Secondary diagonal: (0,2), (1,1), (2,0)
            if((i == j || i + j == N - 1) && matrix[i][j] != 1) {
                return 0;  // Diagonal element not 1, invalid Jadu Matrix
            }
            
            // Check non-diagonal elements
            // If position is not on either diagonal (primary or secondary)
            // then it must contain 0
            if(i != j && i + j != N - 1 && matrix[i][j] != 0) {
                return 0;  // Non-diagonal element not 0, invalid Jadu Matrix
            }
        }
    }
    
    // If we reach here, all conditions are satisfied
    return 1;  // Valid Jadu Matrix
}

int main() {
    // Declare variables for matrix dimensions
    int N, M;  // N = rows, M = columns
    // Declare matrix with max size 105x105
    int matrix[105][105];

    // Read matrix dimensions from input
    scanf("%d %d", &N, &M);

    // Read matrix elements row by row
    // Outer loop for rows (i)
    for(int i = 0; i < N; i++) {
        // Inner loop for columns (j)
        for(int j = 0; j < M; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    // Check if matrix is a Jadu Matrix and print result
    if(jaduMatrix(matrix, N, M)) {
        printf("YES\n");  // Valid Jadu Matrix
    } else {
        printf("NO\n");   // Not a valid Jadu Matrix
    }

    return 0;
}