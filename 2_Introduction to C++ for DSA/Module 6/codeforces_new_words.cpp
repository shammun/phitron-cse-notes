/*

New Words
time limit per test: 1 second
memory limit per test: 256 megabytes
Given a string S
. Print number of times that "EGYPT" word can be formed from S's characters.

Note: Case of the letters doesn't matter. For example: "Egypt", "egypt" and "eGyPt" are the same.

Input
Only one line contains a string S(1≤|S|≤10^6) where |S| is the length of the string and it consists of lowercase and uppercase English letters.

Output
Print the answer required above.

Examples
Input
EgYpTaz
Output
1

Input
pemigdbeigyypetet
Output
2

*/

/*
IDEA
To build one "egypt" we need one e, one g, one y, one p and one t.
Count how many of each of these letters S has (ignoring upper/lower case).
The letter we have the fewest of runs out first, so it decides the answer.
Trace for "pemigdbeigyypetet": e=4, g=2, y=2, p=2, t=2 -> smallest is 2 -> answer 2.
*/

#include <iostream> // Gives us cin (read from keyboard) and cout (print to screen)
#include <string>   // Gives us std::string, a text type that knows its own length
using namespace std; // Lets us write cin, cout, string instead of std::cin, std::cout, std::string

int main(){
    string s; // the input text
    cin >> s; // read one word (no spaces in this problem); a string grows to any length, even 10^6

    // Case does not matter, so first make every letter lowercase.
    // A capital letter minus 'A' is its place in the alphabet (0..25);
    // adding 'a' moves it to the same place among the small letters.
    // e.g. 'G' (71) - 'A' (65) + 'a' (97) = 103 = 'g'.
    // s.size() is the number of characters, so i visits every index 0..size-1.
    for(int i=0; i<s.size(); i++){
        if (s[i] >= 'A' && s[i] <= 'Z'){ // true only for capital letters
            s[i] = char(s[i]) - 'A' + 'a'; // s[i] can be changed in place, a string is editable
        } // end of the capital-letter check
    } // end of the lowercase loop

    // Count only the five letters that EGYPT needs
    int cnt_e = 0, cnt_g = 0, cnt_y = 0, cnt_p = 0, cnt_t = 0; // five counters, all start at 0

    // One pass looks at one character and adds 1 to the matching counter (if any).
    for(int i=0; i<s.size(); i++){
        if(s[i] == 'e'){
            cnt_e++; // ++ adds 1
        } else if(s[i] == 'g'){
            cnt_g++;
        } else if(s[i] == 'y'){
            cnt_y++;
        } else if(s[i] == 'p'){
            cnt_p++;
        } else if(s[i] == 't'){
            cnt_t++;
        } // any other letter is ignored
    } // end of the counting loop

    // Each EGYPT uses one of each letter, so the rarest of the five letters
    // decides how many words can be made: the answer is the smallest count.
    // Start with cnt_e as the "smallest so far", then let each other counter replace it if smaller.
    int ans = cnt_e;
    if(cnt_g < ans){
        ans = cnt_g; // g is rarer so far
    }
    if(cnt_y < ans){
        ans = cnt_y; // y is rarer so far
    }
    if(cnt_p < ans){
        ans = cnt_p; // p is rarer so far
    }
    if(cnt_t < ans){
        ans = cnt_t; // t is rarer so far
    }

    cout << ans << endl; // print the answer, endl = newline

    return 0; // the program ended successfully
} // end of main
