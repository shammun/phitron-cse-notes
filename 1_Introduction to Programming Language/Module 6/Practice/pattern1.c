// N = 6            			1
// 1 2
// 1 2 3
// 1 2 3 4
// 1 2 3 4 5
// 1 2 3 4 5 6

#include <stdio.h>

// Every pattern is a nested loop: the outer loop picks the row, the inner
// loop prints what goes on that row. The only real question is "how many
// things does row i hold?". Here row i holds i numbers, 1 up to i.

int main() {
    int n;
    scanf("%d", &n);

    // Outer loop: one pass per row, i = 1 .. n.
    for(int i = 1; i <= n; i++){
        // Inner loop: row i prints 1, 2, ..., i. Its limit is i, not n,
        // which is what makes each row one longer than the one above.
        for (int j = 1; j <= i; j++){
            printf("%d ", j);
        }
        // The row is finished: move to the next line.
        printf("\n");
    }

    return 0;

}
