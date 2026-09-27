/*

This is a simple program to find a value in an array using
linear search and binary search.

If a value is found, print "found", otherwise print "not found".

Linear search: check every element one by one -> up to n checks, O(n).
               Works on any array, sorted or not.
Binary search: look at the MIDDLE of the range; if the middle is too small,
               the answer can only be on the right, so throw the left half away
               (and the other way round). The range halves each step -> O(log n).
               ONLY works when the array is sorted.
Example input: 5 / 1 3 5 7 9 / 7  -> "found" and "found (binary search)".

*/

#include <iostream>  // cin and cout
#include <vector>    // not needed here, kept from the template
#include <algorithm> // sort() (used only in the commented-out line)
#include <string>    // not needed here
using namespace std; // lets us drop the std:: prefix

int main() { // the program starts running here
    int n; // number of elements
    cin >> n; // read n
    // An array whose size is only known at run time (variable-length array).
    // g++ allows it as an extension; standard C++ would use vector<int> a(n).
    int a[n];

    // Read the n elements.
    for(int i=0; i<n; i++){
        cin >> a[i]; // read one number into slot i
    }

    int val; // the value we are looking for
    cin >> val; // read it

    // O(n)  ---> linear search
    int flag = 0; // 0 = not found yet, 1 = found
    for(int i=0; i<n; i++){ // check each slot from left to right
        if(a[i] == val){ // is this the value?
            flag = 1; // remember we found it
            break; // no need to look further: leave the loop now
        }
    }
    if(flag == 1){ // found during the scan
        cout << "found" << endl;
    }
    else{ // scanned everything, never matched
        cout << "not found" << endl;
    }

    /*
    If not sorted, first sort the array, then apply binary search
    sort(a, a+n);
    */
    // (That line is switched off: it would sort a[0..n-1] into increasing order.
    // a is the first element's address and a+n is one past the last one.)
    // O(logn)  ---> binary search

    // We are assuming the array is sorted

    int flag2 = 0; // 0 = not found yet, 1 = found
    // The search window a[l..r] (both ends included) where val could still be.
    int l = 0, r = n-1; // start with the whole array
    // Keep going while the window has at least one element (l <= r).
    while(l <= r){
        int mid = (l + r) / 2; // index of the middle element (integer division rounds down)
        if(a[mid] == val){ // hit
            flag2 = 1; // found
            break; // stop searching
        }
        else if(a[mid] < val){ // middle is too small -> val must be to the right
            l = mid + 1; // drop mid and everything left of it
        }
        else{ // middle is too big -> val must be to the left
            r = mid - 1; // drop mid and everything right of it
        }
    }
    // Trace on 1 3 5 7 9, val = 7: l=0 r=4 mid=2 (5 < 7) -> l=3;
    // l=3 r=4 mid=3 (7 == 7) -> found.
    if(flag2 == 1){ // binary search found it
        cout << "found (binary search)" << endl;
    }
    else{ // window became empty
        cout << "not found (binary search)" << endl;
    }


    return 0; // program finished successfully
}
