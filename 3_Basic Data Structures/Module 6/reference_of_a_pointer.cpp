#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std; // Allows us to avoid prefixing standard library objects with `std::`.

// change in pointer's address inside the function is not reflected in the main function
void fun(int* p){
    cout << "Value of p: " << *p << endl;
    // *p = 100;
    // cout << "Inside fun()" << *p << endl;
    int y = 100;
    p = &y;
    cout << "Address of p inside fun()" << &p << endl; // prints 0x61ff08
}

// use & before the pointer to pass the reference of the pointer
// using & before the pointer will change the pointer p in the main function
void fun2(int* &p){
    // *p = 100;
    // cout << "Inside fun()" << *p << endl;
    // int y = 100;
    // p = &y;
    p = NULL;
    cout << "Address of p inside fun()" << &p << endl; // prints 0x61ff08
}

int main(){
    int x = 10;
    int* p= &x;

    // if we change a pointer in a function, it will not change the pointer in the main function

    // fun uses a copy of the pointer p
    fun(p);
    // cout << "Inside main()" 
    // cout << x << endl; 

    cout << *p << endl; // prints 10 and not 100

    // because the pointer p in the main function and the pointer 
    // p in the fun function are different pointers

    fun(p);
    cout << "Address of p in main() " << &p << endl; // prints 0x61ff00
    

    // But, if we want the pointer p in the main function to point to the
    // variable y in the fun function, we need to pass the address of the pointer p
    // to the fun function.

    // This is called passing the reference of a pointer to a function
    // fun2 uses the reference of the pointer to p
    fun2(p);

    cout << "Address of p in main() " << &p << endl; // prints 0
    // prints the same address as the address of p in the fun2 function

    // the address of p in the main function is changed by calling the fun2 function

    // the value of y will be deleted after the fun2 function is executed and returned in main
    // function

    return 0;
}