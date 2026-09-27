#include <stdio.h>  // standard input/output library: printf
#include <stdlib.h> // standard library: malloc, calloc, realloc and free live here

/* A dynamic array is memory asked for while the program runs (on the "heap"),
 * instead of a fixed array whose size is written in the code.
 * Its big advantage: it can be made bigger later with realloc.
 * This program makes room for 5 ints, fills them with 1..5, grows the block
 * to 10 ints, fills the new part with 6..10, prints everything, and frees it.
 * Expected output:
 *   1 2 3 4 5
 *   Memory allocation successful
 *   1 2 3 4 5 6 7 8 9 10
 */

int main(){ // program execution starts here
    // malloc() allocates a block of uninitialized memory
    // Here we're allocating space for 5 integers
    // sizeof(int) gives us the size of one integer (typically 4 bytes)
    // We multiply by 5 to get space for 5 integers
    // malloc returns void*, so we cast it to int*
    // (void* = a plain address with no type; the cast (int *) says "treat it as
    // the address of ints". In C the cast is optional, but it is common style.)
    int *arr = (int *)malloc(5 * sizeof(int));

    // Alternative using calloc:
    // calloc() is similar to malloc but:
    // 1. It takes two arguments: number of elements and size of each element
    // 2. It initializes all bytes to zero
    // 3. Often used when you need zeroed memory
    // int *arr = (int *)calloc(5, sizeof(int));
    // (this line is commented out: it is shown only as the calloc version of the malloc line above)

    // Initialize the array with values 1 through 5
    // We can use array notation arr[i] even though arr is a pointer
    // This is because pointers and arrays are closely related in C
    for(int i = 0; i<5; i++){ // i = 0 .. 4, one pass fills one box
        arr[i] = i+1;  // arr[0]=1, arr[1]=2, etc.
    }

    // In C, when you have an array (or a pointer used
    // like an array), the syntax arr[i] is actually
    // shorthand for *(arr + i). This means that arr[i]
    // directly gives you the value at the i-th position
    // of the array, not the address.

    // Print the initial array using %d format specifier
    // %d is used for printing integers in decimal format
    for(int i = 0; i < 5; i++){
        printf("%d ", arr[i]);  // Prints: 1 2 3 4 5
    }

    printf("\n");  // Print newline for better formatting

    // Before reallocating memory, save original pointer
    int *temp = arr;
    // We store the original address of arr in temp
    // This is a safety measure because if realloc fails
    // (returns NULL), we don't want to lose the original
    // pointer as that would cause a memory leak

    // realloc() changes the size of previously allocated memory
    // It tries to extend the existing block if possible
    // If not possible, it allocates new block, copies data, and frees old block
    // Either way the first 5 values (1..5) are kept; the 5 new boxes start
    // with garbage values until we fill them.
    arr = (int *)realloc(arr, 10*sizeof(int));

    // Check if reallocation was successful
    // If realloc returns NULL, memory allocation failed
    // (NULL = the "points nowhere" address; on failure the old block is left untouched)
    if(arr == NULL){
        arr = temp;  // Restore original pointer
        printf("Memory allocation failed\n");
    } else {
        printf("Memory allocation successful\n");

        // Initialize the newly allocated memory (indices 5-9)
        for(int i=5; i< 10; i++){
            arr[i] = i + 1;  // arr[5]=6, arr[6]=7, etc.
        }

        // Print all 10 elements using %d format specifier
        for(int i=0; i < 10; i++){
            printf("%d ", arr[i]);  // Prints: 1 2 3 4 5 6 7 8 9 10
        }
    }

    // Always free dynamically allocated memory to prevent memory leaks
    // free() releases the memory block back to the system
    // (after free, arr must not be used any more - it points at memory we gave back)
    free(arr);

    return 0; // program ended successfully
}
