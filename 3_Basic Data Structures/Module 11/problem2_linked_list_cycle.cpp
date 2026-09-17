/*

https://leetcode.com/problems/linked-list-cycle/

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
    bool hasCycle(ListNode *head) {
        ListNode* slow = head;
        ListNode* fast = head;
        bool flag = false;

        while(fast != NULL && fast->next != NULL){
            slow = slow->next;
            fast = fast->next->next;
            if(slow == fast){
                flag = true;
                break;
            }
        }
        return flag;
    }
};

int main() {
    // Create a linked list: 1 -> 2 -> 3 -> 4 -> 5 (no cycle)
    ListNode* n1 = new ListNode(1);
    ListNode* n2 = new ListNode(2);
    ListNode* n3 = new ListNode(3);
    ListNode* n4 = new ListNode(4);
    ListNode* n5 = new ListNode(5);

    // Linking nodes to form the list: 1 -> 2 -> 3 -> 4 -> 5
    n1->next = n2;
    n2->next = n3;
    n3->next = n4;
    n4->next = n5;

    Solution sol;

    // Test the list without a cycle.
    bool noCycle = sol.hasCycle(n1);
    cout << "List has cycle? " << (noCycle ? "Yes" : "No") << endl;

    // Create a cycle: make the last node (n5) point back to n3.
    n5->next = n3;

    // Test the list with a cycle.
    bool hasCycle = sol.hasCycle(n1);
    cout << "List has cycle? " << (hasCycle ? "Yes" : "No") << endl;

    // Note: In a real application, you'd need to free the allocated memory.
    // However, with a cycle present, cleaning up nodes requires extra care.
    // For simplicity, we're not deallocating memory in this example.

    return 0;
}
