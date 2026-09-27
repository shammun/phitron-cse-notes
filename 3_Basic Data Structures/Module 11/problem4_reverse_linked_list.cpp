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
    // Recursive helper function that reverses the list.
    // 'head' is passed by reference so that it can be updated when we reach the last node.
    // 'tmp' is the current node in the recursion.
    void reverse(ListNode* &head, ListNode* tmp){
        // Base case: the last node. It becomes the new head.
        if(tmp->next == NULL){
            head = tmp;
            return;
        }
        // First reverse everything after tmp...
        reverse(head, tmp->next);
        // ...then, on the way back, turn one arrow: the node after tmp now
        // points back to tmp (1->2 becomes 2->1)...
        tmp->next->next = tmp;
        // ...and tmp's own forward arrow is cut. If tmp is the old head, this
        // is what makes it the new tail.
        tmp->next = NULL;
    }
    
    // Main function to reverse a linked list.
    ListNode* reverseList(ListNode* head) {
        if(head == NULL){    // empty list: nothing to reverse (and tmp->next would crash)
            return head;
        }
        reverse(head, head);
        return head;
    }
};

// Helper function to print the linked list.
void printList(ListNode* head) {
    ListNode* current = head;
    while(current != nullptr) {
        cout << current->val << " ";
        current = current->next;
    }
    cout << endl;
}

int main() {
    // Create a linked list: 1 -> 2 -> 3 -> 4 -> 5
    ListNode* n1 = new ListNode(1);
    ListNode* n2 = new ListNode(2);
    ListNode* n3 = new ListNode(3);
    ListNode* n4 = new ListNode(4);
    ListNode* n5 = new ListNode(5);
    
    n1->next = n2;
    n2->next = n3;
    n3->next = n4;
    n4->next = n5;
    
    cout << "Original list: ";
    printList(n1);
    
    Solution sol;
    ListNode* reversedHead = sol.reverseList(n1);
    
    cout << "Reversed list: ";
    printList(reversedHead);
    
    // Free the allocated memory.
    ListNode* current = reversedHead;
    while(current != nullptr) {
        ListNode* temp = current;
        current = current->next;
        delete temp;
    }
    
    return 0;
}
