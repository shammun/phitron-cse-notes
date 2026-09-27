/* Re-typed practice copy of unit_matrix.c (the question is at the top of
 * that file), with one change: no flag. The moment a wrong cell is found,
 * the program prints NO and ends with return 0, which leaves both loops at
 * once. Only a matrix that survives every check reaches the YES at the end. */

#include <stdio.h>

int main(){
    int N;
    scanf("%d", &N);

    int values[N][N];

    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            scanf("%d", &values[i][j]);
        }
    }

    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            if(i == j){
                /* On the main diagonal the cell must be 1. */
                if(values[i][j] !=1){
                    printf("NO");
                    return 0;
                }
            } else{
                /* Off the diagonal the cell must be 0. */
                if(values[i][j] != 0){
                    printf("NO");
                    return 0;
                }
            }
        }
    }

    printf("YES");

    return 0;

}