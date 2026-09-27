/*

This file contains many examples of map in C++ STL.

map in STL is very similar to a dictionary in python.

In map, key and values are stored in key-value pair.

Insertion complexity is O(logn) and search complexity is O(logn).

Reading or printing one element (looking up its key) is O(logn).
Walking through all n elements with an iterator is O(n) in total.

A map keeps its keys SORTED (it is a balanced BST inside), and every key
appears at most once. Each element is a pair: .first is the key, .second is
the value.

*/


#include<iostream>      // cout, endl
#include <vector>       // not used here
#include <queue>        // not used here
#include <algorithm>    // not used here
#include <string>       // string
#include <map>          // map

using namespace std;    // write map, cout ... without std::

int main(){
    // key, value pair
    map<int, int> mp; // key, value pair, Here key is int and value is int
    // key and values can be of any type
    mp[1] = 10; // 1 is key and 10 is value
    mp[2] = 20; // 2 is key and 20 is value
    mp[3] = 30; // 3 is key and 30 is value
    mp[4] = 40; // 4 is key and 40 is value
    mp[5] = 50; // 5 is key and 50 is value

    // print the map with keys and values

    // first way
    // `it` is an iterator: it points at one key-value pair. mp.begin() is the
    // smallest key; mp.end() is one step past the last (stop there).
    // auto lets the compiler work out the long type (map<int,int>::iterator).
    for(auto it = mp.begin(); it != mp.end(); it++){
        cout << it->first << " " << it->second << endl; // it->first is key and it->second is value
    }

    // second way
    // Range-for over the map: `pair` is each element in key order.
    for(auto &pair : mp){ // &pair to avoid copying -- this creates a refrence to each pair
        cout << pair.first << " " << pair.second << endl; // pair.first is key and pair.second is value
    }

    // map with key of string and value of int
    map<string, int> mp2;
    mp2["abc"] = 10;        // key "abc", value 10
    mp2["def"] = 20;
    mp2["ghi"] = 30;
    mp2["jkl"] = 40;
    mp2["mno"] = 50;

    cout << mp2["abc"] << endl;     // 10

    // if a key is not present in the map, and we want to access it,
    // it will give 0
    // if there is no key in the map, it will create a new key with value 0
    cout << mp2["xyz"] << endl;     // 0, and "xyz" is now stored in mp2

    // How to understand if a key is present in the map or not?
    // count(key) is 1 if the key exists and 0 if not, and unlike [] it does
    // NOT add the key.
    if(mp2.count("sjhgnkjdng")){
        cout << "Key is present" << endl;
    } else {
        cout << "Key is not present" << endl;   // this one prints
    }

    return 0;               // program finished normally
}
