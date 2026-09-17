/*

Palindrome
time limit per test: 1 second
memory limit per test: 256 megabytes
Given a string S. Determine whether S is Palindrome or not

Note: A string is said to be a palindrome if the reverse of the string is same as the string. For example, "abba" is palindrome, but "abbc" is not palindrome.

Input
Only one line contains a string S (1 ≤ |S| ≤ 1000) where |S| is the length of the string and it consists of lowercase letters only.

Output
Print "YES" if the string is palindrome, otherwise print "NO".

Examples:

Input
abba
Output
YES

Input
icpcassiut
Output
NO

Input
mam
Output
YES

*/

#include <iostream> // Include the input/output stream library for using cout
#include <string>   // Include the string library for std::string
#include <algorithm> // Include the algorithm library for reverse function
using namespace std; // Use the standard namespace to avoid writing "std::" repeatedly

int main(){
    string s;
    cin >> s;

    string rev_s = s;
    reverse(rev_s.begin(), rev_s.end());

    if (s == rev_s){
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }

    return 0; // Indicate that the program ended successfully
}