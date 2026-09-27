/*

Scratch work for mid-term Q2: read Q queries of the form `X V`, insert V at index X,
print the list forwards and backwards, and print `Invalid` when X is out of range.

mid_term_question_2_queries_again.cpp is the submitted answer and builds its own doubly
linked list by hand. This file tries the same thing with the STL `list<int>`, which is a
doubly linked list that is already written for you. Less code - but a `list` has no `[]`,
so reaching index X means stepping an iterator X times, and that is the part worth
studying here.

As it stands the file does not compile; see the bug note above main.

*/

// <bits/stdc++.h> is a GCC shortcut header that pulls in the whole standard library
// (iostream, list, vector, algorithm, ...), so one include is enough in contests.
#include <bits/stdc++.h>
using namespace std;    // write list/cout/next instead of std::list/std::cout/std::next

// An iterator is the `list` version of "a pointer to a node". `begin()` is the first
// element, `end()` is one past the last (a stop marker, not an element), `*it` reads the
// value and `it++` moves one node forward.
// The list is taken by reference to avoid copying every node on each call; it is not
// modified here.
// Prints "L -> " followed by the values from front to back.
void print_forward(list<int> &l){
    cout << "L -> ";
    // `auto` lets the compiler work out the long type list<int>::iterator for us.
    // One pass = print one value; stops when it reaches end().
    for(auto it=l.begin(); it!=l.end(); it++){
        cout << *it << " ";     // *it = the value the iterator stands on
    }
    cout << endl;               // newline + flush
}

// Prints "R -> " followed by the values from back to front.
void print_backward(list<int> &l){
    cout << "R -> ";
    // Nothing to walk over, and the code below would step back from an empty list.
    if(l.empty()){              // empty() is true when the list has no elements
        cout << endl;
        return;
    }

    // Start at the LAST element. `end()` is one past the end, so it cannot be printed;
    // `next(l.begin(), l.size()-1)` walks size-1 steps from the front instead and lands
    // on the last element.
    auto it = next(l.begin(), l.size()-1);
    // Walking backwards needs a `while(true)` with the test in the middle: begin() is a
    // real element that must be printed, but stepping back from it is not allowed. So
    // print first, then check whether we have just printed the first element, then step.
    // A `while(it != l.begin())` loop would silently skip the very first value.
    while(true){
        cout << *it << " ";     // print the current value
        if(it == l.begin()){    // just printed the first element: done
            break;
        }
        it--;   // a list iterator can go backwards; a forward_list one cannot
    }
    cout << endl;
    // (Tidier alternative: for(auto it = l.rbegin(); it != l.rend(); it++) walks in reverse.)
}

// BUG (left in place on purpose): the function has no name. It should be
//     void insert_at_any_position(list<int> &l, int X, int V){
// because that is what main calls below. The compiler reports "invalid declarator before
// '&' token" here and then "'insert_at_any_position' was not declared in this scope" at
// the call, so the file produces no output at all.
// Intended job: insert V at index X of l (or print Invalid), then print both directions.
void (list<int> &l, int X, int V){
    // Valid indexes are 0..size, not 0..size-1: index `size` means "append at the end",
    // which is a legal place to insert even though there is no element there yet.
    int size = l.size();        // size() = number of elements (stored, so O(1))
    if(X < 0 || X > size){      // || = "or": either condition makes X invalid
        cout << "Invalid" << endl;
        return;                 // stop: no insert, no prints
    }

    // A list has no l[X], so walk there: X steps from the front leaves `it` on the
    // element currently at index X. When X == size the loop ends exactly on end().
    auto it = l.begin();
    for(int i=0; i < X; i++){   // runs X times
        it++;                   // one node forward
    }
    // insert() puts the value BEFORE the iterator, so the new value takes over index X
    // and everything from X onwards shifts one place right. Inserting before end() is
    // therefore an append - which is why X == size needs no special case here.
    // Example: l = 10 20, X = 1, V = 5 -> it on 20 -> l = 10 5 20.
    l.insert(it, V);

    // The two prints are the check: the R line must read exactly like the L line
    // reversed. Each query costs O(X) for the walk plus O(n) for the two prints.
    print_forward(l);
    print_backward(l);
}

int main(){
    int Q;          // number of queries
    cin >> Q;       // cin >> reads a number, skipping spaces/newlines before it
    // The list starts empty, so the only valid index for the first query is 0.
    list<int> l;    // STL doubly linked list of ints
    // `while(Q--)` runs Q times: the value of Q is tested first and then decreased, so
    // the loop stops when the test sees 0.
    while(Q--){
        int X, V;               // X = index, V = value for this query
        cin >> X >> V;          // read both numbers of the query
        insert_at_any_position(l, X, V);    // (fails to compile because of the BUG above)
    }
    return 0;       // normal exit
}