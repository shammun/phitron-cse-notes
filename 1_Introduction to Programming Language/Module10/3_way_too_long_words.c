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

/* Idea: for each word, find its length. If the length is more than 10,
   print first letter + (length - 2) + last letter; otherwise print the word as it is. */

# include <stdio.h> // standard input/output library: scanf and printf

int main() { // program execution starts here
    int t; // t = number of test cases (words)
    scanf("%d", &t); // read t; &t is the address where scanf stores it

    /* One pass of this loop handles one word completely (read, measure, print).
       test counts the words already handled: 0, 1, ..., t-1. */
    for(int test = 0; test < t; test++){
        /* |S| can be 100, so 105 slots hold the word and the '\0' at its end.
           A C string is a char array that ends with the special character '\0'
           (the "null character", value 0). It marks where the text stops. */
        char s[105];
        scanf("%s", s); // %s reads one word (stops at a space/newline) and adds '\0'; no & because an array name already is an address

        /* The length is counted by hand: walk until the '\0' that closes the string.
           Each pass sees one real character and adds 1 to length. */
        int length = 0; // number of characters counted so far
        for(int i = 0; s[i] != '\0'; i++){ // keep going while the current character is not the end marker
            length++; // one more character counted
        }

        if(length > 10){ // "too long" means strictly more than 10 characters
            /* First character, then how many characters are hidden between
               the first and the last one, then the last character.
               %c prints one character, %d prints an int.
               length - 2 = all characters except the first and the last.
               s[length - 1] is the last character (indexes start at 0).
               Trace: "localization" has length 12 -> 'l', 10, 'n' -> "l10n". */
            printf("%c%d%c\n", s[0], length - 2, s[length - 1]);
        }
        else { // 10 characters or fewer: print the word unchanged
            printf("%s\n", s); // %s prints characters until '\0'; \n moves to a new line
        }
    }

    return 0; // program ended successfully
}
