/*

https://leetcode.com/problems/reverse-linked-list/description/

Reverse Linked List (LeetCode 206) -- a Module 11 problem, solved again

Turn the list around and return its new head. Example: 1 2 3 4 5 -> 5 4 3 2 1.

Idea (recursion, as taught in Module 10): go all the way to the last node
first and make it the new head. While the calls return, each node makes the
node after it point back to itself, and cuts its own forward link.
O(n) time, O(n) recursion depth.

*/

// (LeetCode defines ListNode and supplies includes and main.)
class Solution {
public:     // callable by the judge
    // `head` is a reference so the caller's head pointer can be changed.
    // The recursive call trusts: when it returns, everything after tmp is reversed.
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
        // Trace 1 2 3: head = 3; 3->2, 2->NULL; 2->1, 1->NULL -> 3 2 1.
    }
    // Returns the head of the reversed list.
    ListNode* reverseList(ListNode* head) {
        // An empty list is already reversed (and tmp->next would crash).
        if(head == NULL){
            return head;
        }
        reverse(head, head);    // head is updated through the reference
        return head;
    }
};