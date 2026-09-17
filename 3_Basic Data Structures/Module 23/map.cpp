/*

This file contains many examples of map in C++ STL.

map in STL is very similar to a dictionary in python.

In map, key and values are stored in key-value pair.

Insertion complexity is O(logn) and search complexity is O(logn).

Print complexity for one element is O(logn).
Complexity for printing n values is O(nlogn).



*/


#include<iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string>
#include <map>

using namespace std;

int main(){
    // key, value pair
    map<int, int> mp; // key, value pair, Here key is int and value is int
    // key and values can be of any type
    mp[1] = 10; // 1 is key and 10 is value
    mp[2] = 20; // 2 is key and 20 is value
    mp[3] = 30; // 3 is key and 30 is value
    mp[4] = 40;
    mp[5] = 50;

    // print the map with keys and values

    // first way
    for(auto it = mp.begin(); it != mp.end(); it++){
        cout << it->first << " " << it->second << endl; // it->first is key and it->second is value
    }

    // second way
    for(auto &pair : mp){ // &pair to avoid copying -- this creates a refrence to each pair
        cout << pair.first << " " << pair.second << endl; // pair.first is key and pair.second is value
    }

    // map with key of string and value of int
    map<string, int> mp2;
    mp2["abc"] = 10;
    mp2["def"] = 20;
    mp2["ghi"] = 30;
    mp2["jkl"] = 40;
    mp2["mno"] = 50;

    cout << mp2["abc"] << endl;
    
    // if a key is not present in the map, and we want to access it,
    // it will give 0
    // if there is no key in the map, it will create a new key with value 0
    cout << mp2["xyz"] << endl;

    // How to understand if a key is present in the map or not?
    if(mp2.count("sjhgnkjdng")){
        cout << "Key is present" << endl;
    } else {
        cout << "Key is not present" << endl;
    }

    return 0;
}