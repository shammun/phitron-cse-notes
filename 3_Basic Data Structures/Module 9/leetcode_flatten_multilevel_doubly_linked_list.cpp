/*

Flatten a Multilevel Doubly Linked List   (LeetCode 430)
https://leetcode.com/problems/flatten-a-multilevel-doubly-linked-list/

Every node of this doubly linked list has the usual `val`, `next` and `prev`,
and one extra link: `child`. A `child` may point at the head of another
doubly linked list, whose nodes may again have children, and so on.

Flatten the whole thing into one single-level doubly linked list. Where a node
had a child, that child list must come right after it, and the rest of the
level continues after the last node of the child list. When you are done every
`child` must be NULL, and all the `prev` links must be correct for the new
order. Do it by moving the links, not by building a new list.

Input (for this program, so it can be run here)
The list is written as numbers separated by spaces. Braces hold the child list
of the node written just before them, and may be nested:

  1 2 3 { 7 8 { 11 12 } 9 10 } 4 5 6

means the top level is 1 2 3 4 5 6, node 3 has the child list 7 8 9 10, and
node 8 inside it has the child list 11 12.

Output
Two lines: the flattened list read forward from the head, and the same list
read backward from the tail. The second line is there to prove the `prev`
links are right: it must be the exact reverse of the first one.

Constraints
Values are whole numbers. A child list is never empty (a `{` is always
followed by at least one value before the matching `}`).

Example

input
1 2 3 { 7 8 { 11 12 } 9 10 } 4 5 6

output
forward:  1 2 3 7 8 11 12 9 10 4 5 6
backward: 6 5 4 10 9 12 11 8 7 3 2 1

Second example

input
1 { 2 { 3 } }

output
forward:  1 2 3
backward: 3 2 1

*/

#include <iostream>
#include <string>
using namespace std; // Allows us to avoid prefixing standard library objects with `std::`.

// The node LeetCode gives you: a doubly linked node with one extra link.
class Node {
    public:
        int val;
        Node* prev;
        Node* next;
        Node* child;

    Node(int val) {
        this->val = val;
        this->prev = NULL;
        this->next = NULL;
        this->child = NULL;
    }
};

class Solution {
public:
    Node* flatten(Node* head) {
        Node* cur = head;

        while(cur != NULL){
            if(cur->child != NULL){
                /* Save the rest of this level before touching `cur->next`,
                   otherwise those nodes become unreachable. */
                Node* nextNode = cur->next;

                Node* childHead = cur->child;
                cur->child = NULL; // the answer must have no child links left

                // Put the child list right after `cur`, both links as always.
                cur->next = childHead;
                childHead->prev = cur;

                /* Walk to the end of the child chain. Its own children are
                   still in place; the outer loop will reach them later and
                   splice them in the same way, so one walk is enough here. */
                Node* childTail = childHead;
                while(childTail->next != NULL){
                    childTail = childTail->next;
                }

                // Re-attach the rest of the level after that end.
                childTail->next = nextNode;
                if(nextNode != NULL){
                    nextNode->prev = childTail;
                }
            }

            cur = cur->next;
        }

        return head;
    }
};

/* Reads one chain of nodes. A `{` means "the node just built has a child
   list", so we call this same function again for it; a `}` ends the chain we
   are in. At the top level there is no `}`, so it stops at the end of input. */
Node* build_list(){
    Node* head = NULL;
    Node* tail = NULL;

    string token;
    while(cin >> token){
        if(token == "}"){
            break;
        }
        if(token == "{"){
            tail->child = build_list();
            continue;
        }

        Node* newNode = new Node(stoi(token));
        if(head == NULL){
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }

    return head;
}

// Main function: Entry point of the program.
int main(){
    Node* head = build_list();

    head = Solution().flatten(head);

    cout << "forward: ";
    Node* tail = NULL;
    for(Node* tmp = head; tmp != NULL; tmp = tmp->next){
        cout << " " << tmp->val;
        tail = tmp; // remember the last node so we can walk back from it
    }
    cout << endl;

    cout << "backward:";
    for(Node* tmp = tail; tmp != NULL; tmp = tmp->prev){
        cout << " " << tmp->val;
    }
    cout << endl;

    return 0;
}
