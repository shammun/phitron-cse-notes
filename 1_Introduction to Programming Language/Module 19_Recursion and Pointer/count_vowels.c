/*
I. Count Vowels
time limit per test 1 second
memory limit per test 64 megabytes

Given a string S, print how many vowels it contains. The vowels are
a, e, i, o, u, in small letters or in capital letters. The string may
contain spaces, so read the whole line.

Note: Solve this problem using recursion.

Input
One line containing the string S (1 <= |S| <= 200).

Output
Print one number: how many vowels S contains.

Example
Input
Data Structure Lab
Output
6

Note
The vowels are a, a, u, u, e and a.
*/

#include <stdio.h>

/* Counts the vowels of s starting at index i.

   The job "count the vowels of the whole string" contains a smaller copy of
   itself: "count the vowels from the next character onward". So the function
   answers for position i by asking itself about position i + 1 and then adding
   1 if the character sitting at i is a vowel.

   Base case: when s[i] is the '\0' that ends the string there is nothing left
   to count, so the answer is 0 and the calls start coming back. */
int countVowels(char s[], int i) {
    if(s[i] == '\0') {
        return 0;
    }

    /* the answer for the rest of the string */
    int rest = countVowels(s, i + 1);

    char c = s[i];
    if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' ||
       c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U') {
        return rest + 1;
    }
    return rest;
}

int main() {
    /* 200 characters, one slot for the newline that fgets keeps, and one for
       the '\0'. scanf("%s") would stop at the first space, so it cannot be
       used here. */
    char s[205];
    fgets(s, 205, stdin);

    printf("%d\n", countVowels(s, 0));

    return 0;
}
