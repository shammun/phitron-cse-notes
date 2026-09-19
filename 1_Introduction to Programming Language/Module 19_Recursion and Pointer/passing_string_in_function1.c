/*
 * Passing a string to a function.
 *
 * passing_array_in_function.c showed that an array reaches a function as the
 * address of its first element, which is why that function also had to be
 * told the size: an address on its own says nothing about how many elements
 * follow it.
 *
 * A string is a char array, so it is handed over in exactly the same way -
 * but it needs no size argument. The '\0' at the end of a string is the size
 * information, carried inside the data itself. That is the point of this
 * file. Every string function, strlen included, works by walking forward
 * until it meets that '\0'.
 */

#include <stdio.h>
#include <string.h>

/* char x[] here means the same as char *x: x is the address of the caller's
 * first character, not a copy of the string. Nothing is duplicated, however
 * long the string is - and because it is the caller's memory, a function
 * written this way could also change the string. */
void length(char x[]){
    /* strlen counts the characters before the '\0'. For "programmer" that is
     * 10. What it does not count is the '\0' itself, which is why the array
     * in main is one slot bigger than this number. */
    int n = strlen(x);
    printf("Length of string: %d\n", n);
}

int main(){
    /* char a[] with nothing in the brackets: the compiler counts the
     * characters and reserves 11 slots, 10 letters plus the '\0'. */
    char a[] = "programmer";
    /* The array name on its own means "the address of a[0]", so this hands
     * over the address. No size is needed; the '\0' will stop the counting. */
    length(a);
    return 0;
}