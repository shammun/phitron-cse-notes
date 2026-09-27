#include <bits/stdc++.h>
using namespace std;

// Proof that when returned from stack, it gets deleted automatically from 
// memory.

// declaed globally so that we can access it from inside the main function or
// from any other function.
int *p;

void fun(){
    int x = 10;
    p = &x;
    cout << "Main -> " << *p << endl;
    return;
}

// function always starts compiling from main function
// it sees fun() function and so goes to that function
// it will create a variable x in stack memory with value 10. It occupies
// 4 bytes. It will return and automatically delete x from stack memory.

// To test that memory is deleted automatically, we will create a pointer
// that will store the memory of the variable x within the funciton fun(). We 
// will print the value of pointer or address.
int main(){
    fun();
    cout << "Fun -> " << *p << endl;
    return 0;
}