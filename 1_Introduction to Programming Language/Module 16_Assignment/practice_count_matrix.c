/* Re-typed practice copy of count_matrix.c (the question is at the top of
 * that file). One difference: the queries are stored from index 0 to X - 1,
 * the usual way, instead of from 1 to X.
 * Short version of the task: read an N x M matrix, then for each of X query
 * numbers print how many times it appears in the matrix. */

#include <stdio.h> // standard input/output library: scanf and printf

int main(){ // program execution starts here
    int N, M, X; // rows, columns, number of queries
    scanf("%d %d %d", &N, &M, &X); // & gives scanf each variable's address

    int Numbers[N+5][M+5]; // the matrix, with a little spare room (C99 variable length array)
    /* freq[v] = how many times v is in the matrix. = {0} starts all counts at 0. */
    int freq[100005] = {0};

    /* Read the matrix and count each value as it arrives. */
    for(int i=0; i<N; i++){ // i = row
        for(int j=0; j<M; j++){ // j = column
            scanf("%d", &Numbers[i][j]);
            freq[Numbers[i][j]]++; // one more occurrence of this value
        }
    }

    int numbers_to_check[X + 5]; // the query numbers
    for(int i=0; i<X; i++){ // read X queries into indexes 0 .. X-1
        scanf("%d", &numbers_to_check[i]);
    }

    /* Each answer is a single look-up in freq. */
    for(int i=0; i<X; i++){
        printf("%d\n", freq[numbers_to_check[i]]);
    }

    return 0; // program ended successfully
}
