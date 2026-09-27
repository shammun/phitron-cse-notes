/*

Printing X

Problem Statement

You will be given an positive odd integer N, you need to print the pattern for it. See sample
input and output for understanding the pattern.

Input Format

Input will contain only N.
Constraints

1 <= N <= 20 and N is odd.
Output Format

Output the pattern.
Sample Input 0

5
Sample Output 0

\   /
 \ /
  X
 / \
/   \
Sample Input 1

7
Sample Output 1

\     /
 \   /
  \ /
   X
  / \
 /   \
/     \
Sample Input 2

3
Sample Output 2

\ /
 X
/ \
Sample Input 3

1
Sample Output 3

X

*/

#include <iostream>  // cin and cout
#include <vector>    // not needed here, kept from the template
#include <algorithm> // not needed here
#include <string>    // not needed here
using namespace std; // lets us drop the std:: prefix

int main() { // the program starts running here
    int N; // the size of the X (always odd)
    cin >> N; // read N

    /*
     * The X has three parts for N = 5:
     *   top half (N/2 rows):     \   /     row i: i spaces, \, gap, /, i spaces
     *                             \ /      the gap starts at N-2 and shrinks by 2
     *   middle row:                X       N/2 spaces, then X
     *   bottom half (N/2 rows):   / \      the mirror image: outer spaces shrink,
     *                            /   \     the gap grows by 2 each row
     * (N/2 is integer division: 5/2 = 2.)
     */

    // N = 1 has no arms at all, only the centre.
    if(N == 1){
        cout << "X" << endl; // the whole pattern
        return 0; // done: end the program early
    }

    int spaces = N - 2;         // gap between \ and / on the first row

    // Top half.
    // Row i (i = 0 .. N/2 - 1): i spaces, a backslash, the gap, a slash, i spaces.
    for(int i=0; i < N/2; i++){
        for(int j=0; j <i; j++){            // i spaces on the left
            cout << " ";
        }
        // Inside a string, a backslash starts an escape sequence (like the newline
        // escape), so one real backslash has to be written as two.
        cout << "\\";                       // "\\" in C++ prints one backslash

        for(int j=0; j< spaces; j++){       // the gap
            cout << " ";
        }
        cout << "/"; // the right arm

        for(int k=0; k<i; k++){             // i spaces on the right
            cout << " ";
        }
        cout << endl; // end this row

        spaces -= 2;                        // the arms move one step closer
    }

    // Middle row: the crossing point sits exactly N/2 spaces in.
    for(int i=0; i<N/2; i++){
        cout << " "; // one leading space
    }
    cout << "X" << endl; // the centre, then end the row

    // Bottom half: start close to the centre and open up.
    int space_before_after = N/2 - 1;       // outer spaces on the first bottom row
    int space_between = 1;                  // gap between / and \ on that row
    // Rows N/2 + 1 .. N-1: that is N/2 rows, mirroring the top half.
    for(int i=N/2 + 1; i < N; i++){
        for(int j=0; j<space_before_after; j++){ // left outer spaces
            cout << " ";
        }
        cout << "/"; // the left arm

        for(int k=0; k<space_between; k++){ // the gap
            cout << " ";
        }
        cout << "\\"; // the right arm: one backslash

        for(int l=0; l<space_before_after; l++){ // right outer spaces
            cout << " ";
        }
        cout << endl; // end this row
        space_before_after--;               // arms move outwards...
        space_between += 2;                 // ...so the gap grows by 2
    }

    return 0; // program finished successfully
}
