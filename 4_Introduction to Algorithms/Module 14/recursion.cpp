// Recursion warm-up, and the first step towards dynamic programming.
//
// A recursive function solves a problem by calling itself on a SMALLER version of
// the same problem. Two parts are needed, always:
//   * a base case - a size so small the answer is known outright, with no further
//     call. Leave it out and the calls never stop and the stack overflows.
//   * a recursive step - do one small piece of work here, hand the rest onwards.
//
// Each live call keeps its own copy of its parameters on the call stack, which is
// why k nested calls cost O(k) memory as well as O(k) time.
//
// Three tiny functions below show the pattern, and in particular what changes
// when the work is done BEFORE the call rather than AFTER it.

#include <iostream>
#include <vector>
#include <algorithm>    
#include <string>

using namespace std;

// Add up n, n+1, ... , 5.
// Base case: once n has gone past 5 there is nothing left to add, so 0 - the
// value that changes no sum. Otherwise: this call is responsible for n alone and
// trusts the next call with the rest.
// sum(1) = 1 + sum(2) = 1 + 2 + sum(3) = ... = 15, after 6 calls.
int sum_from_1_to_5(int n){
    if(n > 5){
        return 0;
    }
    return n + sum_from_1_to_5(n + 1);
}

// Print 1 to 5

// Printing happens BEFORE the call, so each number appears on the way down:
// 1, then 2, ... The call tree is a straight chain 1 -> 2 -> 3 -> 4 -> 5 -> 6,
// and the last call does nothing but return.
void print_one_to_five(int n){
    if(n > 5){
        return;
    }
    cout << n << endl;
    print_one_to_five(n + 1);
}

// Exactly the same two lines, swapped. The call goes first, so nothing is
// printed until the deepest call has returned; then the numbers come out while
// the stack unwinds, biggest first. Two lines in a different order, and the
// output is reversed - that is the one idea this function is here to show.
void print_five_to_one(int n){
    if(n > 5){
        return;
    }
    print_five_to_one(n + 1);
    cout << n << endl;
}

int main(){
    print_one_to_five(1);
    // Careful: the name promises 5, 4, 3, 2, 1, but the count still runs UPWARDS
    // from the number given. Starting at 5 makes just one call, so only "5" is
    // printed - which is what this program's output shows. print_five_to_one(1)
    // is the call that prints 5 4 3 2 1. The code is left as it was written.
    print_five_to_one(5);

    int sum = sum_from_1_to_5(1);
    cout << "Sum from 1 to 5 is " << sum << endl;
    return 0;
}