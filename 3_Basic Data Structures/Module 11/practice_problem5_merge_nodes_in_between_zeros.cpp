/*

https://leetcode.com/problems/merge-nodes-in-between-zeros/

Merge Nodes in Between Zeros (LeetCode 2181)
A singly linked list starts with a 0 and ends with a 0, and has more zeros
in between. The zeros cut the list into groups. Replace every group by ONE
node holding the sum of that group, and drop all the zeros. Return the head
of the new list. No two zeros are next to each other, so every group has at
least one number.

Example
list 0 3 1 0 4 5 2 0   ->   4 11        (3+1 = 4, 4+5+2 = 11)
list 0 1 0 3 0 2 2 0   ->   1 3 4

Input for this program: the list values ended by -1.
    0 3 1 0 4 5 2 0 -1

*/

/*
 * The idea: walk the list once with a running `sum`.
 *   - a non-zero value  -> add it to `sum`;
 *   - a zero            -> the group before it is finished, so `sum` becomes
 *                          one node of the answer, and `sum` starts again
 *                          from 0.
 * The very first node is the opening 0, so the walk starts on the node
 * after it; otherwise that first zero would close an empty group.
 *
 * The answer list is built with the head/tail insert from Module 6, so each
 * new node is appended in O(1).
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
    ListNode* mergeNodes(ListNode* head) {
        // The answer list, empty for now.
        ListNode* newHead = NULL;
        ListNode* newTail = NULL;

        int sum = 0;
        // Skip the opening 0: the first group starts right after it.
        ListNode* tmp = head->next;
        while(tmp != NULL){
            if(tmp->val == 0){
                // A zero closes the current group: its sum becomes a node.
                ListNode* newNode = new ListNode(sum);
                if(newHead == NULL){
                    newHead = newNode;        // first node of the answer
                    newTail = newNode;
                }
                else{
                    newTail->next = newNode;  // append after the tail
                    newTail = newNode;
                }
                sum = 0;                      // the next group starts fresh
            }
            else{
                sum += tmp->val;              // still inside a group
            }
            tmp = tmp->next;
        }

        return newHead;
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

    cout << "Before: ";
    printList(head);

    Solution sol;
    ListNode* merged = sol.mergeNodes(head);

    cout << "After merging: ";
    printList(merged);

    return 0;
}
