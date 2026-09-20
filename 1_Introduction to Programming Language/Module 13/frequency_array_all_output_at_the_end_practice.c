#include <stdio.h>

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
 */

int main(){
    int n;
    scanf("%d", &n);

    int a[n+5];
    for(int i=0; i<n; i++){
        scanf("%d", &a[i]);
    }

    int freq[100000] = {0};
    for(int i=0; i<n; i++){
        freq[a[i]] = 1;
    }

    int m;
    scanf("%d", &m);

    /* New bit: store the queries instead of answering them right away. */
    int q[m+5];
    for(int i=0; i<m; i++){
        scanf("%d", &q[i]);
    }

    /* From here on it is printing only - no scanf left to interrupt it. */
    for(int i=0; i<10; i++){
        printf("%d %d\n", i, freq[i]);
    }

    /* Answer the stored queries in the order they were typed. */
    for(int i=0; i<m; i++){
        if(freq[q[i]] == 1){
            printf("%d YES\n", q[i]);
        } else{
            printf("%d NO\n", q[i]);
        }
    }
    
}
