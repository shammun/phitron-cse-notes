// https://leetcode.com/problems/reverse-linked-list/
// Reverse a singly linked list and return the new head: 1 2 3 4 5 -> 5 4 3 2 1.
// The idea (recursion): first reverse everything after the current node, then,
// on the way back up, turn the arrow between the current node and its neighbour.

#include <iostream>     // cout and endl
using namespace std;    // write cout instead of std::cout

// Definition for singly-linked list.
struct ListNode {
    int val;            // the number in this node
    ListNode *next;     // address of the next node (nullptr at the end)
    // Default constructor; ": val(0), next(nullptr)" is an initializer list.
    ListNode() : val(0), next(nullptr) {}
    // Constructor with a value: new ListNode(3) -> node 3, next = nullptr.
    ListNode(int x) : val(x), next(nullptr) {}
    // Constructor with a value and a pointer to the next node.
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// LeetCode's answer class: a recursive helper plus the required function.
class Solution {
public:     // callable from outside the class
    // Recursive helper function that reverses the list.
    // 'head' is passed by reference so that it can be updated when we reach the last node.
    // ('ListNode* &head' = a reference to the caller's pointer: assigning head here
    //  changes the caller's variable, not a copy.)
    // 'tmp' is the current node in the recursion.
    // What the recursive call trusts: after reverse(head, tmp->next) returns, the part
    // after tmp is already reversed and head points to the old last node.
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
        // (tmp->next still points to the old neighbour, because we have not changed tmp yet.)
        tmp->next->next = tmp;
        // ...and tmp's own forward arrow is cut. If tmp is the old head, this
        // is what makes it the new tail.
        tmp->next = NULL;
        // Trace 1 2 3: call(1) -> call(2) -> call(3): base, head = 3.
        // back in call(2): 3->2, 2->NULL.  back in call(1): 2->1, 1->NULL.  Result 3 2 1.
    }

    // Main function to reverse a linked list. Returns the new head.
    ListNode* reverseList(ListNode* head) {
        if(head == NULL){    // empty list: nothing to reverse (and tmp->next would crash)
            return head;
        }
        reverse(head, head);    // start the recursion at the first node; head gets updated
        return head;            // now the old last node
    }
};

// Helper function to print the linked list, values separated by spaces.
void printList(ListNode* head) {
    ListNode* current = head;           // walker
    while(current != nullptr) {         // one pass per node
        cout << current->val << " ";
        current = current->next;        // '->' = member through a pointer
    }
    cout << endl;
}

int main() {
    // Create a linked list: 1 -> 2 -> 3 -> 4 -> 5
    // `new` builds each node on the heap and returns its address.
    ListNode* n1 = new ListNode(1);
    ListNode* n2 = new ListNode(2);
    ListNode* n3 = new ListNode(3);
    ListNode* n4 = new ListNode(4);
    ListNode* n5 = new ListNode(5);

    // Link them in order.
    n1->next = n2;
    n2->next = n3;
    n3->next = n4;
    n4->next = n5;

    cout << "Original list: ";
    printList(n1);                  // Original list: 1 2 3 4 5

    Solution sol;                   // object to call reverseList on
    ListNode* reversedHead = sol.reverseList(n1);   // returns n5's address

    cout << "Reversed list: ";
    printList(reversedHead);        // Reversed list: 5 4 3 2 1

    // Free the allocated memory.
    // Save the node, step forward, then delete - reading ->next after delete is not allowed.
    ListNode* current = reversedHead;
    while(current != nullptr) {
        ListNode* temp = current;   // node to free
        current = current->next;    // move on first
        delete temp;                // then free it
    }

    return 0;   // normal exit
}
