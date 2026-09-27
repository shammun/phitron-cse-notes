/*

Take a singly linked list as input, then take q queries. In each query 
you will be given an index and value. You need to insert those values in 
the given index and print the linked list. If the index is invalid 
print “Invalid”.

Input:
10 20 30 -1
1 40
5 50
4 50
0 100
7 40
1 110
7 40

Output:
10 40 20 30
Invalid
10 40 20 30 50
100 10 40 20 30 50
Invalid
100 110 10 40 20 30 50
100 110 10 40 20 30 50 40


*/

/*
 * Every query is "put value v at index idx". For a list of `size` nodes the
 * valid indexes are 0..size:
 *   idx == 0          -> the new node becomes the head   (insert_at_head)
 *   idx == size       -> the new node goes after the tail (insert_at_tail)
 *   0 < idx < size    -> walk to the node at idx-1 and hook the new node in
 *   anything else     -> "Invalid", the list is not touched
 * After every valid query the whole list is printed on one line.
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std; // Allows us to avoid prefixing standard library objects with `std::`.

class Node{
    public:
        int val;
        Node* next;
    
    Node(int val){
        this->val = val;
        this->next = NULL;
    }
};

// The new node points at the old head, then becomes the head. O(1).
void insert_at_head(Node* &head, int val){
    Node* newNode = new Node(val);
    newNode->next = head;
    head = newNode;
}

// O(1) append using the remembered last node.
void insert_at_tail(Node* &head, Node* &tail,int val){
    Node* newNode = new Node(val);
    if(head==NULL){
        head = newNode;
        tail = newNode;
        return;
    }
    tail->next = newNode;
    tail = newNode;
}

// Insert strictly inside the list (0 < idx < size).
void insert_at_any_index(Node* &head, int idx, int val){
    Node* newNode = new Node(val);
    Node* tmp = head;

    // Stop one node BEFORE the target index: idx-1 steps from the head.
    for(int i=1; i<idx; i++){
        tmp = tmp->next;
    }
    newNode->next = tmp->next; // first grab the rest of the list...
    tmp->next = newNode;       // ...then hang the new node after tmp
}

int get_size(Node* head){
    int size = 0;
    Node* tmp = head;
    while(tmp!=NULL){
        tmp = tmp->next;
        size++;
    }
    return size;
}

// Print the list on one line, values separated by spaces.
void print_linked_list(Node* head){
    Node* tmp = head;
    while(tmp != NULL){
        cout << tmp->val << " ";
        tmp = tmp->next;
    }
    cout << endl;
}

int main(){
    Node* head = NULL;
    Node* tail = NULL;

    // Read the starting list until the stop sign -1.
    int val;
    while(cin >> val && val != -1){
        insert_at_tail(head, tail, val);
    }

    // The queries run until the input ends.
    int idx;
    while(cin >> idx >> val){
        int size = get_size(head);  // the valid range depends on the current size
        if(idx < 0 || idx > size){
            cout << "Invalid" << endl;
            continue;               // nothing inserted, nothing printed
        }
        // Exactly one branch runs ("else if"): on an empty list idx 0 is
        // both "head" and "size", and it must be inserted only once.
        if(idx == 0){
            insert_at_head(head, val);
            if(tail == NULL){
                tail = head;        // the first node is also the last one
            }
        } else if(idx == size){
            insert_at_tail(head, tail, val);
        } else{
            insert_at_any_index(head, idx, val);
        }
        print_linked_list(head);
    }

    return 0;
}
