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

#include <stdio.h>

/* 

In C, global arrays are automatically initialized to 0. This means that all elements of the array f 
are initially set to 0.

This automatic initialization happens because f is declared globally (outside the main function).

*/
// Array to store frequency of each number (initialized to 0 globally)
int f[100000];

int main(){
    // n: size of input array, m: range of numbers (1 to m)
    int n, m;
    scanf("%d %d", &n, &m);

    // Array to store input numbers with some buffer space
    int a[n];

    // Read n numbers and count their frequencies
    for(int i=0; i<n; i++){
        scanf("%d", &a[i]);
        // Increment frequency counter for number a[i]
        f[a[i]] += 1;
    }

    // Print frequency of each number from 1 to m
    for(int i=1; i<=m; i++){
        printf("%d\n", f[i]);
    }

    return 0;
}