/*

V. Frequency Array
https://codeforces.com/group/MWSDmqGsZm/contest/219774/problem/V

You are given N numbers, each between 1 and M. For every value v from 1 to
M, print on its own line how many times v occurs among the N numbers.

Input
First line: N and M (1 <= N, M <= 10^5).
Second line: the N numbers (1 <= A[i] <= M).

Output
M lines; line v holds the count of v.

Example

input
10 5
1 2 3 4 5 3 2 1 5 3

output
2
2
3
1
2

Note
1 and 2 come twice, 3 three times, 4 once and 5 twice.

*/

# include <stdio.h>

/* The counting array: freq[v] will hold how many times v was seen.
   It is global (declared above main) for the same reason as the big array in
   practice_count_letters.c: a global array starts filled with zeros, so every
   count begins at 0 without a loop. 100005 boxes cover every value up to
   10^5, with a little room to spare. */
int freq[100005];

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    /* Read the numbers one at a time and tally each straight away. The value
       itself is the box number, so freq[x]++ finds the right counter in one
       step - no searching through what came before. The numbers are not
       needed afterwards, so they are not kept in an array. */
    for(int i = 0; i < n; i++) {
        int x;
        scanf("%d", &x);
        freq[x]++;
    }

    /* Walk the boxes 1 .. m in order. Box 0 is never used, because the
       values start at 1. A value that never appeared still holds 0, and 0 is
       exactly what must be printed for it. */
    for(int v = 1; v <= m; v++) {
        printf("%d\n", freq[v]);
    }

    return 0;
}
