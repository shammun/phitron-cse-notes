/*

Problem Statement

In a quiet town, a group of linguists is studying the structure of words. They are particularly interested in 
analyzing words to find all the unique letters and arranging them in alphabetical order to understand their 
composition better.

Given a string S consisting of lowercase English letters, your task is to extract all unique letters, sort them 
alphabetically and print the result.

Input Format
A single string S , consisting only of lowercase English letters.

Constraints
1≤∣S∣≤10^6

Output Format
Print a single string containing all unique letters from S, sorted in alphabetical order.

Sample Input 0
hello

Sample Output 0
ehlo

Explanation 0
- The unique letters in "hello" are h, e, l, o.
= Sorting them alphabetically gives "ehlo".

Sample Input 1
banana

Sample Output 1
abn

*/

// Solution idea: a set (Basic Data Structures course) does both jobs at once.
// It keeps only one copy of each value, and it keeps its values sorted. So
// pour every letter into a set<char> and print the set from start to end.

#include <iostream>
#include <string>
#include <set>

using namespace std;

int main(){
    string S;
    cin >> S;

    set<char> unique_letters;

    // Inserting a letter that is already there changes nothing,
    // so "hello" leaves the set holding e, h, l, o.
    for(char c : S){
        unique_letters.insert(c);
    }

    // Walking a set visits its values in increasing order, i.e. a..z.
    for(char c : unique_letters){
        cout << c;
    }

    cout << endl;

    // Each insert is O(log 26), so the whole thing is O(|S|).
    return 0;
}
