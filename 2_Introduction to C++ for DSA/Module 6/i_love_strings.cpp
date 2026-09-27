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

#include <iostream> // Gives us cin (read from keyboard) and cout (print to screen)
#include <string> // Gives us std::string with size(), [] and +=
using namespace std; // Lets us write cin, cout, string instead of std::cin, std::cout, std::string

int main() {
    int n; // number of test cases
    cin >> n; // read it

    // while(n--) runs exactly n times: it checks n (non-zero = true), then subtracts 1.
    // With n = 2: checks 2 (run), checks 1 (run), checks 0 (stop).
    while(n--) {
        string s, t; // the two words of this test case
        cin >> s >> t; // cin >> reads one word each, the space between them is skipped

        /* The answer grows one letter at a time. In C this needed a fixed
           char array big enough for both words; a C++ string grows by itself,
           so `answer += c` is all that is needed. */
        string answer = ""; // start empty

        /* Walk as far as the longer word. Each step adds the letter of S and
           the letter of T, but only if that word still has one at position i.
           That single guard is what handles words of different lengths. */
        int longer = s.size(); // assume s is the longer word
        // s.size() returns an unsigned number; (int) turns it into a normal int
        // so the comparison with the int "longer" is between two ints.
        if((int)t.size() > longer) {
            longer = t.size(); // t is longer after all
        }

        // One pass handles position i of both words.
        // Trace for s = "ey", t = "gpt": i=0 -> "eg", i=1 -> "egyp", i=2 (only t has one) -> "egypt".
        for(int i = 0; i < longer; i++) {
            if(i < (int)s.size()) { // does s still have a letter at position i?
                answer += s[i]; // add it
            }
            if(i < (int)t.size()) { // does t still have a letter at position i?
                answer += t[i]; // add it
            }
        } // end of the for loop

        cout << answer << endl; // print this test's answer, endl = newline
    } // end of the while loop over test cases

    return 0; // the program ended successfully
} // end of main
