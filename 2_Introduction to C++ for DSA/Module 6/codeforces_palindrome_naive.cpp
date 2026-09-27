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

#include <iostream> // Gives us cin (read from keyboard) and cout (print to screen)
#include <string>   // Gives us std::string, a text type that knows its own length
using namespace std; // Lets us write cin, cout, string instead of std::cin, std::cout, std::string

// Two pointers: left starts at the first letter, right at the last.
// They move towards each other, comparing one pair of letters per step.
// With "mam": m == m, then left and right meet in the middle -> palindrome.
// With "abbc": a != c on the first step -> not a palindrome.
// Parameter: s = the word. Returns: true if s reads the same backwards.
bool isPalindrome(string s){
    int left = 0; // index of the first letter
    int right = s.size() - 1; // s.size() is the length, so the last index is size - 1

    while(left < right){ // stop when they meet or cross: every pair has been checked
        if(s[left] != s[right]){ // the mirror letters differ
            return false; // one mismatch is enough
        }
        left++; // step inwards from the left
        right--; // step inwards from the right
    } // end of the while loop

    return true; // no mismatch found
} // end of isPalindrome

int main(){
    string s; // the word to test
    cin >> s; // read it (lowercase letters, no spaces)

    // No reverse() and no extra copy of the string - just the pairwise check
    if(isPalindrome(s)){
        cout << "YES" << endl; // endl = newline
    } else {
        cout << "NO" << endl;
    }
} // end of main (main may leave out return 0; C++ then returns 0 automatically)
