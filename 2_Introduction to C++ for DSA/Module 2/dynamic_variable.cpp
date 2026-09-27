#include <bits/stdc++.h>
using namespace std;

int main(){
    int x = 10; // occupies 4 bytes in stack
    
    // Dynamic variable declaration in heap
    // use new keyword to allocate memory in heap
    // use new to declare a variable in the heap
    // use new to declare a dynamic variable (in the heap)

    // when returned from a function, static variable get deleted as it
    // is defined in the stack. But, when dynamic variable is returned 
    // from a function, it is not deleted as it is defined in heap.
    int *p = new int;
    *p = 100;

    // But, this dynamic memory is more helpful for array than single variable

    cout << *p << endl;
    return 0;

    return 0;
}