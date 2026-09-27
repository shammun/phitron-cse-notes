#include <iostream> // cout
using namespace std; // Allows us to avoid prefixing standard library objects with `std::`.

/*
    No linked list in this file. It is here to isolate one idea before the next file uses
    it on a list: a recursive function does work twice - once on the way down, before it
    calls itself, and once on the way back up, after the call returns. Which side you put
    the printing on decides the order the numbers come out in.

    The two functions below are the same function except for the order of two lines.
    (A recursive function is one that calls itself with a smaller job.)
    Output: 1 2 3 4 5 then 5 4 3 2 1, one number per line.
*/

// Print on the way DOWN: print first, then recurse.
// Parameters: i = the current number, n = the last number to print. Returns nothing.
void recursion_1_to_n(int i, int n){
    // Base case. Every recursion needs one line that returns without calling again,
    // or the calls never stop. Here it is "i has gone past n, there is nothing left".
    if(i > n){
        return; // stop this call and go back to the caller
    }
    cout << i << endl;             // done before the deeper call is even made
    recursion_1_to_n(i+1, n);      // i+1 is what moves us towards the base case
    // Trust: this call prints i+1 .. n in order, so together we print i .. n.
}

// Print on the way UP: recurse first, print afterwards.
void recursion_n_to_1(int i, int n){
    if(i > n){ // base case: nothing left
        return; // go back up
    }
    recursion_n_to_1(i+1, n);      // go all the way to the bottom first
    // Trust: that call has printed n down to i+1; now we add i after them.
    cout << i << endl;             // this line waits until that whole call has finished
    // So the call with i = 5 is the deepest one that prints, and it prints first. Then
    // the call with i = 4 resumes and prints, then 3, 2, 1. The numbers come out in
    // reverse without ever walking backwards - the call stack remembers them for us.
}

int main(){ // the program starts running here
    // Print 1 to 5
    recursion_1_to_n(1, 5);

    // Print 5 to 1
    recursion_n_to_1(1, 5);

    // Cost of either one: n calls, so O(n) time, and O(n) memory for the call stack,
    // because all n calls are alive at once at the deepest point. That stack is the
    // price of the reverse order - and it is why very long lists can overflow it.
    //
    // The next file, reverse_linked_list_printing.cpp, is recursion_n_to_1 with
    // `i+1` replaced by `tmp->next` and `i > n` replaced by `tmp == NULL`. Nothing else
    // changes: that is how a singly linked list gets printed backwards even though its
    // pointers only go forward.

    return 0; // program finished successfully
}
