/*

https://leetcode.com/problems/swapping-nodes-in-a-linked-list/

Swap the k-th node from the beginning of the list with the k-th node from the end,
and return the head.

The idea: a singly linked list only goes forward, so "the k-th from the end" cannot be
reached by walking backwards. Turn it into a distance from the head instead. In a list of
`length` nodes, the k-th node from the end is the (length - k + 1)-th from the start,
which is `length - k` steps away from the head. So: count the nodes once, then walk twice.

And the second trick: the problem only cares about the values, so swap the two `val`
fields instead of re-linking nodes. Swapping nodes properly would mean fixing the two
nodes before them as well, with special cases when the two are neighbours or one is the
head - much more code for the same visible result.

*/

#include <iostream>     // cout (printing) and endl
#include <utility> // for std::swap - swap(a, b) exchanges the contents of a and b
using namespace std;    // so we can write cout / swap instead of std::cout / std::swap

// Definition for singly-linked list (the struct LeetCode provides).
struct ListNode {
    int val;            // the number stored in the node
    ListNode *next;     // address of the next node, nullptr for the last node
    // Default constructor. The ": val(0), next(nullptr)" part is an initializer list
    // that sets the members before the (empty) body runs.
    ListNode() : val(0), next(nullptr) {}
    // Constructor with a value: new ListNode(3) -> node holding 3, next = nullptr.
    ListNode(int x) : val(x), next(nullptr) {}
    // Constructor with a value and a pointer to the next node.
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// LeetCode's answer class: we only have to fill in swapNodes.
class Solution {
public:     // callable from outside the class
    // head = address of the first node, k = which position (1-based) to swap.
    // Returns the head of the (same-shaped) list after the swap.
    ListNode* swapNodes(ListNode* head, int k) {
        // Pass 1: count the nodes. `while(currentNode)` is the short way of writing
        // `while(currentNode != NULL)` - a pointer counts as true unless it is null.
        int length = 0;                 // how many nodes we have seen so far
        ListNode* currentNode = head;   // walker pointer, starts at the first node
        while(currentNode){
            length++;                           // count this node
            currentNode = currentNode->next;    // '->' = member through a pointer; step forward
        }
        // Example 1->2->3->4->5 gives length = 5.

        // Pass 2: the k-th node counting from the front, where the head is the 1st.
        // Starting i at 1 and stopping at i < k makes exactly k-1 steps, so k = 1 takes
        // no step at all and frontNode stays on the head.
        ListNode* frontNode = head;
        for(int i=1; i<k; i++){
            frontNode = frontNode->next;    // one step forward per pass
        }
        // Example k = 2: one step -> frontNode is the node holding 2.

        // Pass 3: the k-th node counting from the back. That is length - k steps from the
        // head. Check it on the example: length = 5, k = 2, so 3 steps from node 1 lands
        // on node 4 - and 4 really is the 2nd node from the end.
        // The loop shape is different here (i <= length-k) but the effect is the same
        // count: length - k steps.
        ListNode* backNode = head;
        for(int i=1; i<=length-k; i++){
            backNode = backNode->next;      // one step forward per pass
        }

        // Exchange only the numbers inside the two nodes. Every `next` pointer in the
        // list is untouched, so the list's shape is exactly as before.
        // (If k > length this would have walked off the end; LeetCode guarantees
        // 1 <= k <= length, so the code does not check.)
        // Example: frontNode->val = 2, backNode->val = 4 -> after swap they hold 4 and 2.
        swap(frontNode->val, backNode->val);

        // The head node itself never moves, so the same pointer is returned. Returning it
        // anyway is LeetCode's convention for list problems, where the head sometimes
        // does change.
        return head;
    }
    // Cost: three walks over the list, so O(n) time, and only a few pointers, O(1) space.
};

// Helper function to print the linked list.
// It is safe to move `head` itself here because the parameter is a copy of the caller's
// pointer (no `&`), so the caller's head is not disturbed.
void printList(ListNode* head) {
    // One pass per node; stops when head becomes nullptr (walked past the last node).
    while(head) {
        cout << head->val;      // print this node's number
        // Print the arrow only between values, never after the last one.
        if(head->next) cout << " -> ";
        head = head->next;      // move to the next node
    }
    cout << endl;   // newline (and flush) after the whole list
}

int main() {
    // Create a sample linked list: 1 -> 2 -> 3 -> 4 -> 5
    // `new ListNode(1)` makes a node on the heap and returns its address.
    ListNode* n1 = new ListNode(1);
    ListNode* n2 = new ListNode(2);
    ListNode* n3 = new ListNode(3);
    ListNode* n4 = new ListNode(4);
    ListNode* n5 = new ListNode(5);

    // Chain them: each node's next points to the following node.
    n1->next = n2;
    n2->next = n3;
    n3->next = n4;
    n4->next = n5;      // n5->next stays nullptr, so n5 is the tail

    cout << "Original list: ";
    printList(n1);      // Original list: 1 -> 2 -> 3 -> 4 -> 5

    // For example, let's swap the 2nd node from the beginning and the 2nd node from the end.
    // 2nd from the front is the node holding 2; 2nd from the end is the node holding 4.
    // So the printed list becomes 1 -> 4 -> 3 -> 2 -> 5.
    int k = 2;
    // LeetCode's method lives inside a class, so an object is needed to call it. On the
    // judge this `main` does not exist - only `class Solution` is submitted.
    Solution sol;
    ListNode* swappedHead = sol.swapNodes(n1, k);   // same address as n1

    cout << "List after swapping kth nodes (k = " << k << "): ";
    printList(swappedHead);     // 1 -> 4 -> 3 -> 2 -> 5

    // Free allocated memory. Every `new` above has a matching `delete` here, and the
    // nodes are still reachable through n1..n5 because only values were swapped, not
    // links. Deleting is done after the last print - touching a node after `delete` is
    // undefined behaviour.
    delete n1;
    delete n2;
    delete n3;
    delete n4;
    delete n5;

    return 0;   // program ended normally
}
