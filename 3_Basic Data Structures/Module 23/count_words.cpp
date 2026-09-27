/*

Count how many times each word appears in a line

Read one whole line of text, split it into words, and count every word with
a map<string, int>. A map keeps its keys sorted, so the words come out in
alphabetical order.

  input : the cat and the dog and the bird
  output: and 2
          bird 1
          cat 1
          dog 1
          the 3

*/

#include<iostream>      // cin and cout
#include <vector>       // not used here
#include <queue>        // not used here
#include <algorithm>    // not used here
#include <string>       // string, getline
#include <sstream>      // stringstream
#include <map>          // map

using namespace std;    // write string, map, cout ... without std::

int main(){
    string s;
    getline(cin, s);        // read the WHOLE line, spaces included (cin >> would stop at the first space)
    stringstream ss(s);     // wrap the line in a stream, so >> can pull words out of it one by one
    string word;            // holds one word at a time
    // Switched off: this would just print every word on its own line.
    /*
    while(ss >> word){
        cout << word << endl;
    }
    */

    map<string, int> mp;    // word -> how many times it has been seen
    // `ss >> word` reads the next word (skipping spaces) and is false when no
    // words are left, which ends the loop. One pass = one word.
    while(ss >> word){
        mp[word]++;         // a new word starts at 0 (map[] creates it), then +1
    }

    // Walk the map in key order. it->first is the word, it->second its count.
    // auto = let the compiler work out the iterator type.
    for(auto it = mp.begin(); it!=mp.end(); it++){
        cout << it->first << " " << it->second << endl;
    }

    return 0;               // program finished normally
}
