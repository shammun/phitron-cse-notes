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

#include <iostream>
#include <string>
using namespace std;

bool matching_location(string s1, string s2, int index){
    if(index + s2.size() > s1.size()){
        return false;
    }
    for(int i=0; i<s2.size(); i++){
        if(s1[index + i] != s2[i]){
            return false;
        }
    }
    return true;
}

int main(){
    int tests;
    cin >> tests;
    string results[1000];

    for(int i=0; i<tests; i++){
        string s1, s2;
        cin >> s1 >> s2;

        string result = "";

        int position = 0;
        while(position < s1.size()){
            if(matching_location(s1, s2, position)){
                result += '#';
                position += s2.size();
            } else{
                result += s1[position];
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