/*

A. Way Too Long Words   (Codeforces 71A)
time limit per test: 1 second
memory limit per test: 256 megabytes

Sometimes words are too long to write down. Every word longer than 10
characters is replaced by a short version: the first letter, then the number
of letters between the first and the last one, then the last letter. So
"localization" becomes "l10n". Words of 10 characters or fewer are written
as they are.

Input
The first line contains a number n (1 <= n <= 100), the number of words.
Each of the next n lines contains one word of 1 to 100 lowercase letters.

Output
Print n lines: the word itself if it is not too long, otherwise its short
version.

Example

input
4
word
localization
internationalization
pneumonoultramicroscopicsilicovolcanoconiosis

output
word
l10n
i18n
p43s

*/

#include <iostream>
#include <string>
using namespace std;

int main() {
    int n;
    cin >> n;

    for(int i = 0; i < n; i++) {
        string s;
        cin >> s;

        /* A C++ string knows its own length, so there is no walk to the '\0'
           and no strlen call: s.size() is the answer already. */
        int len = s.size();

        if(len > 10) {
            /* s[0] is the first letter, s[len - 1] the last one, and the
               letters in between are len - 2 of them. */
            cout << s[0] << len - 2 << s[len - 1] << endl;
        } else {
            cout << s << endl;
        }
    }

    return 0;
}
