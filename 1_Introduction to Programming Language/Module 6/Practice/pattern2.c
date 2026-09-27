// N = 5
// 5 4 3 2 1
// 4 3 2 1
// 3 2 1
// 2 1
// 1

// stdio.h ("standard input output") declares scanf and printf.
#include <stdio.h>

// The mirror of pattern1.c: the rows get shorter, and each row counts down.
// Row "i" starts at i and goes down to 1, so it holds i numbers.

int main() {            // the program starts running here
    int n;              // number of rows (and the first row's starting number)
    scanf("%d", &n);    // %d = read a whole number; &n = where to store it

    // The outer loop counts DOWN: the first row starts at n, the last at 1.
    // i-- means "subtract 1 from i" after each pass; the loop stops once
    // i drops to 0 (0 >= 1 is false).
    for(int i = n; i >= 1; i--){
        // Print i, i-1, ..., 1 on this row.
        for(int j = i; j >= 1; j--){
            printf("%d ", j);   // the number, then a space
        }
        printf("\n");           // row finished: go to the next line
    }

    return 0;           // 0 = the program finished normally
}
