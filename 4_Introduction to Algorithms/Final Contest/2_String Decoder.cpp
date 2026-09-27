/*

String Decoder

Problem Statament

A special String Decoder that can decode strings encoded with a unique pattern. The encoding rule is as 
follows:

- The string consists of lowercase English letters ('a'–'z').
- Each letter is always followed by a single-digit number (0-9), which represents how many times that character 
should appear in the decoded string.
- If a character is followed by 0, it is completely removed from the decoded string.

For example:

- "a2b3c1" is decoded as "aabbbc".
- "x1y0z2" is decoded as "xzz" (since 'y' appears 0 times, it is removed).

Your task is to implement the magical string decoder and decode a given encoded string.

Note - It is guaranteed that the resultant string will not be empty.

Input Format

- The first line contains an integer T (1<=T<=10^5), the number of test cases.
- Each of the next T lines contains a single string S (2 <= |S| <= 10^6), representing an encoded string.

Constraints
1 <= T <= 10^5
2 <= |S| <= 10^6

- Summation of |S| over all test cases doesn't exceed 10^6

Output Format

For each test case, print the decoded string on a new line.

Sample Input 0
2
a2b3c1
x1y0z2

Sample Output 0
aabbbc
xzz

*/

// Solution idea: the encoded string always comes in pairs - a letter, then one
// digit. So walk it two characters at a time: s[i] is the letter, s[i+1] is how
// many copies of it to write.

#include <iostream>     // cin, cout, endl
#include <string>       // string

using namespace std;    // no std:: prefix

// Returns the decoded form of s. s is taken by value (a copy).
string decoder(string s){
    string ans = "";    // the decoded text, built up piece by piece

    // i jumps by 2, so it always lands on a letter, never on a digit.
    // (s.size() is unsigned; comparing with int i only gives a warning.)
    for(int i=0; i<s.size(); i+=2){
        // A digit character is not its number: '3' is stored as 51. Subtracting
        // '0' (48) turns the character '3' into the number 3.
        int freq = s[i+1] - '0';
        // Append the letter freq times. A 0 means the loop never runs, which is
        // exactly "remove this letter".
        for(int j=0; j<freq; j++){
            ans += s[i];    // += on a string appends one character
        }
    }

    // "a2b3c1" -> "aa" + "bbb" + "c" = "aabbbc".
    return ans;
}

int main(){
    int T;              // number of test cases
    cin >> T;

    while(T--){         // one encoded string per test
        string S;
        cin >> S;       // reads one word
        cout << decoder(S) << endl;
    }

    // Linear in the length of the decoded string.
    return 0;
}
