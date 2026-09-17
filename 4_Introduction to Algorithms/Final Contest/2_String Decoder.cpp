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

#include <iostream>
#include <string>

using namespace std;

string decoder(string s){
    string ans = "";

    for(int i=0; i<s.size(); i+=2){
        int freq = s[i+1] - '0';
        for(int j=0; j<freq; j++){
            ans += s[i];
        }
    }
    
    return ans;
}

int main(){
    int T;
    cin >> T;
    
    while(T--){
        string S;
        cin >> S;
        cout << decoder(S) << endl;
    }

    return 0;
}