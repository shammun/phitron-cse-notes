/*

C. Compare
time limit per test: 1 second
memory limit per test: 256 megabytes

Given two strings X and Y. Print the smallest lexicographical one.

Note: Lexicographical is the way of ordering the words based on the alphabetical order
of their component letters.

Input
Only one line contains two strings X, Y (1 <= |X|, |Y| <= 20) consists of lowercase English letters.

Output
Print the smallest lexicographical string.

Note: If both of X and Y are equal, print any of them.

Example

input
acm
acpc

output
acm

*/

/* Idea: "lexicographically smaller" means "comes first in a dictionary".
   The library function strcmp answers exactly that question, so we ask it
   and print whichever string comes first. */

# include <stdio.h>  // standard input/output library: scanf and printf
# include <string.h> // string library: gives us strcmp (and strlen, strcpy, strcat, ...)

int main() { // program execution starts here
    /* Each string has at most 20 letters, so 25 slots hold the letters and the '\0'.
       ('\0' = the null character that marks the end of every C string.) */
    char x[25]; // string X
    char y[25]; // string Y

    scanf("%s %s", x, y); // read two words separated by whitespace; array names are addresses, so no &

    /* strcmp compares the two strings letter by letter, the way a dictionary does.
       It gives a negative number when x comes first, 0 when they are equal
       and a positive number when y comes first.
       Trace: "acm" vs "acpc": 'a'=='a', 'c'=='c', then 'm' < 'p' -> negative -> print "acm".
       If one string is the start of the other ("ab" vs "abc"), the shorter one comes first,
       because its '\0' (value 0) is smaller than any letter.
       "<= 0" also covers the equal case, where printing either one is allowed. */
    if(strcmp(x, y) <= 0){
        printf("%s", x); // x comes first (or both are equal)
    }
    else { // strcmp was positive: y comes first
        printf("%s", y);
    }

    return 0; // program ended successfully
}
