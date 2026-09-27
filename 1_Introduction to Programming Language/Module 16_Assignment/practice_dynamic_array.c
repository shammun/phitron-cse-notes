/* Re-typed practice copy of dynamic_array.c (the question and the long
 * explanation of realloc are in that file). Same steps: start with room for
 * one int, and grow the block by one every time a number arrives. */

#include <stdio.h>  // standard input/output library: scanf and printf
#include <stdlib.h> // standard library: malloc, realloc, free

int main(){ // program execution starts here
    int N; // how many numbers
    scanf("%d", &N); // &N = address where scanf stores N
    /* The dynamic array starts with room for a single int.
       malloc returns a plain void* address; (int *) turns it into an int pointer. */
    int *arr = (int *)malloc(sizeof(int));

    int num_array[N+5]; // ordinary array that receives each number first
    for(int i=0; i<N; i++){ // one pass = one number
        scanf("%d", &num_array[i]);
        /* Grow to i + 1 ints; realloc keeps the values already inside. */
        arr = (int *)realloc(arr, (i+1)*sizeof(int));
        /* The new number goes into the last box. */
        arr[i] = num_array[i];
    }

    for(int i=0; i<N; i++){ // print all numbers with a space after each
        printf("%d ", arr[i]);
    }

    printf("\n"); // end the line

    /* Give the memory back. */
    free(arr);

    return 0; // program ended successfully
}
