/*

S. Search in matrix

Aladdin has a matrix of N rows and M columns, and one more number X. He will
take the number X only if X is not inside the matrix. Tell him what he will do.

Input
First line contains two numbers N and M (1 <= N, M <= 100).
Next N lines contain M numbers each: the matrix.
The last line contains the number X.

Output
Print "will not take number" if X is inside the matrix, otherwise print
"will take number".

Example

input
3 3
1 4 5
2 5 6
7 8 9
5

output
will not take number

Note
5 sits in the first row and also in the second row, so the number is already
inside the matrix.

*/

# include <stdio.h>

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    int a[n][m];
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            scanf("%d", &a[i][j]);
        }
    }

    int x;
    scanf("%d", &x);

    /* found stays 0 until the number is seen somewhere in the grid. One flag
       is enough: we do not care how many times x appears, only whether it is
       there at all. */
    int found = 0;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(a[i][j] == x) {
                found = 1;
                break;      /* stop this row: the answer cannot change any more */
            }
        }
        if(found == 1) {
            break;          /* break only leaves the inner loop, so break again */
        }
    }

    if(found == 1) {
        printf("will not take number\n");
    } else {
        printf("will take number\n");
    }

    return 0;
}
