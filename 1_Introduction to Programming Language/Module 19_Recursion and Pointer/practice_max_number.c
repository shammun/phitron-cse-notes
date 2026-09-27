#include <stdio.h> // standard input/output library: scanf and printf

/* Re-typed practice copy of max_number.c: read n numbers and print the
   largest one, found with recursion instead of a loop.
   Example: 5 / 1 -3 5 4 -6 -> prints 5. */

/* maxFrom(a, i, n) returns the largest value among a[i], a[i+1], ..., a[n-1].
   a = address of the caller's array (int *a works like int a[] here),
   i = index to start from, n = number of elements. */
int maxFrom(int *a, int i, int n){
    /* Base case: i is the last index, so only one number is left,
       and it is its own maximum. */
    if(i == n-1){
        return a[i];
    }

    /* Trust the recursive call to return the largest value after index i. */
    int rest = maxFrom(a, i+1, n);

    /* Keep the bigger of this element and the best of the rest. */
    if(a[i] > rest){
        return a[i];
    } else{
        return rest;
    }
}

int main(){ // program execution starts here
    int n; // number of elements
    scanf("%d", &n); // &n = address where scanf stores n

    int a[n]; // the array (size from input: C99 variable length array)

    for(int i=0; i<n; i++){ // read the n numbers
        scanf("%d", &a[i]);
    }

    printf("%d\n", maxFrom(a, 0, n)); // start at index 0 = the whole array

    return 0; // program ended successfully
}
