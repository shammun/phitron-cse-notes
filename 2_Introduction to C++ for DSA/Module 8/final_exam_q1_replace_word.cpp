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
#include <string>   // std::string
using namespace std; // write cin/cout/string instead of std::cin/...

// Does s2 appear in s1 starting exactly at position `index`?
// Compare s2 letter by letter with the part of s1 that starts at index.
bool matching_location(string s1, string s2, int index){
    // Not enough letters left in s1 for a full copy of s2
    if(index + s2.size() > s1.size()){
        return false;
    }
    for(int i=0; i<s2.size(); i++){
        if(s1[index + i] != s2[i]){
            return false; // one different letter: no match here
        }
    }
    return true; // every letter matched
}

int main(){
    int tests;
    cin >> tests;
    string results[1000]; // T is at most 1000: keep every answer, print them at the end

    for(int i=0; i<tests; i++){
        string s1, s2;
        cin >> s1 >> s2; // S and X have no spaces, so cin >> reads each one

        // Build the answer in a new string, walking through s1 once
        string result = "";

        int position = 0;
        while(position < s1.size()){
            if(matching_location(s1, s2, position)){
                result += '#';          // the whole copy of X becomes one '#'
                position += s2.size();  // jump past the letters just replaced
            } else{
                result += s1[position]; // an ordinary letter is kept as it is
                position++;
            }
        }
        results[i] = result;
    }

    for(int i=0; i<tests; i++){
        cout << results[i] << endl;
    }

    return 0;
}