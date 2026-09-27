/*

Replace Word
time limit per test: 1 second
memory limit per test: 256 megabytes
Given a string S. Print S after replacing every sub-string that is equal to "EGYPT" with space.

Input
Only one line contains a string S (1≤|S|≤10^3) where |S| is the length of the string and it consists of only uppercase English letters.

Output
Print the result as required above.

Examples
Input
BRITISHEGYPTGHANA
Output
BRITISH GHANA

Input
ITALYKOREAEGYPTEGYPTALGERIAEGYPTZ
Output
ITALYKOREA  ALGERIA Z

*/

#include <iostream> // Gives us cin (read from keyboard) and cout (print to screen)
#include <string>   // Gives us std::string with length(), substr(), += and ==
using namespace std; // Lets us write cin, cout, string instead of std::cin, std::cout, std::string

int main(){
    string s; // the input line (only capital letters, no spaces)
    cin >> s; // read it

    // Build the answer in a new string, one piece at a time
    string result = ""; // starts empty; += adds characters to its end
    string word = "EGYPT"; // the word to look for
    int target_length = 5; // length of "EGYPT"
    int i = 0;             // current position in s

    // A while loop, not a for loop, because i moves by different amounts:
    // 5 steps after a match, 1 step otherwise.
    // Trace for "BREGYPTA": B, R copied; at i=2 "EGYPT" matches -> ' ', i jumps to 7; A copied -> "BR A".
    while(i < s.length()){ // s.length() is the same as s.size(): number of characters
        // s.substr(i, 5) is the 5 letters starting at i. The first check makes
        // sure there are still 5 letters left before we look.
        // && stops early: if the first part is false, substr is not even called.
        if (i + target_length <= s.length() && s.substr(i, target_length) == word){
            result += ' ';       // the whole word becomes one space
            i += target_length;  // jump over the 5 letters just replaced
        } else {
            result += s[i];      // an ordinary letter is copied as it is
            i++;                 // move to the next letter
        }
    } // end of the while loop: every letter of s has been handled

    cout << result << endl; // print the finished string, endl = newline

    return 0; // Indicate that the program ended successfully
} // end of main

