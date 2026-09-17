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

#include <iostream> // Include the input/output stream library for using cout
#include <string>   // Include the string library for std::string
using namespace std; // Use the standard namespace to avoid writing "std::" repeatedly

int main(){
    string s;
    cin >> s;

    // Convert the string to lowercase
    for(int i=0; i<s.size(); i++){
        if (s[i] >= 'A' && s[i] <= 'Z'){
            s[i] = char(s[i]) - 'A' + 'a';
        }
    }

    int cnt_e = 0, cnt_g = 0, cnt_y = 0, cnt_p = 0, cnt_t = 0;

    for(int i=0; i<s.size(); i++){
        if(s[i] == 'e'){
            cnt_e++;
        } else if(s[i] == 'g'){
            cnt_g++;
        } else if(s[i] == 'y'){
            cnt_y++;
        } else if(s[i] == 'p'){
            cnt_p++;
        } else if(s[i] == 't'){
            cnt_t++;
        }
    }

    int ans = cnt_e;
    if(cnt_g < ans){
        ans = cnt_g;
    }
    if(cnt_y < ans){
        ans = cnt_y;
    }
    if(cnt_p < ans){
        ans = cnt_p;
    }
    if(cnt_t < ans){
        ans = cnt_t;
    }

    cout << ans << endl;

    return 0;
}