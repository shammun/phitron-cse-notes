// Print an X of height N, where N is odd.
//
// A re-typing of assignment_5_printing_X.cpp, with the same logic. The
// problem statement and the sample pictures are at the top of that file.
//
// Pattern problems all come down to one question: for row i, how many of
// each thing? Every row of the upper half has the shape
//
//     [i spaces] \ [gap spaces] / [i spaces]
//
// The two strokes start at the outside edges and walk inwards, so going down
// one row adds one space in front and takes two away from the gap. Row 0 has
// no leading space and a gap of N - 2; on the last row before the middle the
// strokes are almost touching.
//
// The middle row is a single X after N/2 spaces. N is odd, so N/2 is integer
// division: for N = 5 it is 2, which is both the number of rows above the
// middle and the indent of the X.
//
// The lower half is the mirror image. The strokes swap round to / then \,
// the outside spaces shrink by one per row and the gap grows by two.
//
// Every row is padded with trailing spaces so that all rows are the same
// width, which is what the expected output shows.
//
// One thing that looks like a typo but is not: "\\" in the source is a
// single backslash character. A lone backslash starts an escape sequence, so
// it has to be doubled. "/" needs nothing.
//
// Two harmless oddities left over from typing this out: a doubled semicolon
// after one cout, and no `return 0;` at the end of main. C++ allows main
// alone to end without one - it returns 0 by itself.

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int main(){
    int N;
    cin >> N;

    // N = 1 has no arms at all, just the X. Handling it separately keeps the
    // loops below free of special cases; with N = 1 the gap would start at
    // -1, which no loop could draw.
    if(N == 1){
        cout << "X" << endl;
        return 0;
    }

    // The gap between the two strokes on the very first row: the whole width
    // except the two stroke characters themselves.
    int spaces = N - 2;

    // Upper half: N/2 rows, numbered i = 0 upwards.
    for(int i=0; i<N/2; i++){
        // i spaces in front: row 0 is flush left, each row one step further
        // in.
        for(int j=0; j<i; j++){
            cout << " ";
        }

        cout << "\\";;

        // the gap between the two arms
        for(int j=0; j<spaces; j++){
            cout << " ";
        }

        cout << "/";

        // i spaces after the "/" as well, so every row is the same width
        for(int k=0; k<i; k++){
            cout << " ";
        }

        cout << endl;

        // Both arms move one step inwards on the next row, so the gap loses
        // two, not one.
        spaces -= 2;
    }

    // The middle row: N/2 spaces, then the X.
    for(int i=0; i < N/2; i++){
        cout << " ";
    }

    cout << "X" << endl;

    // Lower half of the X

    // Lower half. On the first row below the middle the arms sit one step in
    // from each edge and one space apart; from there the outside shrinks and
    // the gap grows, so the X opens out again.
    int space_before_after = N/2 - 1;
    int space_between = 1;

    // Counting i from N/2 + 1 up to N-1 is just a way of running the N/2
    // rows that are left; i itself is never used inside the loop.
    for(int i=N/2 + 1; i <N; i++){
        for(int j=0; j<space_before_after; j++){
            cout << " ";
        }
        
        cout << "/";

        for(int k=0;k<space_between; k++){
            cout << " ";
        }

        cout << "\\";

        for(int l=0; l<space_before_after; l++){
            cout << " ";
        }

        cout << endl;
        // The arms move outwards: one less space in front of them, two more
        // between them.
        space_before_after--;
        space_between += 2;
    }
}