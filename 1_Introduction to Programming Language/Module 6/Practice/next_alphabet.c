#include<stdio.h>

// Given a character, print the next alphabet
//
// The letters 'a'..'z' are 26 numbers in a row in the ASCII table, so
// "the next letter" is just "add 1". The only snag is 'z': the next one
// must wrap round to 'a', not become '{' (the character after 'z').
//
// The wrap-around trick in three moves:
//   ch - 'a'        turns the letter into its place, 0 for 'a' ... 25 for 'z'
//   + 1, then % 26  steps one place on; 25 + 1 = 26 and 26 % 26 = 0, so 'z'
//                   comes back to place 0
//   + 'a'           turns the place back into a letter
// For 'c': 2 + 1 = 3, 3 % 26 = 3, 3 + 'a' = 'd'.

// First way to do it: the same idea, but the result is first stored in an
// int and then cast back to char for printing.

// int main() {
//     char ch;
//     scanf("%c", &ch);
//     int ch_val;
    
//     if (ch >= 'a' && ch <= 'z') {
//         ch_val = ((ch - 'a' + 1) % 26) + 'a';
//         printf("%c", (char)ch_val);
//     }

//     return 0;
// }

// Second way to do it: print the result straight away. %c prints the
// character whose number it is given, so no cast is needed.

int main() {
    char ch;
    scanf("%c", &ch);
    
    // Only small letters are handled; anything else prints nothing.
    if (ch >= 'a' && ch <= 'z') {
        printf("%c", ((ch - 'a' + 1) % 26) + 'a');
    }

    return 0;
}
