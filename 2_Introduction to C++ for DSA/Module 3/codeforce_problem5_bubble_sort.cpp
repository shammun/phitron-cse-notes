/*

H. Sorting (Codeforces group, Assiut newcomers sheet)
https://codeforces.com/group/MWSDmqGsZm/contest/219774/problem/H

The problem, in my own words
  Read N and then N numbers. Print the numbers in ascending order
  (smallest first). The judge asks us NOT to use a built-in sort, and to
  write bubble sort or selection sort by hand.
  This file solves it with BUBBLE SORT.
  (codeforce_problem5.cpp does it with sort(), and
  codeforce_problem5_selection_sort.cpp with selection sort.)

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
 * The idea of bubble sort
 *   Walk along the array and compare every pair of NEIGHBOURS,
 *   A[j] and A[j+1]. If the left one is bigger, they are in the wrong
 *   order, so swap them. After one full walk (a "pass") the biggest number
 *   has been pushed all the way to the right end, like a bubble rising to
 *   the top. So it is now in its final place.
 *   Repeat the pass N-1 times. Each pass fixes one more number at the end,
 *   so each pass can stop one box earlier than the one before.
 *
 * Trace with A = {5, 2, 7, 3} (N = 4)
 *   pass i=0: compare 5,2 -> swap -> {2,5,7,3}
 *             compare 5,7 -> ok   -> {2,5,7,3}
 *             compare 7,3 -> swap -> {2,5,3,7}   7 is now in place
 *   pass i=1: compare 2,5 -> ok
 *             compare 5,3 -> swap -> {2,3,5,7}   5 is now in place
 *   pass i=2: compare 2,3 -> ok                  {2,3,5,7}  done
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

    // Bubble sort: N-1 passes over the array.
    // Why N-1? Each pass puts one number in its final place at the right end.
    // After N-1 numbers are in place, the last one left (at the front) must
    // be the smallest, so it is in place too.
    for(int i=0; i<N-1; i++){ // i = how many passes are already done
                              // = how many numbers are already fixed at the end

        // One pass: compare neighbours A[j] and A[j+1].
        // The last i boxes are already sorted, so j only goes up to N-2-i.
        // j < N-1-i also keeps j+1 inside the array (j+1 <= N-1-i).
        for(int j=0; j<N-1-i; j++){
            if(A[j] > A[j+1]){ // left neighbour is bigger: wrong order for ascending
                // Swap A[j] and A[j+1] using a temporary box.
                // We need temp because after "A[j] = A[j+1]" the old A[j]
                // would be lost; temp keeps a copy of it.
                int temp = A[j];   // 1. save the left value
                A[j] = A[j+1];     // 2. move the right value to the left
                A[j+1] = temp;     // 3. put the saved value on the right
            }
            // If A[j] <= A[j+1] they are already in order: do nothing.
        }
    }

    // Print the sorted array, each number followed by a space
    // (the judge ignores the extra space at the end).
    for(int i=0; i<N; i++){ // visit every box from left to right
        cout << A[i] << " "; // print the number, then a space
    }
    cout << endl; // end the output line

    return 0; // tell the system the program finished normally
}
