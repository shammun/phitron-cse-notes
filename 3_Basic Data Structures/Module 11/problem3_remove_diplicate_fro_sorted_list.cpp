/*

https://leetcode.com/problems/remove-duplicates-from-sorted-list/description/

The list is sorted. Delete the repeated values so each value appears once,
and return the head. Example: 1 1 2 3 3 -> 1 2 3.

The idea: in a sorted list, equal values sit next to each other. So one walk
is enough: stand on a node and look at its neighbour. Same value? Skip the
neighbour by pointing past it. Different value? Only then move on.

*/

#include <iostream>
using namespace std;

// Definition for singly-linked list.
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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* temp = head;
        // We compare temp with temp->next, so both must exist.
        while(temp!=NULL && temp->next !=NULL){
            if(temp->val == temp->next->val){
                // Duplicate: unhook the neighbour. Do NOT move temp yet -
                // the new neighbour may be another copy (1 1 1).
                temp->next = temp->next->next;
            } else{
                // Different value: temp's value is now unique, move on.
                temp = temp->next;
            }
        }
        return head;
    }
};

int main() {
    // Create a sample sorted linked list with duplicates: 1 -> 1 -> 2 -> 3 -> 3
    ListNode* n1 = new ListNode(1);
    ListNode* n2 = new ListNode(1);
    ListNode* n3 = new ListNode(2);
    ListNode* n4 = new ListNode(3);
    ListNode* n5 = new ListNode(3);

    // Link the nodes together.
    n1->next = n2;
    n2->next = n3;
    n3->next = n4;
    n4->next = n5;

    // Print the original list.
    cout << "Original list: ";
    ListNode* current = n1;
    while(current != nullptr) {
        cout << current->val << " ";
        current = current->next;
    }
    cout << endl;

    // Call the solution.
    Solution sol;
    ListNode* newHead = sol.deleteDuplicates(n1);

    // Print the list after removing duplicates.
    cout << "List after removing duplicates: ";
    current = newHead;
    while(current != nullptr) {
        cout << current->val << " ";
        current = current->next;
    }
    cout << endl;

    // Clean up the allocated memory.
    current = newHead;
    while(current != nullptr) {
        ListNode* temp = current;
        current = current->next;
        delete temp;
    }

    return 0;
}
