/*

Take a singly linked list as input and check if the linked list contains any duplicate value. You can assume that the maximum value will be 100.

Input:
5 4 8 6 2 1 -1

Output:
NO

Input:
2 4 5 6 7 4 -1

Output:
YES

*/

/*
 * Values are at most 100, so we can keep one yes/no box per possible value:
 * visited[v] says "have I already seen v?". Walk the list once. If the box of
 * the current value is already ticked, this value appeared before - that is a
 * duplicate. Otherwise tick it and move on. One pass, no second loop.
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

void has_duplicate(Node* head){
    // Indexes 0..100, all false: no value has been seen yet.
    // 101 boxes, because the value 100 needs index 100.
    bool visited[101] = {false};

    Node* tmp = head;
    while(tmp != NULL){
        if(visited[tmp->val]){
            // Seen before: we found a duplicate, no need to look further.
            cout << "YES";
            return;
        }
        visited[tmp->val] = true; // first time: remember this value
        tmp = tmp->next;
    }
    // Reached the end without a repeat.
    cout << "NO";
}

int main(){
    Node* head = NULL;
    Node* tail = NULL;

    // Read values until the stop sign -1 (not stored).
    int val;
    while(true){
        cin >> val;
        if(val == -1){
            break;
        }
        insert_at_tail(head, tail, val);
    }
    has_duplicate(head);
}
