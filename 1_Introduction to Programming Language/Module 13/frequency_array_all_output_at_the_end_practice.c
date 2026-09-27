#include <stdio.h> // standard input/output library: scanf and printf

/* Same problem as frequency_array.c, but with the messy screen fixed.
 *
 * In frequency_array.c each query is answered the moment it is typed, so on
 * the terminal my answers and the program's YES/NO lines end up mixed into
 * each other and the run is hard to read back.
 *
 * The change here: read *everything* first - n, the numbers, m and all m
 * queries - and only then print. Nothing comes out of the program until the
 * last number has gone in, so the input sits in one block at the top and the
 * whole output sits in one block below it.
 *
 * The trick is one extra array: the queries have to be kept somewhere while
 * the reading finishes, instead of being used and thrown away one by one.
 *
 * Reminder of the frequency-array idea: freq[x] is a box for the number x.
 * It is 1 if x appeared in the input and 0 if it did not, so "is x there?"
 * is answered by one look-up instead of a scan of the whole array.
 */

int main(){ // program execution starts here
    int n; // how many numbers the array has
    scanf("%d", &n); // &n = address of n, so scanf can store the value there

    int a[n+5]; // variable length array (size decided at run time, C99); +5 is spare room
    for(int i=0; i<n; i++){ // read n numbers into a[0] .. a[n-1]
        scanf("%d", &a[i]);
    }

    int freq[100000] = {0}; // one box per number 0 .. 99999; {0} makes every box start at 0
    for(int i=0; i<n; i++){ // mark each number that appeared
        freq[a[i]] = 1; // the number a[i] is used as the index of its own box
    }

    int m; // number of queries
    scanf("%d", &m);

    /* New bit: store the queries instead of answering them right away. */
    int q[m+5]; // q[i] = the i-th number asked about
    for(int i=0; i<m; i++){ // read all m queries first
        scanf("%d", &q[i]);
    }

    /* From here on it is printing only - no scanf left to interrupt it. */
    for(int i=0; i<10; i++){ // show the boxes for 0 .. 9
        printf("%d %d\n", i, freq[i]); // "number mark"
    }

    /* Answer the stored queries in the order they were typed. */
    for(int i=0; i<m; i++){ // one pass = one stored query
        if(freq[q[i]] == 1){ // q[i] was in the array
            printf("%d YES\n", q[i]);
        } else{ // q[i] never appeared
            printf("%d NO\n", q[i]);
        }
    }

} // end of main; in C99 and later, falling off the end of main means return 0
