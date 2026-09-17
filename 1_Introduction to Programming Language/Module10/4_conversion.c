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

# include <stdio.h>

int main() {
    /* |S| can be 100000, so 100005 slots hold the string and the '\0' at its end.
       The string never contains a space, so scanf with %s reads all of it. */
    char s[100005];
    scanf("%s", s);

    for(int i = 0; s[i] != '\0'; i++){
        if(s[i] == ','){
            printf(" ");
        }
        /* Letters are numbers underneath: 'a' is 32 more than 'A'.
           So subtracting 32 makes a small letter capital, and adding 32 does the opposite. */
        else if(s[i] >= 'a' && s[i] <= 'z'){
            printf("%c", s[i] - 32);
        }
        else {
            printf("%c", s[i] + 32);
        }
    }

    return 0;
}
