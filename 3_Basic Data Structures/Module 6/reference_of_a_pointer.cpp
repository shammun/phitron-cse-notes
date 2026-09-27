// Passing a pointer to a function: by copy (int* p) vs by reference (int* &p).
// A pointer is just a variable that holds an address. Passing it normally
// copies that address into a NEW local pointer, so re-pointing it inside the
// function does not affect the caller's pointer. Passing it as int* &p makes
// the parameter another name for the caller's pointer itself, so re-pointing
// it inside the function DOES change the caller's pointer.
// This is exactly why the linked list functions take Node* &head.
//
// Sample output (the addresses differ from run to run and machine to machine):
//   Value of p: 10
//   Address of p inside fun()0x61fe20      <- the COPY's own address
//   10
//   Value of p: 10
//   Address of p inside fun()0x61fe20
//   Address of p in main() 0x61fe40        <- main's p lives somewhere else
//   Address of p inside fun()0x61fe40      <- fun2's p IS main's p: same address
//   Address of p in main() 0x61fe40

#include <iostream>  // cout
#include <vector>    // not needed here, kept from the template
#include <algorithm> // not needed here
#include <string>    // not needed here
using namespace std; // Allows us to avoid prefixing standard library objects with `std::`.

// Changing WHERE p points inside this function is not reflected in main, because p
// here is a copy of main's pointer. Changing the VALUE it points to with *p = ...
// would be seen by main, since both copies point at the same x.
void fun(int* p){
    cout << "Value of p: " << *p << endl; // *p = the int p points at: 10
    // *p = 100;
    // cout << "Inside fun()" << *p << endl;
    // (Switched off: *p = 100 would change main's x to 100, because the copy still
    // points at x. The second line would then print it.)
    int y = 100; // a local variable; it disappears when fun returns
    p = &y; // re-point the COPY at y; main's p still points at x
    // &p is the address of the pointer variable itself (where the copy is stored),
    // not the address it holds.
    cout << "Address of p inside fun()" << &p << endl; // the copy's own address, e.g. 0x61fe20
}

// use & before the pointer to pass the reference of the pointer
// using & before the pointer will change the pointer p in the main function
// int* &p reads "p is a reference to an int pointer": no copy is made.
void fun2(int* &p){
    // *p = 100;
    // cout << "Inside fun()" << *p << endl;
    // int y = 100;
    // p = &y;
    // (Switched off: p = &y here would leave main's p pointing at a local variable
    // that dies when fun2 returns - a "dangling pointer". NULL is used instead.)
    p = NULL; // main's p now points at nothing
    // Because p is main's pointer under another name, &p is main's p's address.
    cout << "Address of p inside fun()" << &p << endl; // main's p's address, e.g. 0x61fe40
}

int main(){ // the program starts running here
    int x = 10; // an ordinary int
    int* p= &x; // p holds the address of x

    // if we change a pointer in a function, it will not change the pointer in the main function

    // fun uses a copy of the pointer p
    fun(p);
    // cout << "Inside main()"
    // cout << x << endl;
    // (Switched off: would print x, which is still 10.)

    cout << *p << endl; // prints 10 and not 100

    // because the pointer p in the main function and the pointer
    // p in the fun function are different pointers

    fun(p); // same as before: prints "Value of p: 10" and the copy's address
    cout << "Address of p in main() " << &p << endl; // e.g. 0x61fe40
    // (a different address from the one fun printed: two different pointer variables)


    // If we want a function to change where main's p points, we must pass p
    // BY REFERENCE (int* &p) instead of as a copy.
    // (Pointing main's p at a function's local y would be unsafe, though: y dies
    // when the function ends. That is why fun2 sets p to NULL instead.)

    // This is called passing the reference of a pointer to a function
    // fun2 uses the reference of the pointer to p
    fun2(p); // sets main's p to NULL

    // &p is where p itself is stored, and that never changes, so this prints the
    // same address as before - the same address fun2 printed, because fun2's p IS
    // main's p. What fun2 changed is the address STORED in p: it went from &x to
    // NULL, so printing p (not &p) would now show 0. Do not use *p now.
    cout << "Address of p in main() " << &p << endl; // e.g. 0x61fe40, same as before

    // A local variable like y is destroyed when its function returns, which is
    // why pointing main's p at it would be a mistake.

    return 0; // program finished successfully
}
