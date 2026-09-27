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

void insert_at_tail(Node* &head, Node* &tail,int val){
    Node* newNode = new Node(val);
    if(head==NULL){
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
    while(tmp!=NULL){
        tmp = tmp->next;
        size++;
    }
    return size;
}

int main(){
    Node* head = NULL;
    Node* tail = NULL;

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

    // Second list: its own head and tail, filled the same way.
    Node* head2 = NULL;
    Node* tail2 = NULL;

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
        cout << "YES";
    }
    else{
        cout << "NO";
    }

    return 0;
}    
    
