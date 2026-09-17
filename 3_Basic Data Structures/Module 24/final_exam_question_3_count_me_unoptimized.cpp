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
        
        vector<pair<string, int>> word_freq;
        stringstream ss(S);
        string word;
        
        string result = "";
        int count_max = 0;
        
        while(ss >> word){
            bool flag = false;
            for(auto it=word_freq.begin(); it!=word_freq.end(); it++){
                if(it->first == word){
                    it->second = it->second + 1;
                    
                    if(it->second > count_max){
                        result = it->first;
                        count_max = it->second;
                    }
                    flag = true;
                    break;
                }
            }
            if(flag == false){
                word_freq.push_back({word, 1});
            }
        }

        
        for(auto it=word_freq.begin(); it!=word_freq.end(); it++){
            if(it->second > count_max){
                result = it->first;
                count_max = it->second;
            }
        }
        
        cout << result << " " << count_max << endl;
    }

    return 0;
}
