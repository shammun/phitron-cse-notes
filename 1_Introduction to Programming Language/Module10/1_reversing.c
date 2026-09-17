/*

F. Reversing
time limit per test: 1 second
memory limit per test: 64 megabytes

Given a number N and an array A of N numbers. Print the array in a reversed order.

Note:
*Don't use built-in-functions.

Input
First line contains a number N (1 <= N <= 10^3) number of elements.
Second line contains N numbers (0 <= Ai <= 10^9).

Output
Print the array in a reversed order.

Examples

input
4
5 1 3 2

output
2 3 1 5


input
5
1 2 3 4 5

output
5 4 3 2 1

*/

# include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);

    /* N can be 1000, so 1005 slots are always enough. */
    int a[1005];

    for(int i = 0; i < n; i++){
        scanf("%d", &a[i]);
    }

    /* Nothing has to be swapped. We only print from the last index
       down to the first one, so the array itself stays as it is. */
    for(int i = n - 1; i >= 0; i--){
        printf("%d ", a[i]);
    }

    return 0;
}
