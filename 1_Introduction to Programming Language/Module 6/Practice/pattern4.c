// Write a program to print the given pattern.

/*

N = 5

       *
     * * *
   * * * * *
 * * * * * * *
* * * * * * * * *


 */

#include <stdio.h>

// A pyramid: each row is some spaces, then some stars. Count both for row i.
//   stars:  1, 3, 5, ...  that is 2*i - 1 on row i
//   spaces: every star is printed as "* " (two characters wide), so each row
//           must move left by 2 characters: 2*(n - i) spaces on row i,
//           which is 0 on the last row.

int main() {
    int n;
    scanf("%d", &n);

    for(int i = 1; i <= n; i++){
        // Leading spaces for row i.
        for(int j = 1; j <= 2* (n - i); j++){
            printf(" ");
        }

        // Then the 2*i - 1 stars, each followed by a space.
        for(int k = 1; k <= 2 * i - 1; k++){
            printf("* ");
        }

         printf("\n");
    }

    return 0;
}
