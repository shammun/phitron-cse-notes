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

/* Idea: an array is a palindrome when element i equals its "mirror" element
   n-1-i for every i. We only need to check the first half, because the
   second half is checked automatically as the mirror of the first half. */

# include <stdio.h> // standard input/output library: gives us scanf and printf

int main() { // program execution starts here
    int n; // n = number of elements
    scanf("%d", &n); // %d reads one int; &n gives scanf the address of n so it can write into it

    /* N can be 100000, so 100005 slots are always enough.
       (An array this big inside main is fine: 100005 ints is about 400 KB.) */
    int a[100005];

    /* Read the n numbers into a[0] .. a[n-1]; one pass reads one number. */
    for(int i = 0; i < n; i++){
        scanf("%d", &a[i]); // store the next number from input into slot i
    }

    /* Walk from both ends at the same time: the first with the last,
       the second with the second last, and so on. One mismatch is enough
       to say NO, so we remember it in a flag.
       Here 1 means "yes, still a palindrome" and 0 means "no, a mismatch was found".
       We start by assuming YES. */
    int is_palindrome = 1;

    /* i runs over the first half only: 0 .. n/2 - 1 (n/2 is integer division,
       so for n = 5 it is 2 and the middle element a[2] is never compared -
       it is its own mirror, so it cannot break the palindrome).
       Trace with a = {1, 3, 2, 3, 1}: i = 0 compares a[0]=1 with a[4]=1,
       i = 1 compares a[1]=3 with a[3]=3 -> no mismatch -> YES. */
    for(int i = 0; i < n / 2; i++){
        if(a[i] != a[n - 1 - i]){ // a[n-1-i] is the mirror of a[i]: i=0 pairs with n-1, i=1 with n-2, ...
            is_palindrome = 0; // remember that the array is NOT a palindrome
            break; // leave the loop right away; checking more pairs cannot change the answer
        }
    }

    /* Print the answer based on the flag. */
    if(is_palindrome == 1){ // no mismatch was ever found
        printf("YES");
    }
    else { // at least one pair was different
        printf("NO");
    }

    return 0; // program ended successfully
}
