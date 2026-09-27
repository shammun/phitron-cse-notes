/*
Shift Zeros
time limit per test1 second
memory limit per test256 megabytes
Given an array A
 of size N
. Print the array elements after shifting all zeroes in array A
 to the right.

Note: Solve this problem using function.

Input
First line will contain a number N
 (1≤N≤103)
 number of elements.

Second line will contain N
 numbers (0≤Ai≤103)
.

Output
Print the array after shifting right all its zeros.

Examples
InputCopy
4
2 0 0 5
OutputCopy
2 5 0 0
InputCopy
5
1 5 0 7 4
OutputCopy
1 5 7 4 0
*/

/* Note on the statement: "103" is 10^3 (the exponent lost its formatting when it was copied). */

/*
 * This program shifts all zeros in an array to the right while maintaining
 * the relative order of non-zero elements
 * Important concepts shown:
 * 1. Array manipulation using functions
 * 2. Use of format specifiers in scanf/printf
 * 3. In-place array modification
 */

#include <stdio.h> // standard input/output library: scanf and printf

/* Function that shifts zeros to right in an array:
 * Parameters:
 * arr[]: Integer array to be modified
 *        (it receives the address of the caller's first element, so the
 *        changes are made in the caller's own array)
 * n: Size of array
 *
 * Algorithm:
 * 1. Keep track of position where next non-zero should go
 * 2. Scan array and move non-zeros to front
 * 3. Fill remaining positions with zeros
 *
 * For example: arr = [2,0,0,5]
 * First pass: Move non-zeros to front
 * - Move 2 to index 0
 * - Move 5 to index 1
 * Second pass: Fill remaining with zeros
 * - Put 0 at index 2
 * - Put 0 at index 3
 * Result: [2,5,0,0]
 */
void shiftZeros(int arr[], int n){
    int nonZeroIndex = 0;  // Tracks where next non-zero should go

    /* First pass: Move all non-zero elements to front
     * Maintains relative order of non-zero elements
     * (i is always >= nonZeroIndex, so we never overwrite a number we have not read yet)
     */
    for(int i=0; i<n; i++){
        if(arr[i] != 0){
            arr[nonZeroIndex] = arr[i]; // copy this non-zero to the next free front position
            nonZeroIndex++; // move the front position one step right
        }
    }

    /* Second pass: Fill remaining positions with zeros
     * From nonZeroIndex to end of array
     */
    for(int i=nonZeroIndex; i<n; i++){
        arr[i] = 0;
    }
}

int main(){ // program execution starts here
    int n; // number of elements
    /* scanf with %d format specifier:
     * %d is used for reading integer value
     * &n passes address where input should be stored
     */
    scanf("%d", &n);

    /* Create array of size n
     * Will store input numbers
     * (size known only at run time: a C99 variable length array)
     */
    int arr[n];

    /* Read n integers into array
     * Using %d format specifier for each integer
     * &arr[i] passes address of array element
     */
    for(int i=0; i<n; i++){
        scanf("%d", &arr[i]);
    }

    /* Call function to shift zeros right
     * The function receives the address of arr, not a copy, so the original array is modified
     */
    shiftZeros(arr, n);

    /* Print modified array
     * Using %d format specifier for each integer
     * Add space between numbers for readability
     */
    for(int i=0; i<n; i++){
        printf("%d ", arr[i]);  // Note space after %d
    }
    printf("\n");  // Add newline after printing array

    return 0; // program ended successfully
}
