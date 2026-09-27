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
    ListNode* removeElements(ListNode* head, int val) {
        // Part 1: delete matching nodes at the front. Each round the head
        // moves one step right and the old head is freed.
        while(head != NULL && head->val == val){
            ListNode* deleteNode = head;
            head = head->next;
            delete deleteNode;
        }

        // Part 2: the head now holds a different value (or the list is empty).
        // `tmp` stands on a node we keep and inspects the one after it.
        ListNode* tmp = head;
        while(tmp != NULL && tmp->next != NULL){
            if(tmp->next->val == val){
                ListNode* deleteNode = tmp->next;
                tmp->next = tmp->next->next;   // point past the matching node
                delete deleteNode;
                // no step here: the new tmp->next must be checked too
            }
            else{
                tmp = tmp->next;               // keep it and move on
            }
        }

        return head;   // may be a different node, or NULL, after Part 1
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

    // The value to remove.
    int val;
    cin >> val;

    cout << "Before: ";
    printList(head);

    Solution sol;
    head = sol.removeElements(head, val);   // keep the returned head!

    cout << "After removing " << val << ": ";
    printList(head);

    return 0;
}
