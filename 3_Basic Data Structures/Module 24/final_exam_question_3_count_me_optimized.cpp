/*


Problem Statement

You will be given a sentence S that contains words with lowercase and uppercase
English alphabets separated by spaces. You need to determine which word occurs the
most times and also provide the count of that word.

Note: If there are multiple words that occur the most, print the first word that
reaches the maximum count before others.

Input Format
- First line will contain T, the number of test cases.
- Each test case will contain the sentence .

Constraints
1. 1 <= T <= 10^3
2. 1 <= |S| <= 10^4, Here |S| means the length of S.

Output Format
- Output the word and the count that occurs the most.

Sample Input 0
1
Ratul loves to play football when he gets time but Ratul is not a good player so his teacher asked Ratul if he can play with him so that Ratul can progress

Sample Output 0
Ratul 4

Sample Input 1
2
ratul piyush fohad shuvo rafi piyush fohad ratul
jony jony yes papa eating sugar no papa telling lies no papa open your mouth ha ha ha

Sample Output 1
piyush 2
papa 3

*/

#include <bits/stdc++.h>    // GCC shortcut: includes the whole standard library (string, map, sstream, ...)

using namespace std;        // write string, map, cout ... without std::



/*
 * Idea: count every word with a map<string,int> (word -> how many times seen)
 * and keep the best answer while counting.
 *
 * The tie rule ("the first word to REACH the top count wins") is handled by
 * updating the answer only when a count becomes strictly bigger than the
 * best so far. A later word that only ties the best never replaces it.
 *
 * "ratul piyush fohad shuvo rafi piyush fohad ratul": piyush is the first
 * word to reach 2; fohad and ratul reach 2 later, so the answer is piyush 2.
 */
int main()
{
    int T;
    cin >> T;               // number of sentences
    // cin >> T leaves the end of that line in the input. ignore() skips it,
    // otherwise the first getline would read an empty sentence.
    cin.ignore();

    // while(T--) runs the body T times; one pass = one sentence.
    while(T--){
        // Read the whole sentence (with its spaces) in one go...
        string S;
        getline(cin, S);    // getline reads up to the end of the line, spaces included
        // ...and let a stringstream split it into words with >>.
        stringstream ss(S);

        // A new, empty map for every sentence.
        map<string, int> word_freq;

        string result;       // the winning word so far
        int count_max = 0;   // its count
        string word;

        // `ss >> word` pulls out the next word and is false when none are
        // left, which ends the loop. One pass = one word.
        while(ss >> word){
            // One more sighting of this word (a new word starts at 0).
            word_freq[word] = word_freq[word] + 1;
            // Strictly greater: this word is now ahead of every other word.
            if(word_freq[word] > count_max){
                result = word;                  // new leader
                count_max = word_freq[word];    // and its count
            }
        }

        cout << result << " " << count_max << endl;   // endl = newline + flush
    }

    return 0;               // program finished normally
}
