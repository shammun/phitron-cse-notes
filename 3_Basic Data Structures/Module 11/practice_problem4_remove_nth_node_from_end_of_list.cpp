/*

https://leetcode.com/problems/remove-nth-node-from-end-of-list/

Remove Nth Node From End of List (LeetCode 19)
You get the head of a singly linked list and a number `n`. Delete the node
that is `n` places from the END of the list (n = 1 is the last node) and
return the head of the list that is left. `n` is always between 1 and the
size of the list.

Example
list 1 2 3 4 5, n = 2   ->   1 2 3 5      (4 is 2nd from the end)
list 1,         n = 1   ->   (empty list)
list 1 2,       n = 1   ->   1

Input for this program: the list values ended by -1, then `n`.
    1 2 3 4 5 -1
    2

*/

/*
 * The idea: "n-th from the end" is just "some index from the front" once we
 * know the size. In a list of `size` nodes, the n-th node from the end sits
 * at 0-based index `size - n`:
 *     1 2 3 4 5, size 5, n = 2  ->  index 5 - 2 = 3, which holds 4.
 *
 * So the job becomes two things we already know from Module 6 and 7:
 *   1. walk the list once and count its size;
 *   2. delete the node at index `size - n`.
 *
 * Deleting at an index in a singly list means standing on the node BEFORE it
 * (index - 1) and pointing past it. Index 0 (the head) has no node before it,
 * so it is handled on its own: the head just moves one step forward. That
 * happens exactly when n == size, e.g. the one-node list with n = 1.
 */

#include <iostream>     // cin, cout, endl
using namespace std;    // write cin/cout without the std:: prefix

// Definition for singly-linked list (the one LeetCode gives you).
struct ListNode {
    int val;            // the number in this node
    ListNode *next;     // address of the next node (nullptr at the end)
    // Default constructor; the ": ..." initializer list sets the members.
    ListNode() : val(0), next(nullptr) {}
    // Constructor with a value: new ListNode(4) -> node 4 with no next.
    ListNode(int x) : val(x), next(nullptr) {}
    // Constructor with a value and a pointer to the next node.
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// LeetCode's answer class.
class Solution {
public:     // callable from main
    // Deletes the n-th node from the end and returns the (maybe new) head.
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        // Step 1: count the nodes.
        int size = 0;               // counter
        ListNode* tmp = head;       // walker, starts at the head
        // One pass per node; stops when tmp walks past the last node.
        while(tmp != NULL){
            size++;                 // count this node
            tmp = tmp->next;        // '->' reads a member through a pointer: step forward
        }

        // The node to delete, counted from the front (0-based).
        int idx = size - n;         // 1 2 3 4 5, n = 2 -> idx 3 (the node holding 4)

        // Step 2a: deleting the head. Nothing stands before it, so the
        // head itself moves to the second node (or NULL if it was alone).
        if(idx == 0){
            ListNode* deleteNode = head;    // remember the old head
            head = head->next;              // second node (or NULL) becomes the head
            delete deleteNode;              // free the old head's memory
            return head;                    // done early
        }

        // Step 2b: stop on the node just before the victim (index idx - 1).
        // Starting on index 0, we need idx - 1 steps.
        tmp = head;
        // i runs 1 .. idx-1, so the body runs idx-1 times (one step each).
        // Example idx = 3: 2 steps -> tmp on index 2 (the node holding 3).
        for(int i = 1; i < idx; i++){
            tmp = tmp->next;
        }

        // Point past the victim, then free it.
        ListNode* deleteNode = tmp->next;   // the victim (node 4 in the example)
        tmp->next = tmp->next->next;        // 3 now points straight to 5
        delete deleteNode;                  // free the victim

        return head;   // the head only changes in Step 2a
    }
};

// Append at the end in O(1), because `tail` is remembered.
// `ListNode* &head` is a reference to the caller's pointer, so assignments here
// update main's head/tail directly.
void insert_at_tail(ListNode* &head, ListNode* &tail, int val){
    ListNode* newNode = new ListNode(val);  // new node on the heap
    if(head == NULL){       // first node ever: it is head and tail
        head = newNode;
        tail = newNode;
        return;
    }
    tail->next = newNode;   // link after the current last node
    tail = newNode;         // it becomes the new last node
}

// Helper function to print the linked list.
void printList(ListNode* head) {
    if(head == NULL){           // empty list message
        cout << "(empty)";
    }
    // Print every value followed by a space; head is a local copy, safe to move.
    while(head != NULL) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    ListNode* head = NULL;      // start with an empty list
    ListNode* tail = NULL;

    // Read the list until -1.
    int x;
    while(true){                // endless loop, left only by `break`
        cin >> x;               // read the next number (spaces/newlines are skipped)
        if(x == -1){            // sentinel value: stop reading
            break;
        }
        insert_at_tail(head, tail, x);
    }

    // Which node from the end to remove.
    int n;
    cin >> n;

    cout << "Before: ";
    printList(head);            // Before: 1 2 3 4 5

    Solution sol;               // object to call the member function on
    head = sol.removeNthFromEnd(head, n);   // keep the returned head!

    cout << "After removing node " << n << " from the end: ";
    printList(head);            // After removing node 2 from the end: 1 2 3 5

    return 0;                   // normal exit
}
