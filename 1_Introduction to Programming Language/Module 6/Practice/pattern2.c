// N = 5            			
// 5 4 3 2 1
// 4 3 2 1
// 3 2 1
// 2 1
// 1

#include <stdio.h>

// The mirror of pattern1.c: the rows get shorter, and each row counts down.
// Row "i" starts at i and goes down to 1, so it holds i numbers.

int main() {
    int n;
    scanf("%d", &n);

    // The outer loop counts DOWN: the first row starts at n, the last at 1.
    for(int i = n; i >= 1; i--){
        // Print i, i-1, ..., 1 on this row.
        for(int j = i; j >= 1; j--){
            printf("%d ", j);
        }
        printf("\n");
    }

    return 0;
}
