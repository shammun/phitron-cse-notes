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
 *
 * Output:
 *   12345
 *   12345
 *   programmer
 *   crogrammer
 *   apple
 */

#include <stdio.h>  // standard input/output library: printf
#include <string.h> // string library: strcpy

/* Function that takes two parameters:
 * int *x: Pointer to first element of array
 *         Arrays decay to pointers when passed to functions
 * int n: Size of array - needed because size information is lost when array is passed
 *
 * This function uses %d formatter because it prints individual integers
 * Each integer is accessed using pointer arithmetic and printed separately
 */

// The parameter int *x receives the address of the first element of the caller's array.
void fun(int *x, int n){
    /* First way to access array elements: Pointer arithmetic
     * *(x + i) means:
     * - Start at address x
     * - Move i positions forward (each position is sizeof(int) bytes)
     * - Get value at that address using *
     *
     * Using %d formatter because we're printing one integer at a time
     * (no space is printed, so the numbers come out joined: 12345)
     */
    for(int i=0; i<n; i++){
        printf("%d", *(x+i));
    }
}

/* Function that takes a string parameter
 * Uses %s formatter because it handles entire string at once
 * %s automatically prints characters until it finds null terminator (\0)
 * so no loop and no length are needed here
 */
void fun2(char *x){
    printf("%s\n", x);  // Print entire string using %s
    x[0] = 'c';  // Modify first character - shows strings are mutable (this changes the caller's array)
}

/* Function demonstrating string manipulation
 * Takes two string parameters and copies second into first
 * Uses strcpy which is designed for string copying
 * strcpy automatically handles null terminator
 */
void fun3(char *x, char *y){
    x[0] = 'c';  // First modify initial character ("air" -> "cir"), but the next line overwrites it anyway
    x = strcpy(x, y);  // Then copy entire string y into x; strcpy returns x itself, so assigning it back to x changes nothing
}

int main(){ // program execution starts here
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
    printf("\n"); // end the first output line

    /* Second way to access array elements: Array indexing
     * a[i] is actually converted by compiler to *(a + i)
     * This is more readable than pointer arithmetic
     * Both methods work exactly the same way internally
     * Still using %d because we're printing integers one at a time
     */
    for(int i=0; i<5; i++){
        printf("%d", a[i]);
    }

    printf("\n"); // end the second output line

    /* String operations using %s formatter
     * b[] is a character array (string) initialized with "programmer"
     * Will be printed using %s which handles entire string at once
     */
    char b[] = "programmer";
    fun2(b);  // Demonstrates string printing and modification
    printf("%s\n", b);  // Show modified string: "crogrammer"

    /* More string operations showing copying
     * Both d and e are character arrays with space for 10 chars
     * Will be printed using %s formatter
     */
    char d[10] = "air";
    char e[10] = "apple";
    fun3(d, e);  // Copy e into d (the 'c' written first is overwritten by the copy)
    printf("%s\n", d);  // Show result of string copy: "apple"

    return 0; // program ended successfully
}
