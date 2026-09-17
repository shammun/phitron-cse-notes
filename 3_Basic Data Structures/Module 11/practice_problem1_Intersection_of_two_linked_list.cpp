/*

https://leetcode.com/problems/intersection-of-two-linked-lists/

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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* tempA = headA;
        while(tempA != NULL){
            ListNode* tempB = headB;
            while(tempB != NULL){
                if(tempA == tempB){
                    return tempA;
                }
                tempB = tempB->next;
            }
            tempA = tempA->next;
        }
        return NULL;
    }
};

// Helper function to print a linked list.
void printList(ListNode* head) {
    while (head != nullptr) {
        cout << head->val << " -> ";
        head = head->next;
    }
    cout << "NULL" << endl;
}

int main() {
    // Create common nodes that will serve as the intersection part:
    // Intersection list: 8 -> 4 -> 5
    ListNode* common1 = new ListNode(8);
    ListNode* common2 = new ListNode(4);
    ListNode* common3 = new ListNode(5);
    common1->next = common2;
    common2->next = common3;
    
    // Create list A: 4 -> 1 -> 8 -> 4 -> 5
    ListNode* A1 = new ListNode(4);
    ListNode* A2 = new ListNode(1);
    A1->next = A2;
    A2->next = common1;  // Link to intersection
    
    // Create list B: 5 -> 6 -> 1 -> 8 -> 4 -> 5
    ListNode* B1 = new ListNode(5);
    ListNode* B2 = new ListNode(6);
    ListNode* B3 = new ListNode(1);
    B1->next = B2;
    B2->next = B3;
    B3->next = common1;  // Link to intersection

    // Print both lists.
    cout << "List A: ";
    printList(A1);
    cout << "List B: ";
    printList(B1);
    
    // Find the intersection.
    Solution sol;
    ListNode* intersection = sol.getIntersectionNode(A1, B1);
    
    if(intersection != nullptr) {
        cout << "Intersection at node with value: " << intersection->val << endl;
    } else {
        cout << "No intersection found." << endl;
    }
    
    // Clean up allocated memory.
    // Note: Since the intersection nodes are shared, they must be deleted only once.
    delete A1;
    delete A2;
    delete B1;
    delete B2;
    delete B3;
    delete common1;  // This also deletes common2 and common3 by following the chain.
    // (In a production system you might need a more sophisticated cleanup to avoid double-deletion.)
    
    return 0;
}
