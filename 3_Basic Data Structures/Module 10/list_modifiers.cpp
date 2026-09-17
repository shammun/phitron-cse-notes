/*

This is a tutorial about the modifiers of list container in the C++ Standard Template Library (STL).

*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <list>
using namespace std; 

int main(){
    // Assigning one list to another using = operator
    list<int> l = {1, 2, 3, 4, 5}; // Creates a list with values 1, 2, 3, 4, 5.
    cout << "The value of l is: " << endl;
    for(int val: l){
        cout << val << " ";
    }
    cout << endl;
    cout << endl;
    list<int> l2 = l; // Creates a list with values 1, 2, 3, 4, 5.
    // Instead of writing in one line like the above, we can also write:
    // list l2;
    // l2 = l;
    
    cout << "After using list<int> l2 = l, the value of l2 is: " << endl; 
    for(int val: l2){
        cout << val << " ";
    }
    cout << endl;
    cout << endl;

    // We can also assign a list to another list using the assign() function
    list<int> l3;
    l3.assign(l.begin(), l.end());

    // Adding element at the end of the list
    l.push_back(6);

    cout << "After adding 6 at the end of the list l using l.push_back(6);, the value of l is: " << endl;
    for(int val: l){
        cout << val << " ";
    }
    cout << endl;
    cout << endl;

    // Does this change the value of l2?
    // No, because l2 is a copy of l.
    // l2 is not a reference to l.
    cout << "After adding 6 at the end of the list l, the value of l2 is still: " << endl;
    for(int val: l2){
        cout << val << " ";
    }
    cout << endl;

    cout << "We can see that l2 is not changed as l2 is a copy of l and not a reference to l." << endl;

    // Adding element at the beginning of the list
    l.push_front(0);
    cout << "After adding 0 at the beginning of the list l using l.push_front(0);, the value of l is: " << endl;
    for(int val: l){
        cout << val << " ";
    }
    cout << endl;
    cout << endl;

    // delete the last element of the list
    l.pop_back();
    cout << "After deleting the last element of the list l using l.pop_back();, the value of l is: " << endl;
    for(int val: l){
        cout << val << " ";
    }
    cout << endl;
    cout << endl;

    // delete the first element of the list
    l.pop_front();  
    cout << "After deleting the first element of the list l using l.pop_front();, the value of l is: " << endl;
    for(int val: l){
        cout << val << " ";
    }
    cout << endl;
    cout << endl;

    // Access the 3rd element or index 2 of the list
    cout << "The 3rd element of the list l is: " << *next(l.begin(), 2) << endl;
    cout << endl;
    cout << endl;

    // Insert at any position -- O(N) -- if inserts 1 element
    // insert 100 at the 3rd position or index 2 of the list
    l.insert(next(l.begin(), 2), 100);
    cout << "After inserting 100 at the 3rd position of the list l using l.insert(next(l.begin(), 2), 100);, the value of l is: " << endl;
    for(int val: l){
        cout << val << " ";
    }   
    cout << endl;
    cout << endl;

    // Inserst multiple elements at any position
    // We will insert at index 2 of l, all the elements of l4
    list<int> l4 = {111, 222, 333, 444, 555};
    l.insert(next(l.begin(), 2), l4.begin(), l4.end()); // 1 2 111 222 333 444 555 100 3 4 5
    cout << "After inserting all the elements of l4 at the 3rd position of the list l using l.insert(next(l.begin(), 2), l4.begin(), l4.end());, the value of l is: " << endl;
    for(int val: l){
        cout << val << " ";
    }   
    cout << endl;
    cout << endl;

    // We can also elements of a vector to some arbitrary position of the list
    // We will insert at index 2 of l, all the elements of v
    vector<int> v = {33, 44, 55};
    l.insert(next(l.begin(), 2), v.begin(), v.end()); // 1 2 33 44 55 111 222 333 444 555 100 3 4 5
    cout << "After inserting all the elements of v at the 3rd position of the list l using l.insert(next(l.begin(), 2), v.begin(), v.end());, the value of l is: " << endl;
    for(int val: l){
        cout << val << " ";
    }   
    cout << endl;
    cout << endl;

    // erase at any position -- O(N) -- if deletes 1 element
    // delete the 3rd element or index 2 of the list
    l.erase(next(l.begin(), 2)); // 1 2 44 55 111 222 333 444 555 100 3 4 5
    cout << "After deleting the 3rd element of the list l using l.erase(next(l.begin(), 2));, the value of l is: " << endl;
    for(int val: l){
        cout << val << " ";
    }
    cout << endl;
    cout << endl;

    // delete the first element of the list
    l.erase(l.begin()); // 2 44 55 111 222 333 444 555 100 3 4 5
    cout << "After deleting the first element of the list l using l.erase(l.begin());, the value of l is: " << endl;
    for(int val: l){
        cout << val << " ";
    }
    cout << endl;   
    cout << endl;

    // delete the last element of the list
    l.erase(--l.end()); // 2 44 55 111 222 333 444 555 100 3 4

    cout << "After deleting the last element of the list l using l.erase(--l.end());, the value of l is: " << endl;
    for(int val: l){
        cout << val << " ";
    }
    cout << endl;   
    cout << endl;

    // delete multiple elements at any position
    // We will delete the 3rd, 4th, 5th element or index 2, 3 and 4 of the list
    l.erase(next(l.begin(), 2), next(l.begin(), 5)); // 2 44 333 444 555 100 3 4
    cout << "After deleting the 3rd and 4th element of the list l using l.erase(next(l.begin(), 2), next(l.end(), 2));, the value of l is: " << endl;    
    for(int val: l){
        cout << val << " ";     
    }
    cout << endl;
    cout << endl;

    l.push_back(1000);
    l.push_back(1000);
    cout << "After pushing 1000 2 times at the end of the list l using l.push_back(1000);, the value of l is: " << endl;
    // 2 44 333 444 555 100 3 4 1000 1000
    for(int val: l){
        cout << val << " ";
    }
    cout << endl;
    cout << endl;

    // replace all the 1000s with 999
    replace(l.begin(), l.end(), 1000, 999); // 2 44 333 444 555 100 3 4 999 999
    cout << "After replacing all the 1000s with 999 in the list l using replace(l.begin(), l.end(), 1000, 999);, the value of l is: " << endl;
    for(int val: l){
        cout << val << " ";
    }
    cout << endl;
    cout << endl;

    // find -- returns an iterator to the first occurence of the element
    // find the first occurence of 999 in the list l
    // as it returns an iterator, we will use auto to store the iterator
    auto it = find(l.begin(), l.end(), 999);
    // if it doesn't find the element, it returns l.end()
    if(it != l.end()){
        cout << "The first occurence of 999 in the list l is at index " << distance(l.begin(), it) << endl;
    }
    else{
        cout << "999 is not present in the list l." << endl;
    }
    cout << endl;
    cout << endl;

    // find the first occurence of 333 in the list l
    auto it2 = find(l.begin(), l.end(), 333);
    if(it2 != l.end()){
        cout << "The first occurence of 333 in the list l is at index " << distance(l.begin(), it2) << endl;
    }
    else{
        cout << "333 is not present in the list l." << endl;
    }
    cout << endl;
    cout << endl;

    // find the first occurence of 333 in the list l
    auto it3 = find(l.begin(), l.end(), 45678);
    if(it3 != l.end()){
        cout << "The first occurence of 45678 in the list l is at index " << distance(l.begin(), it3) << endl;
    }
    else{
        cout << "45678 is not present in the list l." << endl;
    }

    // remove an element from the list
    l.remove(999); // 2 44 333 444 555 100 3 4 1000 1000
    cout << "After removing 999 from the list l using l.remove(999), the value of l is: " << endl;
    for(int val: l){
        cout << val << " ";
    }

    cout << endl;
    cout << endl;

    return 0;
}