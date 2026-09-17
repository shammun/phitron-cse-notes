/*
 * This program demonstrates how strings are passed to functions and modified in C
 * Important concepts shown:
 * 1. Strings are character arrays in C
 * 2. Like regular arrays, strings are passed by reference
 * 3. Changes made to string in function affect original string
 * 4. Various string manipulation functions from different headers:
 *    - stdio.h for input/output (printf)
 *    - string.h for string operations 
 *    - ctype.h for character operations (toupper)
 */

#include <stdio.h>
#include <string.h>
#include <ctype.h>

/* Function that takes a string parameter:
 * char x[]: String parameter - Actually receives address of first character
 *           Writing char x[] is same as writing char* x
 * The function modifies first character to uppercase
 */
void makeFirstCharUpper(char x[]){
    /* toupper() from ctype.h converts character to uppercase
     * x[0] accesses first character of string
     * Since we have string's address, changes affect original string
     */
    x[0] = toupper(x[0]);
    
    /* Print modified string using %s format specifier
     * %s tells printf to expect a string (char array)
     */
    printf("%s\n", x);
}

int main(){
    /* Initialize string using array initialization
     * char a[] automatically allocates enough space for "programmer"
     * Including null terminator \0 at end
     */
    char a[] = "programmer";
    
    /* Call function by passing string 'a'
     * Array name 'a' automatically converts to address of first character
     */
    makeFirstCharUpper(a);
    
    /* Print string again to show it's permanently modified
     * This is because strings are passed by reference
     * Any changes in function affect original string
     */
    printf("After function call, there is also change to original string: %s\n", a);

    return 0;
}