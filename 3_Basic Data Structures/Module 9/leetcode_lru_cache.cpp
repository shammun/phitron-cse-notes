/*

LRU Cache   (LeetCode 146)
https://leetcode.com/problems/lru-cache/

Build a small store that can hold only `capacity` keys at a time.

  get(key)        return the value kept for `key`, or -1 if it is not there.
  put(key, value) store the value for `key`. If the key is already in the
                  store, overwrite its value. If the store is full and the key
                  is new, throw out the key that was used least recently, then
                  store the new one.

"Used" means either a get or a put on that key. LRU is short for
"least recently used": the one that has been waiting the longest since its
last use is the one that goes.

Both operations should take the same small amount of work no matter how many
keys are stored. That needs two structures working together:

  * a doubly linked list of the keys in use order, newest at the front and
    the least recently used one at the back. Because every node knows its
    `prev` and `next`, a node in the middle can be unhooked in a few steps.
  * a map from key to the node holding it, so we can find that node without
    walking the list.

Input (for this program, so it can be run here)
First line: capacity and q, the number of commands.
Then q lines, one command each:

  put <key> <value>
  get <key>

Output
One line for every `get`: the value, or -1.

Constraints
Capacity is at least 1. Keys and values are whole numbers.

Example

input
2 9
put 1 1
put 2 2
get 1
put 3 3
get 2
put 4 4
get 1
get 3
get 4

output
1
-1
-1
3
4

Reading the example: the store holds 2 keys. `get 1` answers 1 and also makes
key 1 the newest, so when `put 3 3` needs room it drops key 2 (hence -1 for
`get 2`). `put 4 4` then drops key 1, which was the oldest by then.

*/

#include <iostream>
#include <string>
#include <unordered_map>
using namespace std; // Allows us to avoid prefixing standard library objects with `std::`.

// A doubly linked node that carries both the key and the value.
class Node {
    public:
        int key;     // kept as well, because the eviction needs to erase it from the map
        int val;
        Node* next;
        Node* prev;

    Node(int key, int val) {
        this->key = key;
        this->val = val;
        this->next = NULL;
        this->prev = NULL;
    }
};

class LRUCache {
public:
    int capacity;
    Node* head; // fake node in front of the newest key
    Node* tail; // fake node behind the least recently used key
    unordered_map<int, Node*> table;

    LRUCache(int capacity) {
        this->capacity = capacity;

        /* Two fake nodes at the ends. They are never returned to anybody;
           they exist so that every unhook and every insert has a node on
           both sides, and we never have to ask "is this the head?". */
        head = new Node(0, 0);
        tail = new Node(0, 0);
        head->next = tail;
        tail->prev = head;
    }

    // Take a node out of the list. Both of its neighbours must be re-linked.
    void remove_node(Node* node) {
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }

    // Put a node right after `head`, which is what "newest" means here.
    void insert_at_front(Node* node) {
        node->next = head->next;
        head->next->prev = node;
        head->next = node;
        node->prev = head;
    }

    int get(int key) {
        if(table.find(key) == table.end()){
            return -1;
        }

        Node* node = table[key];

        // A get counts as a use, so the node moves to the front.
        remove_node(node);
        insert_at_front(node);

        return node->val;
    }

    void put(int key, int value) {
        if(table.find(key) != table.end()){
            // Known key: only the value changes, no node is created or dropped.
            Node* node = table[key];
            node->val = value;
            remove_node(node);
            insert_at_front(node);
            return;
        }

        if((int)table.size() == capacity){
            /* Full. The node just before the fake tail is the one nobody has
               touched for the longest time. Erase it from the map too —
               this is why the node stores its key. */
            Node* lru = tail->prev;
            remove_node(lru);
            table.erase(lru->key);
            delete lru;
        }

        Node* newNode = new Node(key, value);
        table[key] = newNode;
        insert_at_front(newNode);
    }
};

// Main function: Entry point of the program.
int main(){
    int capacity, q;
    cin >> capacity >> q;

    LRUCache cache(capacity);

    for(int i = 0; i < q; i++){
        string command;
        cin >> command;

        if(command == "put"){
            int key, value;
            cin >> key >> value;
            cache.put(key, value);
        } else if(command == "get"){
            int key;
            cin >> key;
            cout << cache.get(key) << endl;
        }
    }

    return 0;
}
