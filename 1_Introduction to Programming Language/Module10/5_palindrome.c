/*

I. Palindrome
time limit per test: 1 second
memory limit per test: 256 megabytes

Given a string S. Determine whether S is Palindrome or not

Note: A string is said to be a palindrome if the reverse of the string is same as the string.
For example, "abba" is palindrome, but "abbc" is not palindrome.

Input
Only one line contains a string S (1 <= |S| <= 1000) where |S| is the length of the string
and it consists of lowercase letters only.

Output
Print "YES" if the string is palindrome, otherwise print "NO".

Examples

input
abba

output
YES


input
icpcassiut

output
NO


input
mam

output
YES

*/

# include <stdio.h>

int main() {
    /* |S| can be 1000, so 1005 slots hold the letters and the '\0' at the end. */
    char s[1005];
    scanf("%s", s);

    /* Count the length by walking the array until the closing '\0'. */
    int length = 0;
    for(int i = 0; s[i] != '\0'; i++){
        length++;
    }

    /* Same idea as the palindrome array, but with characters:
       compare the first letter with the last, the second with the second last,
       and stop at the middle. One mismatch is enough to answer NO. */
    int is_palindrome = 1;

    for(int i = 0; i < length / 2; i++){
        if(s[i] != s[length - 1 - i]){
            is_palindrome = 0;
            break;
        }
    }

    if(is_palindrome == 1){
        printf("YES");
    }
    else {
        printf("NO");
    }

    return 0;
}
