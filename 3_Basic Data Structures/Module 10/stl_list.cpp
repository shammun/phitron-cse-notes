/*

This is a tutorial about the list container in the C++ Standard Template Library (STL).

*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <list>
using namespace std; 

int main(){
    list<int> l;
    cout << l.size() << endl; // 0

    list<int> l2(10); // Creates a list of size 10 with all values initialized to 0.
    cout << l2.size() << endl; // 10

    list<int> l3(10, 5); // Creates a list of size 10 with all values initialized to 5.
    // 5 5 5 5 5 5 5 5 5 5
    cout << l3.size() << endl; // 10

    // first element
    cout << l3.front() << endl; // 5

    // last element
    cout << l3.back() << endl; // 5


    // iterator -- .begin() and .end()
    cout << *l3.begin() << endl; // 5
    cout << *l3.end() << endl; // invalid value as it goes one beyond the last element
    //  *l3.end() is dereferencing an invalid position, which leads to undefined behavior

    cout << *(--l3.end()) << endl; // This gives the correct value of 5
    // gives the index at which the last element is stored

    list<int> l4 = {1, 2, 3, 4, 5}; // Creates a list with values 1, 2, 3, 4, 5.
    cout << l4.size() << endl; // 5

    cout << *l4.begin() << endl; // 1

    cout << *(--l4.end()) << endl; // 5

    //  copies every element in the range [first, last) from l4 into the new list
    list<int> l5(l4.begin(), l4.end()); // Creates a list with values 1, 2, 3, 4, 5.
    cout << l5.size() << endl; // 5

    // Use of the iterators to print the list

    // printing list using iterator
    for(auto it=l5.begin(); it!=l5.end(); it++){
        cout << *it << " ";
    }

    cout << endl;

    // even easier way
    for(int val: l5){
        cout << val << " ";
    }

    // creating a list by copying other list
    list<int> l6(l5); // Creates a list with values 1, 2, 3, 4, 5.
    cout << l6.size() << endl; // 5

    // We can also create a list by copying array
    int arr[] = {1, 2, 3, 4, 5};
    list<int> l7(arr, arr+5); // Creates a list with values 1, 2, 3, 4, 5.

    // printing list
    cout << "The list l7 is:" << endl;
    for(int val: l7){
        cout << val << " ";
    }

    cout << endl;

    // We can also create a list by copying a vector
    vector<int> v = {10, 20, 30, 40, 50};
    list<int> l8(v.begin(), v.end()); // Creates a list with values 10, 20, 30, 40, 50.

    for(int val: l8){
        cout << val << " ";
    }

    cout << endl;

    // Clearing a list
    l8.clear(); // O(N)

    cout << l8.size() << endl; // 0

    // Checking if a list is empty
    if(l8.empty()){
        cout << "List is empty" << endl;
    }
    else{
        cout << "List is not empty" << endl;
    }

    // resizing a list
    // Initially, l7 was 1 2 3 4 5
    l7.resize(10); // 1 2 3 4 5 0 0 0 0 0 
    cout << l7.size() << endl; // 10

    cout << "After resizing, the list l7 is:" << endl;

    for(int val: l7){
        cout << val << " ";
    }

    return 0;
}