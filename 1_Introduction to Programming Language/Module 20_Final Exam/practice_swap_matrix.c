#include <stdio.h> // standard input/output library: scanf and printf

/* Re-typed practice copy of swap_matrix.c: swap the first and last columns,
   then swap the first and last rows, then print the matrix.
   Example:
     1 2 3 4        2 5 4 6
     5 6 7 8   ->   8 6 7 5
     6 5 4 2        4 2 3 1 */

/* swap(a, b): exchanges the two ints that a and b point to.
   Pointers are needed so that the changes reach the matrix cells in main. */
void swap(int *a, int *b){
    int temp = *a; // keep the first value
    *a = *b; // first cell gets the second value
    *b = temp; // second cell gets the old first value
}

int main(){ // program execution starts here
    int N, M; // N rows, M columns
    scanf("%d %d", &N, &M); // & gives scanf the addresses of N and M

    int matrix[N][M]; // size from input (C99 variable length array)

    for(int i=0; i<N; i++){ // read row i ...
        for(int j=0; j<M; j++){ // ... column by column
            scanf("%d", &matrix[i][j]);
        }
    }

    for(int i=0; i<N; i++){ // step 1: in every row, swap the first and last column
        swap(&matrix[i][0], &matrix[i][M-1]); // &matrix[i][0] = address of that cell
    }

    for(int j=0; j<M; j++){ // step 2: in every column, swap the first and last row
        swap(&matrix[0][j], &matrix[N-1][j]);
    }

    for(int i=0; i<N; i++){ // print the result, one row per line
        for(int j=0; j<M; j++){
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }

    return 0; // program ended successfully
}
