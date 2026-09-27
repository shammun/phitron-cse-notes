/*

Count Letters
time limit per test: 2 seconds
memory limit per test: 64 megabytes
Given a string S. Determine how many times does each letter occurred in S.

Input
Only one line contains the string S (1 ≤ |S| ≤ 107) where |S| is the length of the
string and it consists of only lowercase English letters.
(107 here means 10^7; the superscript was lost when copying.)

Output
For each character that appears in S, print a single line that contains the following
format: "X : Y" where X is the letter and Y is the number of times that letter X
occurred in S.

Note: you must print letters in ascending order.

Examples

Input
aaabbc
Output
a : 3
b : 2
c : 1

Input
regff
Output
e : 1
f : 2
g : 1
r : 1



*/

#include <iostream>  // cin and cout
#include <vector>    // vector
#include <algorithm> // not needed here, kept from the template
#include <string>    // string: a sequence of characters
using namespace std; // lets us drop the std:: prefix

int main() { // the program starts running here
    string s; // will hold the input word
    cin >> s; // read one word (cin >> stops at the first space or newline)

    // Create a vector of 26 with all values initialized to 0
    // to store the frequency of each letter
    // vector<int> freq(26, 0) means: 26 slots, each starting at 0.
    vector<int> freq(26, 0);

    // Use the vector as a frequency array: slot 0 is 'a', slot 1 is 'b', ...
    // ch - 'a' turns a letter into its slot number ('c' - 'a' = 2).
    // (Characters are stored as numbers: 'a' is 97, 'c' is 99, so 99 - 97 = 2.)
    // With aaabbc: freq[0] becomes 3, freq[1] becomes 2, freq[2] becomes 1.
    // for(char ch: s) is a range-for loop: ch takes each character of s in turn.
    for(char ch: s){
        freq[ch - 'a']++; // add 1 to this letter's counter
    }

    // print the frequency of each letter in ascending order
    // if the frequency is greater than 0
    // Going i = 0..25 visits the letters a..z in order, which gives the
    // required ascending order for free (no sorting needed).
    for(int i=0; i<26; i++){
        if(freq[i] > 0){ // skip letters that never appeared
            char ch = 'a' + i;   // turn the slot number back into its letter
            cout << ch << " : " << freq[i] << endl; // e.g. "a : 3"
        }
    }

    return 0; // program finished successfully
}
// Time O(|S| + 26) = O(|S|); extra space O(26) = O(1).
