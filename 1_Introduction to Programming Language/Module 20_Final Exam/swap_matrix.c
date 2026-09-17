/*
You will be given a 2D matrix of N * M size. The matrix will contain integer values only. You need to print the matrix after doing the following operations.

Firstly you will swap all the elements of the first column with the elements of the last column.

After that you will swap the elements of the first row with elements of the last row.

Input Format

First line will contain N and M the row and column respectively.
Then the 2D matrix will be given.
Constraints

2 <= N,M <= 100
0 <= Element <= 100
Output Format

Print the matrix after the required operations.

Sample Input 0

3 4
1 2 3 4
5 6 7 8
6 5 4 2
Sample Output 0

2 5 4 6
8 6 7 5
4 2 3 1
*/

#include <stdio.h>

// Function to swap two integers using pointers
// Parameters:
// - a: Pointer to first integer
// - b: Pointer to second integer 
// This function uses a temporary variable to exchange values
void swap(int *a, int *b){
    int temp = *a;  // Store first value in temp
    *a = *b;        // Copy second value to first location
    *b = temp;      // Copy temp (original first value) to second location
}

int main(){
    // Declare variables N and M for matrix dimensions
    // N = number of rows, M = number of columns
    int N, M;
    
    // Read matrix dimensions using scanf
    // %d format specifier is used since N and M are integers
    // & operator gets the address where the scanned value should be stored
    scanf("%d %d", &N, &M);

    // Declare 2D array of size N x M to store the matrix
    // Note: This is Variable Length Array (VLA) feature in C99
    int matrix[N][M];

    // Nested loops to read matrix elements
    // Outer loop i iterates through rows (0 to N-1)
    // Inner loop j iterates through columns (0 to M-1)
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            // Read each matrix element
            // &matrix[i][j] gives address of element at position (i,j)
            scanf("%d", &matrix[i][j]);
        }
    }

    // First operation: Swap first column (j=0) with last column (j=M-1)
    // Loop through each row i
    for(int i=0; i<N; i++){
        // matrix[i][0] is element in first column
        // matrix[i][M-1] is element in last column
        swap(&matrix[i][0], &matrix[i][M-1]);
    }

    // Second operation: Swap first row (i=0) with last row (i=N-1)
    // Loop through each column j
    for(int j=0; j<M; j++){
        // matrix[0][j] is element in first row
        // matrix[N-1][j] is element in last row
        swap(&matrix[0][j], &matrix[N-1][j]);
    }

    // Print the modified matrix
    // Nested loops similar to input, but using printf instead of scanf
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            // Print each element followed by space
            // %d format specifier for integer output
            printf("%d ", matrix[i][j]);
        }
        // Print newline after each row is complete
        printf("\n");
    }

    return 0;
}