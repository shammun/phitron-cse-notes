/*

This is a tutorial about the list container in the C++ Standard Template Library (STL).

`list<int>` is the STL doubly linked list of ints: every value sits in its own
node with links to the next and the previous node (like the Node class of
Module 9, but ready-made). This file shows the ways to CREATE a list, how to
read its first/last element, how to walk it, and clear / empty / resize.

Iterators: an iterator "points at" one element of a container.
    l.begin()   points at the first element
    l.end()     points ONE PAST the last element - there is no value there
    *it         reads the element `it` points at
    ++it / --it moves it one node forward / back

*/

#include <iostream>   // cout
#include <vector>     // std::vector - used once, to build a list from a vector
#include <algorithm>  // sort/max/min - not used in this file
#include <string>     // std::string - not used in this file
#include <list>       // std::list, the STL doubly linked list
using namespace std;  // lets us write list, cout ... instead of std::list, std::cout ...

int main(){
    list<int> l;               // an empty list of ints
    cout << l.size() << endl; // 0   (size() = number of elements; endl = newline + flush)

    list<int> l2(10); // Creates a list of size 10 with all values initialized to 0.
    cout << l2.size() << endl; // 10

    list<int> l3(10, 5); // Creates a list of size 10 with all values initialized to 5.
    // 5 5 5 5 5 5 5 5 5 5
    cout << l3.size() << endl; // 10

    // first element - O(1)
    cout << l3.front() << endl; // 5

    // last element - O(1)
    cout << l3.back() << endl; // 5


    // iterator -- .begin() and .end()
    cout << *l3.begin() << endl; // 5
    // BUG: `*l3.end()` reads a position that holds no element (one past the
    // last). That is undefined behaviour - it may print junk or crash.
    // Fix: delete this line, or read the last element with l3.back().
    cout << *l3.end() << endl; // invalid value as it goes one beyond the last element
    //  *l3.end() is dereferencing an invalid position, which leads to undefined behavior

    cout << *(--l3.end()) << endl; // This gives the correct value of 5
    // `--l3.end()` moves the one-past-the-end iterator back onto the last
    // element, and `*` reads its value (the same as l3.back()).

    list<int> l4 = {1, 2, 3, 4, 5}; // Creates a list with values 1, 2, 3, 4, 5.
    cout << l4.size() << endl; // 5

    cout << *l4.begin() << endl; // 1

    cout << *(--l4.end()) << endl; // 5

    //  copies every element in the range [first, last) from l4 into the new list
    list<int> l5(l4.begin(), l4.end()); // Creates a list with values 1, 2, 3, 4, 5.
    cout << l5.size() << endl; // 5

    // Use of the iterators to print the list

    // printing list using iterator:
    // `auto` lets the compiler work out the type (list<int>::iterator);
    // start at begin(), stop when we reach end(), `it++` moves one node on.
    for(auto it=l5.begin(); it!=l5.end(); it++){
        cout << *it << " ";   // the value under the iterator
    }

    cout << endl;   // end the line

    // even easier way: range-for, `val` takes each value in turn
    for(int val: l5){
        cout << val << " ";
    }
    // (no endl here, so the next number printed lands on the same line)

    // creating a list by copying other list
    list<int> l6(l5); // Creates a list with values 1, 2, 3, 4, 5.
    cout << l6.size() << endl; // 5

    // We can also create a list by copying array
    int arr[] = {1, 2, 3, 4, 5};
    // An array name works like a pointer to its first element, so `arr` and
    // `arr+5` (one past the last) mark the range [first, last) to copy.
    list<int> l7(arr, arr+5); // Creates a list with values 1, 2, 3, 4, 5.

    // printing list
    cout << "The list l7 is:" << endl;
    for(int val: l7){
        cout << val << " ";
    }

    cout << endl;

    // We can also create a list by copying a vector (any iterator range works)
    vector<int> v = {10, 20, 30, 40, 50};
    list<int> l8(v.begin(), v.end()); // Creates a list with values 10, 20, 30, 40, 50.

    for(int val: l8){        // print l8
        cout << val << " ";
    }

    cout << endl;

    // Clearing a list: removes (and frees) every node
    l8.clear(); // O(N)

    cout << l8.size() << endl; // 0

    // Checking if a list is empty: empty() is true when size() is 0
    if(l8.empty()){
        cout << "List is empty" << endl;       // this branch runs
    }
    else{
        cout << "List is not empty" << endl;
    }

    // resizing a list: resize(n) cuts the list to n elements, or adds
    // 0s at the end until it has n elements
    // Initially, l7 was 1 2 3 4 5
    l7.resize(10); // 1 2 3 4 5 0 0 0 0 0
    cout << l7.size() << endl; // 10

    cout << "After resizing, the list l7 is:" << endl;

    for(int val: l7){        // 1 2 3 4 5 0 0 0 0 0
        cout << val << " ";
    }

    return 0;   // 0 = the program ended normally
}
