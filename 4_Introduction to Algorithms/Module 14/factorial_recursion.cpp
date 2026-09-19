// n! = n * (n-1) * ... * 2 * 1, written recursively.
// The definition is already recursive - n! is n times (n-1)! - so the code is
// almost a transcription of it. See recursion.cpp for base case and call stack.

#include <iostream>
#include <vector>
#include <algorithm>    
#include <string>

using namespace std;

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
    if(n == 1){
        return 1;
    }
    return n * fact(n-1);
}

int main(){
    int n;
    cin >> n;
    cout << fact(n) << endl;
    // No `return 0;` here. C++ allows main alone to leave it out and treats the
    // end of main as a successful return 0; every other function must return.
}