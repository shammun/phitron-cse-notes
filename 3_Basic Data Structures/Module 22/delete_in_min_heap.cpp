/*

Min heap -- Root value is always smaller than its child nodes

(More exactly: every parent is at most as big as its children, so the
smallest value is at the root. Equal values are allowed.)

Delete from a min heap = remove the root (the minimum). It is
delete_in_max_heap.cpp with every comparison flipped:
  1. copy the last value to index 0 and pop_back(),
  2. sift down: while the value is BIGGER than its smaller child, swap it
     with that smaller child and follow it down.
Array indexing: parent (i - 1) / 2, children 2*i + 1 and 2*i + 2.

Trace: min heap 10 20 30 40 50. Delete: 50 moves to the top -> 50 20 30 40.
  children of index 0 are 20 and 30; 20 is smaller and 20 < 50 -> swap
  -> 20 50 30 40; children of index 1: only 40 (index 3); 40 < 50 -> swap
  -> 20 40 30 50. Index 3 has no children -> stop.

BUG: exactly as in delete_in_max_heap.cpp, delete_heap is missing its
closing `}`, so main ends up inside it and the file does not compile.
Fix: add one `}` after the while loop. main also never prints the heap after
the delete, so a second print_heap(v) is needed to see the result.

*/

#include<iostream>      // cin and cout (on this compiler it also happens to bring INT_MAX)
#include <vector>       // vector

using namespace std;    // write cout, vector, swap without std::

// Insert x into the min heap v: append it, then bubble it up while it is
// SMALLER than its parent. v is a reference (&), so the caller's vector changes.
void insert_heap(vector<int> &v, int x){
    v.push_back(x);                     // the end is the only free slot
    int cur_idx = v.size() - 1;         // where x sits now
    while(cur_idx != 0){                // stop at the root
        int par_idx = (cur_idx -1) / 2; // parent's index
        if(v[cur_idx] < v[par_idx]){    // smaller than the parent breaks the min rule
            swap(v[cur_idx], v[par_idx]);   // exchange the two values
            cur_idx = par_idx;              // follow x upwards
        } else{
            break;                      // parent is smaller: fine
        }
    }
}

// Read n values and insert each one, so v becomes a valid min heap.
void heap_input(vector<int> &v, int n){
    for(int i=0; i<n; i++){             // one value per pass
        int x;
        cin >> x;
        insert_heap(v, x);
    }
}

// Print the heap array (array order = level by level).
void print_heap(vector<int> &v){
    for(int x : v){                     // range-for: x is each value in turn
        cout << x << " ";
    }
    cout << endl;                       // endl = newline + flush
}


/* The code below is wrong.
   (It is a copy of the max-heap attempt: it uses > comparisons, which are
   the wrong direction for a min heap, and it stops as soon as the right
   child is missing even if the left child should still be swapped.)

void delete_heap_mine(vector<int> &v){
    v[0] = v.back(); // v[0] = v[v.size() - 1];
    v.pop_back();

    int cur_idx = 0;

    while(true){
        int left_idx = (2 * cur_idx) + 1;
        int right_idx = (2 * cur_idx) + 2;
        if(left_idx >= v.size()){
            break;
        }
        if(right_idx >= v.size()){
            break;
        }
        if(left_idx < v.size() && right_idx < v.size()){
            if(v[left_idx] > v[right_idx] && v[left_idx] > v[cur_idx]){
                swap(v[left_idx], v[cur_idx]);
                cur_idx = left_idx;
            } else if(v[right_idx] > v[left_idx] && v[right_idx] > v[cur_idx]){
                swap(v[right_idx], v[cur_idx]);
                cur_idx = right_idx;
            } else{
                break;
            }
        }
    }
}

*/

// Remove the root (the minimum) from the min heap v.
// (v must not be empty.)
void delete_heap(vector<int> &v){
    v[0] = v.back();                    // the last value replaces the root
    v.pop_back();                       // remove the last slot; the tree stays complete

    int cur_idx = 0;                    // the moved value starts at the top

    // Sift down: one pass moves the value one level down; the function
    // returns when neither child is smaller than it.
    while(true){
        int left_idx = (2 * cur_idx) + 1;   // left child's index
        int right_idx = (2 * cur_idx) + 2;  // right child's index



        // A missing child counts as INT_MAX (the largest int), so it can
        // never be picked as "the smaller child".
        int left_val = INT_MAX;
        int right_val = INT_MAX;

        if(left_idx < v.size()){        // the left child exists
            left_val = v[left_idx];
        }
        if(right_idx < v.size()){       // the right child exists
            right_val = v[right_idx];
        }

        // Left is the smaller (or equal) child and is below the current value: swap down-left.
        if(left_val <= right_val && left_val < v[cur_idx]){
            swap(v[left_idx], v[cur_idx]);
            cur_idx = left_idx;
        // Right is strictly smaller and below the current value: swap down-right.
        } else if(right_val < left_val && right_val < v[cur_idx]){
            swap(v[right_idx], v[cur_idx]);
            cur_idx = right_idx;
        } else{
            return;                     // both children are bigger (or missing): done
        }
    }
    // BUG: the closing `}` of delete_heap is missing here, so main below is
    // parsed as if it were inside this function and the file does not compile.


int main(){
    vector<int> v;          // the heap, empty at first
    int n;
    cin >> n;               // how many values to read

    heap_input(v, n);       // build the min heap

    print_heap(v);          // show it

    delete_heap(v);         // remove the minimum (the result is not printed)

    return 0;               // program finished normally
}
