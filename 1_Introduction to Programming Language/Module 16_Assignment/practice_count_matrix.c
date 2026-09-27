/* Re-typed practice copy of count_matrix.c (the question is at the top of
 * that file). One difference: the queries are stored from index 0 to X - 1,
 * the usual way, instead of from 1 to X. */

#include <stdio.h>

int main(){
    int N, M, X;
    scanf("%d %d %d", &N, &M, &X);

    int Numbers[N+5][M+5];
    /* freq[v] = how many times v is in the matrix. */
    int freq[100005] = {0};

    /* Read the matrix and count each value as it arrives. */
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            scanf("%d", &Numbers[i][j]);
            freq[Numbers[i][j]]++;
        }
    }

    int numbers_to_check[X + 5];
    for(int i=0; i<X; i++){
        scanf("%d", &numbers_to_check[i]);
    }

    /* Each answer is a single look-up in freq. */
    for(int i=0; i<X; i++){
        printf("%d\n", freq[numbers_to_check[i]]);
    }

    return 0;
}