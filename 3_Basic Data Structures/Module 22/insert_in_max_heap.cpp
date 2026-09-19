/*

Insert into a max heap

A binary heap is a complete binary tree -- every level is full except possibly
the last, which is filled from the left -- obeying one rule:

    max heap: every parent is at least as big as both of its children.

So the biggest value of all sits at the very top. Note what the rule does NOT
say: left and right are in no particular order, and a value two levels down
may well be bigger than something on the other side of the tree. A heap is
much weaker than a BST, and that is why it is cheaper to maintain.

The array trick
---------------
Because the tree is complete it has no gaps, so it can be stored in a plain
array, level by level, left to right. No pointers are needed at all -- the
family links are arithmetic on the index:

        index:   0    1    2    3    4    5    6
                 |    |    |    |    |    |    |
                        0
                     /     \
                   1         2
                  / \       / \
                 3   4     5   6

    parent of i     = (i - 1) / 2      (integer division)
    left child of i = 2*i + 1
    right child of i= 2*i + 2

A quick check: children 3 and 4 both give (3-1)/2 = 1 and (4-1)/2 = 1, their
parent. And index 0 has no parent, which is why the loop below stops there.
An index that comes out >= the array size means that child does not exist.

Insert = push_back, then bubble up
----------------------------------
The new value has to go in the only free slot of a complete tree: the end of
the array. From there it may be bigger than its parent, which breaks the rule,
so swap the two. That can break the rule one level higher, so repeat. The
value keeps climbing until its parent beats it, or until it reaches index 0.

Nothing else in the tree is disturbed: swapping a big value up past a smaller
parent leaves the smaller value above the same children it already dominated.

Cost: a complete tree of n nodes is about log2(n) levels deep and each swap
climbs one level, so insert is O(log n).

This program expects an array that is ALREADY a valid max heap, adds one value
to it, and prints the array. It does not build a heap out of arbitrary input.

*/

#include<iostream>
#include <vector>

using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> v(n);

    // The existing heap, in array order (level by level, left to right).
    for(int i=0; i<n; i++){
        cin >> v[i];
    }

    // The value to insert. push_back puts it in the first free slot, which
    // is the last position of the bottom level -- the tree stays complete.
    int val;
    cin >> val;
    v.push_back(val);
    int cur_idx = v.size() - 1;   // where the new value is sitting now
    // Climb while there is a parent to climb to. Index 0 is the root, so
    // reaching it means the value is the new maximum and the loop must end.
    while(cur_idx != 0){
        int par_idx = (cur_idx - 1) / 2;
        // Bigger than the parent: the max-heap rule is broken here, so swap
        // them and carry on checking from the parent's position.
        if(v[cur_idx] > v[par_idx]){
            swap(v[cur_idx], v[par_idx]);
            cur_idx = par_idx;
        } else{
            // The parent already beats it. Everything above the parent is
            // at least as big, so the whole path is fine -- stop.
            break;
        }
    }

    // Print the array. It is still a heap, just one element longer.
    // For heap 60 40 50 10 30 20 and value 55: 55 lands at index 6, beats
    // its parent 50 at index 2 and swaps, then stops under 60 (55 < 60),
    // giving 60 40 55 10 30 20 50.
    for(int x : v){
        cout << x << " ";
    }
    cout << endl;

    return 0;
}
