/*

Insert into a min heap

This is insert_in_max_heap.cpp with one character changed. That file explains
the heap, the array-as-tree indexing -- parent (i-1)/2, children 2i+1 and
2i+2 -- and why the new value is appended and then bubbled up. All of it
applies here unchanged.

The only difference is which way the rule points:

    max heap: every parent is at least as big as its children  -> swap on >
    min heap: every parent is at most as big as its children   -> swap on <

So the smallest value ends up at index 0 instead of the largest, and the new
value climbs while it is SMALLER than its parent. Same shape, same cost
O(log n), one comparison flipped.

The input must already be a valid min heap.

*/

#include<iostream>
#include <vector>

using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> v(n);

    // The existing min heap, in array order.
    for(int i=0; i<n; i++){
        cin >> v[i];
    }

    int val;
    cin >> val;
    v.push_back(val);           // the only free slot in a complete tree
    int cur_idx = v.size() - 1;
    while(cur_idx != 0){        // index 0 is the root: nowhere left to climb
        int par_idx = (cur_idx - 1) / 2;
        // `<` instead of `>` -- the whole difference from the max heap.
        // A value smaller than its parent breaks the min-heap rule, so it
        // moves up one level and the check repeats from there.
        if(v[cur_idx] < v[par_idx]){
            swap(v[cur_idx], v[par_idx]);
            cur_idx = par_idx;
        } else{
            break;              // parent is already smaller; the path is fine
        }
    }

    // For heap 10 20 30 40 50 60 and value 5: 5 lands at index 6, beats its
    // parent 30 (index 2), then beats 10 (index 0), so it becomes the new
    // smallest value at the top -- 5 20 10 40 50 60 30.
    for(int x : v){
        cout << x << " ";
    }
    cout << endl;

    return 0;
}
