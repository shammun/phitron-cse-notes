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

#include <bits/stdc++.h>
using namespace std;

// An iterator is the `list` version of "a pointer to a node". `begin()` is the first
// element, `end()` is one past the last (a stop marker, not an element), `*it` reads the
// value and `it++` moves one node forward.
// The list is taken by reference to avoid copying every node on each call; it is not
// modified here.
void print_forward(list<int> &l){
    cout << "L -> ";
    for(auto it=l.begin(); it!=l.end(); it++){
        cout << *it << " ";
    }
    cout << endl;
}

void print_backward(list<int> &l){
    cout << "R -> ";
    // Nothing to walk over, and the code below would step back from an empty list.
    if(l.empty()){
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
        cout << *it << " ";
        if(it == l.begin()){
            break;
        }
        it--;   // a list iterator can go backwards; a forward_list one cannot
    }
    cout << endl;
}

// BUG (left in place on purpose): the function has no name. It should be
//     void insert_at_any_position(list<int> &l, int X, int V){
// because that is what main calls below. The compiler reports "invalid declarator before
// '&' token" here and then "'insert_at_any_position' was not declared in this scope" at
// the call, so the file produces no output at all.
void (list<int> &l, int X, int V){
    // Valid indexes are 0..size, not 0..size-1: index `size` means "append at the end",
    // which is a legal place to insert even though there is no element there yet.
    int size = l.size();
    if(X < 0 || X > size){
        cout << "Invalid" << endl;
        return;
    }

    // A list has no l[X], so walk there: X steps from the front leaves `it` on the
    // element currently at index X. When X == size the loop ends exactly on end().
    auto it = l.begin();
    for(int i=0; i < X; i++){
        it++;
    }
    // insert() puts the value BEFORE the iterator, so the new value takes over index X
    // and everything from X onwards shifts one place right. Inserting before end() is
    // therefore an append - which is why X == size needs no special case here.
    l.insert(it, V);

    // The two prints are the check: the R line must read exactly like the L line
    // reversed. Each query costs O(X) for the walk plus O(n) for the two prints.
    print_forward(l);
    print_backward(l);
}

int main(){
    int Q;
    cin >> Q;
    // The list starts empty, so the only valid index for the first query is 0.
    list<int> l;
    // `while(Q--)` runs Q times: the value of Q is tested first and then decreased, so
    // the loop stops when the test sees 0.
    while(Q--){
        int X, V;
        cin >> X >> V;
        insert_at_any_position(l, X, V);
    }
    return 0;
}