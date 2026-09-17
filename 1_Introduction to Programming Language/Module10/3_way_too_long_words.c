/*

F. Way Too Long Words
time limit per test: 1 second
memory limit per test: 256 megabytes

Given a string S. Print the origin string if it's not too long otherwise, print the special abbreviation.

Note: The string is called too long, if its length is strictly more than 10 characters.
If the string is too long then you have to print the string in the following manner:

- Print the first character in the string.
- Print number of characters between the first and the last characters.
- Print the last character in the string.

For example: "localization" will be "l10n", and "internationalization" will be "i18n".

Input
The first line contains a number T (1 <= T <= 100) number of test cases.
Each of the T following lines contains a string S (1 <= |S| <= 100) where |S| is the length of the string.

It's guaranteed that S contains only lowercase Latin letters.

Output
For each test case, print the result string.

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

# include <stdio.h>

int main() {
    int t;
    scanf("%d", &t);

    for(int test = 0; test < t; test++){
        /* |S| can be 100, so 105 slots hold the word and the '\0' at its end. */
        char s[105];
        scanf("%s", s);

        /* The length is counted by hand: walk until the '\0' that closes the string. */
        int length = 0;
        for(int i = 0; s[i] != '\0'; i++){
            length++;
        }

        if(length > 10){
            /* First character, then how many characters are hidden between
               the first and the last one, then the last character. */
            printf("%c%d%c\n", s[0], length - 2, s[length - 1]);
        }
        else {
            printf("%s\n", s);
        }
    }

    return 0;
}
