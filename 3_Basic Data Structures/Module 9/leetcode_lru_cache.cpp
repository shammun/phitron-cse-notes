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

#include <iostream>        // cin and cout
#include <string>          // std::string (the command words "put" / "get")
#include <unordered_map>   // std::unordered_map - a hash table: key -> value lookups in O(1) on average
using namespace std; // Allows us to avoid prefixing standard library objects with `std::`.

// A doubly linked node that carries both the key and the value.
class Node {
    public:          // members below are usable from outside the class
        int key;     // kept as well, because the eviction needs to erase it from the map
        int val;     // the cached value
        Node* next;  // the node after this one (toward the LEAST recently used end)
        Node* prev;  // the node before this one (toward the MOST recently used end)

    // Constructor: runs on `new Node(k, v)`. `this->key` is the member, `key` the parameter.
    Node(int key, int val) {
        this->key = key;
        this->val = val;
        this->next = NULL;   // not linked yet
        this->prev = NULL;
    }
};

// The cache. Two structures work together:
//   * the list keeps the keys in "last used" order: newest right after `head`,
//     oldest right before `tail`;
//   * the map finds the node of any key in O(1), so we never walk the list.
// Every operation is O(1) on average.
class LRUCache {
public:
    int capacity;   // the most keys the cache may hold
    Node* head; // fake node in front of the newest key
    Node* tail; // fake node behind the least recently used key
    // unordered_map<int, Node*>: key -> address of that key's node.
    unordered_map<int, Node*> table;

    // Constructor: an empty cache that can hold `capacity` keys.
    LRUCache(int capacity) {
        this->capacity = capacity;   // member = parameter (same name, hence `this->`)

        /* Two fake nodes at the ends. They are never returned to anybody;
           they exist so that every unhook and every insert has a node on
           both sides, and we never have to ask "is this the head?". */
        head = new Node(0, 0);
        tail = new Node(0, 0);
        head->next = tail;   // empty list: head <-> tail
        tail->prev = head;
    }

    // Take a node out of the list. Both of its neighbours must be re-linked.
    // (The node itself is not freed; it is about to be re-inserted or deleted.)
    void remove_node(Node* node) {
        node->prev->next = node->next;   // the node before now skips forward past it
        node->next->prev = node->prev;   // the node after now skips back past it
    }

    // Put a node right after `head`, which is what "newest" means here.
    // Same four links as any doubly list insert; the two lines about the old
    // first node come first, while `head->next` still points at it.
    void insert_at_front(Node* node) {
        node->next = head->next;     // node -> old first
        head->next->prev = node;     // node <- old first
        head->next = node;           // head -> node
        node->prev = head;           // head <- node
    }

    // Return the value of `key`, or -1 if it is not cached.
    int get(int key) {
        // `find` returns `table.end()` when the key is not in the map.
        if(table.find(key) == table.end()){
            return -1;
        }

        Node* node = table[key];   // the key's node (the map lookup is O(1))

        // A get counts as a use, so the node moves to the front.
        remove_node(node);
        insert_at_front(node);

        return node->val;
    }

    // Store key -> value. If the cache is full, first throw out the least
    // recently used key.
    void put(int key, int value) {
        if(table.find(key) != table.end()){   // key already cached
            // Known key: only the value changes, no node is created or dropped.
            Node* node = table[key];
            node->val = value;         // overwrite the value
            remove_node(node);         // and mark it as just used:
            insert_at_front(node);     // move it to the front
            return;                    // done
        }

        // `table.size()` is unsigned; `(int)` turns it into an int so the
        // comparison with the int `capacity` is between two ints.
        if((int)table.size() == capacity){
            /* Full. The node just before the fake tail is the one nobody has
               touched for the longest time. Erase it from the map too -
               this is why the node stores its key. */
            Node* lru = tail->prev;
            remove_node(lru);          // out of the list
            table.erase(lru->key);     // out of the map
            delete lru;                // and give its memory back
        }

        Node* newNode = new Node(key, value);   // brand-new key
        table[key] = newNode;                   // map: key -> its node
        insert_at_front(newNode);               // newest, so at the front
    }
};

// Main function: Entry point of the program.
// Reads the capacity and q commands ("put k v" / "get k"), prints every get.
int main(){
    int capacity, q;
    cin >> capacity >> q;   // `>>` can be chained: reads two numbers in a row

    LRUCache cache(capacity);   // the constructor runs here

    // One command per round.
    for(int i = 0; i < q; i++){
        string command;
        cin >> command;         // reads one word

        if(command == "put"){
            int key, value;
            cin >> key >> value;
            cache.put(key, value);             // prints nothing
        } else if(command == "get"){
            int key;
            cin >> key;
            cout << cache.get(key) << endl;    // the value or -1; endl = newline + flush
        }
    }

    return 0;   // normal exit
}
