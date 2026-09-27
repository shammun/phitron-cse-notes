/*

In your company you have been given a task to sort out the job applications acording to the candidates experience.

If experience is less than 1, it's "Entry-level candidate".
If experience is between 1 and 3 (inclusive), it's "Junior candidate".
If experience is between 4 and 7 (inclusive), it's "Mid-level candidate".
If experience is greater than 7, it's "Senior candidate".
You will be given list of N candidates experience. For each of them print what kind of candidate he/she is according the the experience.

Input Format

The first line will contain an integer N, the number of candidates.
The next line will contain N numbers, the experiences of the candidates.
Constraints

1 <= N <= 10^5
You can assume no candidate has experience more than 20.
Output Format

For each experience, print one of these strings (without quotes) "Entry-level candidate", "Junior candidate", "Mid-level candidate" and "Senior candidate" according to the catagory.

Sample Input 0

4
4
0
3
8
Sample Output 0

Mid-level candidate
Entry-level candidate
Junior candidate
Senior candidate

*/



#include <stdio.h>      /* scanf and printf */
#include <string.h>     /* not used here (template leftover) */
#include <math.h>       /* not used here (template leftover) */
#include <stdlib.h>     /* not used here (template leftover) */

/* main: program entry point; return 0 = success. */
int main() {

    /* The idea: read all N experiences, then put each one in its band with
     * an if / else-if chain, checked from the smallest band up:
     *   below 1 -> Entry-level,  1..3 -> Junior,  4..7 -> Mid-level,
     *   above 7 -> Senior.
     * Because each else-if is only reached when the tests above it failed,
     * the last case needs no condition at all. */

    int N;                      /* number of candidates */
    scanf("%d", &N);            /* %d = int; &N = address of N so scanf can fill it */

    int experiences[100000];    /* room for the maximum 10^5 candidates */

    /* Read the N experiences. */
    for(int i=0; i<N; i++){
        scanf("%d", &experiences[i]);   /* store into slot i */
    }

    /* One line of output per candidate, in input order. */
    for(int i = 0; i < N; i++){
        if(experiences[i] < 1){                                     /* 0 years */
            printf("Entry-level candidate\n");
        } else if (experiences[i] >= 1 && experiences[i] <= 3){     /* && = both must hold */
            printf("Junior candidate\n");
        } else if(experiences[i] >= 4 && experiences[i] <= 7){
            printf("Mid-level candidate\n");
        } else {                                                    /* 8 or more */
            printf("Senior candidate\n");
        }
    }
    /* Sample 4 0 3 8 -> Mid-level, Entry-level, Junior, Senior. */

    return 0;
}
