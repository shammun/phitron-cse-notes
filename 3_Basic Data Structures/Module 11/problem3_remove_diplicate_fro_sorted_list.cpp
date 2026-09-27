/*

https://leetcode.com/problems/remove-duplicates-from-sorted-list/description/

The list is sorted. Delete the repeated values so each value appears once,
and return the head. Example: 1 1 2 3 3 -> 1 2 3.

The idea: in a sorted list, equal values sit next to each other. So one walk
is enough: stand on a node and look at its neighbour. Same value? Skip the
neighbour by pointing past it. Different value? Only then move on.

*/

#include <iostream>     // cout and endl
using namespace std;    // write cout instead of std::cout

// Definition for singly-linked list.
struct ListNode {
    int val;            // the number in this node
    ListNode *next;     // address of the next node (nullptr at the end)
    // Default constructor; ": val(0), next(nullptr)" is an initializer list.
    ListNode() : val(0), next(nullptr) {}
    // Constructor with a value: new ListNode(2) -> node 2, next = nullptr.
    ListNode(int x) : val(x), next(nullptr) {}
    // Constructor with a value and a pointer to the next node.
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// LeetCode's answer class.
class Solution {
public:     // callable from main
    // Removes repeated values from a sorted list; returns the head (it never changes,
    // because the first node is always kept).
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* temp = head;      // the node we stand on
        // We compare temp with temp->next, so both must exist.
        while(temp!=NULL && temp->next !=NULL){
            if(temp->val == temp->next->val){
                // Duplicate: unhook the neighbour. Do NOT move temp yet -
                // the new neighbour may be another copy (1 1 1).
                // (The unhooked node is not deleted here, so its memory leaks;
                // `delete` on it would be the tidy version.)
                temp->next = temp->next->next;
            } else{
                // Different value: temp's value is now unique, move on.
                temp = temp->next;
            }
        }
        // Trace 1 1 2 3 3: on first 1, next is 1 -> skip; next is 2 -> move; on 2 -> move;
        // on 3, next is 3 -> skip; next is NULL -> loop ends. Result 1 2 3.
        return head;
    }
};

int main() {
    // Create a sample sorted linked list with duplicates: 1 -> 1 -> 2 -> 3 -> 3
    // `new` builds a node on the heap and returns its address.
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
    ListNode* current = n1;             // walker for printing
    while(current != nullptr) {         // one pass per node
        cout << current->val << " ";
        current = current->next;
    }
    cout << endl;                       // Original list: 1 1 2 3 3

    // Call the solution.
    Solution sol;                       // object needed to call the member function
    ListNode* newHead = sol.deleteDuplicates(n1);   // same address as n1

    // Print the list after removing duplicates.
    cout << "List after removing duplicates: ";
    current = newHead;                  // reuse the walker from the start
    while(current != nullptr) {
        cout << current->val << " ";
        current = current->next;
    }
    cout << endl;                       // List after removing duplicates: 1 2 3

    // Clean up the allocated memory.
    // Walk the list and delete each node. We save the node in temp and step forward
    // BEFORE deleting it, because after `delete` we may not read temp->next any more.
    // Note: this frees only the nodes still in the list (1, 2, 3). The skipped
    // duplicates (n2 and n5) are no longer reachable from the list and stay allocated.
    current = newHead;
    while(current != nullptr) {
        ListNode* temp = current;       // node to free
        current = current->next;        // move on first
        delete temp;                    // then free it
    }

    return 0;   // normal exit
}
