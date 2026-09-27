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

#include <iostream> // Include the input/output stream library for using cout
#include <string>   // Include the string library for std::string
using namespace std; // Use the standard namespace to avoid writing "std::" repeatedly

int main(){
    string s;
    cin >> s;

    // Build the answer in a new string, one piece at a time
    string result = "";
    string word = "EGYPT";
    int target_length = 5; // length of "EGYPT"
    int i = 0;             // current position in s

    // A while loop, not a for loop, because i moves by different amounts:
    // 5 steps after a match, 1 step otherwise.
    while(i < s.length()){
        // s.substr(i, 5) is the 5 letters starting at i. The first check makes
        // sure there are still 5 letters left before we look.
        if (i + target_length <= s.length() && s.substr(i, target_length) == word){
            result += ' ';       // the whole word becomes one space
            i += target_length;  // jump over the 5 letters just replaced
        } else {
            result += s[i];      // an ordinary letter is copied as it is
            i++;
        }
    }

    cout << result << endl;

    return 0; // Indicate that the program ended successfully
}

