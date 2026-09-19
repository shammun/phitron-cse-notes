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

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std; 

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
    // Five nodes built by hand - no input is read.
    Node* head = new Node(10);
    Node* a = new Node(20);
    Node* b = new Node(30);
    Node* c = new Node(40);
    Node* d = new Node(50);
    
    // 10 -> 20 -> 30 -> 40 -> 50 ...
    head->next = a;
    a->next = b;
    b->next = c;
    c->next = d;
    // ... and then back from 50 to 20, which closes the loop.
    d->next = a;

    // Both runners start at the head; `flag` remembers why the loop ended.
    Node* slow = head;
    Node* fast = head;
    bool flag = false;

    // Stop as soon as `fast` cannot take two more steps.
    while(fast != NULL && fast->next != NULL){
        // The bug: this test runs before the first move, when both pointers
        // are still on `head`. It should come after the two lines below.
        if(slow == fast){
            flag = true;
            break;
        }

        // One step, then two steps.
        slow = slow->next;
        fast = fast->next->next;
    }

    if(flag == true){
        cout << "Cycle Detected" << endl;
    }
    else{
        cout << "No Cycle" << endl;
    }

    return 0;
}