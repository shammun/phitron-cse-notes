/*

Take two singly linked lists as input and check if their sizes are same or not.

Input:
2 1 5 3 4 9 -1
1 2 3 4 5 6 -1

Output:
YES

Input:
5 1 4 5 -1
5 1 4 -1

Output:
NO


*/

/*
 * Two lists have the same size when they hold the same number of nodes; the
 * values do not matter. So: read the first list until -1, count it; read the
 * second list the same way, count it; compare the two counts.
 *
 * Practice copy. It has one bug in the Node constructor, kept on purpose -
 * see the BUG note there.
 */

#include <iostream>   // cin and cout
#include <vector>     // std::vector - not used here
#include <algorithm>  // sort/max/min - not used here
#include <string>     // std::string - not used here
using namespace std; // Allows us to avoid prefixing standard library objects with `std::`.

// One node of a singly linked list.
class Node{
    public:
        int val;       // the data
        Node* next;    // the next node's address; should be NULL for the last node

        // Constructor, runs on `new Node(x)`.
        Node(int val){
            this->val = val;       // member `val` = parameter `val`
            // BUG: there is no parameter called `next`, so `next` here IS the
            // member itself: this line copies the member's uninitialised
            // garbage into itself. The last node then has a random `next`,
            // and get_size keeps walking into random memory - it may count
            // wrong or crash (undefined behaviour). Fix: this->next = NULL;
            this->next = next; // BUG (kept on purpose): should be NULL, see the note
        }
};


// Append `val` at the end in O(1); references let main see new head/tail.
void insert_at_tail(Node* &head, Node* &tail, int val){
    Node* newNode = new Node(val);   // heap node
    if(head == NULL){                // empty list
        head = newNode;
        tail = newNode;
        return;
    }
    tail->next = newNode; // link after the last node...
    tail = newNode;       // ...and make the new node the last one
}

// Walk from head to NULL and add 1 for every node passed.
int get_size(Node* head){
    int size = 0;
    Node* tmp = head;
    while(tmp != NULL){   // relies on the last node's next being NULL (see BUG above)
        tmp = tmp->next;
        size++;
    }
    return size;
}

int main(){
    Node* head = NULL;    // list 1
    Node* tail = NULL;
    Node* head2 = NULL;   // list 2
    Node* tail2 = NULL;

    // First list: values until the stop sign -1 (not stored).
    int val;
    while(true){
        cin >> val;
        if(val == -1){
            break;
        }
        insert_at_tail(head, tail, val);
    }
    int size_1 = get_size(head);

    // Second list, read the same way.
    while(true){
        cin >> val;
        if(val == -1){
            break;
        }
        insert_at_tail(head2, tail2, val);
    }
    int size_2 = get_size(head2);

    // Only the counts are compared, never the values.
    if(size_1 == size_2){
        cout << "YES" << endl;   // endl = newline + flush
    } else{
        cout << "NO" << endl;
    }

    return 0;
}
