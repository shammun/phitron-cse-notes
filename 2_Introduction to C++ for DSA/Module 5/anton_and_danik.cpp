/*

A. Anton and Danik   (Codeforces 734A)
time limit per test: 1 second
memory limit per test: 256 megabytes

Anton and Danik played n games of chess, and every game was won by one of
them. The result is given as a string of n letters: 'A' where Anton won and
'D' where Danik won. Tell who won more games.

Input
The first line contains a number n (1 <= n <= 100000), the number of games.
The second line contains a string of n letters, each 'A' or 'D'.

Output
Print "Anton" if Anton won more games, "Danik" if Danik won more games, and
"Friendship" if they won the same number of games.

Examples

input
6
ADAAAA

output
Anton

input
7
DDDAADA

output
Danik

input
6
DADADA

output
Friendship

*/

#include <iostream> // cin (read input) and cout (print output)
#include <string>   // the C++ string type: a text that knows its own length and grows by itself
using namespace std; // write cin/cout/string instead of std::cin/std::cout/std::string

int main() { // program starts here
    int n;     // number of games
    cin >> n;  // read n from the first line

    string s;  // will hold the results, e.g. "ADAAAA"
    cin >> s;  // cin >> reads one word (it stops at a space/newline); the results have no spaces

    /* One walk over the string is enough. Danik's games are the ones Anton
       did not win, so only one counter is really needed, but two make the
       comparison below easy to read. */
    int anton = 0, danik = 0; // wins counted so far for each player
    // Pass i looks at game i; s[i] is the i-th character (the first one is s[0])
    for(int i = 0; i < n; i++) {
        if(s[i] == 'A') { // 'A' in single quotes is one character; == compares it
            anton++;      // Anton won this game
        } else {
            danik++;      // otherwise the letter is 'D': Danik won
        }
    }
    // Trace "ADAAAA": anton = 5, danik = 1 -> "Anton"

    if(anton > danik) {                  // Anton won more games
        cout << "Anton" << endl;
    } else if(danik > anton) {           // Danik won more games
        cout << "Danik" << endl;
    } else {                             // neither is bigger, so they are equal
        cout << "Friendship" << endl;
    }

    return 0; // program ended normally
}
