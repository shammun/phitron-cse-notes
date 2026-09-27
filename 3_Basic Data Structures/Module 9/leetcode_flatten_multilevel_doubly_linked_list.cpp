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

#include <iostream>   // cin and cout
#include <string>     // std::string, and stoi (text -> int)
using namespace std; // Allows us to avoid prefixing standard library objects with `std::`.

// The node LeetCode gives you: a doubly linked node with one extra link.
class Node {
    public:            // members below are usable from outside the class
        int val;       // the value
        Node* prev;    // node before this one on the same level (NULL = none)
        Node* next;    // node after this one on the same level (NULL = none)
        Node* child;   // head of a lower-level list hanging from this node (NULL = none)

    // Constructor: runs on `new Node(x)`; `this->val` is the member, `val` the parameter.
    Node(int val) {
        this->val = val;
        this->prev = NULL;    // no links yet
        this->next = NULL;
        this->child = NULL;
    }
};

// LeetCode wraps the answer in a class called Solution.
class Solution {
public:
    // Flatten the list in place and return its head (the head never changes).
    // Idea: walk the top level with `cur`. Whenever `cur` has a child list,
    // splice that whole child list in between `cur` and `cur->next`. The walk
    // then continues INTO the spliced nodes, so deeper children get the same
    // treatment later. Every node is walked over at most twice: O(n).
    //
    // Trace with 1 2 3 { 7 8 9 } 4:
    //   cur=3 has child 7: 3 -> 7 8 9 -> 4, child of 3 cleared
    //   cur moves on through 7, 8, 9, 4 - none has a child - done.
    Node* flatten(Node* head) {
        Node* cur = head;   // the node we are looking at

        while(cur != NULL){                 // until we walk off the end
            if(cur->child != NULL){         // this node has a child list to splice in
                /* Save the rest of this level before touching `cur->next`,
                   otherwise those nodes become unreachable. */
                Node* nextNode = cur->next;

                Node* childHead = cur->child;   // first node of the child list
                cur->child = NULL; // the answer must have no child links left

                // Put the child list right after `cur`, both links as always.
                cur->next = childHead;          // cur -> first child
                childHead->prev = cur;          // cur <- first child

                /* Walk to the end of the child chain. Its own children are
                   still in place; the outer loop will reach them later and
                   splice them in the same way, so one walk is enough here. */
                Node* childTail = childHead;
                while(childTail->next != NULL){   // stops on the last node of the child level
                    childTail = childTail->next;
                }

                // Re-attach the rest of the level after that end.
                childTail->next = nextNode;       // last child -> saved rest (may be NULL)
                if(nextNode != NULL){             // there is a rest to link back
                    nextNode->prev = childTail;   // last child <- saved rest
                }
            }

            cur = cur->next;   // next node - which is the first child if we just spliced
        }

        return head;
    }
};

/* Reads one chain of nodes. A `{` means "the node just built has a child
   list", so we call this same function again for it; a `}` ends the chain we
   are in. At the top level there is no `}`, so it stops at the end of input. */
// Returns the head of the chain it read (a recursive-descent reader: each
// call handles one level; the recursive call trusts itself to read exactly
// one child list up to its matching `}`).
Node* build_list(){
    Node* head = NULL;   // first node of this chain (none yet)
    Node* tail = NULL;   // last node of this chain (none yet)

    string token;        // one word of input: a number, "{" or "}"
    // `cin >> token` reads one word; the loop ends when the input runs out.
    while(cin >> token){
        if(token == "}"){
            break;           // this chain is finished
        }
        if(token == "{"){
            tail->child = build_list();   // read the child list of the last node built
            continue;                     // skip the rest of this round, read the next word
        }

        // `stoi` turns text like "12" into the int 12.
        Node* newNode = new Node(stoi(token));   // `new` makes the node on the heap
        if(head == NULL){          // first node of this chain
            head = newNode;
            tail = newNode;
        } else {                   // append after the last node, both links
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }

    return head;
}

// Main function: Entry point of the program.
int main(){
    Node* head = build_list();          // read the whole multilevel list

    // `Solution()` makes a temporary Solution object and calls flatten on it.
    head = Solution().flatten(head);

    cout << "forward: ";
    Node* tail = NULL;
    // Walk forward: start at head, stop at NULL, step with ->next.
    for(Node* tmp = head; tmp != NULL; tmp = tmp->next){
        cout << " " << tmp->val;
        tail = tmp; // remember the last node so we can walk back from it
    }
    cout << endl;   // end the line (endl = newline + flush)

    cout << "backward:";
    // Walk backward from the last node using ->prev; proves the prev links are right.
    for(Node* tmp = tail; tmp != NULL; tmp = tmp->prev){
        cout << " " << tmp->val;
    }
    cout << endl;

    return 0;   // normal exit
}
