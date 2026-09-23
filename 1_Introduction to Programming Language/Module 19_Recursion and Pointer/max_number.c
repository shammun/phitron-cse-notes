/*
Max Number
time limit per test1 second
memory limit per test64 megabytes
Given a number N and an array A of N numbers. Print the maximum value in this array.

Note: Solve this problem using recursion.

Input
First line contains a number N (1 ≤ N ≤ 103) number of elements.

Second line contains N numbers ( - 109 ≤ Ai ≤ 109).

Output
Print the maximum value in this array.

Example
InputCopy
5
1 -3 5 4 -6
OutputCopy
5
*/

/*
 * The largest value in an array, found with recursion instead of a loop.
 *
 * maxFrom(a, i, n) answers one question: "what is the largest value from
 * index i to the end?". It cannot see the whole answer at once, so it asks
 * itself the same question about the shorter piece that starts at i+1, then
 * compares that answer with a[i] and keeps the bigger one.
 *
 * It has the same shape as count_vowels.c: the recursive call happens first,
 * and the work for the current index is done after it returns.
 */

#include <stdio.h>

/* int *a is the address of the caller's array (int a[] means the same).
 * n is passed so the function knows where the array ends. */
int maxFrom(int *a, int i, int n){
    /* Base case: i is the last index, so the piece is a single number and
     * that number is its own maximum. Stopping here, and not at i == n,
     * means we never compare against a made-up starting value. */
    if(i == n-1){
        return a[i];
    }

    /* The largest value in everything after index i. */
    int rest = maxFrom(a, i+1, n);

    /* Keep whichever is bigger: this element or the best of the rest. */
    if(a[i] > rest){
        return a[i];
    }
    return rest;
}

int main(){
    int n;
    scanf("%d", &n);

    int a[n];

    for(int i=0; i<n; i++){
        scanf("%d", &a[i]);
    }

    /* Start at index 0 so the answer covers the whole array.
     * Values go down to -10^9, so starting a "max so far" at 0 would be
     * wrong for an all-negative array; the base case avoids that. */
    printf("%d\n", maxFrom(a, 0, n));

    return 0;
}
