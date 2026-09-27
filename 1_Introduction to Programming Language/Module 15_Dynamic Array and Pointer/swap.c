#include <stdio.h> // standard input/output library: printf

/* Swapping two variables through pointers.
 * *x means "the box x points at". Since x points at a, writing to *x writes
 * to a itself - that is how the swap reaches the real variables.
 * Output:
 *   Before swapping: a = 5, b = 8
 *   After swapping: a = 8, b = 5
 */

int main(){ // program execution starts here
    int a = 5, b = 8; // the two values to swap
    int *x = &a, *y = &b; // x points at a, y points at b
    printf("Before swapping: a = %d, b = %d\n", a, b);

    int temp = *x; // dereferencing x (reading a through it) and storing the value in temp
    *x = *y; // read b through y, write it into the box x points at, which is a
    *y = temp; // temp is a plain int (no * needed); its value goes into the box y points at, which is b

    printf("After swapping: a = %d, b = %d\n", a, b);
    return 0; // program ended successfully
}
