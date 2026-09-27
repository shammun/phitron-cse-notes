/*
Problem Statement

You will be given a 2D matrix of N * M size. You will also be given X numbers. For each of the Number you have to print how many times the Number have appeared in the matrix.

Input Format

First line will contain N and M the number of row and column respectively and X,the number of integers we are going to search.
Then the 2D matrix will be given.
Then X lines will contain X integer Numbers.
Constraints

2 <= N,M,X <= 100
0 <= Element <= 1000
0 <= Number <=1000
Output Format

For each of the x integers print a single line with how many times that number have appeared.

Sample Input 0

2 3 3
1 2 5
2 6 4
2
6
7
Sample Output 0

2
1
0
*/


#include<stdio.h> // standard input/output library: scanf and printf

int main(){ // program execution starts here
    int N, M, X; // N rows, M columns, X questions
    scanf("%d %d %d", &N, &M, &X); // & gives scanf the address of each variable

    int Numbers[N][M]; // the matrix; its size comes from input (C99 variable length array)

    /* The frequency array from Module 13: freq[v] counts how often v is in
       the matrix. Values go up to 1000, so 100005 boxes are more than
       enough. = {0} starts every count at 0. */
    int freq[100005] = {0};

    /* Read the matrix row by row with two nested loops, and count each
       value the moment it is read. After this, every question "how many
       times is v there?" is answered by freq[v], without walking the
       matrix again.
       Trace with the sample 1 2 5 / 2 6 4: freq[2] = 2, freq[6] = 1, freq[7] stays 0. */
    for(int i=0; i<N; i++){ // i = row
        for(int j=0; j<M; j++){ // j = column
            scanf("%d", &Numbers[i][j]); // store the cell
            freq[Numbers[i][j]]++; // add 1 to the counter of that value
        }
    }

    /* Keep the X query numbers. They are stored from index 1 to X (not 0 to
       X - 1); the +5 in the size leaves room for the extra box. */
    int numbers_to_check[X+5];
    for(int i=1; i<=X; i++){ // i = 1 .. X
        scanf("%d", &numbers_to_check[i]);
    }

    /* Answer each query with one look-up. */
    for(int i=1; i<=X; i++){
        printf("%d\n", freq[numbers_to_check[i]]); // how many times that number was in the matrix
    }

    return 0; // program ended successfully
}
