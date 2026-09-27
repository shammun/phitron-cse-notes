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

/* Idea: read the grid, read X, then visit every cell until X is found.
   A flag remembers whether it was found. */

# include <stdio.h> // standard input/output library: scanf and printf

int main() { // program execution starts here
    int n, m; // n = rows, m = columns
    scanf("%d %d", &n, &m); // & gives scanf the addresses of n and m

    int a[n][m]; // the grid; size comes from input (C99 variable length array)
    for(int i = 0; i < n; i++) { // i = row
        for(int j = 0; j < m; j++) { // j = column; the inner loop fills one row
            scanf("%d", &a[i][j]); // &a[i][j] = address of cell (i, j)
        }
    }

    int x; // the number Aladdin wants to take
    scanf("%d", &x);

    /* found stays 0 until the number is seen somewhere in the grid. One flag
       is enough: we do not care how many times x appears, only whether it is
       there at all. */
    int found = 0;
    for(int i = 0; i < n; i++) { // visit every row ...
        for(int j = 0; j < m; j++) { // ... and every column of that row
            if(a[i][j] == x) { // this cell holds x
                found = 1;
                break;      /* stop this row: the answer cannot change any more */
            }
        }
        if(found == 1) {
            break;          /* break only leaves the inner loop, so break again */
        }
    }

    if(found == 1) { // x is already in the matrix
        printf("will not take number\n");
    } else { // x was nowhere in the matrix
        printf("will take number\n");
    }

    return 0; // program ended successfully
}
