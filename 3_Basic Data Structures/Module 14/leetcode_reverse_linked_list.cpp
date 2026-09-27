/*

https://leetcode.com/problems/reverse-linked-list/description/

Reverse Linked List (LeetCode 206) -- a Module 11 problem, solved again

Turn the list around and return its new head. Example: 1 2 3 4 5 -> 5 4 3 2 1.

Idea (recursion, as taught in Module 10): go all the way to the last node
first and make it the new head. While the calls return, each node makes the
node after it point back to itself, and cuts its own forward link.
O(n) time, O(n) recursion depth.

*/

class Solution {
public:
    // `head` is a reference so the caller's head pointer can be changed.
    void reverse(ListNode* &head, ListNode* tmp){
        // Base case: tmp is the last node, so it becomes the new head.
        if(tmp->next == NULL){
            head = tmp;
            return;
        }
        // First reverse everything after tmp ...
        reverse(head, tmp->next);
        // ... then make the next node point back to tmp ...
        tmp->next->next = tmp;
        // ... and cut tmp's forward link (the old first node ends with NULL).
        tmp->next = NULL;
    }
    ListNode* reverseList(ListNode* head) {
        // An empty list is already reversed (and tmp->next would crash).
        if(head == NULL){
            return head;
        }
        reverse(head, head);
        return head;
    }
};