#include <stdio.h> // standard input/output library: scanf and printf

/* Re-typed practice copy of shift_zeros.c: move every 0 in the array to the
   right end, keeping the other numbers in their original order.
   Example: 2 0 0 5 -> 2 5 0 0 */

/* shift_zeros(arr, n): changes the caller's array in place (arr receives the
   address of the caller's first element, so no copy is made). Returns nothing. */
void shift_zeros(int arr[], int n){
    int nonZeroIndex = 0; // the next position where a non-zero number should go

    /* Pass 1: copy each non-zero number forward to position nonZeroIndex.
       Trace with 2 0 0 5: 2 -> arr[0], skip, skip, 5 -> arr[1]; nonZeroIndex ends at 2. */
    for(int i=0; i<n; i++){
        if(arr[i] != 0){
            arr[nonZeroIndex] = arr[i]; // move it forward (i is never behind nonZeroIndex, so nothing unread is overwritten)
            nonZeroIndex++; // the next non-zero goes one place further
        }
    }

    /* Pass 2: everything from nonZeroIndex to the end becomes 0. */
    for(int i=nonZeroIndex; i<n; i++){
        arr[i] = 0;
    }
}

int main(){ // program execution starts here
    int n; // number of elements
    scanf("%d", &n); // &n = address where scanf stores n

    int arr[n]; // the array (size from input: C99 variable length array)

    for(int i=0; i<n; i++){ // read the n numbers
        scanf("%d", &arr[i]);
    }

    shift_zeros(arr, n); // arr is changed inside the function

    for(int i=0; i<n; i++){
        // BUG: "%d" has no space after it, so the numbers are printed glued
        // together ("2500" instead of "2 5 0 0 "), which the judge rejects.
        // Fix: printf("%d ", arr[i]); as in shift_zeros.c.
        printf("%d", arr[i]);
    }
    printf("\n"); // end the line

    return 0; // program ended successfully
}
