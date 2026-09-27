/*

This is about set in C++ STL.

Set is a container that stores unique elements in a specific order.

It has O(logn) time complexity for insertion, deletion and search.

It maintains a balanced BST and so the operations are O(logn).

It uses BST internally. Uses inorder traversal to print elements in sorted order.

(Unique means a value inserted twice is kept only once. The "specific order"
is ascending by default. Internally it is a self-balancing BST - a red-black
tree - so it never degenerates into a chain.)

Input "6  5 1 4 1 3 5" prints, all on one line (there is no endl between parts):
    1 3 4 5 5 4 3 1 4 is present

*/

#include<iostream>      // cin and cout
#include <vector>       // vector
#include <queue>        // not used here
#include <algorithm>    // reverse
#include <string>       // not used here
#include <map>          // not used here
#include <set>          // set

using namespace std;    // write set, vector, cout ... without std::

int main(){
    set<int> s;                 // an empty set of ints
    int n;
    cin >> n;                   // how many values to read
    // One pass reads one value and inserts it; duplicates are silently ignored.
    for(int i=0; i<n; i++){
        int x;
        cin >> x;
        s.insert(x);            // O(log n)
    }

    // print the set in ascending order without duplicates
    // An iterator `it` points at one element; *it is that element.
    // s.begin() is the smallest, s.end() is one step PAST the largest (stop there).
    // auto lets the compiler work out the long iterator type (set<int>::iterator).
    for(auto it = s.begin(); it != s.end(); it++){
        cout << *it << " ";
    }

    // A set always keeps its elements in ascending order; it cannot be
    // rearranged. To print it backwards you can walk it with s.rbegin() and
    // s.rend(), or (as below) copy it into a vector and reverse the vector.
    // (A set declared as set<int, greater<int>> keeps descending order instead.)

    vector<int> v;
    for(auto it = s.begin(); it != s.end(); it++){
        v.push_back(*it);       // copy each value, smallest first
    }
    reverse(v.begin(), v.end());    // now largest first

    // Range-for: x takes each value of v in turn.
    for(int x : v){
        cout << x << " ";
    }

    // Is an element present?
    // Is 4 present in the set?

    // count(x) is 1 if x is in the set, 0 if not (a set never holds duplicates).
    if(s.count(4)){
        cout << "4 is present" << endl;
    } else {
        cout << "4 is not present" << endl;
    }

    return 0;                   // program finished normally
}
