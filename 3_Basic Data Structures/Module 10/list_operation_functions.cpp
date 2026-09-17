#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <list>
using namespace std; 

int main(){
    list<int> l = {1, 2, 3, 3, 40, 30, 40, 30, 3, 3, 4, 5}; 
    // remoove a value from the list
    l.remove(3);
    for(int val: l){
        cout << val << " ";
    }
    cout << endl;
    cout << endl;

    // sort the list
    l.sort();
    for(int val: l){
        cout << val << " ";
    }
    cout << endl;
    cout << endl;

    // sort in descending order
    l.sort(greater<int>());
    for(int val: l){
        cout << val << " ";
    }
    cout << endl;
    cout << endl;

    // reverse the order
    l.reverse();


    // unique function removes duplicates from the list and keeps only the first occurrence of each element.
    // it only works on sorted lists
    l.sort();
    l.unique();
    for(int val: l){
        cout << val << " ";
    }
    cout << endl;
    cout << endl;

    // reverse the list
    l.reverse();
    for(int val: l){
        cout << val << " ";
    }
    cout << endl;
    cout << endl;

    // is a list empty?
    l.empty();
    cout << "Is the list l empty? " << l.empty() << endl;
    
    return 0;
}