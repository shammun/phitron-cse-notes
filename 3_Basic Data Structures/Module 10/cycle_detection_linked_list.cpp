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



int main(){
    Node* head = new Node(10);
    Node* a = new Node(20);
    Node* b = new Node(30);
    Node* c = new Node(40);
    Node* d = new Node(50);

    head->next = a;
    a->next = b;
    b->next = c;
    c->next = d;
    d->next = a;

    Node* slow = head;
    Node* fast = head;
    bool flag = false;

    while(fast != NULL && fast->next != NULL){
        if(slow == fast){
            flag = true;
            break;
        }
        
        slow = slow->next;
        fast = fast->next->next;
    }

    if(flag == true){
        cout << "Cycle Detected" << endl;
    }
    else{
        cout << "No Cycle" << endl;
    }

    return 0;
}
