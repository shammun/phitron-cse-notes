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

/* Idea: store all N numbers in an array, then print them starting from the
   LAST index and moving towards index 0. The array is never changed.
   Note: Ai can be up to 10^9. An int holds values up to about 2.1 * 10^9,
   so int is big enough here. */

# include <stdio.h> // standard input/output library: gives us scanf (read input) and printf (print output)

int main() { // every C program starts running from main(); "int" means it returns a whole number to the system
    int n; // n = how many numbers the array has
    scanf("%d", &n); // %d = read one int; &n = the ADDRESS of n, so scanf can store the value inside n

    /* N can be 1000, so 1005 slots are always enough.
       The array is created with a fixed size; we only use the first n slots
       (indexes 0 .. n-1). The few extra slots are a safety margin. */
    int a[1005];

    /* Input loop: i is the index being filled. One pass reads one number
       into a[i]. i goes 0, 1, ..., n-1 and the loop stops when i == n. */
    for(int i = 0; i < n; i++){
        scanf("%d", &a[i]); // &a[i] = address of slot i, so the number read goes straight into a[i]
    }

    /* Nothing has to be swapped. We only print from the last index
       down to the first one, so the array itself stays as it is.
       i starts at n-1 (the last valid index, because indexes start at 0),
       goes down by 1 each pass (i--), and the loop stops after i == 0 is printed.
       Trace with a = {5, 1, 3, 2}, n = 4: i = 3 -> 2, i = 2 -> 3, i = 1 -> 1, i = 0 -> 5
       so the output is "2 3 1 5 ". */
    for(int i = n - 1; i >= 0; i--){
        printf("%d ", a[i]); // print a[i] followed by a space to separate the numbers
    }

    return 0; // returning 0 from main tells the system the program finished without error
}
