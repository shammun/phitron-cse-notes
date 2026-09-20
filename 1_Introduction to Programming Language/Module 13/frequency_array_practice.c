#include <stdio.h>

/* Re-typed practice copy of frequency_array.c.
 * Same program, written out again from memory to fix the steps in my head:
 * mark every number that came, show the marks for 0 to 9, then answer
 * "is x there?" questions. See frequency_array.c for the long explanation.
 */

int main(){
    int n;
    scanf("%d", &n);

    int a[n+5];
    for(int i=0; i<n; i++){
        scanf("%d", &a[i]);
    }

    /* The tally sheet. `= {0}` puts 0 in all 100000 boxes. */
    int freq[100000] = {0};
    for(int i=0; i<n; i++){
        freq[a[i]] = 1;          /* 1 means "this number came", not how many times */
    }

    for(int i=0; i<10; i++){
        printf("%d %d\n", i, freq[i]);
    }

    int m;
    scanf("%d", &m);

    /* Read a query and answer it straight away, one at a time. */
    for(int i=0; i<m; i++){
        int x;
        scanf("%d", &x);
        printf("%d ", x);

        if(freq[x] == 1){
            printf("YES\n");
        } else{
            printf("NO\n");
        }
    }
}
