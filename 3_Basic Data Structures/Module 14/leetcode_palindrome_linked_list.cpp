/*

https://leetcode.com/problems/palindrome-linked-list/description/

Palindrome Linked List (LeetCode 234)

A list is a palindrome if it reads the same forwards and backwards. A linked
list can only be walked forwards, so the plan is: make a second list with the
same values, reverse that copy, then walk the original and the reversed copy
side by side. They match at every step exactly when the list is a palindrome.

This is Module 11's toolkit reused -- insert at tail, and reverse a list
recursively -- which is why the problem sits in this practice folder.

Cost: O(n) time, O(n) extra memory for the copy plus O(n) recursion depth for
the reverse. (A stack-free version exists: find the middle, reverse only the
second half. This one favours reusing what was already built.)

The file holds only the Solution class, as LeetCode expects; `ListNode` comes
from the judge (and from the test harness the site uses to run it here).

*/

class Solution {
public:
    /* Reverse the list that starts at `tmp`, recursively.

       `head` is passed by reference (`ListNode* &`) because the caller's head
       pointer has to be changed: after reversing, the old LAST node is the
       new first node. */
    void reverse(ListNode* &head, ListNode* tmp){
        // Deepest call: `tmp` is the last node, so it becomes the new head.
        if(tmp->next == NULL){
            head = tmp;
            return;
        }
        // Reverse everything after `tmp` first. When this returns, the part
        // behind `tmp` already points backwards.
        reverse(head, tmp->next);
        // Now turn the one link this call owns: the node after `tmp` should
        // point back at `tmp`...
        tmp->next->next = tmp;
        // ...and `tmp` must stop pointing forwards, or the two nodes would
        // point at each other and the list would loop forever.
        tmp->next = NULL;
    }

    // Add a value at the end of a list. `tail` is kept so this is O(1) and
    // the copy comes out in the same order as the original. Both pointers are
    // by reference because an empty list has to set them both.
    void insert_at_tail(ListNode* &head, ListNode* &tail, int val){
        ListNode* newNode = new ListNode(val);
        if(head==NULL){
            head = newNode;
            tail = newNode;
            return;
        }
        tail->next = newNode;
        tail = newNode;
    }

    bool isPalindrome(ListNode* head) {
        ListNode* newHead = NULL;
        ListNode* newTail = NULL;

        // Step 1: copy the list. New nodes are built, so reversing the copy
        // in step 2 leaves the original list untouched -- the judge (and the
        // comparison below) still needs it in its original order.
        ListNode* tmp = head;
        while(tmp != NULL){
            insert_at_tail(newHead, newTail, tmp->val);
            tmp = tmp->next;
        }
        // Step 2: reverse the copy. Both arguments start at newHead: one is
        // the head pointer to update, the other is where the walk begins.
        reverse(newHead, newHead);

        // Step 3: walk both lists together. The lists have the same length,
        // so one counter is enough.
        tmp = head;
        ListNode* tmp2 = newHead;

        while(tmp != NULL){
            // One mismatch is enough to answer: leave immediately.
            if(tmp->val != tmp2->val){
                return false;
            }
            tmp = tmp->next;
            tmp2 = tmp2->next;
        }
        // Every pair matched, so the list reads the same in both directions.
        return true;
    }
};
