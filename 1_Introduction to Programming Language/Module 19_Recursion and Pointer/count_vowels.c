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
    /* Why not scanf?

       scanf("%s", s) reads one WORD. It stops at the first space, tab or
       newline. For the input "Data Structure Lab" it would put only "Data"
       into s, and the answer would be 2 instead of 6. This problem says the
       string may contain spaces, so we need something that reads the whole
       line. That is what fgets does.

       What fgets does

       fgets ("f" for file, "gets" for get string) reads characters and
       copies them into s until one of these happens:
         - it reads the Enter key ('\n') at the end of the line, or
         - s is full (see the 205 below), or
         - the input runs out.
       Spaces are ordinary characters to fgets, so it keeps going past them.
       Then it puts a '\0' after the last character, so s is a normal C
       string that ends in '\0', just like one scanf("%s") would give you.

       The full line: fgets(s, 205, stdin);

         s      Where to put the text: the char array declared just below.
                As with scanf("%s", s), there is no & in front of s: an
                array's name already gives the address of its first element.

         205    The size of s. fgets reads at most 205 - 1 = 204 characters,
                which leaves one slot for the '\0'. This is the safety limit:
                even if someone types 1000 characters, fgets stops before the
                end of the array, so it never writes past s. (scanf("%s") has
                no such limit unless you write one, e.g. "%204s".)
                Why 205? The string has up to 200 characters, fgets also
                keeps the '\n' from the Enter key (1 more), and the '\0'
                needs a slot (1 more). That makes 202; 205 gives a little
                room to spare.

         stdin  WHERE to read from. fgets can read from any open file, so
                you must tell it which one. stdin ("standard input") is the
                name C gives the keyboard, or whatever input is fed to the
                program, such as a judge's test file. It is the same place
                scanf always reads from; scanf just doesn't make you say so.
                stdin is set up for you by <stdio.h>, so it needs no
                declaration. Its partners are stdout (where printf writes)
                and stderr (for error messages).

       The '\n' that fgets keeps

       After typing "Data Structure Lab" and pressing Enter, s holds
           D a t a   S t r u c t u r e   L a b \n \0
       The '\n' is not a vowel, so countVowels just skips it and the count
       is still right. In other programs, where the newline would get in the
       way (for example when comparing two strings), you remove it first. */
    char s[205];
    fgets(s, 205, stdin);

    printf("%d\n", countVowels(s, 0));

    return 0;
}
