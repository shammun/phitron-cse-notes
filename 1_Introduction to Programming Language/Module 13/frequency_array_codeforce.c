/*

Frequency Array
time limit per test1 second
memory limit per test256 megabytes
Given 2 numbers N
, M
 and an array A
 of N
 numbers. For every number from 1 to M
, print how many times this number appears in this array.

Input
First line contains two numbers N
, M
 (1≤N≤105,1≤M≤105)
.

Second line contains N
 numbers (1≤Ai≤M)
.

Output
Print M
 lines, the ith
 line should contain number of times that the number i
 appears in A

Example
InputCopy
10 5
1 2 3 4 5 3 2 1 5 3
OutputCopy
2
2
3
1
2
Note
Numbers from 1 to 5 appearance are :

1 appears 2 times in the array .
2 appears 2 times in the array.
3 appears 3 times in the array.
4 appears once in the array.
5 appears 2 times in the array.



*/

/* Note on the statement above: it was copied from the web page, where the
   limits are 1 <= N <= 10^5 and 1 <= M <= 10^5 (the "105" is 10 to the power 5).

   Idea: a counting (frequency) array. f[x] = how many times the number x has
   been seen. Every number read adds 1 to its own box; at the end, box i holds
   the answer for i. This is one pass over the input instead of M separate scans. */

#include <stdio.h> // standard input/output library: scanf and printf

/*

In C, global arrays are automatically initialized to 0. This means that all elements of the array f
are initially set to 0.

This automatic initialization happens because f is declared globally (outside the main function).
(A local array inside main, without "= {0}", would start with garbage values instead.
Global arrays also do not use the limited stack space, so big ones are safe here.)

*/
// Array to store frequency of each number (initialized to 0 globally)
// BUG: M (and so Ai) can be 100000, but valid indexes of f are only 0 .. 99999.
// For Ai = 100000, f[a[i]] += 1 writes one box past the end, and the print loop
// reads f[100000] too. Fix: declare it one bigger, e.g. int f[100005];
int f[100000];

int main(){ // program execution starts here
    // n: size of input array, m: range of numbers (1 to m)
    int n, m;
    scanf("%d %d", &n, &m); // read both ints; & gives scanf their addresses

    // Array to store input numbers (exactly n slots, no spare room;
    // its size is known only at run time - a C99 variable length array)
    int a[n];

    // Read n numbers and count their frequencies
    // One pass reads one number and immediately adds 1 to that number's box.
    // Trace with 1 2 3 4 5 3 2 1 5 3: after all passes f[1]=2, f[2]=2, f[3]=3, f[4]=1, f[5]=2.
    for(int i=0; i<n; i++){
        scanf("%d", &a[i]); // store the number in a[i]
        // Increment frequency counter for number a[i]
        f[a[i]] += 1; // the number itself is the index; "+= 1" means add one to that box
    }

    // Print frequency of each number from 1 to m
    // i starts at 1 (not 0) because the numbers are 1 .. m, and "<=" includes m itself.
    for(int i=1; i<=m; i++){
        printf("%d\n", f[i]); // one count per line
    }

    return 0; // program ended successfully
}
