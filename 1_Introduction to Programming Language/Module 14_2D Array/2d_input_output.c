#include <stdio.h>

/* This program demonstrates reading, modifying and printing a 2D array */
int main(){
    /* Declare variables to store dimensions of 2D array
     * n = number of rows
     * m = number of columns 
     */
    int n, m;
    
    /* Read dimensions from user input using scanf
     * %d format specifier is used for reading integers
     * &n, &m are addresses where the input values will be stored
     * Space between %d %d means we expect user to input two numbers separated by space
     */
    scanf("%d %d", &n, &m);

    /* Declare 2D array with extra buffer space
     * Size is (n+5)x(m+5) to avoid any potential buffer overflow
     * Array indices will go from 0 to n-1 for rows and 0 to m-1 for columns
     */
    int a[n+5][m+5];

    /* Read array elements using nested loops
     * Outer loop (i) iterates through rows (0 to n-1)
     * Inner loop (j) iterates through columns (0 to m-1)
     */
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            /* Read each element using scanf
             * %d format specifier for reading integer
             * &a[i][j] gives address where element will be stored
             */
            scanf("%d", &a[i][j]);
        }
    }

    /* Modify specific elements in the array
     * a[1][2] = element at row 1, column 2 (0-based indexing)
     * a[2][3] = element at row 2, column 3 
     */
    a[1][2] = 100;
    a[2][3] = 200;

    /* Print the modified array using nested loops
     * Outer loop (i) iterates through rows
     * Inner loop (j) iterates through columns
     */
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            /* Print each element using printf
             * %d format specifier for printing integer
             * Space after %d creates gap between elements
             */
            printf("%d ", a[i][j]);
        }
        /* Print newline after each row for matrix-like output */
        printf("\n");
    }
}

/*
Input:
3 4
1 2 3 4 5 6 7 8 9 10 11 12

Output:
1 2 3 4 
5 6 100 8 
9 10 11 200

Input:
3 4
1 2 3 4
5 6 7 8
9 10 11 12

Output:
1 2 3 4 
5 6 100 8 
9 10 11 200 
*/