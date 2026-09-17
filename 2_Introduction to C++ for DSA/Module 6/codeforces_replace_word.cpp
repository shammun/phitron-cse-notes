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

    string result = "";
    string word = "EGYPT";
    int target_length = 5;
    int i = 0;

    while(i < s.length()){
        if (i + target_length <= s.length() && s.substr(i, target_length) == word){
            result += ' ';
            i += target_length;
        } else {
            result += s[i];
            i++;
        }
    }

    cout << result << endl;

    return 0; // Indicate that the program ended successfully
}

