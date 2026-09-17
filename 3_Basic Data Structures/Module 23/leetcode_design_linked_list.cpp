/*

https://leetcode.com/problems/design-linked-list/

Design linked list

*/


class Node{
    public: 
        int val;
        Node* next;
        Node* prev;

    Node(int val){
        this->val = val;
        this->next = NULL;
        this->prev = NULL;
    }

};

class MyLinkedList {
public:
    Node* head;
    Node* tail;
    int size;

    MyLinkedList() {
        head = NULL;
        tail = NULL;
        size = 0;
    }
    
    int get(int index) {
        if(index < 0 || index >= size){
            return -1;
        }
        Node* tmp = head;
        for(int i=0; i<index; i++){
            tmp = tmp->next;
        }
        return tmp->val;
    }
    
    void addAtHead(int val) {
        Node* newNode = new Node(val);
        if(head == NULL){
            head = tail = newNode;
        } else{
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
        size++;
    }
    
    void addAtTail(int val) {
        Node* newNode = new Node(val);
        if(tail == NULL){
            head = tail = newNode;
        } else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
        size++;
    }
    
    void addAtIndex(int index, int val) {
        if(index < 0 || index > size){
            return;
        }

        if(index == 0){
            addAtHead(val);
            return;
        }

        if(index == size){
            addAtTail(val);
            return;
        }

        Node* tmp = head;
        for(int i=1; i<index; i++){
            tmp = tmp->next;
        }

        Node* newNode = new Node(val);
        newNode->next = tmp->next;
        tmp->next->prev = newNode;
        newNode->prev = tmp;
        tmp->next = newNode;

        size++;
    }
    
    void deleteAtIndex(int index) {
        if(index < 0 || index >= size || size == 0){
            return;
        }

        if(size == 1){
            delete head;
            head = tail = NULL;
        }

        else if(index == 0){
            Node* temp = head;
            head = head->next;
            head->prev = NULL;
            delete temp;
        }

        else if(index == size-1){
            Node* temp = tail;
            tail = tail->prev;
            tail->next = NULL;
            delete temp;
        }

        else{
            Node* curr = head;
            for(int i=0; i<index; i++){
                curr = curr->next;
            }
            curr->prev->next = curr->next;
            curr->next->prev = curr->prev;
            delete curr;
        }        

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