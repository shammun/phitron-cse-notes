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

/* Idea: exactly like min/max of three numbers, except that strings are
   compared with strcmp and copied with strcpy (not with < and =). */

#include <stdio.h>  // standard input/output library: scanf and printf
#include <string.h> // string library: strcmp (compare) and strcpy (copy)
#include <math.h>   // math functions (part of the HackerRank template; not used here)
#include <stdlib.h> // general utilities (template; not used here)

int main() { // program execution starts here

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */

    /* Each string can have 1000 letters, plus one slot for the '\0' that
       ends it. min and max hold copies of the best strings found so far. */
    char S1[1001], S2[1001], S3[1001], min[1001], max[1001];
    scanf("%s %s %s", S1, S2, S3); // read three words; array names are addresses, so no &

    /* The same idea as min/max of three numbers: start with the first one as
       both the smallest and the largest. Strings cannot be copied with =,
       so strcpy(destination, source) copies the letters.
       The comma between the two calls is the comma operator: it simply runs
       the left call, then the right call, like two separate statements. */
    strcpy(min, S1), strcpy(max, S1);

    /* strcmp(x, y) compares in dictionary order: it is negative when x comes
       before y, 0 when they are equal and positive when x comes after y.
       So "< 0" means "earlier than the smallest so far". */
    if(strcmp(S2, min) < 0){ // S2 comes before the current min
        strcpy(min, S2); // S2 is the new min
    }
    if(strcmp(S3, min) < 0){ // S3 comes before the current min
        strcpy(min, S3);
    }
    /* "> 0" means "later than the largest so far". */
    if(strcmp(S2, max) > 0){ // S2 comes after the current max
        strcpy(max, S2); // S2 is the new max
    }
    if(strcmp(S3, max) > 0){ // S3 comes after the current max
        strcpy(max, S3);
    }
    /* Trace with "abc def ghi": min starts "abc"; "def" and "ghi" are not smaller -> min "abc".
       max starts "abc"; "def" > "abc" -> max "def"; "ghi" > "def" -> max "ghi". */

    printf("%s\n", min); // line 1: the smallest string
    printf("%s\n", max); // line 2: the largest string

    return 0; // program ended successfully
}
