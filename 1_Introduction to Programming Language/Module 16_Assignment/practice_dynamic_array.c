/* Re-typed practice copy of dynamic_array.c (the question and the long
 * explanation of realloc are in that file). Same steps: start with room for
 * one int, and grow the block by one every time a number arrives. */

#include <stdio.h>
#include <stdlib.h>

int main(){
    int N;
    scanf("%d", &N);
    /* The dynamic array starts with room for a single int. */
    int *arr = (int *)malloc(sizeof(int));

    int num_array[N+5];
    for(int i=0; i<N; i++){
        scanf("%d", &num_array[i]);
        /* Grow to i + 1 ints; realloc keeps the values already inside. */
        arr = (int *)realloc(arr, (i+1)*sizeof(int));
        /* The new number goes into the last box. */
        arr[i] = num_array[i];
    }

    for(int i=0; i<N; i++){
        printf("%d ", arr[i]);
    }

    printf("\n");

    /* Give the memory back. */
    free(arr);

    return 0;
}