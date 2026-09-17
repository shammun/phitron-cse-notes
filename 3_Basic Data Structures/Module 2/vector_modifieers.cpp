/*

We will learn about vector modifiers in this tutorial.

*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    vector<int> v = {1,2,3,4,5};
    vector<int> v2;
    
    // Assigning values to the vector v2 using = operator
    v2 = v;

    for(int i=0; i<v2.size(); i++){
        cout << v2[i] << " ";
    }

    // When we do not need index, we can use this shortcut loop
    for(int x : v2){
        cout << x << " ";
    }

    // Assigning values to the vector v2 using assign() function
    v2.assign(v.begin(), v.end());

    // pop_back() function removes the last element from the vector
    v2.pop_back();
    // Now, the vector v2 will be {1, 2, 3, 4}
    for(int x : v2){
        cout << x << " ";
    }

    // insert(position, value) function inserts the element at the specified position
    v2.insert(v2.begin(), 10);
    // Now, the vector v2 will be {10, 1, 2, 3, 4}
    for(int x : v2){
        cout << x << " ";
    }

    // insert at the last position
    v2.insert(v2.end(), 20);
    // Now, the vector v2 will be {10, 1, 2, 3, 4, 20}
    for(int x : v2){
        cout << x << " ";
    }

    // insert multiple elements at the last position
    v2.insert(v2.end(), 3, 30);
    // Now, the vector v2 will be {10, 1, 2, 3, 4, 20, 30, 30, 30}
    for(int x : v2){
        cout << x << " ";
    }

    // insert multiple elements at the specified position
    v2.insert(v2.begin() + 3, 2, 40); 
    // here, we are inserting 2 elements with value 40 at position 3
    // Now, the vector v2 will be {10, 1, 2, 40, 40, 3, 4, 20, 30, 30, 30}

    // insert at position 5
    v2.insert(v2.begin() + 5, 50);
    // Now, the vector v2 will be {10, 1, 2, 40, 40, 50, 3, 4, 20, 30, 30, 30}
    for(int x : v2){
        cout << x << " ";
    }

    // erase(position) function removes the element at the specified position
    v2.erase(v2.begin() + 5); // here, we are removing the element at position 5 with value 50
    // Now, the vector v2 will be {10, 1, 2, 40, 40, 3, 4, 20, 30, 30, 30}
    for(int x : v2){
        cout << x << " ";
    }

    // erase(start, end) function removes the elements in the range [start, end)
    v2.erase(v2.begin() + 3, v2.begin() + 5); 
    // here, we are removing the elements in the range [3, 5)
    // So, it will remove the elements at position 3 and 4 with values 40 and 40
    // Now, the vector v2 will be {10, 1, 2, 3, 4, 20, 30, 30, 30}

    // Now, we will use some more functions that are not under vector class

    // replace(position, value) function replaces the element at the specified 
    // position with the given value
    // replace(start_position, end_position, value_to_be_replaced, new_value)
    // This replaces all the occurrences of the value_to_be_replaced with new_value
    
    // Suppose, we want to replace all the 30s with 100
    replace(v2.begin(), v2.end(), 30, 100);
    // Now, the vector v2 will be {10, 1, 2, 3, 4, 20, 100, 100, 100}
    for(int x : v2){
        cout << x << " ";
    }

    // find(start, end, value) function returns the iterator to the first occurrence of the value
    // If the value is not found, it returns the end iterator
    // So, we can use this function to check if a value is present in the vector or not
    // Is value 100 present in the vector v2?
    if(find(v2.begin(), v2.end(), 100) != v2.end()){
        cout << "100 is present in the vector" << endl;
    }
    else{
        cout << "100 is not present in the vector" << endl;
    }

    // find position of 100 in the vector v2
    // vector<int>::iterator it = find(v2.begin(), v2.end(), 100);
    // Instead of vector<int>::iterator it. we can just write auto it
    auto it = find(v2.begin(), v2.end(), 100); // this is a pointer to the first occurrence of 100 in the vector v2
    // as it is a pointer, we can use *it to access the value at that position
    cout << *it << endl; // prints 6 as it is at position 6 in the vector v2
    // Now, it will point to the first occurrence of 100 in the vector v2
    // So, we can use it to access the value at that position
    cout << "The first occurrence of 100 is at position " << distance(v2.begin(), it) << endl;
    // distance() function returns the distance between two iterators
    // it will return the vakue 3 because 100 is at position 6 in the vector v2

    return 0;
}