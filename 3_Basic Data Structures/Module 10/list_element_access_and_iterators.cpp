// std::list - reading elements: front(), back(), and iterators.
//
// `list<int>` is the STL (Standard Template Library) doubly linked list: every
// element sits in its own node with links to the next and previous node, just
// like the Node class of Module 9, but written and tested for us.
//
// A linked list has no `l[2]`: there is no O(1) jump to an index, because the
// nodes are not side by side in memory. To reach the third element you must
// walk to it. The STL walks with ITERATORS: an iterator is a small object that
// "points at" one element; `*it` reads that element, `++it` / `--it` move it
// one node forward / back.
//
// Output for the list {10, 20, 30, 40, 50}:
//     10
//     50
//     30
//     10
//     50

#include <iostream>   // cout
#include <vector>     // std::vector - not used in this file
#include <algorithm>  // sort/max/min - not used in this file
#include <string>     // std::string - not used in this file
#include <list>       // std::list, the STL doubly linked list
using namespace std;  // lets us write list and cout instead of std::list, std::cout

int main(){
    // Make a list and fill it from a brace list; the order is kept: 10 is first.
    list<int> l = {10, 20,30, 40, 50};
    // Accessing the first element of the list using the front() function
    cout << l.front() << endl;   // 10 (O(1)); endl = newline + flush
    // Accessing the last element of the list using the back() function
    cout << l.back() << endl;    // 50 (O(1))

    // Accessing any element of the list using next function
    // Accessing the third element (index 2) of the list using the next function:
    // `l.begin()` is an iterator on the first element; `next(it, 2)` returns
    // a copy moved 2 nodes forward (a walk, O(2)); `*` reads the element there.
    cout << *next(l.begin(), 2) << endl;   // 30

    // Accessing the first element using begin() function
    cout << *l.begin() << endl;   // 10 - `*` reads what the iterator points at

    // Accessing the last element using end() function
    // `l.end()` points one PAST the last element (it holds no value, never
    // read `*l.end()`). `--` moves it back onto the last element, then `*` reads it.
    cout << *(--l.end()) << endl;   // 50
    // Commented-out alternative (with a typo, `coout`); l.back() gives the same 50:
    // coout << l.back() << endl;





    return 0;   // 0 = the program ended normally
}
