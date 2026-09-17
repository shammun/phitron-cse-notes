/*

Problem Statement

Write a program to determine if a given string contains the word "Jessica." If the word is present in the string, the program should output "YES," otherwise it should output "NO."

NOTE: You need to find only "Jessica"; not "jessica" or "JeSsica" or any other form. Words are separated by spaces.

Input Format

Input will contain a string S containing names. There is a space in between two names.
Constraints

1 <= |S| <= 1000; Here |S| means the length of the string.
Output Format

Output YES or NO according to the question.
Sample Input 0

Rahat Rifat Sakib Asif Sifat Jessica Ratul Munna
Sample Output 0

YES
Sample Input 1

Rahat Rifat Sakib Asif Sifat Ratul Munna
Sample Output 1

NO
Sample Input 2

Rahat Rifat Sakib Asif jessica Sifat Ratul Munna
Sample Output 2

NO
Sample Input 3

Rahat Rifat Sakib Asif Jessicarvai Sifat Ratul Munna
Sample Output 3

NO

*/

#include <iostream>
#include <string>
using namespace std;

int main(){
    string s;
    getline(cin, s);

    bool flag = false;
    string word = "";

    for(int i=0; i<s.size(); i++){
        if(s[i] != ' '){
            word += s[i];
        } else{
            if(word == "Jessica"){
                flag = true;
                break;
            }
            word = "";
        }
    }

    if(word == "Jessica"){
        flag = true;
    }

    if(flag){
        cout << "YES" << endl;
    } else{
        cout << "NO" << endl;
    }

    return 0;
}