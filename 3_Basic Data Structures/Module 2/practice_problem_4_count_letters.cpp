/*

Count Letters
time limit per test: 2 seconds
memory limit per test: 64 megabytes
Given a string S. Determine how many times does each letter occurred in S.

Input
Only one line contains the string S (1 ≤ |S| ≤ 107) where |S| is the length of the 
string and it consists of only lowercase English letters.

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

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int main() {
    string s;
    cin >> s;

    // Create a vector of 26 with all values initialized to 0 
    // to store the frequency of each letter
    vector<int> freq(26, 0);

    for(char ch: s){
        freq[ch - 'a']++;
    }

    // print the frequency of each letter in ascending order
    // if the frequency is greater than 0
    for(int i=0; i<26; i++){
        if(freq[i] > 0){
            char ch = 'a' + i;
            cout << ch << " : " << freq[i] << endl;
        }
    }
    
    return 0;
}