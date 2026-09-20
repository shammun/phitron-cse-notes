#include <stdio.h>

/* This is a C program that demonstrates the use of 2D arrays and memory addressing.
 *
 * Note on the name: this file used to be saved as basic.py by mistake. It was
 * always C code - Python could never run it - so it is basic.c now.
 */

int main() {
    /* Declaring and initializing a 2D array of size 3x5
     * - First dimension (3) represents rows
     * - Second dimension (5) represents columns
     * The array is initialized with values in a structured format:
     * Row 1: 1,2,3,4,5
     * Row 2: 6,7,8,9,10
     * Row 3: 11,12,13,14,15
     */
    int arr[3][5] = {
        {1, 2, 3, 4, 5},     /* Row 0 values */
        {6, 7, 8, 9, 10},    /* Row 1 values */
        {11, 12, 13, 14, 15} /* Row 2 values */
    };

    /* Using nested loops to iterate through the 2D array
     * - Outer loop (i) iterates through rows (0 to 2)
     * - Inner loop (j) iterates through columns (0 to 4)
     */
    for(int i=0; i < 3; i++){
        for(int j=0; j<5; j++){
            /* For each element, we print:
             * i = current row index
             * j = current column index
             * &arr[i][j] = memory address of current element
             * arr[i][j] = value stored at current element
             *
             * Three things in this one line are worth spelling out, because
             * this is the first program in the course that prints an address.
             *
             * 1. `&` means "the address of". `&arr[i][j]` is not the number
             *    kept in the cell - that is `arr[i][j]` - it is WHERE the cell
             *    sits in memory. You have written `&` since Module 1 without
             *    thinking about it: `scanf("%d", &a)` has to be told where to
             *    put the number it reads.
             *
             * 2. `%p` is the placeholder for an address, the way `%d` is the
             *    placeholder for an int. It prints in hexadecimal, which is
             *    why the addresses read 1041FDE0 instead of 272760288. Do not
             *    print an address with %d: on this compiler an address is 8
             *    bytes and an int is 4, so %d would take half of it and the
             *    rest of the line would come out wrong.
             *
             * 3. `(void*)` turns the address into the exact type %p is defined
             *    to take. Two kinds of address are involved here. `&arr[i][j]`
             *    is an `int*`: an address that also carries the note "an int
             *    lives here", which is what lets C know that stepping to the
             *    next one means moving 4 bytes. `void*` is the plain address
             *    with that note rubbed off: "somewhere in memory, and I am not
             *    saying what is there". printf cannot inspect the type of what
             *    you hand it - it believes the format string and nothing else -
             *    so the standard says %p must be given a void*, and the cast
             *    is how you say "read this one as a plain address".
             *
             *    Do you have to write it? Honestly, no. On every ordinary
             *    compiler an int* and a void* are the same size and the same
             *    bits, so this line prints exactly the same thing with the
             *    cast left off, and the pointer programs in Module 15 do leave
             *    it off. The cast is the by-the-book version, and it is what
             *    keeps `gcc -Wall` from warning about the mismatch. You will
             *    meet both forms; now you know what the difference is for.
             *
             * Last, count the placeholders and count the values after the
             * comma: there must be four of each, in the same order. Write one
             * %d too many and printf reads a value nobody passed, which prints
             * rubbish and does not even warn you unless you compile with -Wall.
             */
            printf("i = %d, j = %d, address = %p, value = %d || ", i, j, (void*)&arr[i][j], arr[i][j]);
        }
        /* Print newline after each row for better formatting */
        printf("\n");
    }
}
