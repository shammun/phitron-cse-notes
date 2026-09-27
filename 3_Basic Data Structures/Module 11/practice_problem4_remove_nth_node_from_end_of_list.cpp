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

#include <iostream>
using namespace std;

// Definition for singly-linked list (the one LeetCode gives you).
struct ListNode {
    int val;
    ListNode *next;
    // Default constructor.
    ListNode() : val(0), next(nullptr) {}
    // Constructor with a value.
    ListNode(int x) : val(x), next(nullptr) {}
    // Constructor with a value and a pointer to the next node.
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        // Step 1: count the nodes.
        int size = 0;
        ListNode* tmp = head;
        while(tmp != NULL){
            size++;
            tmp = tmp->next;
        }

        // The node to delete, counted from the front (0-based).
        int idx = size - n;

        // Step 2a: deleting the head. Nothing stands before it, so the
        // head itself moves to the second node (or NULL if it was alone).
        if(idx == 0){
            ListNode* deleteNode = head;
            head = head->next;
            delete deleteNode;
            return head;
        }

        // Step 2b: stop on the node just before the victim (index idx - 1).
        // Starting on index 0, we need idx - 1 steps.
        tmp = head;
        for(int i = 1; i < idx; i++){
            tmp = tmp->next;
        }

        // Point past the victim, then free it.
        ListNode* deleteNode = tmp->next;
        tmp->next = tmp->next->next;
        delete deleteNode;

        return head;   // the head only changes in Step 2a
    }
};

// Append at the end in O(1), because `tail` is remembered.
void insert_at_tail(ListNode* &head, ListNode* &tail, int val){
    ListNode* newNode = new ListNode(val);
    if(head == NULL){
        head = newNode;
        tail = newNode;
        return;
    }
    tail->next = newNode;
    tail = newNode;
}

// Helper function to print the linked list.
void printList(ListNode* head) {
    if(head == NULL){
        cout << "(empty)";
    }
    while(head != NULL) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    ListNode* head = NULL;
    ListNode* tail = NULL;

    // Read the list until -1.
    int x;
    while(true){
        cin >> x;
        if(x == -1){
            break;
        }
        insert_at_tail(head, tail, x);
    }

    // Which node from the end to remove.
    int n;
    cin >> n;

    cout << "Before: ";
    printList(head);

    Solution sol;
    head = sol.removeNthFromEnd(head, n);   // keep the returned head!

    cout << "After removing node " << n << " from the end: ";
    printList(head);

    return 0;
}
