/*

You have already solved a problem where you had to find minimum and maximum value among 3 integer numbers.

Now you will be given 3 strings you have to find lexicographically minimum and maximum string among them.

Input Format

The first line will contain 3 strings, S1, S2, S3 containing only lowercase letters.

Constraints

1 <= |S1|, |S2|, |S3| <= 1000

Output Format

In the first line print the lexicographically minimum string.

In the second line print the lexicographically maximum string.

Sample Input 0

abc def ghi
Sample Output 0

abc
ghi

*/



#include <stdio.h>      /* scanf and printf */
#include <string.h>     /* strcmp (compare two strings) and strcpy (copy a string) */
#include <math.h>       /* not used here (template leftover) */
#include <stdlib.h>     /* not used here (template leftover) */

/* main: program entry point; return 0 = success. */
int main() {

    /* The idea: the same as finding the min and max of three numbers, but
     * strings are compared with strcmp and copied with strcpy (a C string
     * cannot be assigned with =).
     *   strcmp(a, b) < 0  means a comes before b in dictionary order,
     *   strcmp(a, b) > 0  means a comes after b.
     * Start with S1 as both the smallest and the largest so far, then let
     * S2 and S3 challenge each one. */

    /* Each char array holds up to 1000 letters plus the '\0' that marks the end
     * of a C string, hence size 1001. */
    char S1[1001], S2[1001], S3[1001], min[1001], max[1001];
    /* %s reads one word (stops at a space). No & here: an array name already
     * gives the address of its first character. */
    scanf("%s %s %s", S1, S2, S3);

    /* S1 is the first candidate for both answers.
     * (The comma operator runs the two calls one after the other.) */
    strcpy(min, S1), strcpy(max, S1);

    /* Does S2 or S3 come earlier than the current minimum? */
    if(strcmp(S2, min) < 0){
        strcpy(min, S2);        /* S2 is the new minimum */
    }
    if(strcmp(S3, min) < 0){
        strcpy(min, S3);        /* S3 is the new minimum */
    }
    /* Does S2 or S3 come later than the current maximum? */
    if(strcmp(S2, max) > 0){
        strcpy(max, S2);
    }
    if(strcmp(S3, max) > 0){
        strcpy(max, S3);
    }
    /* Sample abc def ghi: min stays abc, max becomes def then ghi. */

    printf("%s\n", min);        /* %s prints a C string */
    printf("%s\n", max);

    return 0;
}
