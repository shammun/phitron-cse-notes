/*

Practice copy of cycle_detection_linked_list.cpp, re-typed from memory. It is
the same program line for line - including the bug.

The idea: `slow` takes one step per round, `fast` takes two. Inside a loop
`fast` gains exactly one node on `slow` each round, so the gap between them
shrinks 3, 2, 1, 0 and they must end up on the same node - a fast runner
cannot jump over a slow one when it only gains one place at a time. If the
list ends instead, `fast` is the pointer that runs out first, which is why
both `fast != NULL` and `fast->next != NULL` are checked before it jumps two
nodes. `slow` needs no check: it only walks where `fast` has already been.

The bug, kept from the original: `if(slow == fast)` is tested at the top of
the loop, before the pointers move. On the first round both are still on
`head`, so every list of two or more nodes is reported as having a cycle.
Move the pointers first, then compare.

LeetCode 141 - Linked List Cycle
https://leetcode.com/problems/linked-list-cycle/

*/

#include <iostream>   // cin (keyboard input) and cout (screen output)
#include <vector>   // std::vector (a resizable array) - not used in this file
#include <algorithm>   // sort, reverse, swap, max, min ... - not used in this file
#include <string>   // std::string - not used in this file
using namespace std;   // lets us write cout, list ... instead of std::cout, std::list ...

class Node{   // one node: a value plus a link to the next node
    public:   // members below are usable from outside the class
        int val;   // the value this node carries
        Node* next;   // address of the node after this one (NULL = none)

    Node(int val){   // constructor: runs on `new Node(x)`
        this->val = val;   // `this->val` = the member, plain `val` = the parameter
        this->next = NULL;   // not linked to anything yet
    }
};

// main: build a 5-node list whose last node points back to the
// second one, then run the tortoise-and-hare test on it.
int main(){
    // Five nodes built by hand - no input is read.
    Node* head = new Node(10);   // first node (`new` makes it on the heap and returns its address)
    Node* a = new Node(20);   // second node
    Node* b = new Node(30);   // third node
    Node* c = new Node(40);   // fourth node
    Node* d = new Node(50);   // fifth (last) node
    
    // 10 -> 20 -> 30 -> 40 -> 50 ...
    head->next = a;   // 10 -> 20
    a->next = b;   // 20 -> 30
    b->next = c;   // 30 -> 40
    c->next = d;   // 40 -> 50
    // ... and then back from 50 to 20, which closes the loop.
    d->next = a;   // 50 -> 20: the cycle

    // Both runners start at the head; `flag` remembers why the loop ended.
    Node* slow = head;   // the tortoise: 1 step per round
    Node* fast = head;   // the hare: 2 steps per round
    bool flag = false;   // true = a cycle was found

    // Stop as soon as `fast` cannot take two more steps.
    while(fast != NULL && fast->next != NULL){
        // The bug: this test runs before the first move, when both pointers
        // are still on `head`. It should come after the two lines below.
        // BUG: compares before moving, so it is true on round 1 for any list of
        // 2+ nodes. Fix: move `slow = slow->next; fast = fast->next->next;`
        // above this `if`.
        if(slow == fast){
            flag = true;   // remember that the two met
            break;   // stop the walk
        }

        // One step, then two steps.
        slow = slow->next;   // tortoise: one node
        fast = fast->next->next;   // hare: two nodes
    }

    if(flag == true){   // the pointers met
        cout << "Cycle Detected" << endl;   // endl = newline + flush
    }
    else{
        cout << "No Cycle" << endl;   // fast reached the end
    }

    return 0;   // 0 = the program ended normally
}