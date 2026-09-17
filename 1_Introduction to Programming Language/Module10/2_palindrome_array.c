/*

G. Palindrome Array
time limit per test: 1 second
memory limit per test: 256 megabytes

Given a number N and an array A of N numbers. Determine if it's palindrome or not.

Note:
An array is called palindrome if it reads the same backward and forward, for example,
arrays { 1 } and { 1,2,3,2,1 } are palindromes, while arrays { 1,12 } and { 4,7,5,4 } are not.

Input
First line contains a number N (1 <= N <= 10^5) number of elements.
Second line contains N numbers (1 <= Ai <= 10^9).

Output
Print "YES" (without quotes) if A is a palindrome array, otherwise, print "NO" (without quotes).

Examples

input
5
1 3 2 3 1

output
YES


input
4
1 2 3 4

output
NO

*/

# include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);

    /* N can be 100000, so 100005 slots are always enough. */
    int a[100005];

    for(int i = 0; i < n; i++){
        scanf("%d", &a[i]);
    }

    /* Walk from both ends at the same time: the first with the last,
       the second with the second last, and so on. One mismatch is enough
       to say NO, so we remember it in a flag. */
    int is_palindrome = 1;

    for(int i = 0; i < n / 2; i++){
        if(a[i] != a[n - 1 - i]){
            is_palindrome = 0;
            break;
        }
    }

    if(is_palindrome == 1){
        printf("YES");
    }
    else {
        printf("NO");
    }

    return 0;
}
