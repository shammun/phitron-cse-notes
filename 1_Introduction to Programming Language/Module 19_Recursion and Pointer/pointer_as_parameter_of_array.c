/*
 * This program demonstrates two different ways to access array elements:
 * 1. Using pointer arithmetic (*(ptr + index))
 * 2. Using array indexing notation (array[index])
 * Both methods achieve the same result but use different syntax
 *
 * The program also shows different ways to format output:
 * - %d for integers: Used to print single integer values
 * - %s for strings: Used to print character arrays (strings) until null terminator
 * This helps understand how C handles different data types in printf
 */

#include <stdio.h>
#include <string.h>

/* Function that takes two parameters:
 * int *x: Pointer to first element of array
 *         Arrays decay to pointers when passed to functions
 * int n: Size of array - needed because size information is lost when array is passed
 *
 * This function uses %d formatter because it prints individual integers
 * Each integer is accessed using pointer arithmetic and printed separately
 */

// The array parameter ar[] is interpreted as a pointer to the first element of the array.
void fun(int *x, int n){
    /* First way to access array elements: Pointer arithmetic
     * *(x + i) means:
     * - Start at address x
     * - Move i positions forward (each position is sizeof(int) bytes)
     * - Get value at that address using *
     * 
     * Using %d formatter because we're printing one integer at a time
     */
    for(int i=0; i<n; i++){
        printf("%d", *(x+i));
    }
}

/* Function that takes a string parameter
 * Uses %s formatter because it handles entire string at once
 * %s automatically prints characters until it finds null terminator (\0)
 * This is more efficient than printing character by character
 */
void fun2(char *x){
    printf("%s\n", x);  // Print entire string using %s
    x[0] = 'c';  // Modify first character - shows strings are mutable
}

/* Function demonstrating string manipulation
 * Takes two string parameters and copies second into first
 * Uses strcpy which is designed for string copying
 * strcpy automatically handles null terminator
 */
void fun3(char *x, char *y){
    x[0] = 'c';  // First modify initial character
    x = strcpy(x, y);  // Then copy entire string y into x
}

int main(){
    /* Initialize array with 5 integers
     * Elements are stored in consecutive memory locations
     * Will be printed using %d formatter in fun() - one integer at a time
     */
    int a[5] = {1,2,3,4,5};
    
    /* Pass array to function
     * 'a' automatically converts to address of first element
     * Same as writing &a[0]
     */
    fun(a, 5);
    printf("\n");

    /* Second way to access array elements: Array indexing
     * a[i] is actually converted by compiler to *(a + i)
     * This is more readable than pointer arithmetic
     * Both methods work exactly the same way internally
     * Still using %d because we're printing integers one at a time
     */
    for(int i=0; i<5; i++){
        printf("%d", a[i]);
    }

    printf("\n");

    /* String operations using %s formatter
     * b[] is a character array (string) initialized with "programmer"
     * Will be printed using %s which handles entire string at once
     */
    char b[] = "programmer";
    fun2(b);  // Demonstrates string printing and modification
    printf("%s\n", b);  // Show modified string

    /* More string operations showing copying
     * Both d and e are character arrays with space for 10 chars
     * Will be printed using %s formatter
     */
    char d[10] = "air";
    char e[10] = "apple";
    fun3(d, e);  // Copy e into d after modifying first char
    printf("%s\n", d);  // Show result of string copy

    return 0;
}