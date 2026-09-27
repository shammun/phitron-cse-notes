#include <stdio.h> // standard input/output library: scanf and printf

/* Re-typed practice copy of frequency_array.c.
 * Same program, written out again from memory to fix the steps in my head:
 * mark every number that came, show the marks for 0 to 9, then answer
 * "is x there?" questions. See frequency_array.c for the long explanation.
 *
 * Short version of the idea: freq[x] is a box for the number x; it holds 1
 * if x was in the input and 0 otherwise, so each question is one look-up.
 */

int main(){ // program execution starts here
    int n; // how many numbers will be read
    scanf("%d", &n); // &n = address of n, where scanf writes the value

    int a[n+5]; // array sized at run time (C99 variable length array), with 5 spare slots
    for(int i=0; i<n; i++){ // read the n numbers into a[0] .. a[n-1]
        scanf("%d", &a[i]);
    }

    /* The tally sheet. `= {0}` puts 0 in all 100000 boxes.
       Numbers must be between 0 and 99999 to have a box. */
    int freq[100000] = {0};
    for(int i=0; i<n; i++){ // visit every input number
        freq[a[i]] = 1;          /* 1 means "this number came", not how many times */
    }

    for(int i=0; i<10; i++){ // show the marks for the numbers 0 .. 9
        printf("%d %d\n", i, freq[i]); // "number mark"
    }

    int m; // how many questions
    scanf("%d", &m);

    /* Read a query and answer it straight away, one at a time. */
    for(int i=0; i<m; i++){ // one pass = one question
        int x; // the number asked about
        scanf("%d", &x);
        printf("%d ", x); // echo the number first

        if(freq[x] == 1){ // its box was marked -> it was in the input
            printf("YES\n");
        } else{ // box still 0 -> it was not
            printf("NO\n");
        }
    }
} // end of main; in C99 and later, reaching here means return 0
