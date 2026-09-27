/*

https://www.hackerrank.com/contests/final-exam-a-introduction-to-algorithms-a-batch-06/challenges/pile-of-word-37-3

Pile of Word

Problem Statement

Pile of Word is a word formed by rearranging the letters of another word, using all the original 
letters exactly once. In other words, it involves creating a new word by rearranging the characters 
of a given word. It is possible that after rearranging it looks like the original one.

You will be given two strings S1 and S2. You need to determine if the strings are Pile of Word of each 
other.

Input Format

First line will contain T, the number of test cases.
Each line of the test case will contain S1 and S2 separated by a space. The string will contain Enlish 
small alphabets only.

Constraints
1. 1 <= T <= 10^3
2. 1 <= |S1|, |S2| <= 10^4. Here || means the length of string.

Output Format
- Ouptut YES if the strings are Pile of Word to each other, NO otherwise.

Sample Input 0
4
eat tea
madam madam
ball all
ant tan

Sample Output 0
YES
YES
NO
YES

*/

// Solution idea: two words are rearrangements of each other exactly when they
// contain the same letters the same number of times. Sorting both words puts
// their letters in one fixed order, so after sorting they must be identical.
// ("tea" and "eat" both sort to "aet".)

#include <iostream>     // cin, cout, endl
#include <string>       // string
#include <algorithm>    // sort

using namespace std;    // no std:: prefix

// s1 and s2 are taken by value (copies), so sorting them here does not
// disturb the caller's strings.
bool pileOfWord(string s1, string s2){
    // sort(begin, end) puts the characters in increasing (alphabetical) order.
    sort(s1.begin(), s1.end());
    sort(s2.begin(), s2.end());

    // Different lengths can never use "all the letters exactly once".
    // ("ball" has 4 letters, "all" only 3.)
    if(s1.length() != s2.length()){
        return false;
    }

    // Compare the sorted words letter by letter; one mismatch is enough to say no.
    // (s1 == s2 would do the same comparison in one step.)
    for(int i = 0; i < s1.length(); i++){
        if(s1[i] != s2[i]){
            return false;
        }
    }

    return true;       // every letter matched
}

int main(){
    int t;             // number of test cases
    cin >> t;

    while(t--){        // one pass per test case
        string s1, s2;
        cin >> s1 >> s2;   // the two words sit on one line, split by a space

        if(pileOfWord(s1, s2)){
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }

    // Sorting dominates: O(L log L) per test case, L = word length.
    return 0;
}
