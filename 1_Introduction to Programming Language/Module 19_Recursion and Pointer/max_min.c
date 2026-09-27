/*
Max and MIN
time limit per test1 second
memory limit per test64 megabytes
Given an array A of size N. Print the minimum and the maximum number in the array.

Note: Solve this problem using function.

Input
First line will contain a number N (1 ≤ N ≤ 103) number of elements.

Second line will contain N numbers (0 ≤ Xi ≤ 105).

Output
Print the minimum and the maximum number separated by a space.

Example
InputCopy
5
10 13 95 1 3
OutputCopy
1 95
*/

/* Note on the statement: "103" is 10^3 and "105" is 10^5 (the exponents lost
   their formatting when the statement was copied). */

/*
 * This program finds minimum and maximum values in an array using functions
 * Important concepts shown:
 * 1. Passing arrays and pointers as function parameters
 * 2. Using scanf/printf with different format specifiers
 * 3. Pointer dereferencing to modify values
 *
 * Why pointers: a function can return only ONE value, but we need two
 * answers. So main hands over the addresses of its min and max, and the
 * function writes both answers straight into them.
 */

#include <stdio.h> // standard input/output library: scanf and printf

/* Function that finds minimum and maximum values in array:
 * Parameters:
 * arr[]: Integer array to search through
 *        (as a parameter, arr[] really receives the address of the first
 *        element; the array itself is not copied)
 * n: Size of array
 * *min: Pointer to store minimum value
 * *max: Pointer to store maximum value
 *
 * Algorithm:
 * 1. Initialize min and max to first element
 * 2. Compare each element with current min/max
 * 3. Update min/max through pointers if new value found
 *
 * Uses pointer dereferencing (*min, *max) to modify
 * original variables in calling function
 *
 * Trace with 10 13 95 1 3: start 10/10; 13 -> max 13; 95 -> max 95; 1 -> min 1; 3 -> no change -> "1 95".
 */
void minMax(int arr[], int n, int *min, int *max){
    /* Initialize both min and max to first element
     * Use pointer dereferencing to modify values
     */
    *min = arr[0];
    *max = arr[0];

    /* Loop through remaining elements
     * Compare each with current min and max
     * Update if new min/max found using pointer dereferencing
     * (i starts at 1 because arr[0] is already the starting value)
     */
    for(int i=1; i<n; i++){
        if(arr[i] < *min){ // smaller than the smallest so far
            *min = arr[i]; // writes into main's min
        }
        if(arr[i] > *max){ // larger than the largest so far
            *max = arr[i]; // writes into main's max
        }
    }
}

int main(){ // program execution starts here
    int n; // number of elements
    /* scanf with %d format specifier:
     * %d is used for reading integer input
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

    int min, max; // will be filled in by minMax
    /* Call minMax function:
     * Pass array, size, and addresses of min/max
     * Function will modify min and max through pointers
     */
    minMax(arr, n, &min, &max);

    /* printf with %d format specifiers:
     * Two %d used because printing two integers
     * Space between %d adds space between numbers
     * \n adds newline after printing
     */
    printf("%d %d\n", min, max);

    return 0; // program ended successfully
}
