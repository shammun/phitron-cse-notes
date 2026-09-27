// Topic: what happens to a normal local (stack) variable when its function returns.
// fun() makes x = 10 on the stack and saves its address in the global pointer p.
// After fun() returns, main reads *p again - but x's memory has already been released.
// One run on this machine printed:
//   Main -> 10     (printed INSIDE fun, while x is still alive - see the BUG note below)
//   Fun -> 0       (printed in main, after x died - garbage, could be any value)

#include <bits/stdc++.h> // GCC-only "include everything" header (iostream, algorithm, vector, ...)
using namespace std; // lets us write cout instead of std::cout

// Proof that when returned from stack, it gets deleted automatically from
// memory.
// (More exactly: when a function returns, its stack frame - the memory holding its
//  local variables - is released automatically, and can be reused by the next call.)

// declaed globally so that we can access it from inside the main function or
// from any other function.
// int *p is a pointer: a variable that stores the address of an int.
// A global starts as nullptr (address 0) until something is stored in it.
int *p;

// fun: no parameters, returns nothing (void). Makes a local x and points p at it.
void fun(){
    int x = 10; // local variable in fun's stack frame; it dies when fun returns
    p = &x; // &x = "the address of x"; the global p now remembers where x lives
    // *p = "the value at the address in p" = x = 10 (x is still alive here)
    // BUG: the labels are swapped. This line runs inside fun but prints "Main ->",
    // and the line in main prints "Fun ->". Fix: swap the two label strings.
    cout << "Main -> " << *p << endl;
    return; // leave fun; x's stack memory is released right now
}

// function always starts compiling from main function
// (Fixed: the whole file is compiled first; it is the RUNNING program that
//  always starts EXECUTING at main.)
// it sees fun() function and so goes to that function
// it will create a variable x in stack memory with value 10. It occupies
// 4 bytes. It will return and automatically delete x from stack memory.

// To test that memory is deleted automatically, we will create a pointer
// that will store the memory of the variable x within the funciton fun(). We
// will print the value of pointer or address.
// (Note: reading a dead variable through a pointer is "undefined behaviour" - the
//  result is not guaranteed. It may print garbage such as 0, or even still 10 if
//  nothing has overwritten that memory yet. It is never safe to rely on.)
int main(){ // the program starts running here
    fun(); // run fun: prints the first line, then x dies and p becomes a dangling pointer
    // p still holds the OLD address, but nothing valid lives there any more.
    // *p reads whatever is in that memory now -> garbage (0 on one run here).
    cout << "Fun -> " << *p << endl;
    return 0; // returning 0 from main tells the system the program ended fine
}