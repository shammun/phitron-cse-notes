/*

This is a tutorial about the modifiers of list container in the C++ Standard Template Library (STL).

`list<int>` is the STL doubly linked list: each value lives in its own node,
linked to the node before and after it. "Modifiers" are the functions that
change the list: assign/copy, push_back, push_front, pop_back, pop_front,
insert, erase, remove, plus the general algorithms replace and find.

Positions in a list are given with ITERATORS, not indexes. An iterator is a
small object that points at one element: `l.begin()` points at the first
element, `l.end()` points one PAST the last one, `next(it, k)` is a copy of
`it` moved k nodes forward, and `*it` reads the element it points at.
Reaching index k is a walk of k steps, so it costs O(k). Once you HAVE the
iterator, inserting or erasing there is O(1) - only a few links change.

*/

#include <iostream>   // cout
#include <vector>     // std::vector - used once below, to insert a vector's values into the list
#include <algorithm>  // replace and find (general algorithms that work through iterators)
#include <string>     // std::string - not used in this file
#include <list>       // std::list, the STL doubly linked list
using namespace std;  // lets us write list, cout ... instead of std::list, std::cout ...

int main(){
    // Assigning one list to another using = operator
    list<int> l = {1, 2, 3, 4, 5}; // Creates a list with values 1, 2, 3, 4, 5.
    cout << "The value of l is: " << endl;   // endl = newline + flush
    // Range-for: `val` takes each element's value in turn, first to last.
    for(int val: l){
        cout << val << " ";
    }
    cout << endl;   // end the line
    cout << endl;   // plus one empty line as a separator
    list<int> l2 = l; // Creates a list with values 1, 2, 3, 4, 5 - a full COPY of l (new nodes).
    // Instead of writing in one line like the above, we can also write
    // (with the element type, which the commented lines below leave out -
    // it has to be `list<int> l2;`):
    // list l2;
    // l2 = l;

    cout << "After using list<int> l2 = l, the value of l2 is: " << endl;
    for(int val: l2){          // print l2
        cout << val << " ";
    }
    cout << endl;
    cout << endl;

    // We can also assign a list to another list using the assign() function:
    // assign(first, last) replaces l3's contents with the elements from
    // `first` up to (not including) `last` - here, all of l. (l3 is not used again.)
    list<int> l3;
    l3.assign(l.begin(), l.end());

    // Adding element at the end of the list - O(1)
    l.push_back(6);   // 1 2 3 4 5 6

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
    for(int val: l2){          // still 1 2 3 4 5
        cout << val << " ";
    }
    cout << endl;

    cout << "We can see that l2 is not changed as l2 is a copy of l and not a reference to l." << endl;

    // Adding element at the beginning of the list - O(1)
    l.push_front(0);   // 0 1 2 3 4 5 6
    cout << "After adding 0 at the beginning of the list l using l.push_front(0);, the value of l is: " << endl;
    for(int val: l){
        cout << val << " ";
    }
    cout << endl;
    cout << endl;

    // delete the last element of the list - O(1)
    l.pop_back();   // 0 1 2 3 4 5
    cout << "After deleting the last element of the list l using l.pop_back();, the value of l is: " << endl;
    for(int val: l){
        cout << val << " ";
    }
    cout << endl;
    cout << endl;

    // delete the first element of the list - O(1)
    l.pop_front();   // 1 2 3 4 5
    cout << "After deleting the first element of the list l using l.pop_front();, the value of l is: " << endl;
    for(int val: l){
        cout << val << " ";
    }
    cout << endl;
    cout << endl;

    // Access the 3rd element or index 2 of the list:
    // next(l.begin(), 2) walks 2 nodes from the first one; `*` reads the value (3).
    cout << "The 3rd element of the list l is: " << *next(l.begin(), 2) << endl;
    cout << endl;
    cout << endl;

    // Insert at any position -- O(N) -- if inserts 1 element
    // (O(N) for the walk to the position; the insert itself is O(1).)
    // insert 100 at the 3rd position or index 2 of the list:
    // insert(pos, value) puts the value BEFORE the element `pos` points at.
    l.insert(next(l.begin(), 2), 100);   // 1 2 100 3 4 5
    cout << "After inserting 100 at the 3rd position of the list l using l.insert(next(l.begin(), 2), 100);, the value of l is: " << endl;
    for(int val: l){
        cout << val << " ";
    }
    cout << endl;
    cout << endl;

    // Insert multiple elements at any position
    // We will insert at index 2 of l, all the elements of l4:
    // insert(pos, first, last) copies the range [first, last) in before `pos`.
    list<int> l4 = {111, 222, 333, 444, 555};
    l.insert(next(l.begin(), 2), l4.begin(), l4.end()); // 1 2 111 222 333 444 555 100 3 4 5
    cout << "After inserting all the elements of l4 at the 3rd position of the list l using l.insert(next(l.begin(), 2), l4.begin(), l4.end());, the value of l is: " << endl;
    for(int val: l){
        cout << val << " ";
    }
    cout << endl;
    cout << endl;

    // We can also insert the elements of a vector at some arbitrary position of
    // the list - any container's iterator range works.
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
    // (again O(N) for the walk, O(1) for the erase itself)
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

    // delete the last element of the list: `l.end()` is one past the last
    // element, `--` moves it back onto the last one.
    l.erase(--l.end()); // 2 44 55 111 222 333 444 555 100 3 4

    cout << "After deleting the last element of the list l using l.erase(--l.end());, the value of l is: " << endl;
    for(int val: l){
        cout << val << " ";
    }
    cout << endl;
    cout << endl;

    // delete multiple elements at any position
    // We will delete the 3rd, 4th, 5th element or index 2, 3 and 4 of the list:
    // erase(first, last) removes [first, last) - index 2 up to, NOT including, index 5.
    l.erase(next(l.begin(), 2), next(l.begin(), 5)); // 2 44 333 444 555 100 3 4
    // BUG (message text only): the line below prints "3rd and 4th element" and
    // "next(l.end(), 2)", but the code above erased the 3rd, 4th and 5th elements
    // with next(l.begin(), 5). The list itself is correct.
    cout << "After deleting the 3rd and 4th element of the list l using l.erase(next(l.begin(), 2), next(l.end(), 2));, the value of l is: " << endl;
    for(int val: l){
        cout << val << " ";
    }
    cout << endl;
    cout << endl;

    l.push_back(1000);   // add 1000 at the end...
    l.push_back(1000);   // ...twice
    cout << "After pushing 1000 2 times at the end of the list l using l.push_back(1000);, the value of l is: " << endl;
    // 2 44 333 444 555 100 3 4 1000 1000
    for(int val: l){
        cout << val << " ";
    }
    cout << endl;
    cout << endl;

    // replace all the 1000s with 999: replace(first, last, old, new) from
    // <algorithm> overwrites every `old` in [first, last) with `new`. O(n).
    replace(l.begin(), l.end(), 1000, 999); // 2 44 333 444 555 100 3 4 999 999
    cout << "After replacing all the 1000s with 999 in the list l using replace(l.begin(), l.end(), 1000, 999);, the value of l is: " << endl;
    for(int val: l){
        cout << val << " ";
    }
    cout << endl;
    cout << endl;

    // find -- returns an iterator to the first occurrence of the element
    // find the first occurrence of 999 in the list l
    // as it returns an iterator, we will use auto to store the iterator
    // (`auto` = "let the compiler work out the type", here list<int>::iterator)
    auto it = find(l.begin(), l.end(), 999);
    // if it doesn't find the element, it returns l.end()
    if(it != l.end()){
        // distance(a, b) counts the steps from a to b - that is the index. O(n).
        cout << "The first occurence of 999 in the list l is at index " << distance(l.begin(), it) << endl;   // 8
    }
    else{
        cout << "999 is not present in the list l." << endl;
    }
    cout << endl;
    cout << endl;

    // find the first occurrence of 333 in the list l
    auto it2 = find(l.begin(), l.end(), 333);
    if(it2 != l.end()){        // found
        cout << "The first occurence of 333 in the list l is at index " << distance(l.begin(), it2) << endl;   // 2
    }
    else{
        cout << "333 is not present in the list l." << endl;
    }
    cout << endl;
    cout << endl;

    // look for 45678, which is NOT in the list, so find returns l.end()
    auto it3 = find(l.begin(), l.end(), 45678);
    if(it3 != l.end()){
        cout << "The first occurence of 45678 in the list l is at index " << distance(l.begin(), it3) << endl;
    }
    else{
        cout << "45678 is not present in the list l." << endl;   // this branch runs
    }

    // remove an element from the list: remove(x) deletes EVERY node equal to x. O(n).
    l.remove(999); // 2 44 333 444 555 100 3 4
    cout << "After removing 999 from the list l using l.remove(999), the value of l is: " << endl;
    for(int val: l){
        cout << val << " ";
    }

    cout << endl;
    cout << endl;

    return 0;   // 0 = the program ended normally
}
