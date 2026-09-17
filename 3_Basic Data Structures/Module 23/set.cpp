/*

This is about set in C++ STL.

Set is a container that stores unique elements in a specific order.

It has O(logn) time complexity for insertion, deletion and search.

It maintains a balanced BST and so the operations are O(logn).

It uses BST internally. Uses inorder traversal to print elements in sorted order.

*/

#include<iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string>
#include <map>
#include <set>

using namespace std;

int main(){
    set<int> s;
    int n;
    cin >> n;
    for(int i=0; i<n; i++){
        int x;
        cin >> x;
        s.insert(x);
    }

    // print the set in ascending order without duplicates
    for(auto it = s.begin(); it != s.end(); it++){
        cout << *it << " ";
    }

    // We can't reverse the order of elements in set
    // If we really have to, we can put it in vector and print it in reverse order

    vector<int> v;
    for(auto it = s.begin(); it != s.end(); it++){
        v.push_back(*it);
    }
    reverse(v.begin(), v.end());
    
    for(int x : v){
        cout << x << " ";
    }

    // Is an element present?
    // Is 4 present in the set?

    if(s.count(4)){
        cout << "4 is present" << endl;
    } else {
        cout << "4 is not present" << endl;
    }

    return 0;
}