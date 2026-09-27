/*
Problem Statement

You will be given a matrix of size N * N. You need to tell if it is unit matrix or not.

Note: A matrix is called a unit matrix if all the primary diagonal elements are 1 and all the non-diagonal elements are 0.

Input Format

First line will contain N, the row and column of the square matrix.
Then the N * N sized matrix will be given where the values are integer only.
Constraints

1 <= N <= 100
0 <= Values <= 100
Output Format

Ouput "YES" if the matrix is unit matrix, otherwise output "NO" without the quotation marks.
Sample Input 0

3
1 0 0
0 1 0
0 0 1
Sample Output 0

YES
Sample Input 1

5
1 0 0 0 0
0 1 0 0 0
0 0 1 0 1
0 0 0 1 0
0 0 0 0 1
Sample Output 1

NO
*/

#include <stdio.h>

int main(){
    int N;
    scanf("%d", &N);

    int values[N][N];

    /* flag = 1 means "still looks like a unit matrix". One wrong cell is
       enough to switch it to 0 for good. */
    int flag = 1;

    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            scanf("%d", &values[i][j]);
        }
    }

    /* Check every cell. A cell is on the main diagonal when its row number
       equals its column number (i == j); there it must be 1. Everywhere else
       it must be 0. */
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            if(i==j){
                if(values[i][j] != 1){
                    flag = 0;
                    break;
                }
            }else{
                if(values[i][j] != 0){
                    flag = 0;
                    break;
                }
            }
        }
        /* break only leaves the inner loop, so the outer loop still visits
           the remaining rows. That does not change the answer (flag stays
           0); it only costs a little time. */
    }

    if(flag == 1){
        printf("YES");
    }else{
        printf("NO");
    }

    return 0;
}