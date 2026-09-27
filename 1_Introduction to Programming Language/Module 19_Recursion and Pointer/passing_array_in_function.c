/*
 * This program demonstrates how arrays are passed to functions in C
 * Important concepts shown:
 * 1. An array is never copied into a function: the function receives the
 *    address of its first element, so it works on the caller's own array
 * 2. When passing array to function, we need to pass its size separately
 * 3. Array notation [] in parameter is same as using pointer *
 *
 * Output: Sum of array elements: 55
 */

#include <stdio.h> // standard input/output library: printf

/* Function that takes two parameters:
 * x[]: Array parameter - Actually receives address of first element
 *      Writing int x[] is same as writing int* x
 * n: Size of array - Needed because array size information is lost when passed
 * Returns: the sum of x[0] .. x[n-1] as an int.
 */
int fun(int x[], int n){
    int sum = 0; // running total, starts at 0
    /* Loop through array using index
     * Since we have array's address, we can access elements using [] operator
     * x[i] is same as *(x + i) in pointer arithmetic
     */
    for(int i=0; i<n; i++){
        sum += x[i];  // Add each element to sum
    }
    return sum;  // Return total sum
}

int main(){ // program execution starts here
    /* Initialize array with 10 elements
     * a[10] allocates space for 10 integers
     * {1,2,...10} initializes those spaces with values
     */
    int a[10] = {1,2,3,4,5,6,7,8,9,10};

    /* Call function by passing:
     * a: Array name (automatically converts to address of first element)
     * 10: Size of array
     */
    int result = fun(a, 10); // 1 + 2 + ... + 10 = 55

    /* Print result using printf
     * %d is format specifier for integers
     */
    printf("Sum of array elements: %d\n", result);
    return 0; // program ended successfully
}
