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

/*
 * The idea: for each row, count how many spaces go where.
 *
 * Upper half (N/2 rows, row i = 0, 1, ...):
 *     i spaces, a back-slash, "spaces" gap spaces, a slash, i spaces
 *   The gap starts at N - 2 (full width minus the two strokes) and shrinks
 *   by 2 each row, because both strokes move one step inwards.
 * Middle row: N/2 spaces then X. (N/2 is integer division: 5/2 = 2.)
 * Lower half (N/2 rows): the mirror image - a slash first, then a
 *   back-slash; the outside spaces shrink by 1 per row, the gap grows by 2.
 *
 * Trace for N = 5 (dots stand for spaces):
 *     row 0: 0 before, gap 3   ->  \.../
 *     row 1: 1 before, gap 1   ->  .\./.
 *     middle: 2 spaces + X     ->  ..X
 *     lower 1: 1 outside, gap 1 -> ./.\.
 *     lower 2: 0 outside, gap 3 -> /...\
 *
 * In C++ source, "\\" is ONE back-slash character: a single back-slash
 * inside quotes starts an escape sequence (like \n), so it must be doubled.
 *
 * C++ pieces used: #include <iostream> gives cin (read) and cout (print);
 * cout << x prints x, endl ends the line. <vector>, <algorithm>, <string>
 * are not used. using namespace std; lets us skip the std:: prefix.
 */
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int main() {        // the program starts here
    int N;          // the height (and width) of the X; always odd
    cin >> N;       // read N

    /* N = 1 is just a single X with no arms. Handled on its own because
       the gap below would start at 1 - 2 = -1. */
    if(N == 1){
        cout << "X" << endl;
        return 0;   // done: end the program
    }

    int spaces = N - 2;     // gap between the two strokes on row 0

    /* Upper half: rows i = 0 .. N/2 - 1. */
    for(int i=0; i < N/2; i++){
        for(int j=0; j <i; j++){    // i leading spaces
            cout << " ";
        }
        cout << "\\";               // one back-slash (written doubled in code)

        for(int j=0; j< spaces; j++){   // the gap
            cout << " ";
        }
        cout << "/";                // the right-hand stroke

        for(int k=0; k<i; k++){     // i trailing spaces, so all rows are N wide
            cout << " ";
        }
        cout << endl;               // finish this row

        spaces -= 2;                // next row: both strokes one step inwards
    }

    /* Middle row: N/2 spaces, then the X in the centre column. */
    for(int i=0; i<N/2; i++){
        cout << " ";
    }
    cout << "X" << endl;

    /* Lower half. Its first row has the strokes one step in from each
       edge-to-centre position: N/2 - 1 spaces outside, 1 space between. */
    int space_before_after = N/2 - 1;
    int space_between = 1;
    /* N/2 more rows. i runs from N/2 + 1 to N - 1 only to count them;
       its value is not used inside. */
    for(int i=N/2 + 1; i < N; i++){
        for(int j=0; j<space_before_after; j++){    // outside spaces (left)
            cout << " ";
        }
        cout << "/";                                // left stroke

        for(int k=0; k<space_between; k++){         // the gap
            cout << " ";
        }
        cout << "\\";                               // right stroke: one back-slash

        for(int l=0; l<space_before_after; l++){    // outside spaces (right)
            cout << " ";
        }
        cout << endl;               // finish this row
        space_before_after--;       // strokes move outwards: one less outside...
        space_between += 2;         // ...and two more in the middle
    }

    return 0;       // 0 = finished normally
}