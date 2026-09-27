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

#include <iostream>   // cin (keyboard input) and cout (screen output)
#include <vector>   // std::vector (a resizable array) - not used in this file
#include <algorithm>   // sort, reverse, swap, max, min ... - not used in this file
#include <string>   // std::string - not used in this file
using namespace std; // Allows us to avoid prefixing standard library objects with `std::`.

// The plain singly linked node: a value and one arrow forward.
class Node{   // one node: a value plus a link to the next node
    public:   // members below are usable from outside the class
        int val;   // the value this node carries
        Node* next;   // address of the node after this one (NULL = none)

    Node(int val){   // constructor: runs on `new Node(x)`
        this->val = val;   // `this->val` = the member, plain `val` = the parameter
        this->next = NULL;   // not linked to anything yet
    }
};



// main: build the list by hand, then run the tortoise-and-hare test on it.
int main(){
    // Five nodes, made one by one. Nothing is read from the input here, so
    // the shape of the list is entirely under our control - which is what we
    // want when testing a detector.
    Node* head = new Node(10);   // first node (`new` makes it on the heap and returns its address)
    Node* a = new Node(20);   // second node
    Node* b = new Node(30);   // third node
    Node* c = new Node(40);   // fourth node
    Node* d = new Node(50);   // fifth (last) node

    // Wire them up: 10 -> 20 -> 30 -> 40 -> 50.
    head->next = a;   // 10 -> 20
    a->next = b;   // 20 -> 30
    b->next = c;   // 30 -> 40
    c->next = d;   // 40 -> 50
    // And the line that closes the loop: the last node points back at the
    // second one, so 20 -> 30 -> 40 -> 50 -> 20 goes round for ever. Note
    // that the loop does not have to include the head.
    d->next = a;   // 50 -> 20: the cycle

    // Both runners start on the same node.
    Node* slow = head;   // the tortoise: 1 step per round
    Node* fast = head;   // the hare: 2 steps per round
    // `break` leaves the loop without saying why it stopped, so we record
    // the reason in a flag and read it afterwards.
    bool flag = false;   // true = a cycle was found

    // Keep going while `fast` can still take two steps. Both tests are
    // needed, and in this order: `fast->next` must not be read unless `fast`
    // itself is a real node.
    while(fast != NULL && fast->next != NULL){
        // Here is the bug: on the first round neither pointer has moved yet,
        // so both are still on `head` and this is true at once. The compare
        // belongs *after* the two moves below.
        // BUG: compares before moving, so it is true on round 1 for any list of
        // 2+ nodes. Fix: move `slow = slow->next; fast = fast->next->next;`
        // above this `if`.
        if(slow == fast){
            flag = true;   // remember that the two met
            break;   // stop the walk
        }
        
        // One step for the tortoise, two for the hare. Inside a loop the hare
        // gains exactly one node on the tortoise per round, so the distance
        // between them shrinks to zero and they land on the same node.
        slow = slow->next;   // tortoise: one node
        fast = fast->next->next;   // hare: two nodes
    }

    // Report what the walk found.
    if(flag == true){   // the pointers met
        cout << "Cycle Detected" << endl;   // endl = newline + flush
    }
    else{
        cout << "No Cycle" << endl;   // fast reached the end
    }

    return 0;   // 0 = the program ended normally
}
