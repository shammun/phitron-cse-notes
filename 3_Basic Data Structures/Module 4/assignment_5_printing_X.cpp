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

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int main() {
    int N;
    cin >> N;

    /*
     * The X has three parts for N = 5:
     *   top half (N/2 rows):     \   /     row i: i spaces, \, gap, /, i spaces
     *                             \ /      the gap starts at N-2 and shrinks by 2
     *   middle row:                X       N/2 spaces, then X
     *   bottom half (N/2 rows):   / \      the mirror image: outer spaces shrink,
     *                            /   \     the gap grows by 2 each row
     */

    // N = 1 has no arms at all, only the centre.
    if(N == 1){
        cout << "X" << endl;
        return 0;
    }

    int spaces = N - 2;         // gap between \ and / on the first row

    // Top half.
    for(int i=0; i < N/2; i++){
        for(int j=0; j <i; j++){            // i spaces on the left
            cout << " ";
        }
        cout << "\\";                       // "\\" in C++ prints one backslash

        for(int j=0; j< spaces; j++){       // the gap
            cout << " ";
        }
        cout << "/";

        for(int k=0; k<i; k++){             // i spaces on the right
            cout << " ";
        }
        cout << endl;

        spaces -= 2;                        // the arms move one step closer
    }

    // Middle row: the crossing point sits exactly N/2 spaces in.
    for(int i=0; i<N/2; i++){
        cout << " ";
    }
    cout << "X" << endl;

    // Bottom half: start close to the centre and open up.
    int space_before_after = N/2 - 1;       // outer spaces on the first bottom row
    int space_between = 1;                  // gap between / and \ on that row
    for(int i=N/2 + 1; i < N; i++){
        for(int j=0; j<space_before_after; j++){
            cout << " ";
        }
        cout << "/";

        for(int k=0; k<space_between; k++){
            cout << " ";
        } 
        cout << "\\";

        for(int l=0; l<space_before_after; l++){
            cout << " ";
        }
        cout << endl;
        space_before_after--;               // arms move outwards...
        space_between += 2;                 // ...so the gap grows by 2
    }

    return 0;
}