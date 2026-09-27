/*

In this tutorial, we will learn about vector iterators.

An iterator is an object that points at one element of a container, like a
pointer points at one element of an array.
  v.begin() -> iterator to the first element
  v.end()   -> iterator to the position just AFTER the last element
               (it points at nothing; it only marks where to stop)
  *it       -> the value the iterator points at
  it++      -> move to the next element
Output of this program: "1 2 3 4 5 3 25 1 2 3 4 5 3 25 " (the list twice).

*/

#include <iostream>  // cout
#include <vector>    // vector
#include <algorithm> // not needed here, kept from the template
using namespace std; // lets us drop the std:: prefix

int main() { // the program starts running here
    vector<int> v = {1,2,3,4,5,3,25}; // 7 elements

    // Using iterator, we can access the elements of the vector
    // vector<int>::iterator is the full type name of "an iterator into a vector<int>".
    // Start at begin(), stop when we reach end(), step with it++.
    for(vector<int>::iterator it = v.begin(); it != v.end(); it++){
        cout << *it << " "; // *it = the element it points at
    }

    // We can also use auto keyword to declare the iterator
    // auto tells the compiler "work out the type from the value on the right";
    // here it becomes vector<int>::iterator, exactly as above, but shorter.
    for(auto it = v.begin(); it != v.end(); it++){
        cout << *it << " "; // print the element
    }


    return 0; // program finished successfully
}
