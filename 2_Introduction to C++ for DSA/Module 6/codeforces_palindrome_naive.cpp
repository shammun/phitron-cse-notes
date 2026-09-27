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
using namespace std; // Use the standard namespace to avoid writing "std::" repeatedly

// Two pointers: left starts at the first letter, right at the last.
// They move towards each other, comparing one pair of letters per step.
// With "mam": m == m, then left and right meet in the middle -> palindrome.
bool isPalindrome(string s){
    int left = 0;
    int right = s.size() - 1; // s.size() is the length, so the last index is size - 1

    while(left < right){ // stop when they meet or cross: every pair has been checked
        if(s[left] != s[right]){
            return false; // one mismatch is enough
        }
        left++;
        right--;
    }

    return true; // no mismatch found
}

int main(){
    string s;
    cin >> s;

    // No reverse() and no extra copy of the string - just the pairwise check
    if(isPalindrome(s)){
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
}