/*

F. Reversing  (extra practice problem)
https://codeforces.com/group/MWSDmqGsZm/contest/219774/problem/F

Read N numbers and print them back in the opposite order, last one first.
Do it by hand with a loop - no ready-made "reverse" function.

Input
First line: N (1 <= N <= 1000).
Second line: the N numbers (each between 0 and 10^9).

Output
The numbers from the last one to the first, separated by spaces.

Example

input
4
5 1 3 2

output
2 3 1 5

*/

/* stdio.h ("standard input output") declares scanf and printf. The
   space in "# include" is allowed; it means the same as #include. */
# include <stdio.h>

int main() {            /* the program starts running here */
    int n;              /* the input number N */
    scanf("%d", &n);    /* %d = read a whole number; &n = where to put it */

    /* The numbers have to be kept: the first one we must print is the LAST
       one read, so nothing can be printed until everything has arrived.
       Each value is at most 10^9, which still fits in an int. */
    int a[n];

    /* Reading goes forwards as usual: a[0], a[1], ..., a[n - 1]. */
    for(int i = 0; i < n; i++){
        scanf("%d", &a[i]);    /* &a[i] = the address of box i */
    }

    /* Printing goes backwards. The last box is a[n - 1] (not a[n], which is
       one step past the end), and the loop runs while i >= 0 so that a[0]
       is printed too. i-- moves one box to the left on each pass. */
    for(int i = n - 1; i >= 0; i--){
        printf("%d ", a[i]);   /* value, then a space. 5 1 3 2 -> 2 3 1 5 */
    }

    return 0;   /* 0 = the program finished normally */
}
