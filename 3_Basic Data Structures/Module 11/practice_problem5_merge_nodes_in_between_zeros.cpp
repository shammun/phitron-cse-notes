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

#include <iostream>     // cin, cout, endl
using namespace std;    // no need to write std:: before cin/cout

// Definition for singly-linked list (the one LeetCode gives you).
struct ListNode {
    int val;            // the number in this node
    ListNode *next;     // address of the next node (nullptr = end of list)
    // Default constructor; ": val(0), next(nullptr)" sets the members up front.
    ListNode() : val(0), next(nullptr) {}
    // Constructor with a value: new ListNode(4) -> node 4, next = nullptr.
    ListNode(int x) : val(x), next(nullptr) {}
    // Constructor with a value and a pointer to the next node.
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// LeetCode's answer class.
class Solution {
public:     // callable from main
    // Builds and returns a NEW list of group sums; the input list is only read.
    ListNode* mergeNodes(ListNode* head) {
        // The answer list, empty for now.
        ListNode* newHead = NULL;   // first node of the answer
        ListNode* newTail = NULL;   // last node of the answer (for O(1) appends)

        int sum = 0;                // running total of the current group
        // Skip the opening 0: the first group starts right after it.
        ListNode* tmp = head->next;
        // One pass per input node; stops after the closing 0 (its next is NULL).
        while(tmp != NULL){
            if(tmp->val == 0){
                // A zero closes the current group: its sum becomes a node.
                ListNode* newNode = new ListNode(sum);
                if(newHead == NULL){
                    newHead = newNode;        // first node of the answer
                    newTail = newNode;        // it is also the last one
                }
                else{
                    newTail->next = newNode;  // append after the tail
                    newTail = newNode;        // the new node is the tail now
                }
                sum = 0;                      // the next group starts fresh
            }
            else{
                sum += tmp->val;              // still inside a group
            }
            tmp = tmp->next;                  // move to the next input node
        }
        // Trace 0 3 1 0 4 5 2 0: sum 3, 4, zero -> node 4; sum 4, 9, 11, zero -> node 11.

        return newHead;             // head of "4 11"
    }
};

// Append at the end in O(1), because `tail` is remembered.
// `ListNode* &head` = reference to main's pointer, so main sees the changes.
void insert_at_tail(ListNode* &head, ListNode* &tail, int val){
    ListNode* newNode = new ListNode(val);  // new node on the heap
    if(head == NULL){       // empty list: new node is head and tail
        head = newNode;
        tail = newNode;
        return;
    }
    tail->next = newNode;   // hook it after the last node
    tail = newNode;         // and remember it as the last node
}

// Helper function to print the linked list.
void printList(ListNode* head) {
    if(head == NULL){           // nothing in the list
        cout << "(empty)";
    }
    // Print each value and a space; head is a copy, so moving it is harmless.
    while(head != NULL) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    ListNode* head = NULL;      // empty input list
    ListNode* tail = NULL;

    // Read the list until -1.
    int x;
    while(true){                // repeat until `break`
        cin >> x;               // read one number
        if(x == -1){            // -1 marks the end of input
            break;
        }
        insert_at_tail(head, tail, x);
    }

    cout << "Before: ";
    printList(head);            // Before: 0 3 1 0 4 5 2 0

    Solution sol;               // object to call mergeNodes on
    ListNode* merged = sol.mergeNodes(head);    // a separate, new list

    cout << "After merging: ";
    printList(merged);          // After merging: 4 11

    return 0;                   // normal exit
}
