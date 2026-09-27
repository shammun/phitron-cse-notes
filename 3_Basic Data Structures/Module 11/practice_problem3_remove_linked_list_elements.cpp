/*

https://leetcode.com/problems/remove-linked-list-elements/

Remove Linked List Elements (LeetCode 203)
Given the head of a singly linked list and a number `val`, delete every node
whose value is `val` and return the (possibly new) head.

Example
list 1 2 6 3 4 5 6, val = 6   ->   1 2 3 4 5
list 7 7 7 7,       val = 7   ->   (empty list)

Input for this program: the list values ended by -1, then `val`.
    1 2 6 3 4 5 6 -1
    6

*/

/*
 * The idea: this is Module 7's "delete a node" done for every match in one
 * walk. Deleting a node in a singly list means standing on the node *before*
 * it and pointing past it: `tmp->next = tmp->next->next`.
 *
 * The head has no node before it, so it is handled first, on its own:
 * while the head holds `val`, move the head one step forward and free the old
 * one. A `while`, not an `if`, because the new head may match too (7 7 7 7).
 *
 * After that the head is safe, and `tmp` walks the rest looking one node
 * ahead:
 *   - next node matches   -> unhook it, and stay where we are, because the
 *                            node that slides in may match as well (6 6);
 *   - next node is fine   -> step forward.
 */

#include <iostream>     // cin (read from keyboard), cout (print), endl
using namespace std;    // lets us write cin/cout instead of std::cin/std::cout

// Definition for singly-linked list (the one LeetCode gives you).
struct ListNode {
    int val;            // the number stored in this node
    ListNode *next;     // address of the next node; nullptr/NULL = no next node
    // Default constructor. ": val(0), next(nullptr)" is an initializer list that
    // sets the members before the empty body {} runs.
    ListNode() : val(0), next(nullptr) {}
    // Constructor with a value: new ListNode(6) -> node holding 6, next = nullptr.
    ListNode(int x) : val(x), next(nullptr) {}
    // Constructor with a value and a pointer to the next node.
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// LeetCode's answer class.
class Solution {
public:     // callable from main
    // head = first node's address, val = the number to wipe out.
    // Returns the new head (it changes if the first nodes are deleted).
    ListNode* removeElements(ListNode* head, int val) {
        // Part 1: delete matching nodes at the front. Each round the head
        // moves one step right and the old head is freed.
        // `head != NULL` is checked FIRST: if the list is empty, && stops there and
        // head->val is never read (reading through NULL would crash).
        while(head != NULL && head->val == val){
            ListNode* deleteNode = head;    // remember the old head so we can free it
            head = head->next;              // the second node becomes the head
            delete deleteNode;              // give the old node's memory back
        }
        // Trace 7 7 7 7, val 7: four rounds, head ends as NULL (empty list).

        // Part 2: the head now holds a different value (or the list is empty).
        // `tmp` stands on a node we keep and inspects the one after it.
        ListNode* tmp = head;
        // Runs while there is a "next node" to inspect; stops at the last node
        // (or at once if the list became empty).
        while(tmp != NULL && tmp->next != NULL){
            if(tmp->next->val == val){          // the node after tmp must go
                ListNode* deleteNode = tmp->next;   // remember it for delete
                tmp->next = tmp->next->next;   // point past the matching node
                delete deleteNode;              // free its memory
                // no step here: the new tmp->next must be checked too
            }
            else{
                tmp = tmp->next;               // keep it and move on
            }
        }
        // Trace 1 2 6 3 4 5 6, val 6: tmp on 2 sees 6 -> unhook -> 1 2 3 4 5 6;
        // ... tmp on 5 sees 6 -> unhook -> 1 2 3 4 5; tmp on 5 has no next -> stop.

        return head;   // may be a different node, or NULL, after Part 1
    }
};

// Append at the end in O(1), because `tail` is remembered.
// `ListNode* &head` = a REFERENCE to the caller's pointer: changing head/tail here
// changes the variables in main too (without & we would only change copies).
void insert_at_tail(ListNode* &head, ListNode* &tail, int val){
    ListNode* newNode = new ListNode(val);  // make the node on the heap
    if(head == NULL){       // empty list: the new node is both first and last
        head = newNode;
        tail = newNode;
        return;             // done, nothing to link
    }
    tail->next = newNode;   // old last node now points to the new node
    tail = newNode;         // the new node is the last node now
}

// Helper function to print the linked list, e.g. "1 2 3 4 5 ".
void printList(ListNode* head) {
    if(head == NULL){           // nothing to print: say so
        cout << "(empty)";
    }
    // One pass per node; head is a copy of the caller's pointer, so moving it is safe.
    while(head != NULL) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;               // end the line
}

int main() {
    ListNode* head = NULL;      // empty list to start: no first node...
    ListNode* tail = NULL;      // ...and no last node

    // Read the list until -1.
    int x;
    // while(true) loops forever; the `break` inside is the only way out.
    while(true){
        cin >> x;               // cin >> skips spaces/newlines and reads the next number
        if(x == -1){            // -1 is the "end of list" marker, not a value
            break;              // leave the loop
        }
        insert_at_tail(head, tail, x);  // add x to the end of the list
    }

    // The value to remove.
    int val;
    cin >> val;

    cout << "Before: ";
    printList(head);            // Before: 1 2 6 3 4 5 6

    Solution sol;               // object needed to call the member function
    head = sol.removeElements(head, val);   // keep the returned head!
    // (tail is not used after this, so it is fine that it may now point to a deleted node.)

    cout << "After removing " << val << ": ";
    printList(head);            // After removing 6: 1 2 3 4 5

    return 0;                   // normal end (the remaining nodes are not freed; the OS reclaims them)
}
