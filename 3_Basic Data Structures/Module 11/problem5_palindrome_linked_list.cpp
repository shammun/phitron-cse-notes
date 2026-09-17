/*

https://leetcode.com/problems/palindrome-linked-list/

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
    // Recursively reverse the linked list.
    // 'head' is passed by reference so that when we reach the last node,
    // we can update the original head pointer.
    // 'tmp' is used to traverse the list.
    void reverse(ListNode* &head, ListNode* tmp){
        if(tmp->next == NULL){
            head = tmp;
            return;
        }
        reverse(head, tmp->next);
        tmp->next->next = tmp;
        tmp->next = NULL;
    }

    // Inserts a new node with value 'val' at the tail of the list.
    // Both 'head' and 'tail' are passed by reference to update them if needed.
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

    // Checks if the linked list is a palindrome.
    // This function creates a copy of the original list, reverses the copy,
    // and then compares node values one by one.
    bool isPalindrome(ListNode* head){
        ListNode* newHead = NULL;
        ListNode* newTail = NULL;

        ListNode* tmp = head;
        while(tmp != NULL){
            insert_at_tail(newHead, newTail, tmp->val);
            tmp = tmp->next;
        }
        // Reverse the copied list.
        reverse(newHead, newHead);

        // Compare the original list and the reversed copy.
        tmp = head;
        ListNode* tmp2 = newHead;
        while(tmp != NULL){
            if(tmp->val != tmp2->val){
                return false;
            }
            tmp = tmp->next;
            tmp2 = tmp2->next;
        }
        return true;
    }
};

int main(){
    // Build a sample linked list.
    // Let's create a palindrome list: 1 -> 2 -> 3 -> 2 -> 1
    ListNode* head = NULL;
    ListNode* tail = NULL;
    Solution sol;
    
    sol.insert_at_tail(head, tail, 1);
    sol.insert_at_tail(head, tail, 2);
    sol.insert_at_tail(head, tail, 3);
    sol.insert_at_tail(head, tail, 2);
    sol.insert_at_tail(head, tail, 1);

    // Test if the list is a palindrome.
    bool result = sol.isPalindrome(head);
    cout << "Is the list a palindrome? " << (result ? "Yes" : "No") << endl;

    // Clean up the allocated memory for the original list.
    ListNode* curr = head;
    while(curr != nullptr) {
        ListNode* temp = curr;
        curr = curr->next;
        delete temp;
    }
    // Note: The reversed copy inside isPalindrome is not freed in this example.
    // In production code, you should free all allocated memory.

    return 0;
}
