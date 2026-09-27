/* Re-typed practice copy of no_repeatation.c (the question is at the top of
 * that file): count the values, then count those whose count is exactly 1. */

#include <stdio.h>

int main(){
    int N;
    scanf("%d", &N);

    int freq[100005] = {0};

    int Numbers[N+5];

    for(int i=0; i<N; i++){
        scanf("%d", &Numbers[i]);
    }

    /* Pass 1: how often each value appears. */
    for(int i=0; i<N; i++){
        freq[Numbers[i]]++;
    }

    /* Pass 2: a value seen exactly once adds 1 to the answer. */
    int count = 0;
    for(int i=0; i<N; i++){
        if(freq[Numbers[i]] == 1){
            count++;
        }
    }

    printf("%d\n", count);

    return 0;
}
