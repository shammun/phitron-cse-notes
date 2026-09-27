/*

Count Me

Problem Statement

You will be given a sentence  that contains words with lowercase and uppercase English alphabets separated by spaces. You need to determine which word occurs the most times and also provide the count of that word.

Note: If there are multiple words that occur the most, print the first word that reaches the maximum count before others.

Input Format

First line will contain , the number of test cases.
Each test case will contain the sentence .
Constraints

, Here  means the length of .
Output Format

Output the word and the count that occurs the most.
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
 * Idea: the same counting as the optimized version, but the counts are kept
 * in a vector of (word, count) pairs instead of a map. For every word we
 * search the vector from the start; that search is what makes this version
 * slow (O(words x distinct words)), and the map version fixes it.
 *
 * The answer is updated only when a count becomes strictly bigger than the
 * best so far, so the first word to reach the top count wins a tie.
 */
int main()
{
    int T;
    cin >> T;               // number of sentences
    // Skip the rest of the line after T, so getline reads the sentence.
    cin.ignore();           // (cin >> T leaves the newline behind; ignore() throws that one character away)

    // while(T--) runs the body T times; one pass = one sentence.
    while(T--){
        string S;
        getline(cin, S);    // the whole line, spaces included

        // (word, count) pairs in the order the words first appeared.
        vector<pair<string, int>> word_freq;
        stringstream ss(S); // lets >> read the sentence word by word
        string word;

        string result = "";  // the winning word so far
        int count_max = 0;    // its count

        // One pass = one word; `ss >> word` is false when no words are left.
        while(ss >> word){
            // flag becomes true if the word is already in the vector.
            bool flag = false;
            // Linear search: `it` points at one (word, count) pair;
            // it->first is the word, it->second its count.
            for(auto it=word_freq.begin(); it!=word_freq.end(); it++){
                if(it->first == word){
                    // Seen before: one more sighting.
                    it->second = it->second + 1;

                    // Strictly greater: this word takes the lead.
                    if(it->second > count_max){
                        result = it->first;
                        count_max = it->second;
                    }
                    flag = true;
                    break;      // found it: stop searching
                }
            }
            // First sighting: add it with count 1. (The best is not updated
            // here, so a count of 1 never becomes the answer inside the loop.)
            if(flag == false){
                word_freq.push_back({word, 1});     // {a, b} builds the pair
            }
        }


        // Safety net for a sentence where every word appears once:
        // count_max is still 0, so the first word (count 1) becomes the answer.
        // Otherwise no count is bigger than count_max and nothing changes.
        for(auto it=word_freq.begin(); it!=word_freq.end(); it++){
            if(it->second > count_max){
                result = it->first;
                count_max = it->second;
            }
        }

        cout << result << " " << count_max << endl;   // endl = newline + flush
    }

    return 0;               // program finished normally
}
