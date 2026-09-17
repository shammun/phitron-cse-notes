#include <iostream>
#include <utility> // for std::swap
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
    ListNode* swapNodes(ListNode* head, int k) {
        int length = 0;
        ListNode* currentNode = head;
        while(currentNode){
            length++;
            currentNode = currentNode->next;
        }

        ListNode* frontNode = head;
        for(int i=1; i<k; i++){
            frontNode = frontNode->next;
        }

        ListNode* backNode = head;
        for(int i=1; i<=length-k; i++){
            backNode = backNode->next;
        }

        swap(frontNode->val, backNode->val);
        return head;
    }
};

// Helper function to print the linked list.
void printList(ListNode* head) {
    while(head) {
        cout << head->val;
        if(head->next) cout << " -> ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    // Create a sample linked list: 1 -> 2 -> 3 -> 4 -> 5
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

    // For example, let's swap the 2nd node from the beginning and the 2nd node from the end.
    int k = 2;
    Solution sol;
    ListNode* swappedHead = sol.swapNodes(n1, k);

    cout << "List after swapping kth nodes (k = " << k << "): ";
    printList(swappedHead);

    // Free allocated memory.
    delete n1;
    delete n2;
    delete n3;
    delete n4;
    delete n5;

    return 0;
}
