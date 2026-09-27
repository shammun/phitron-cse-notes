/* Re-typed practice copy of no_repeatation.c (the question is at the top of
 * that file): count the values, then count those whose count is exactly 1.
 * Example: 1 4 3 3 5 2 4 6 2 3 -> only 1, 5 and 6 appear once -> prints 3. */

#include <stdio.h> // standard input/output library: scanf and printf

int main(){ // program execution starts here
    int N; // how many numbers
    scanf("%d", &N); // &N = address where scanf stores N

    int freq[100005] = {0}; // freq[v] = how many times v appears; {0} starts all at 0

    int Numbers[N+5]; // the input numbers

    for(int i=0; i<N; i++){ // read N numbers
        scanf("%d", &Numbers[i]);
    }

    /* Pass 1: how often each value appears. */
    for(int i=0; i<N; i++){
        freq[Numbers[i]]++; // the value is the index of its own counter
    }

    /* Pass 2: a value seen exactly once adds 1 to the answer. */
    int count = 0;
    for(int i=0; i<N; i++){
        if(freq[Numbers[i]] == 1){
            count++;
        }
    }

    printf("%d\n", count); // print the answer

    return 0; // program ended successfully
}
