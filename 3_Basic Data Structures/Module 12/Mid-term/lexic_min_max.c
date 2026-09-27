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



#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {

    /* The idea: the same as finding the min and max of three numbers, but
     * strings are compared with strcmp and copied with strcpy (a C string
     * cannot be assigned with =).
     *   strcmp(a, b) < 0  means a comes before b in dictionary order,
     *   strcmp(a, b) > 0  means a comes after b.
     * Start with S1 as both the smallest and the largest so far, then let
     * S2 and S3 challenge each one. */
    
    char S1[1001], S2[1001], S3[1001], min[1001], max[1001];
    scanf("%s %s %s", S1, S2, S3);
    
    /* S1 is the first candidate for both answers. */
    strcpy(min, S1), strcpy(max, S1);
    
    /* Does S2 or S3 come earlier than the current minimum? */
    if(strcmp(S2, min) < 0){
        strcpy(min, S2);
    }
    if(strcmp(S3, min) < 0){
        strcpy(min, S3);
    }
    /* Does S2 or S3 come later than the current maximum? */
    if(strcmp(S2, max) > 0){
        strcpy(max, S2);
    }
    if(strcmp(S3, max) > 0){
        strcpy(max, S3);
    }
    
    printf("%s\n", min);
    printf("%s\n", max);
    
    return 0;
}