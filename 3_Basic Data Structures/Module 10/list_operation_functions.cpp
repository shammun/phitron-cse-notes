// std::list - the "operations": remove, sort, unique, reverse, empty.
//
// These are MEMBER functions of list (called as l.sort(), not sort(...)).
// The general std::sort from <algorithm> needs jumping to any index, which a
// linked list cannot do, so list brings its own sort.
//
// Output (each block is followed by a blank line):
//     1 2 40 30 40 30 4 5          (after remove(3))
//     1 2 4 5 30 30 40 40          (after sort)
//     40 40 30 30 5 4 2 1          (after sort with greater<int>)
//     1 2 4 5 30 40                (after sort + unique)
//     40 30 5 4 2 1                (after reverse)
//     Is the list l empty? 0

#include <iostream>   // cout
#include <vector>     // std::vector - not used in this file
#include <algorithm>  // sort/max/min - not used in this file
#include <string>     // std::string - not used in this file
#include <list>       // std::list, the STL doubly linked list
using namespace std;  // lets us write list and cout instead of std::list, std::cout

int main(){
    list<int> l = {1, 2, 3, 3, 40, 30, 40, 30, 3, 3, 4, 5};   // a list filled from a brace list
    // remove a value from the list: remove(3) deletes EVERY node holding 3. O(n).
    l.remove(3);
    // Range-for: `val` takes each element's value in turn, from first to last.
    for(int val: l){
        cout << val << " ";
    }
    cout << endl;   // end the line
    cout << endl;   // and print one empty line as a separator

    // sort the list: ascending (small to large). O(n log n).
    l.sort();
    for(int val: l){                // print it
        cout << val << " ";
    }
    cout << endl;
    cout << endl;

    // sort in descending order: `greater<int>()` is a ready-made comparison
    // object meaning "a comes first if a > b", so large values go first.
    l.sort(greater<int>());
    for(int val: l){                // print it
        cout << val << " ";
    }
    cout << endl;
    cout << endl;

    // reverse the order: 40 40 30 30 5 4 2 1 -> 1 2 4 5 30 30 40 40.
    // (Not printed, and the sort just below would re-order the list anyway.)
    l.reverse();


    // unique() removes a value when it EQUALS THE ONE RIGHT BEFORE IT, keeping
    // the first of each run. So it only removes all duplicates when equal values
    // are next to each other - which is why the list is sorted first.
    // (On an unsorted list like 3 1 3, nothing would be removed.)
    l.sort();       // 1 2 4 5 30 30 40 40
    l.unique();     // 1 2 4 5 30 40
    for(int val: l){
        cout << val << " ";
    }
    cout << endl;
    cout << endl;

    // reverse the list: the nodes' order is flipped in place. O(n).
    l.reverse();    // 40 30 5 4 2 1
    for(int val: l){
        cout << val << " ";
    }
    cout << endl;
    cout << endl;

    // is a list empty? empty() returns true/false. This first call throws the
    // answer away (it does nothing useful); the next line prints it.
    l.empty();
    // `cout` prints a bool as 1 (true) or 0 (false) - here 0, the list has 6 values.
    cout << "Is the list l empty? " << l.empty() << endl;

    return 0;   // 0 = the program ended normally
}
