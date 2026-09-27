#include <stdio.h> // standard input/output library: printf

/* The first pointer program.
 * A pointer is a variable whose value is an ADDRESS (a location in memory).
 *   &a   = "address of a"
 *   int *b = &a;   declares b as "pointer to int" and stores a's address in it
 *   *b   = "the value at the address stored in b" (dereferencing) - here, a itself
 * Writing through *b changes a, because *b and a are the same box in memory.
 * The addresses in the sample output comments come from one run; they change
 * every run, but the ones that should match always match.
 */

int main(){ // program execution starts here
    // Declare an integer variable 'a' and initialize it with value 5
    int a = 5;

    // Declare a pointer variable 'b' that stores the address of 'a'
    // The & operator gets the address of variable 'a'
    // (The * here is part of the TYPE: "int *" = pointer to int. It does not dereference.)
    int *b = &a;

    // b contains the address of a, while &b gives you the address of the pointer b itself in memory.

    // Print the memory address of variable 'a' using %p format specifier
    // %p is used for printing pointer/address values in hexadecimal format
    printf("Address of a: %p\n", &a);
    // Address of a: 0x7ffdac0d17f8

    // &b gives address where pointer 'b' itself is stored
    // (b is a variable too, so it has its own address - different from a's)
    printf("Address of b: %p\n", &b);
    // Address of b: 0x7ffdac0d1800

    // output the memory address of the variable a, since b was
    // initialized to point to a with int *b = &a;
    printf("Value of b: %p\n", b);
    // Value of b: 0x7ffdac0d17f8

    // Print the value that pointer 'b' is pointing to
    // *b dereferences the pointer to get the value stored at that address
    printf("Value of b after dereferencing: %d\n", *b);
    // Value of b after dereferencing: 5

    // Create a new variable 'val' and initialize it with the value
    // that pointer 'b' is pointing to (which is value of 'a')
    // val gets a COPY of the number 5; it is a separate box, not linked to a.
    int val = *b;
    printf("Value of val: %d\n", val); // prints 5

    // Change the value at the memory location that 'b' points to
    // Since 'b' points to 'a', this will change value of 'a' to 10
    *b = 10;

    // Update val with new value that 'b' points to
    // (needed because val is only a copy; without this line val would still be 5)
    val = *b;

    // Demonstrate that changing value through pointer 'b'
    // actually changed the value of original variable 'a'
    printf("This also changes the value of a after changing the value of b\n");
    printf("Value of a is now: %d\n", a);
    // Value of a is now: 10
    printf("Value of val after changing the value of b: %d\n", val);
    // Value of val after changing the value of b: 10

    return 0; // program ended successfully

}
