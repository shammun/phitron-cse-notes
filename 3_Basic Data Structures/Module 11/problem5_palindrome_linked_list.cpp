/*

https://leetcode.com/problems/palindrome-linked-list/

Say whether a singly linked list reads the same forwards and backwards.
Example: 1 2 2 1 -> true,  1 2 -> false.

The idea: a singly list cannot be walked backwards, so make a reversed copy
and walk the original and the copy side by side. If every pair matches, the
list is a palindrome. Costs O(n) extra memory for the copy.

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

// LeetCode's answer class, with two helpers and the required function.
class Solution {
public:     // callable from main
    // Recursively reverse the linked list.
    // 'head' is passed by reference so that when we reach the last node,
    // we can update the original head pointer.
    // 'tmp' is used to traverse the list.
    // Base case: the last node. Recursive call trusts: the rest after tmp gets reversed.
    void reverse(ListNode* &head, ListNode* tmp){
        if(tmp->next == NULL){       // last node: the new head
            head = tmp;
            return;
        }
        reverse(head, tmp->next);    // reverse the rest first
        tmp->next->next = tmp;       // turn the arrow back to tmp
        tmp->next = NULL;            // cut tmp's old forward arrow
    }

    // Inserts a new node with value 'val' at the tail of the list.
    // Both 'head' and 'tail' are passed by reference to update them if needed.
    void insert_at_tail(ListNode* &head, ListNode* &tail, int val){
        ListNode* newNode = new ListNode(val);  // new node on the heap
        if(head == NULL){       // empty list: new node is head and tail
            head = newNode;
            tail = newNode;
            return;
        }
        tail->next = newNode;   // link after the old last node
        tail = newNode;         // new last node
    }

    // Checks if the linked list is a palindrome.
    // This function creates a copy of the original list, reverses the copy,
    // and then compares node values one by one.
    bool isPalindrome(ListNode* head){
        ListNode* newHead = NULL;   // the copy starts empty
        ListNode* newTail = NULL;

        // Copy: one pass per original node, append its value to the copy.
        ListNode* tmp = head;
        while(tmp != NULL){
            insert_at_tail(newHead, newTail, tmp->val);
            tmp = tmp->next;
        }
        // Reverse the copied list.
        // (LeetCode guarantees at least one node, so newHead is not NULL here.)
        reverse(newHead, newHead);

        // Compare the original list and the reversed copy.
        // Both have the same length, so tmp2 runs out exactly when tmp does.
        tmp = head;
        ListNode* tmp2 = newHead;
        while(tmp != NULL){
            if(tmp->val != tmp2->val){  // a mismatch: front and back differ
                return false;
            }
            tmp = tmp->next;            // move both walkers one step
            tmp2 = tmp2->next;
        }
        // Trace 1 2 3 2 1: copy reversed = 1 2 3 2 1 -> all 5 pairs equal -> true.
        return true;
    }
};

int main(){
    // Build a sample linked list.
    // Let's create a palindrome list: 1 -> 2 -> 3 -> 2 -> 1
    ListNode* head = NULL;      // empty list to start
    ListNode* tail = NULL;
    Solution sol;               // object; insert_at_tail is a member, so we call it through sol

    sol.insert_at_tail(head, tail, 1);
    sol.insert_at_tail(head, tail, 2);
    sol.insert_at_tail(head, tail, 3);
    sol.insert_at_tail(head, tail, 2);
    sol.insert_at_tail(head, tail, 1);

    // Test if the list is a palindrome.
    bool result = sol.isPalindrome(head);
    // (result ? "Yes" : "No") is the ternary operator: "Yes" when result is true.
    cout << "Is the list a palindrome? " << (result ? "Yes" : "No") << endl;  // Yes

    // Clean up the allocated memory for the original list.
    // Save, step, then delete (never read ->next of a deleted node).
    ListNode* curr = head;
    while(curr != nullptr) {
        ListNode* temp = curr;
        curr = curr->next;
        delete temp;
    }
    // Note: The reversed copy inside isPalindrome is not freed in this example.
    // In production code, you should free all allocated memory.

    return 0;   // normal exit
}
