#include <iostream>
using namespace std;

int main(){
    int x = 10; // occupies 4 bytes in stack
    
    // Dynamic variable declaration in heap
    // use new keyword to allocate memory in heap
    // use new to declare a variable in the heap
    // use new to declare a dynamic variable (in the heap)
    int *p = new int;
    *p = 100;

    // But, this dynamic memory is more helpful for array than single variable

    cout << *p << endl;
    return 0;

    return 0;
}