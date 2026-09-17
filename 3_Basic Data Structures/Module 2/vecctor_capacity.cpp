#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> v;
    cout << v.capacity() << endl; // prints 0
    // When we will store value, it will increase the capacity of the vector

    // Add element to the vector
    v.push_back(10);
    cout << v.capacity() << endl; // prints 1

    // Add element to the vector
    v.push_back(20);
    cout << v.capacity() << endl; // prints 2

    // Add element to the vector
    v.push_back(30);
    cout << v.capacity() << endl; // prints 4

    // When we will store value, when increasing capacity,
    // it will increase the capacity of the vector by a factor of 2

    // Add element to the vector
    v.push_back(40);
    cout << v.capacity() << endl; // prints 4

    v.push_back(50); // this is the fift value and so the capacity 4 will be doubled to 8
    cout << v.capacity() << endl; // prints 8

    return 0;
}