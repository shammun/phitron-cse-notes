// Write a program to print the given pattern
/*
N = 6
A
B B
C C C
D D D D
E E E E E
F F F F F F
*/

// stdio.h ("standard input output") declares scanf and printf.
#include <stdio.h>

// Same shape as pattern1.c (row i has i items), but every item on row i is
// the same letter: the i-th letter of the alphabet.

int main() {            // the program starts running here
    int n;              // number of rows
    scanf("%d", &n);    // %d = read a whole number; &n = where to store it

    // Outer loop: row i = 1 .. n.
    for(int i = 1; i <= n; i++) {
        // Inner loop: print i items on row i.
        for(int j = 1; j <= i; j++){
            // 'A' + i - 1 is the i-th letter: row 1 gets 'A' + 0 = 'A',
            // row 2 gets 'A' + 1 = 'B', and so on. %c prints the number as a
            // character. Note it uses i (the row), not j, so the letter
            // stays the same along the row.
            printf("%c ", 'A' + i - 1);
        }
        printf("\n");       // row finished: go to the next line
    }

    return 0;           // 0 = the program finished normally
}
