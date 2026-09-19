// MERGE SORT - divide.cpp and conquer.cpp joined into one working sort.
//
// The plan in three lines:
//     sort the left half, sort the right half, merge the two sorted halves.
// The first two steps are the same problem on a smaller slice, so the function
// calls itself; the third step is the two-pointer walk from conquer.cpp.
//
// Time O(n log n): about log2(n) levels of splitting, and each level moves every
// element exactly once during its merges. That holds whatever the input looks
// like - already sorted, reversed or shuffled - because the array is always cut
// down the middle and always merged.
// Space O(n) for the temporary halves, plus O(log n) of call stack.

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

// conquer(c, l, mid, r) merges two neighbouring slices of ONE array:
//     the left half  c[l .. mid]
//     the right half c[mid+1 .. r]
// Both are already sorted when this is called. The result is written back over
// c[l .. r], and nothing outside that range is touched.
void conquer(int c[], int l, int mid, int r){
    // Copy the left half out into a. Positions l..mid inclusive, so mid - l + 1
    // of them - the "+ 1" is the usual off-by-one trap with inclusive ranges.
    int n = mid - l + 1;
    int a[n];
    for(int i=0; i<n; i++){
        a[i] = c[l+i];
    }

    // Copy the right half out into b. Positions mid+1..r, so r - mid of them.
    // The copies are not optional: the merge writes into c from position l
    // onwards, and without them it would overwrite left-half values that have
    // not been read yet.
    int m = r - mid;
    int b[m];
    for(int i=0; i<m; i++){
        b[i] = c[mid+1+i];
    }

    // Now, take the two pointers for the two arrays and pointer for the result array
    // Exactly the walk from conquer.cpp, with one difference: curr starts at l,
    // not 0, because the merged values go back into the middle of c rather than
    // into a fresh array. i and j are fresh, since a and b are fresh copies.
    // Both halves are sorted, so the smallest value still unplaced is always at
    // a[i] or b[j] - one comparison per value placed, one walk forwards, done.
    int i=0, j=0, curr=l;

    while(i < n && j < m){
        // `<` and not `<=`, so on a tie the value from the RIGHT half is copied
        // first. That makes this sort unstable: equal values can swap places.
        // Changing it to a[i] <= b[j] would make it stable.
        if(a[i] < b[j]){
            c[curr] = a[i];
            i++;
            curr++;
        } else{
            c[curr] = b[j];
            j++;
            curr++;
        }
    }

    // Whichever half still has a tail is copied across as it stands.
    while(i < n){
        c[curr] = a[i];
        i++;
        curr++;
    }

    while(j < m){
        c[curr] = b[j];
        j++;
        curr++;
    }
}

// divide(a, l, r) sorts the slice a[l..r], both ends included.
// Same splitting as divide.cpp, with the merge added at the end.
void divide(int a[], int l, int r){ // O(nlogn) -- this does the merge sort
    // A slice of one element (or none) is already sorted.
    if(l >= r){
        return;
    }
    // Left half is [l, mid], right half is [mid+1, r]: together exactly l..r.
    int mid = (l+r)/2;
    divide(a, l, mid); // merge sort the left half
    divide(a, mid+1, r); // merge sort the right half
    // By the time this line runs, both halves are sorted in place, so the merge
    // can assume what it needs. Order matters: merge first and there would be
    // nothing sorted to merge.
    conquer(a, l, mid, r); // merge the two sorted arrays
}

int main(){
    // First we will take the input for two arrays

    int n, m;      // m is read but never used, a leftover from conquer.cpp -
    cin >> n >> m; // the input must still contain it or n would be misread.

    int a[n];
    for(int i=0; i<n; i++){
        cin >> a[i];
    }

    // Sort the whole array: positions 0 to n-1 inclusive.
    divide(a, 0, n-1);

    for(int i=0; i<n; i++){
        cout << a[i] << " ";
    }

    return 0;
}