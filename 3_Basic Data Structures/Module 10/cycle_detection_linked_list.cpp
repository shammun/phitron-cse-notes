/*

Does the list loop back on itself? Floyd's "tortoise and hare" test.

LeetCode 141 - Linked List Cycle
https://leetcode.com/problems/linked-list-cycle/

Two pointers start at the head. `slow` moves one node per round, `fast` moves
two. Then one of two things must happen.

If the list ends, `fast` is the one that gets there first and the walk simply
stops - no cycle.

If the list loops, neither pointer can ever leave the loop again, so `fast`
keeps going round and must eventually come up behind `slow`. And it cannot
jump over it. Once both are inside the loop, look at the gap from `fast` to
`slow`, counted forwards around the loop. Every round `fast` closes that gap
by exactly one node: it gains two and `slow` gains one. So the gap goes
5, 4, 3, 2, 1, 0 - it cannot skip a value, and 0 means the two pointers are
standing on the same node. That is the whole proof, and it is also the reason
the stride is two and not three: with a longer stride the gap shrinks by more
than one each round and could step straight over `slow`.

The NULL checks are the other half of the method. `slow` never needs one - it
is always behind `fast`, on ground `fast` has already walked. `fast` is the
one that can fall off the end, and it reads two links per round, so both have
to be checked before it moves: `fast != NULL` (am I still standing on a
node?) and `fast->next != NULL` (is there a second node to jump to?). `&&`
stops at the first false, so `fast->next` is only read once `fast` is known to
be a real node.

The bug in this file (worth seeing, not worth copying): the comparison
`if(slow == fast)` is made at the top of the loop, before either pointer has
moved. On the very first round both are still sitting on `head`, so the test
is true straight away and this program answers "Cycle Detected" for any list
of two or more nodes. It prints the right answer here only because there
really is a cycle. Move both pointers first and compare afterwards. To see it
for yourself, change `d->next = a;` to `d->next = NULL;` below: the answer
should become "No Cycle", and it does not.

No input is read; the list is built by hand in `main`.

*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std; // Allows us to avoid prefixing standard library objects with `std::`.

// The plain singly linked node: a value and one arrow forward.
class Node{
    public:
        int val;
        Node* next;

    Node(int val){
        this->val = val;
        this->next = NULL;
    }
};



int main(){
    // Five nodes, made one by one. Nothing is read from the input here, so
    // the shape of the list is entirely under our control - which is what we
    // want when testing a detector.
    Node* head = new Node(10);
    Node* a = new Node(20);
    Node* b = new Node(30);
    Node* c = new Node(40);
    Node* d = new Node(50);

    // Wire them up: 10 -> 20 -> 30 -> 40 -> 50.
    head->next = a;
    a->next = b;
    b->next = c;
    c->next = d;
    // And the line that closes the loop: the last node points back at the
    // second one, so 20 -> 30 -> 40 -> 50 -> 20 goes round for ever. Note
    // that the loop does not have to include the head.
    d->next = a;

    // Both runners start on the same node.
    Node* slow = head;
    Node* fast = head;
    // `break` leaves the loop without saying why it stopped, so we record
    // the reason in a flag and read it afterwards.
    bool flag = false;

    // Keep going while `fast` can still take two steps. Both tests are
    // needed, and in this order: `fast->next` must not be read unless `fast`
    // itself is a real node.
    while(fast != NULL && fast->next != NULL){
        // Here is the bug: on the first round neither pointer has moved yet,
        // so both are still on `head` and this is true at once. The compare
        // belongs *after* the two moves below.
        if(slow == fast){
            flag = true;
            break;
        }
        
        // One step for the tortoise, two for the hare. Inside a loop the hare
        // gains exactly one node on the tortoise per round, so the distance
        // between them shrinks to zero and they land on the same node.
        slow = slow->next;
        fast = fast->next->next;
    }

    // Report what the walk found.
    if(flag == true){
        cout << "Cycle Detected" << endl;
    }
    else{
        cout << "No Cycle" << endl;
    }

    return 0;
}
