#include <stdio.h>
#include <stdlib.h>

int main(){
    // malloc() allocates a block of uninitialized memory
    // Here we're allocating space for 5 integers
    // sizeof(int) gives us the size of one integer (typically 4 bytes)
    // We multiply by 5 to get space for 5 integers
    // malloc returns void*, so we cast it to int*
    int *arr = (int *)malloc(5 * sizeof(int));

    // Alternative using calloc:
    // calloc() is similar to malloc but:
    // 1. It takes two arguments: number of elements and size of each element
    // 2. It initializes all bytes to zero
    // 3. Often used when you need zeroed memory
    // int *arr = (int *)calloc(5, sizeof(int));

    // Initialize the array with values 1 through 5
    // We can use array notation arr[i] even though arr is a pointer
    // This is because pointers and arrays are closely related in C
    for(int i = 0; i<5; i++){
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
    arr = (int *)realloc(arr, 10*sizeof(int));
    
    // Check if reallocation was successful
    // If realloc returns NULL, memory allocation failed
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
    free(arr);

    return 0;
}