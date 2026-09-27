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

/* Idea: store all experiences, then for each one pick exactly one label
   using an if / else if / else ladder. */

#include <stdio.h>  // standard input/output library: scanf and printf
#include <string.h> // string functions (part of the HackerRank template; not used here)
#include <math.h>   // math functions (template; not used here)
#include <stdlib.h> // general utilities (template; not used here)

int main() { // program execution starts here

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */

    int N; // number of candidates
    scanf("%d", &N); // read N; &N is the address where scanf stores it

    /* Room for the largest N allowed (10^5). */
    int experiences[100000];

    /* First read every experience...
       (scanf with %d skips spaces AND newlines, so it works whether the
       numbers are on one line or, as in the sample, one per line.) */
    for(int i=0; i<N; i++){
        scanf("%d", &experiences[i]); // store candidate i's experience
    }

    /* ...then label each one with an if-else ladder. The ranges do not
       overlap and together cover every number, so exactly one branch runs
       for each candidate. The last case needs no test: anything that is not
       below 1, not 1..3 and not 4..7 must be above 7.
       (Because the ladder checks in order, the ">= 1" and ">= 4" parts are
       already guaranteed when those branches are reached; they are kept for clarity.) */
    for(int i = 0; i < N; i++){ // one pass = one candidate
        if(experiences[i] < 1){ // 0 years
            printf("Entry-level candidate\n");
        } else if (experiences[i] >= 1 && experiences[i] <= 3){ // && = both conditions must be true: 1..3
            printf("Junior candidate\n");
        } else if(experiences[i] >= 4 && experiences[i] <= 7){ // 4..7
            printf("Mid-level candidate\n");
        } else { // everything left: 8 or more
            printf("Senior candidate\n");
        }
    }

    return 0; // program ended successfully
}
