/*

STL Pair

A pair<A, B> holds exactly two values, possibly of different types, glued
together: .first is the first value and .second is the second. It is handy
for things that come in twos (x and y, a name and a score, a node and its
level) and it is what we will put into queues and vectors later.

With input "2  5 6  7 8" the program prints
  2 3
  2 3
  Hello 3
  1 2
  3 4
and then reads the two pairs (5,6) and (7,8) into v2 (it does not print them).

*/

#include <iostream>     // cin and cout
#include <utility>      // pair and make_pair
#include <string>       // string
#include <vector>       // vector
using namespace std;    // write pair, cout, ... without std::

int main(){
    pair<int, int> p1;              // a pair of two ints; both start at 0
    p1 = make_pair(2, 3);           // make_pair(a, b) builds a pair from two values
    cout << p1.first << " " << p1.second << endl;   // prints "2 3" (endl = newline + flush)

    // we can also do the following
    pair<int, int> p2;
    p2 = {2, 3};                    // brace syntax (C++11): same as make_pair(2, 3)
    cout << p2.first << " " << p2.second << endl;   // "2 3"

    pair<string, int> p3;           // the two parts may have different types
    p3 = {"Hello", 3};
    cout << p3.first << " " << p3.second << endl;   // "Hello 3"

    // vector of pairs
    vector<pair<int, int>> v;       // a growable array whose items are pairs
    v.push_back(make_pair(1, 2));   // push_back adds an item at the end
    v.push_back(make_pair(3, 4));
    // i is the index of the pair being printed; v.size() is how many pairs there are.
    for(int i=0; i<v.size(); i++){
        cout << v[i].first << " " << v[i].second << endl;   // "1 2" then "3 4"
    }

    // Take input from user to create vector of pairs of integers of the size n
    int n;
    cin >> n;                       // how many pairs to read
    // A new name (v2): `v` already exists above, and declaring it twice
    // would not compile. v2(n) makes n pairs of (0, 0) ready to be filled.
    vector<pair<int, int>> v2(n);
    // Each pass reads two numbers straight into the i-th pair's two parts.
    for(int i=0; i<n; i++){
        cin >> v2[i].first >> v2[i].second;
    }

    return 0;                       // program finished normally
}
