/*

https://leetcode.com/problems/design-linked-list/

Design linked list  (LeetCode 707)

Build a list class with these five operations, where positions are 0-based:

    get(index)              the value at that position, or -1 if the index
                            is out of range
    addAtHead(val)          new first element
    addAtTail(val)          new last element
    addAtIndex(index, val)  insert so the new node ends up AT `index`.
                            index == size appends; index > size does nothing
    deleteAtIndex(index)    remove the node at that position, if it exists

Three decisions make the rest of the code simple:

  * doubly linked nodes -- `prev` means a node in the middle can be unlinked
    without walking back to find the one before it;
  * a `tail` pointer -- appending and deleting the last node become O(1)
    instead of a walk to the end;
  * a `size` counter kept up to date by every add and delete -- every bounds
    check below relies on it, and counting the nodes each time would be O(n).

Cost: addAtHead and addAtTail are O(1); get, addAtIndex and deleteAtIndex are
O(n) because they may have to walk to the position.

This is judge-style code: only the class, no main.

*/


// One node of the doubly linked list.
class Node{
    public:
        int val;        // the stored value
        Node* next;     // the node after this one (NULL = none)
        Node* prev;     // the node before this one (NULL = none)

    // Constructor, runs on `new Node(x)`: this->val is the member, val the parameter.
    Node(int val){
        this->val = val;
        this->next = NULL;   // not linked yet
        this->prev = NULL;
    }

};

class MyLinkedList {
public:            // LeetCode calls these from outside the class
    Node* head;     // first node (NULL when empty)
    Node* tail;     // last node (NULL when empty)
    int size;       // how many nodes there are

    // An empty list: no nodes, so both ends point at nothing.
    MyLinkedList() {
        head = NULL;
        tail = NULL;
        size = 0;
    }

    // Value at position index, or -1 if there is no such position.
    int get(int index) {
        // The problem asks for -1 rather than a crash on a bad index. This
        // guard is also what makes the walk below safe -- it can never run
        // off the end.
        if(index < 0 || index >= size){
            return -1;
        }
        Node* tmp = head;       // start at node 0
        // index steps from the head lands on node number `index`:
        // 0 steps -> head, 1 step -> the second node, and so on.
        for(int i=0; i<index; i++){
            tmp = tmp->next;    // one step to the right
        }
        return tmp->val;
    }

    // New first element.
    void addAtHead(int val) {
        Node* newNode = new Node(val);  // `new` builds the node on the heap and returns its address
        // First node in an empty list: it is both ends at once.
        if(head == NULL){
            head = tail = newNode;      // a = b = c sets both to newNode
        } else{
            // Link it in front, both ways, then move head.
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
        size++;   // every add must keep the counter honest
    }

    // New last element.
    void addAtTail(int val) {
        Node* newNode = new Node(val);
        if(tail == NULL){               // empty list: the node is both ends
            head = tail = newNode;
        } else {
            tail->next = newNode;       // old last node points forward to it
            newNode->prev = tail;       // it points back to the old last node
            tail = newNode;             // it is the new last node
        }
        size++;
    }

    // Insert val so that it ends up at position index.
    void addAtIndex(int index, int val) {
        // index == size is allowed (append); anything beyond it is not.
        if(index < 0 || index > size){
            return;
        }

        // The two ends have their own O(1) helpers, and they also handle the
        // empty list. Sending them here keeps the general case below simple.
        if(index == 0){
            addAtHead(val);
            return;
        }

        // This case MUST be caught before the general code below: at
        // index == size there is no node to the right, so `tmp->next->prev`
        // would follow a NULL pointer.
        if(index == size){
            addAtTail(val);
            return;
        }

        // Walk to the node BEFORE the target position, node index-1. The
        // loop starts at 1 because tmp already stands on node 0.
        Node* tmp = head;
        for(int i=1; i<index; i++){
            tmp = tmp->next;
        }

        // Splice between tmp and tmp->next. All four pointers have to be
        // rewritten, and the order matters: tmp->next is still needed by the
        // first two lines, so it is changed last.
        Node* newNode = new Node(val);
        newNode->next = tmp->next;      // new node points forward to tmp's old neighbour
        tmp->next->prev = newNode;      // that neighbour points back to the new node
        newNode->prev = tmp;            // new node points back to tmp
        tmp->next = newNode;            // tmp points forward to the new node

        size++;
    }

    // Remove the node at position index, if it exists.
    void deleteAtIndex(int index) {
        // Nothing to delete outside the list. (`size == 0` is already
        // covered by `index >= size`, but it is stated for clarity.)
        if(index < 0 || index >= size || size == 0){
            return;
        }

        // Only one node: the list becomes empty, so both ends are cleared.
        // Forgetting this would leave head or tail pointing at freed memory.
        if(size == 1){
            delete head;                // `delete` frees the node's memory
            head = tail = NULL;
        }

        // First node: the second becomes the head and must forget the node
        // in front of it.
        else if(index == 0){
            Node* temp = head;          // remember the old first node
            head = head->next;          // second node becomes the first
            head->prev = NULL;          // nothing in front of it any more
            delete temp;                // free the old first node
        }

        // Last node: the one before it becomes the tail and must stop
        // pointing forwards. This is O(1) thanks to `prev` and `tail`.
        else if(index == size-1){
            Node* temp = tail;          // remember the old last node
            tail = tail->prev;          // the one before it becomes the last
            tail->next = NULL;          // nothing after it any more
            delete temp;                // free the old last node
        }

        // A node in the middle: walk to it, then let its two neighbours
        // point straight at each other, closing the gap.
        else{
            Node* curr = head;
            for(int i=0; i<index; i++){
                curr = curr->next;      // walk to node number index
            }
            curr->prev->next = curr->next;  // left neighbour skips over curr
            curr->next->prev = curr->prev;  // right neighbour points back past curr
            delete curr;                    // free the removed node
        }

        // One line for all four cases, since exactly one node was removed.
        size--;
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */
