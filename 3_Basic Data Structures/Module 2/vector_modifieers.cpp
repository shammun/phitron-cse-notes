/*

We will learn about vector modifiers in this tutorial.

Modifiers are functions that CHANGE a vector: =, assign, push_back, pop_back,
insert, erase. At the end we also use three helpers from <algorithm> that work
on any range: replace, find, distance.
Positions are given as iterators: v.begin() is index 0, v.begin() + k is
index k, v.end() is one past the last element.
Note: the print loops below never print a newline, so the whole output comes
out as one long line of numbers.

*/

#include <iostream>  // cout
#include <vector>    // vector
#include <algorithm> // replace() and find()
using namespace std; // lets us drop the std:: prefix

int main() { // the program starts running here
    vector<int> v = {1,2,3,4,5}; // source vector
    vector<int> v2; // empty target vector

    // Assigning values to the vector v2 using = operator
    // This COPIES every element: v2 becomes its own {1,2,3,4,5}; changing v2
    // later does not change v. Cost O(n).
    v2 = v;

    // Print with an index loop.
    for(int i=0; i<v2.size(); i++){
        cout << v2[i] << " "; // prints 1 2 3 4 5
    }

    // When we do not need index, we can use this shortcut loop
    // (range-for: x takes a COPY of each element of v2 in turn)
    for(int x : v2){
        cout << x << " "; // prints 1 2 3 4 5 again
    }

    // Assigning values to the vector v2 using assign() function
    // assign(first, last) throws away v2's old contents and copies the range
    // [first, last) into it. Here it copies all of v, so v2 is {1,2,3,4,5}.
    v2.assign(v.begin(), v.end());

    // pop_back() function removes the last element from the vector
    // (O(1); never call it on an empty vector)
    v2.pop_back();
    // Now, the vector v2 will be {1, 2, 3, 4}
    for(int x : v2){
        cout << x << " "; // prints 1 2 3 4
    }

    // insert(position, value) function inserts the element at the specified position
    // Everything from that position onward shifts one step right, so inserting
    // at the front costs O(n).
    v2.insert(v2.begin(), 10);
    // Now, the vector v2 will be {10, 1, 2, 3, 4}
    for(int x : v2){
        cout << x << " "; // prints 10 1 2 3 4
    }

    // insert at the last position
    // (inserting at end() is the same as push_back)
    v2.insert(v2.end(), 20);
    // Now, the vector v2 will be {10, 1, 2, 3, 4, 20}
    for(int x : v2){
        cout << x << " "; // prints 10 1 2 3 4 20
    }

    // insert multiple elements at the last position
    // insert(position, count, value): put `count` copies of `value` there
    v2.insert(v2.end(), 3, 30);
    // Now, the vector v2 will be {10, 1, 2, 3, 4, 20, 30, 30, 30}
    for(int x : v2){
        cout << x << " "; // prints 10 1 2 3 4 20 30 30 30
    }

    // insert multiple elements at the specified position
    v2.insert(v2.begin() + 3, 2, 40);
    // here, we are inserting 2 elements with value 40 at position 3
    // Now, the vector v2 will be {10, 1, 2, 40, 40, 3, 4, 20, 30, 30, 30}
    // (not printed)

    // insert at position 5
    v2.insert(v2.begin() + 5, 50);
    // Now, the vector v2 will be {10, 1, 2, 40, 40, 50, 3, 4, 20, 30, 30, 30}
    for(int x : v2){
        cout << x << " "; // prints the 12 values above
    }

    // erase(position) function removes the element at the specified position
    // (elements after it shift one step left: O(n))
    v2.erase(v2.begin() + 5); // here, we are removing the element at position 5 with value 50
    // Now, the vector v2 will be {10, 1, 2, 40, 40, 3, 4, 20, 30, 30, 30}
    for(int x : v2){
        cout << x << " "; // prints the 11 values above
    }

    // erase(start, end) function removes the elements in the range [start, end)
    // [start, end) means start is included, end is NOT included.
    v2.erase(v2.begin() + 3, v2.begin() + 5);
    // here, we are removing the elements in the range [3, 5)
    // So, it will remove the elements at position 3 and 4 with values 40 and 40
    // Now, the vector v2 will be {10, 1, 2, 3, 4, 20, 30, 30, 30}

    // Now, we will use some more functions that are not under vector class
    // (they come from <algorithm> and work on any range given by two iterators)

    // (To change the value at ONE position you simply write v2[i] = value;
    // replace() below changes every element equal to a given value.)
    // replace(start_position, end_position, value_to_be_replaced, new_value)
    // This replaces all the occurrences of the value_to_be_replaced with new_value

    // Suppose, we want to replace all the 30s with 100
    replace(v2.begin(), v2.end(), 30, 100); // O(n): checks every element
    // Now, the vector v2 will be {10, 1, 2, 3, 4, 20, 100, 100, 100}
    for(int x : v2){
        cout << x << " "; // prints 10 1 2 3 4 20 100 100 100
    }

    // find(start, end, value) function returns the iterator to the first occurrence of the value
    // If the value is not found, it returns the end iterator
    // So, we can use this function to check if a value is present in the vector or not
    // Is value 100 present in the vector v2?
    if(find(v2.begin(), v2.end(), 100) != v2.end()){ // got something other than end() -> found
        cout << "100 is present in the vector" << endl; // printed
    }
    else{ // find returned end() -> not found
        cout << "100 is not present in the vector" << endl;
    }

    // find position of 100 in the vector v2
    // vector<int>::iterator it = find(v2.begin(), v2.end(), 100);
    // Instead of vector<int>::iterator it. we can just write auto it
    // (auto = let the compiler work out the type from the right-hand side)
    auto it = find(v2.begin(), v2.end(), 100); // an iterator (it works like a pointer) to the first 100 in v2
    // Like a pointer, *it gives the VALUE stored at that position.
    cout << *it << endl; // prints 100 (the value); its position is 6
    // Now, it will point to the first occurrence of 100 in the vector v2
    // So, we can use it to access the value at that position
    cout << "The first occurrence of 100 is at position " << distance(v2.begin(), it) << endl;
    // distance(a, b) returns how many steps b is after a. Here it returns 6,
    // because 100 is at index 6 in
    // {10, 1, 2, 3, 4, 20, 100, 100, 100}. (For a vector, it - v2.begin() gives the same 6.)

    return 0; // program finished successfully
}
