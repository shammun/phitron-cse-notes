/*

Take a doubly linked list as input and check if it forms any palindrome or not.

Input:
10 20 30 20 10 -1

Output:
YES

Input:
10 20 30 30 20 10 -1

Output:
YES

Input:
10 20 30 40 20 10 -1

Output:
NO

*/


/*
 * The idea: a palindrome reads the same from both ends, and a doubly linked
 * list can be walked from both ends at once. Put `i` on the head and `j` on
 * the tail, compare the two values, then step `i` forward and `j` backward.
 * One mismatch is enough to say NO. If they reach the middle with no
 * mismatch, the answer is YES.
 *
 * The stopping test is the same one reverse_doubly_linked_list.cpp uses:
 * `i != j` stops an odd-length list when both land on the middle node, and
 * `i->prev != j` stops an even-length list the moment the two pointers cross.
 *
 * Practice copy. On top of the `return;` bug in `main` (use `break;`), this
 * one changed `is_palindrome` to return `void` and to `return true;`, so it
 * does not compile: `bool result = is_palindrome(...)` cannot store a void.
 * Declare it `bool` and `return flag;` - returning `true` would throw the
 * comparisons away and call every list a palindrome.
 */

#include <iostream>   // cin (keyboard input) and cout (screen output)
#include <vector>   // std::vector (a resizable array) - not used in this file
#include <algorithm>   // sort, reverse, swap, max, min ... - not used in this file
#include <string>   // std::string - not used in this file
using namespace std;   // lets us write cout, list ... instead of std::cout, std::list ...

// A doubly linked node: the value, an arrow forward and an arrow back.
class Node {   // one node: a value plus links to the next AND the previous node
    public:   // members below are usable from outside the class
        int val;   // the value this node carries
        Node* next;   // address of the node after this one (NULL = none)
        Node* prev;   // address of the node before this one (NULL = none)

    Node(int val) {   // constructor: runs on `new Node(x)`
        this->val = val;   // `this->val` = the member, plain `val` = the parameter
        this->next = NULL;   // not linked to anything yet
        this->prev = NULL;   // not linked to anything yet
    }
};


// Append at the end in O(1), because `tail` is remembered.
// `Node* &head` = a reference to the caller's pointer (not a copy), so the
// function can move main's own head/tail.
void insert_at_tail(Node* &head, Node* &tail, int val){
    Node* newNode = new Node(val);   // new node on the heap; its links start as NULL
    if(head==NULL){   // empty list?
        head = newNode;   // the only node is the first node...
        tail = newNode;   // ...and also the last node
        return;   // done - skip the rest of the function
    }
    tail->next = newNode;   // old last node points forward to the new node
    newNode->prev = tail;   // new node points back to the old last node
    tail = newNode;   // the new node is the last node now
}

// BUG: `void` here, but `main` stores the answer in a bool. Fix: make it `bool`.
void is_palindrome(Node* &head, Node* &tail){
    bool flag = true;   // innocent until a mismatch is found
    // `Node* i=head, *j=tail` declares TWO pointers (each needs its own `*`).
    // Each round: compare, then i steps forward and j steps back.
    for(Node* i=head, *j=tail; i!=j && i->prev != j; i=i->next, j=j->prev){
        // Compare the pair that mirrors each other.
        if(i->val != j->val){
            flag = false;   // one different pair is enough
            break;          // no need to look further
        }
    }
    // BUG: a `void` function cannot return a value (compile error), and `true`
    // would ignore the comparisons anyway. Fix: `return flag;` in a `bool` function.
    return true;   // bug: should be `return flag;` in a `bool` function
}

// main: read the list until -1, then print YES if it is a palindrome, else NO.
int main(){
    Node* head1 = NULL;   // first node (none yet: empty list)
    Node* tail1 = NULL;   // last node (none yet)

    int val;   // holds each number as it is read
    while(true){   // repeat until -1
        cin >> val;   // read the next integer (spaces/newlines are skipped)
        if(val==-1){   // -1 ends the input
            // BUG: a bare `return;` in `int main` does not compile, and would leave
            // the program before the check. Fix: `break;`
            return;   // bug: should be `break;` (see the top comment)
        }
        insert_at_tail(head1, tail1, val);   // append, keeping input order
    }

    // Check the list and print the verdict.
    bool result = is_palindrome(head1, tail1);   // true = palindrome

    if(result){   // palindrome?
        cout << "YES" << endl;   // endl = newline + flush
    }
    else{
        cout << "NO" << endl;   // endl = newline + flush
    }

    return 0;   // 0 = the program ended normally
}