/*

Delete from a max heap (remove the root, i.e. the biggest value)

A max heap is a complete binary tree stored in an array, where every parent
is at least as big as its children (see insert_in_max_heap.cpp). For index i:
    parent = (i - 1) / 2,  left child = 2*i + 1,  right child = 2*i + 2.

Deleting always removes the ROOT (index 0), the maximum. The trick:
  1. copy the LAST value into index 0 and pop_back() - the tree stays
     complete (no gap), but the value at the top is now probably too small;
  2. "sift down": while the value is smaller than its bigger child, swap it
     with that bigger child and follow it down. Swapping with the BIGGER
     child is what keeps the rule true: the bigger child becomes the parent
     of the smaller one.
Cost: O(log n), one swap per level.

Trace: heap 50 40 30 10 20. Delete: 20 moves to the top -> 20 40 30 10.
  children of index 0 are 40 and 30; 40 is bigger and 40 > 20 -> swap
  -> 40 20 30 10; children of index 1: only 10 (index 3); 10 < 20 -> stop.

This program reads n values, builds a max heap by inserting them one by one,
prints it, then deletes the root.

BUG: the function delete_heap below is missing its closing `}`. The last `}`
before main closes the while loop, so main ends up INSIDE delete_heap and the
file does not compile ("a function-definition is not allowed here").
Fix: add one more `}` after the while loop's closing brace. Even then, main
never prints the heap after delete_heap(v), so a second print_heap(v) call
would be needed to see the result.

*/

#include<iostream>      // cin and cout (on this compiler it also happens to bring INT_MIN)
#include <vector>       // vector

using namespace std;    // write cout, vector, swap without std::

// Insert x into the max heap v: append it, then bubble it up while it is
// bigger than its parent (see insert_in_max_heap.cpp). v is a reference (&),
// so the caller's vector is changed.
void insert_heap(vector<int> &v, int x){
    v.push_back(x);                     // the only free slot of a complete tree: the end
    int cur_idx = v.size() - 1;         // where x sits now
    while(cur_idx != 0){                // index 0 is the root: nowhere left to climb
        int par_idx = (cur_idx -1) / 2; // parent's index
        if(v[cur_idx] > v[par_idx]){    // bigger than the parent breaks the rule
            swap(v[cur_idx], v[par_idx]);   // exchange the two values
            cur_idx = par_idx;              // follow x upwards
        } else{
            break;                      // parent is bigger: the path is fine
        }
    }
}

// Read n values and insert each one, so v becomes a valid max heap.
void heap_input(vector<int> &v, int n){
    for(int i=0; i<n; i++){             // one value per pass
        int x;
        cin >> x;
        insert_heap(v, x);
    }
}

// Print the heap array, level by level (that is just array order).
void print_heap(vector<int> &v){
    for(int x : v){                     // range-for: x is each value in turn
        cout << x << " ";
    }
    cout << endl;                       // endl = newline + flush
}


// A first attempt, switched off. Why it is wrong: it stops as soon as the
// RIGHT child is missing (right_idx >= size), even when a left child exists
// and is bigger, so the heap rule can stay broken at the bottom. It also does
// nothing when the two children are equal (neither strict > is true).
/*

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

// Remove the root (the maximum) from the max heap v.
// (v must not be empty: v[0] and v.back() need at least one value.)
void delete_heap(vector<int> &v){
    v[0] = v.back();                    // back() = the last value; it replaces the root
    v.pop_back();                       // remove the last slot; the tree stays complete

    int cur_idx = 0;                    // the moved value starts at the top

    // Sift down. One pass moves the value one level down; the function
    // returns when neither child is bigger than it.
    while(true){
        int left_idx = (2 * cur_idx) + 1;   // left child's index
        int right_idx = (2 * cur_idx) + 2;  // right child's index



        // A missing child counts as INT_MIN (the smallest int), so it can
        // never win a comparison. This avoids reading outside the vector.
        int left_val = INT_MIN;
        int right_val = INT_MIN;

        if(left_idx < v.size()){        // the left child exists
            left_val = v[left_idx];
        }
        if(right_idx < v.size()){       // the right child exists
            right_val = v[right_idx];
        }

        // Left is the bigger (or equal) child and beats the current value: swap down-left.
        if(left_val >= right_val && left_val > v[cur_idx]){
            swap(v[left_idx], v[cur_idx]);
            cur_idx = left_idx;
        // Right is strictly bigger and beats the current value: swap down-right.
        } else if(right_val > left_val && right_val > v[cur_idx]){
            swap(v[right_idx], v[cur_idx]);
            cur_idx = right_idx;
        } else{
            return;                     // both children are smaller (or missing): done
        }
    }
    // BUG: the closing `}` of delete_heap is missing here, so main below is
    // parsed as if it were inside this function and the file does not compile.


int main(){
    vector<int> v;          // the heap, empty at first
    int n;
    cin >> n;               // how many values to read

    heap_input(v, n);       // build the max heap

    print_heap(v);          // show it

    delete_heap(v);         // remove the maximum (the result is not printed)

    return 0;               // program finished normally
}
