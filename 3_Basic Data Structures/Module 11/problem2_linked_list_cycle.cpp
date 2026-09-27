/*

https://leetcode.com/problems/linked-list-cycle/

Say whether a singly linked list loops back on itself (some node's `next`
points to an earlier node). Example: 1 2 3 4 5 with 5 -> 3 has a cycle.

The idea (Floyd's slow and fast pointers, from Module 10): `slow` moves one
node per round, `fast` two. With no cycle, `fast` reaches the end (NULL). With
a cycle there is no end, both pointers end up going round the loop, and
`fast` gains exactly one node on `slow` every round, so it must land on the
same node sooner or later. Meeting = cycle.

*/


#include <iostream>     // cout and endl
using namespace std;    // write cout instead of std::cout

// Definition for singly-linked list.
struct ListNode {
    int val;            // the number in this node
    ListNode *next;     // address of the next node, nullptr at the end
    // Default constructor; the ": ..." initializer list sets both members.
    ListNode() : val(0), next(nullptr) {}
    // Constructor with a value: new ListNode(1) -> node 1, next = nullptr.
    ListNode(int x) : val(x), next(nullptr) {}
    // Constructor with a value and a pointer to the next node.
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// LeetCode's answer class.
class Solution {
public:     // callable from main
    // Returns true if the list starting at head contains a cycle, false otherwise.
    bool hasCycle(ListNode *head) {
        ListNode* slow = head;  // the tortoise: 1 node per round
        ListNode* fast = head;  // the hare: 2 nodes per round
        bool flag = false;   // no cycle, until the two pointers meet

        // `fast` needs two more nodes to take its double step. If either is
        // missing the list has an end, so there is no cycle.
        // (fast != NULL is tested first so fast->next is never read through NULL.)
        while(fast != NULL && fast->next != NULL){
            slow = slow->next;           // one step
            fast = fast->next->next;     // two steps
            // Move first, then compare: at the start both are on head and
            // would "meet" without proving anything.
            // Trace with 1 2 3 4 5 and 5 -> 3: (slow,fast) = (2,3), (3,5), (4,4) -> meet.
            if(slow == fast){            // same address = same node
                flag = true;             // a cycle exists
                break;                   // no need to keep walking
            }
        }
        return flag;
    }
};

int main() {
    // Create a linked list: 1 -> 2 -> 3 -> 4 -> 5 (no cycle)
    // `new` makes each node on the heap and returns its address.
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

    Solution sol;   // object used to call hasCycle

    // Test the list without a cycle.
    bool noCycle = sol.hasCycle(n1);    // false here
    // (cond ? "Yes" : "No") is the ternary operator: picks "Yes" if cond is true, else "No".
    cout << "List has cycle? " << (noCycle ? "Yes" : "No") << endl;    // prints No

    // Create a cycle: make the last node (n5) point back to n3.
    n5->next = n3;      // now 1 2 3 4 5 3 4 5 3 ... forever

    // Test the list with a cycle.
    bool hasCycle = sol.hasCycle(n1);   // true now
    cout << "List has cycle? " << (hasCycle ? "Yes" : "No") << endl;   // prints Yes

    // Note: In a real application, you'd need to free the allocated memory.
    // However, with a cycle present, cleaning up nodes requires extra care.
    // For simplicity, we're not deallocating memory in this example.
    // (A walk-and-delete loop would go round the cycle forever and delete nodes twice.)

    return 0;   // normal exit
}
