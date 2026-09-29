/*

H. Sorting (Codeforces group, Assiut newcomers sheet)
https://codeforces.com/group/MWSDmqGsZm/contest/219774/problem/H

The problem, in my own words
  Read N and then N numbers. Print the numbers in ascending order
  (smallest first). The judge asks us NOT to use a built-in sort, and to
  write bubble sort or selection sort by hand.
  This file solves it with SELECTION SORT.
  (codeforce_problem5.cpp does it with sort(), and
  codeforce_problem5_bubble_sort.cpp with bubble sort.)

Input
  First line: N (0 < N < 10^3).
  Second line: N numbers, each between -100 and 100.

Output
  The N numbers in ascending order, separated by spaces.

Example
  input      output
  4
  5 2 7 3    2 3 5 7

*/

/*
 * The idea of selection sort
 *   Fill the array from the left, one box at a time.
 *   For box i: look at every box from i to the end, SELECT the smallest
 *   number there, and swap it into box i. Now boxes 0..i hold the i+1
 *   smallest numbers in order, and they never move again.
 *   Do this for i = 0, 1, ..., N-2. The last box then holds the biggest
 *   number automatically.
 *
 * Difference from bubble sort: bubble sort swaps neighbours many times per
 * pass; selection sort only remembers WHERE the smallest is (its index) and
 * does at most one swap per pass.
 *
 * Trace with A = {5, 2, 7, 3} (N = 4)
 *   i=0: smallest of {5,2,7,3} is 2 (index 1) -> swap A[0],A[1] -> {2,5,7,3}
 *   i=1: smallest of {5,7,3}   is 3 (index 3) -> swap A[1],A[3] -> {2,3,7,5}
 *   i=2: smallest of {7,5}     is 5 (index 3) -> swap A[2],A[3] -> {2,3,5,7}
 *   done: {2, 3, 5, 7}
 */

#include <iostream> // gives us cin (read input) and cout (print output)
using namespace std; // lets us write cin/cout instead of std::cin/std::cout

int main(){
    int N; // how many numbers there are
    cin >> N; // read N from the first line

    int A[N]; // an array with N boxes, A[0] .. A[N-1], to hold the numbers
              // (sizing an array with a variable is a g++ feature; fine here since N < 1000)

    // Read the N numbers into the array, one box at a time.
    for(int i=0; i<N; i++){ // i goes 0, 1, ..., N-1: one box per number
        cin >> A[i]; // cin skips spaces/newlines and reads the next number into box i
    }

    // Selection sort: choose the right number for box i, for i = 0 .. N-2.
    // (When boxes 0..N-2 are right, the one number left must go in box N-1,
    // so there is no need to handle the last box.)
    for(int i=0; i<N-1; i++){ // i = the box we are filling now

        // Find the index of the smallest number in boxes i .. N-1.
        // Start by assuming box i itself is the smallest.
        int minIndex = i; // index (position) of the smallest value seen so far

        for(int j=i+1; j<N; j++){ // look at every box to the right of i
            if(A[j] < A[minIndex]){ // found a smaller value than the best so far
                minIndex = j;       // remember its position (don't swap yet)
            }
        }
        // Now A[minIndex] is the smallest number among boxes i .. N-1.

        // Swap it into box i using a temporary box.
        // We need temp because after "A[i] = A[minIndex]" the old A[i]
        // would be lost; temp keeps a copy of it.
        // (If minIndex == i the swap just puts the value back where it was.)
        int temp = A[i];        // 1. save the value currently in box i
        A[i] = A[minIndex];     // 2. put the smallest value into box i
        A[minIndex] = temp;     // 3. put the saved value where the smallest was
    }

    // Print the sorted array, each number followed by a space
    // (the judge ignores the extra space at the end).
    for(int i=0; i<N; i++){ // visit every box from left to right
        cout << A[i] << " "; // print the number, then a space
    }
    cout << endl; // end the output line

    return 0; // tell the system the program finished normally
}
