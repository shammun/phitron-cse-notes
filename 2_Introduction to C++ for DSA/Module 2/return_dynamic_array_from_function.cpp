// Topic: a function that returns an array. It must be a heap (new) array,
// because a normal local array dies when the function returns.
// Example: input 1 2 3 4 5 -> output "1 2 3 4 5 "

#include <bits/stdc++.h> // GCC-only "include everything" header (iostream, algorithm, vector, ...)
using namespace std; // lets us write cin/cout instead of std::cin/std::cout

/*

// As the following fun() declares a static array, it's memory will be deleted
// after the function returns and thus main will print segmentation fault
// ("static array" here = a normal fixed-size local array on the stack, not the
//  C++ keyword static. The result is undefined behaviour: a crash, garbage, or
//  by luck the right numbers - never safe. This whole block is switched off.)

int* fun(){
    int a[5]; // declaring a static array
    for(int i=0; i<5; i++){
        cin >> a[i];
    }
    return a; // returning pointer to the static array
}

int main(){
    int * x = fun(); // receiving array from function as a ponter
    for(int i=0; i<5; i++){
        cout << x[i] << " ";
    }
    return 0;
}

*/

// So, we will use dynamic array

// fun: no parameters; returns int* = the address of the first box of a heap array.
int* fun(){
    // new int[5] asks the heap for 5 int boxes and returns the first box's address.
    // Heap memory is not freed when fun returns, so the address stays valid.
    int *a = new int[5]; // declaring a dynamic array
    for(int i=0; i<5; i++){ // i = 0..4, one number per pass
        cin >> a[i]; // cin skips spaces/newlines and reads the next number into box i
    }
    return a; // returning pointer to the dynamic array (only the pointer variable a dies, not the boxes)
}

int main(){ // the program starts running here
    int * x = fun(); // receiving array from function as a pointer; x[i] now reads the heap boxes
    for(int i=0; i<5; i++){ // print all 5 values
        cout << x[i] << " "; // box i, then a space
    }
    // Good habit (not done here): delete[] x; to give the heap array back.
    return 0; // returning 0 from main tells the system the program ended fine
}

