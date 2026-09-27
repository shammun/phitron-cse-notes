/*

Problem Statement

You will be given two strings S and X. You need to replace all X from string S with a '#' sign.

Input Format

First line will contain T, the number of test cases.
Next T lines will contain a line with S and X.

Constraints

1. 1 <= T <= 1000
2. 1 <= |S|, |X| <= 1000
3. |X| <= |S|

Output Format

- For each test cases output the modified string S.

Sample Input 0

2
rahimisagoodguy good
canyoutellmewhereicanfindheriwillbegreatefultoyouifyoutellmetheanswer you

Sample Output 0

rahimisa#guy
can#tellmewhereicanfindheriwillbegreatefulto#if#tellmetheanswer

*/

#include <iostream> // cin and cout
#include <string>   // std::string (text that can grow), .size(), += and [] on strings
using namespace std; // write cin/cout/string instead of std::cin/...

// Does s2 appear in s1 starting exactly at position `index`?
// Compare s2 letter by letter with the part of s1 that starts at index.
// Parameters: s1 = the big string S, s2 = the word X, index = where to test in s1.
// Returns true for a full match, false otherwise.
// Example: s1 = "rahimisagoodguy", s2 = "good", index = 8 -> s1[8..11] = "good" -> true.
bool matching_location(string s1, string s2, int index){
    // Not enough letters left in s1 for a full copy of s2
    // (.size() gives the number of characters in a string)
    if(index + s2.size() > s1.size()){
        return false;
    }
    // One pass compares letter i of s2 with the letter i places after index in s1
    for(int i=0; i<s2.size(); i++){
        if(s1[index + i] != s2[i]){ // s[k] is the k-th character (counting from 0)
            return false; // one different letter: no match here
        }
    }
    return true; // every letter matched
}

int main(){ // Program execution starts here
    int tests; // number of test cases T
    cin >> tests; // read T
    string results[1000]; // T is at most 1000: keep every answer, print them at the end

    // One pass of this loop solves one test case
    for(int i=0; i<tests; i++){
        string s1, s2; // s1 = S, s2 = X
        cin >> s1 >> s2; // S and X have no spaces, so cin >> reads each one

        // Build the answer in a new string, walking through s1 once
        string result = ""; // starts empty and grows letter by letter

        int position = 0; // where we are in s1 right now
        // Each pass handles the text starting at `position`, until we pass the end of s1
        while(position < s1.size()){
            if(matching_location(s1, s2, position)){ // a copy of X starts here
                result += '#';          // the whole copy of X becomes one '#'
                position += s2.size();  // jump past the letters just replaced
            } else{
                result += s1[position]; // an ordinary letter is kept as it is
                position++; // move on by one letter
            }
        }
        // Trace with S = "abab", X = "ab": pos 0 match -> "#", pos 2 match -> "##", pos 4 = end.
        results[i] = result; // remember this test case's answer
    }

    // Print all answers, one per line
    for(int i=0; i<tests; i++){
        cout << results[i] << endl; // endl = newline (and flush)
    }

    return 0; // the program ended successfully
}
