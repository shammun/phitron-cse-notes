#include <stdio.h>

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main(){
    int N, M;
    scanf("%d %d", &N, &M);

    int matrix[N][M];

    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            scanf("%d", &matrix[i][j]);
        }
    }

    for(int i=0; i<N; i++){
        swap(&matrix[i][0], &matrix[i][M-1]);
    }

    for(int j=0; j<M; j++){
        swap(&matrix[0][j], &matrix[N-1][j]);
    }

    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }

    return 0;
}