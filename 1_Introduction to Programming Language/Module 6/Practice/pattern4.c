// Write a program to print the given pattern.

/*

N = 5

        *
      * * *
    * * * * *
  * * * * * * *
* * * * * * * * *

 */

// stdio.h ("standard input output") declares scanf and printf.
#include <stdio.h>

// A pyramid: each row is some spaces, then some stars. Count both for row i.
//   stars:  1, 3, 5, ...  that is 2*i - 1 on row i
//   spaces: every star is printed as "* " (two characters wide), so each row
//           must move left by 2 characters: 2*(n - i) spaces on row i,
//           which is 0 on the last row.
// Trace N = 3: row 1 -> 4 spaces + 1 star, row 2 -> 2 spaces + 3 stars,
//              row 3 -> 0 spaces + 5 stars.

int main() {            // the program starts running here
    int n;              // number of rows
    scanf("%d", &n);    // %d = read a whole number; &n = where to store it

    // One pass per row, i = 1 .. n.
    for(int i = 1; i <= n; i++){
        // Leading spaces for row i.
        for(int j = 1; j <= 2* (n - i); j++){
            printf(" ");
        }

        // Then the 2*i - 1 stars, each followed by a space.
        for(int k = 1; k <= 2 * i - 1; k++){
            printf("* ");
        }

         printf("\n");  // row finished: go to the next line
    }

    return 0;           // 0 = the program finished normally
}
