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

#include <iostream>
#include <string>
#include <set>

using namespace std;

int main(){
    string S;
    cin >> S;

    set<char> unique_letters;

    for(char c : S){
        unique_letters.insert(c);
    }

    for(char c : unique_letters){
        cout << c;
    }

    cout << endl;

    return 0;
}