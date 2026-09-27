/* Re-typed practice copy of unit_matrix.c (the question is at the top of
 * that file), with one change: no flag. The moment a wrong cell is found,
 * the program prints NO and ends with return 0, which leaves both loops at
 * once. Only a matrix that survives every check reaches the YES at the end.
 * (A unit matrix has 1 on the main diagonal and 0 everywhere else.) */

#include <stdio.h> // standard input/output library: scanf and printf

int main(){ // program execution starts here
    int N; // the matrix is N x N
    scanf("%d", &N); // &N = address where scanf stores N

    int values[N][N]; // the matrix (size from input: C99 variable length array)

    for(int i=0; i<N; i++){ // i = row
        for(int j=0; j<N; j++){ // j = column
            scanf("%d", &values[i][j]);
        }
    }

    for(int i=0; i<N; i++){ // visit every row ...
        for(int j=0; j<N; j++){ // ... and every column
            if(i == j){ // row number equals column number: a main-diagonal cell
                /* On the main diagonal the cell must be 1. */
                if(values[i][j] !=1){
                    printf("NO");
                    return 0; // returning from main ends the whole program right here
                }
            } else{
                /* Off the diagonal the cell must be 0. */
                if(values[i][j] != 0){
                    printf("NO");
                    return 0; // stop at the first wrong cell
                }
            }
        }
    }

    printf("YES"); // reached only if no cell was wrong

    return 0; // program ended successfully

}
