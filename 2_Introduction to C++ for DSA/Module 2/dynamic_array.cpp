// Topic: a dynamic array - an array made on the heap with new, used exactly like a normal array.
// Program: read 5 numbers into it, then print them back on one line.
// Example: input 1 2 3 4 5 -> output "1 2 3 4 5 "

#include <bits/stdc++.h> // GCC-only "include everything" header: iostream, algorithm, vector, string, ... in one line
using namespace std; // lets us write cin/cout instead of std::cin/std::cout

int main() // the program starts running here
{
    // int a[5]; // static array
    // (The line above is switched off. It would make a normal array of 5 ints on the
    //  stack: its memory is freed automatically when main ends, and it cannot be freed earlier.)

    // new int[5] asks the heap (a big memory area that is NOT freed automatically)
    // for 5 int boxes placed side by side, and gives back the address of the FIRST box.
    // int *a is a pointer: a variable that stores an address of an int.
    // Heap memory stays until we call delete[] (or the program ends).
    int *a = new int[5]; // dynamic array

    // Read the 5 numbers. a[i] on a pointer means "the box i steps after the first one",
    // so a pointer to a heap array is indexed exactly like a normal array.
    // i goes 0,1,2,3,4 and the loop stops when i becomes 5.
    for(int i=0; i<5; i++){
        cin >> a[i]; // cin skips spaces/newlines and reads the next whole number into box i
    }
    // Print them back in the same order, each followed by a space
    for(int i=0; i<5; i++){
        cout << a[i] << " "; // print box i, then a space
    }

    // Note: the array is never given back with delete[] a; here. When main ends the
    // operating system reclaims all memory anyway, but the good habit is to write delete[] a;
    return 0; // returning 0 from main tells the system the program ended fine
}