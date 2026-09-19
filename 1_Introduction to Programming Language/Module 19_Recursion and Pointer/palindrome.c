/*
 * Is the array the same read forwards and backwards?
 *
 * The recursive way to say it: the stretch of the array between i and j is a
 * palindrome when a[i] equals a[j] AND the shorter stretch between i+1 and
 * j-1 is a palindrome too. So each call checks one outer pair and hands the
 * inside to the next call. The two ends walk towards each other.
 *
 * For 1 2 3 2 1:
 *
 *     isPalindrome(a, 0, 4)     a[0] == a[4] ?  1 == 1, ok
 *       isPalindrome(a, 1, 3)   a[1] == a[3] ?  2 == 2, ok
 *         isPalindrome(a, 2, 2) a[2] == a[2] ?  the middle matches itself
 *           isPalindrome(a, 3, 1)  i > j, base case, returns 1
 *
 * The base case is i > j: the ends have crossed, which can only happen after
 * every pair has been checked and matched, so the answer is yes. An
 * odd-length array reaches it through a middle element compared with itself;
 * an even-length one steps straight over.
 *
 * The recursion is a different shape from factorial.c: there the answer was
 * built up with a multiplication after the call returned, here the answer is
 * simply passed back up unchanged once a decision has been made.
 */

#include <stdio.h>

/* int *a is the address of the caller's array; writing int a[] would mean
 * the same thing. No size is passed, because i and j already say which
 * stretch of the array this call is responsible for.
 * The return value is used as a yes/no: 1 for yes, 0 for no. C has no
 * separate true/false type unless you include <stdbool.h>, and any non-zero
 * value counts as true in an if. */
int isPalindrome(int *a, int i, int j){
    /* Base case: the two ends have crossed, so every pair matched. */
    if(i > j){
        return 1;
    }

    /* One outer pair, then the rest of the array inside it.
     * && stops as soon as its left side is false, so the first mismatch
     * returns 0 straight away and the recursive call is never made - there
     * is no point inspecting the inside of an array that has already
     * failed. */
    return a[i] == a[j] && isPalindrome(a, i+1, j-1);
}

int main(){
    int n;
    scanf("%d", &n);

    int a[n];

    for(int i=0; i<n; i++){
        scanf("%d", &a[i]);
    }

    /* Start with the whole array: first index 0, last index n-1. */
    if(isPalindrome(a, 0, n-1)){
        printf("YES\n");
    } else{
        printf("NO\n");
    }

    return 0;
}