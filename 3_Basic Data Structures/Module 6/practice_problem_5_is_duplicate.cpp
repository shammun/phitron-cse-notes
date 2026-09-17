/*

Take a singly linked list as input and check if the linked 
list is sorted in ascending order.

Input:
1 5 6 8 9 -1

Output:
YES

Input:
2 4 6 5 8 4 -1

Output:
NO

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
    tail->next = newNode;
    tail = newNode;
}

void ascending_sort_check(Node* head){
    Node* tmp = head;
    while(tmp->next != NULL){
        if(tmp->next->val < tmp->val){
            cout << "NO";
            return;
        }
    }
    cout << "YES";
}

int main(){
    Node* head = NULL;
    Node* tail = NULL;

    int val;
    // while(true){
    while(cin >> val){
        // cin >> val;
        if(val == -1){
            break;
        }
        insert_at_tail(head, tail, val);
    }

    ascending_sort_check(head);

    return 0;
}    
    
