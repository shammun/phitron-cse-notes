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

#include <iostream>
#include <string>
using namespace std;

int main() {
    int n;
    cin >> n;

    string s;
    cin >> s;

    /* One walk over the string is enough. Danik's games are the ones Anton
       did not win, so only one counter is really needed, but two make the
       comparison below easy to read. */
    int anton = 0, danik = 0;
    for(int i = 0; i < n; i++) {
        if(s[i] == 'A') {
            anton++;
        } else {
            danik++;
        }
    }

    if(anton > danik) {
        cout << "Anton" << endl;
    } else if(danik > anton) {
        cout << "Danik" << endl;
    } else {
        cout << "Friendship" << endl;
    }

    return 0;
}
