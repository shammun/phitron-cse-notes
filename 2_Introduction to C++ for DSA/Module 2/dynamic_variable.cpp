// Topic: a dynamic variable - one int made on the heap with new and used through a pointer.
// Output: 100

#include <bits/stdc++.h> // GCC-only "include everything" header (iostream, algorithm, vector, ...)
using namespace std; // lets us write cout instead of std::cout

int main(){ // the program starts running here
    // A normal local variable: it lives in main's stack frame.
    // An int takes 4 bytes. Stack memory is freed automatically when the function ends.
    // (x is not used again - it is here only to compare with the heap variable below.)
    int x = 10; // occupies 4 bytes in stack

    // Dynamic variable declaration in heap
    // use new keyword to allocate memory in heap
    // use new to declare a variable in the heap
    // use new to declare a dynamic variable (in the heap)

    // when returned from a function, a normal local (stack) variable gets deleted
    // as it is defined in the stack. But, when dynamic variable is returned
    // from a function, it is not deleted as it is defined in heap.
    // (Fixed wording: the old comment said "static variable" here. In C++ "static"
    //  is a keyword with a different meaning - a static local lives until the program
    //  ends. The variable that dies with the function is an ordinary local, a stack variable.)

    // new int asks the heap for one int box (4 bytes) and returns its address.
    // The box has no name; the only way to reach it is through the pointer p.
    int *p = new int;
    // *p means "the box p points to" (dereference). This stores 100 in the heap box.
    *p = 100;

    // But, this dynamic memory is more helpful for array than single variable
    // (because an array's size can be chosen at run time, e.g. new int[n]).

    cout << *p << endl; // *p reads the value in the heap box -> prints 100; endl = newline
    // Good habit (not done here): delete p; gives the heap box back.
    return 0; // main ends here with "success" (0)

    return 0; // never reached - the return above already ended main; this line is harmless but useless
}