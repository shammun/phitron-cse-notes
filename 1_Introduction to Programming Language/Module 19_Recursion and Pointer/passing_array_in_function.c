/*
 * This program demonstrates how arrays are passed to functions in C
 * Important concepts shown:
 * 1. Arrays are always passed by reference in C
 * 2. When passing array to function, we need to pass its size separately
 * 3. Array notation [] in parameter is same as using pointer *
 */

#include <stdio.h>

/* Function that takes two parameters:
 * x[]: Array parameter - Actually receives address of first element
 *      Writing int x[] is same as writing int* x
 * n: Size of array - Needed because array size information is lost when passed
 */
int fun(int x[], int n){
    int sum = 0;
    /* Loop through array using index
     * Since we have array's address, we can access elements using [] operator
     * x[i] is same as *(x + i) in pointer arithmetic
     */
    for(int i=0; i<n; i++){
        sum += x[i];  // Add each element to sum
    }
    return sum;  // Return total sum
}

int main(){
    /* Initialize array with 10 elements
     * a[10] allocates space for 10 integers
     * {1,2,...10} initializes those spaces with values
     */
    int a[10] = {1,2,3,4,5,6,7,8,9,10};
    
    /* Call function by passing:
     * a: Array name (automatically converts to address of first element)
     * 10: Size of array
     */
    int result = fun(a, 10);
    
    /* Print result using printf
     * %d is format specifier for integers
     */
    printf("Sum of array elements: %d\n", result);
    return 0;
}