// Topic: "growing" an array from 3 to 5 elements.
// No array can change its size once made, so growing always means:
// make a bigger array, copy the old values over, then fill the new places.
// Part 1 does this with static (stack) arrays, part 2 with dynamic (heap) arrays.
// The heap version is better because the old array can be deleted as soon as the copy is done.
// Example: input 10 20 30 (static part) and 1 2 3 (dynamic part) prints
//   10 20 30 40 50   and later   1 2 3 40 50

#include <bits/stdc++.h> // GCC-only "include everything" header (iostream, algorithm, vector, ...)
using namespace std; // Use the standard namespace to avoid prefixing std:: before standard functions

int main(){ // the program starts running here
    // First we create a static array 'a' of size 3
    // Static arrays are allocated on the stack and have a fixed size
    int a[3];
    // Static arrays can not be deleted and it will be in the memory
    // and will rest in the memory even after the function returns
    // This will waste the memory
    // (Fixed: a stack array IS freed automatically when its function returns.
    //  The real problem is that it can NOT be freed any EARLIER: after we copy a
    //  into b, a still takes space until main ends, even though we no longer need it.)

    // Dynamic arrays can be deleted and it will not be in the memory
    // (i.e. with delete[] we can free a heap array at the exact moment we are done with it.)


    cout << "Enter the elements of the static array: " << endl; // prompt, then newline
    // Use a for loop to take input for each element of the static array 'a'
    // i goes 0,1,2 - one box per pass; the loop stops when i becomes 3
    for(int i=0; i<3; i++){
        cin >> a[i]; // Read input from the user and store it in the array 'a' (cin skips spaces)
    }

    // Create another static array 'b' of size 5
    // This array is larger to accommodate additional elements
    int b[5];
    // Copy the elements of array 'a' into array 'b'
    // Only 3 passes, because a has only 3 values; b[3] and b[4] are still empty after this
    for(int i=0; i<3; i++){
        b[i] = a[i]; // Copy each element from 'a' to 'b'
    }
    // Add additional elements to the new positions in array 'b'
    b[3] = 40; // 4th box (index 3)
    b[4] = 50; // 5th box (index 4) - the last valid index of a size-5 array

    // Print the elements of the new static array 'b'
    cout << "The elements of the new array after using an array of size 5 are: " << endl;
    for(int i=0; i<5; i++){ // i = 0..4, all 5 boxes
        cout << b[i] << " "; // Print each element of the array 'b'
    }

    // Static arrays remain in the stack memory
    // (both a and b stay until main ends - a is wasted space from now on)

    cout << endl; // Print a newline character for better output formatting

    // Now we create a dynamic array 'p' of size 3
    // Dynamic arrays are allocated on the heap and can be resized
    // (Fixed: a heap array can NOT be resized either. What it allows is the same
    //  "make a bigger one and copy" trick, but the old one can be deleted right after.)
    // new int[3] asks the heap for 3 int boxes and returns the address of the first;
    // the pointer p stores that address, and p[i] reaches box i like a normal array.
    int *p = new int[3];
    cout << "Enter the elements of the dynamic array: " << endl; // prompt
    // Use a for loop to take input for each element of the dynamic array pointed to by 'p'
    for(int i=0; i<3; i++){
        cin >> p[i]; // Read input from the user and store it in the dynamic array
    }

    // Create another dynamic array 'q' of size 5
    // This array is larger to accommodate additional elements
    int *q = new int[5];
    // Copy the elements of the dynamic array 'p' into the new dynamic array 'q'
    for(int i=0; i<3; i++){
        q[i] = p[i]; // Copy each element from 'p' to 'q'
    }
    // Add additional elements to the new positions in array 'q'
    q[3] = 40; // new 4th value
    q[4] = 50; // new 5th value

    cout << endl; // Print a newline character for better output formatting
    // Print the elements of the new dynamic resized array 'q'
    cout << "The elements of the new dynamic resized array are: " << endl;
    for(int i=0; i<5; i++){ // i = 0..4
        cout << q[i] << " "; // Print each element of the dynamic array 'q'
    }

    // Free the dynamically allocated memory to avoid memory leaks
    // (the old small array p is not needed any more; in real code this delete[] p
    //  would go right after the copy loop, which is the whole advantage of the heap)
    delete[] p; // use [] to delete an array
    // delete[] q; // use [] to indicate that this is an array
    // (switched off: it would free q too. Since main ends right after, the OS
    //  reclaims it anyway, but writing it is the good habit.)

    return 0; // Return 0 to indicate successful execution of the program
}