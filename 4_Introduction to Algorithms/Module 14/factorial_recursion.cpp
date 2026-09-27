// n! = n * (n-1) * ... * 2 * 1, written recursively.
// The definition is already recursive - n! is n times (n-1)! - so the code is
// almost a transcription of it. See recursion.cpp for base case and call stack.
//
// Recursion in one sentence: a function that calls itself on a SMALLER input,
// plus a BASE CASE - an input small enough to answer directly - so the chain of
// calls stops.

#include <iostream>     // cin, cout, endl
#include <vector>       // not used here
#include <algorithm>    // not used here
#include <string>       // not used here

using namespace std;    // write cout instead of std::cout

// fact(5) = 5 * fact(4) = 5 * 4 * fact(3) = ... = 120, after 5 calls.
// The multiplication happens on the way back up: nothing is multiplied until the
// base case has returned.
//
// Two traps worth knowing, both left in place here:
//   * the base case only catches n == 1. fact(0) goes to -1, -2, -3 ... and never
//     stops, until the stack overflows. `if(n <= 1) return 1;` is the safe form,
//     and it also gives the correct 0! = 1.
//   * the answer is an int, so it overflows silently from 13! upwards
//     (13! = 6227020800, well past the int limit of about 2.1 billion).
int fact(int n) {
    if(n == 1){          // base case: 1! = 1, stop recursing
        return 1;        // BUG: n = 0 (or negative) never reaches here -> endless recursion; use n <= 1
    }
    // Trust that fact(n-1) returns (n-1)! correctly, then multiply by n.
    return n * fact(n-1);
}

int main(){
    int n;                     // the number whose factorial we want
    cin >> n;                  // read it
    cout << fact(n) << endl;   // print n! and a newline (endl also flushes)
    // No `return 0;` here. C++ allows main alone to leave it out and treats the
    // end of main as a successful return 0; every other function must return.
}