/*

G. Conversion
time limit per test: 2 seconds
memory limit per test: 64 megabytes

Given a string S. Print the origin string after replacing the following:

- Replace every comma character ',' with a space character.
- Replace every capital character in S with its respective small character and Vice Versa.

Input
Only one line contains a string S (1 <= |S| <= 10^5) where |S| is the length of the string
and it consists of lower and upper English letters and comma character ','.

Output
Print the string after the conversion.

Example

input
happy,NewYear,enjoy

output
HAPPY nEWyEAR ENJOY

*/

/* Idea: go through the string one character at a time and print a converted
   character right away: ',' becomes ' ', small letters become capital, and
   capital letters become small. The string itself is never changed. */

# include <stdio.h> // standard input/output library: scanf and printf

int main() { // program execution starts here
    /* |S| can be 100000, so 100005 slots hold the string and the '\0' at its end.
       The string never contains a space, so scanf with %s reads all of it.
       (%s stops reading at the first space or newline.) */
    char s[100005];
    scanf("%s", s); // read the whole string; s (array name) is already an address, so no & is needed

    /* One pass looks at one character s[i]. i starts at 0 and the loop stops
       when it reaches the '\0' that marks the end of the string. */
    for(int i = 0; s[i] != '\0'; i++){
        if(s[i] == ','){ // a comma: print a space in its place
            printf(" ");
        }
        /* Letters are numbers underneath: 'a' is 32 more than 'A'.
           So subtracting 32 makes a small letter capital, and adding 32 does the opposite.
           (In the ASCII table 'A' = 65 and 'a' = 97; 97 - 65 = 32.)
           s[i] >= 'a' && s[i] <= 'z' is true only for small letters,
           because 'a'..'z' are consecutive numbers (97..122). */
        else if(s[i] >= 'a' && s[i] <= 'z'){
            printf("%c", s[i] - 32); // e.g. 'h' (104) - 32 = 72 = 'H'; %c prints the number as a character
        }
        else { // not a comma and not small, so (by the problem rules) it is a capital letter
            printf("%c", s[i] + 32); // e.g. 'N' (78) + 32 = 110 = 'n'
        }
    }

    return 0; // program ended successfully
}
