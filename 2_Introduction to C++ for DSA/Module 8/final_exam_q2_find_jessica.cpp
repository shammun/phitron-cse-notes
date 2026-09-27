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

#include <iostream> // cin and cout
#include <string>   // std::string and getline
using namespace std; // write cin/cout/string instead of std::cin/...

int main(){ // Program execution starts here
    string s; // the whole line of names
    // cin >> s would stop at the first space and read only "Rahat".
    getline(cin, s); // the names are separated by spaces, so read the whole line

    bool flag = false; // becomes true once the exact word "Jessica" is seen (bool holds true/false)
    string word = "";  // the word being built, one letter at a time

    // Cut the line into words by hand: letters are added to `word`; a space
    // means the word is complete, so check it and start a new one.
    // Comparing whole words matters: "Jessicarvai" contains Jessica but is
    // not the word Jessica, and == on strings is case-sensitive, so
    // "jessica" does not count either.
    // i walks over every character of s; s.size() is the length of the line.
    for(int i=0; i<s.size(); i++){
        if(s[i] != ' '){ // a letter: part of the current word
            word += s[i]; // append it to the word
        } else{ // a space: the current word is finished
            if(word == "Jessica"){ // exact, case-sensitive comparison of the whole word
                flag = true;
                break; // found it, no need to read further (break leaves the loop at once)
            }
            word = ""; // start collecting the next word
        }
    }

    // The last word has no space after it, so the loop never checked it
    // (e.g. "Rahat Jessica" ends with word = "Jessica" still unchecked)
    if(word == "Jessica"){
        flag = true;
    }

    // Print the answer
    if(flag){
        cout << "YES" << endl;
    } else{
        cout << "NO" << endl;
    }

    return 0; // the program ended successfully
}
