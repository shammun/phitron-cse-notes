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

void has_duplicate(Node* head){
    bool visited[101] = {false};

    Node* tmp = head;
    while(tmp != NULL){
        if(visited[tmp->val]){
            cout << "YES";
            return;
        }
        visited[tmp->val] = true;
        tmp = tmp->next;
    }
    cout << "NO";
}

int main(){
    Node* head = NULL;
    Node* tail = NULL;

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

