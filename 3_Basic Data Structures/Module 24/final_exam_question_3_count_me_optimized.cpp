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

#include <bits/stdc++.h>

using namespace std;



int main()
{
    // Write your code here
    int T;
    cin >> T;
    cin.ignore();
    
    while(T--){
        string S;
        getline(cin, S);
        stringstream ss(S);
        
        map<string, int> word_freq;
        
        string result;
        int count_max = 0;
        string word;
        
        while(ss >> word){
            word_freq[word] = word_freq[word] + 1;
            if(word_freq[word] > count_max){
                result = word; 
                count_max = word_freq[word];
            }
        }
        
        cout << result << " " << count_max << endl;
    }

    return 0;
}
