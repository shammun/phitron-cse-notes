// size vs capacity of a vector.
// size()     = how many elements the vector holds right now.
// capacity() = how many elements fit in the memory it has ALREADY reserved.
// When push_back() finds no free room (size == capacity), the vector grabs a
// bigger block (g++ doubles it), copies the old elements over and frees the old
// block. Doubling means copying happens rarely, so push_back is O(1) on average.
// The exact numbers below are what g++ (libstdc++) prints; other compilers may
// grow differently (Visual C++ grows by 1.5x).

#include <iostream> // cout
#include <vector>   // vector
using namespace std; // lets us drop the std:: prefix

int main() { // the program starts running here
    vector<int> v; // an empty vector of ints: size 0, no memory reserved yet
    cout << v.capacity() << endl; // prints 0
    // When we will store value, it will increase the capacity of the vector

    // Add element to the vector
    v.push_back(10); // push_back(x) puts x at the end; size becomes 1
    cout << v.capacity() << endl; // prints 1

    // Add element to the vector
    v.push_back(20); // no room (1 of 1 used) -> capacity doubles to 2
    cout << v.capacity() << endl; // prints 2

    // Add element to the vector
    v.push_back(30); // no room (2 of 2 used) -> capacity doubles to 4
    cout << v.capacity() << endl; // prints 4

    // When we will store value, when increasing capacity,
    // it will increase the capacity of the vector by a factor of 2

    // Add element to the vector
    v.push_back(40); // there is still room (3 of 4 used) -> no growth
    cout << v.capacity() << endl; // prints 4

    v.push_back(50); // this is the fift value and so the capacity 4 will be doubled to 8
    cout << v.capacity() << endl; // prints 8

    return 0; // program finished successfully
}
