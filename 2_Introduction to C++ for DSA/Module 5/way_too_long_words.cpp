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

#include <iostream> // cin (read input) and cout (print output)
#include <string>   // the C++ string type
using namespace std; // write cin/cout/string instead of std::cin/std::cout/std::string

int main() { // program starts here
    int n;     // number of words
    cin >> n;  // read n

    // One pass = read one word and print its answer line
    for(int i = 0; i < n; i++) {
        string s;  // the current word (a fresh empty string every pass)
        cin >> s;  // cin >> reads one word, stopping at the space/newline

        /* A C++ string knows its own length, so there is no walk to the '\0'
           and no strlen call: s.size() is the answer already. */
        int len = s.size(); // number of letters in the word

        if(len > 10) { // too long: needs the short form
            /* s[0] is the first letter, s[len - 1] the last one, and the
               letters in between are len - 2 of them. */
            // "localization": len 12 -> 'l', 12-2 = 10, 'n' -> prints l10n
            // cout prints the char, then the number, then the char, all glued together.
            cout << s[0] << len - 2 << s[len - 1] << endl;
        } else {
            cout << s << endl; // 10 letters or fewer: print the word as it is
        }
    }

    return 0; // program ended normally
}
