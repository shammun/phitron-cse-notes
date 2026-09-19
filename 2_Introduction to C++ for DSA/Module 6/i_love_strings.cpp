/*

K. I Love strings
time limit per test: 2 seconds
memory limit per test: 64 megabytes

Given two strings S and T. Print a new string that contains the following:

- The first letter of the string S followed by the first letter of the string T.
- The second letter of the string S followed by the second letter of the string T.
- and so on...

In other words, the new string should be ( S0 + T0 + S1 + T1 + .... ).

Note: If the length of S is greater than the length of T then you have to add the rest of
S letters at the end of the new string and vice versa.

Input
The first line contains a number N (1 <= N <= 50) the number of test cases.

Each of the N following lines contains two string S, T (1 <= |S|, |T| <= 50) consists of
lower and upper English letters.

Output
For each test case, print the required string.

Example

input
2
ipAsu ccsit
ey gpt

output
icpcAssiut
egypt

*/

#include <iostream>
#include <string>
using namespace std;

int main() {
    int n;
    cin >> n;

    while(n--) {
        string s, t;
        cin >> s >> t;

        /* The answer grows one letter at a time. In C this needed a fixed
           char array big enough for both words; a C++ string grows by itself,
           so `answer += c` is all that is needed. */
        string answer = "";

        /* Walk as far as the longer word. Each step adds the letter of S and
           the letter of T, but only if that word still has one at position i.
           That single guard is what handles words of different lengths. */
        int longer = s.size();
        if((int)t.size() > longer) {
            longer = t.size();
        }

        for(int i = 0; i < longer; i++) {
            if(i < (int)s.size()) {
                answer += s[i];
            }
            if(i < (int)t.size()) {
                answer += t[i];
            }
        }

        cout << answer << endl;
    }

    return 0;
}
