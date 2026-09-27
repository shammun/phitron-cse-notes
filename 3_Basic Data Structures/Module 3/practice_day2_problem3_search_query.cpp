/*

Problem-3: Search Query

1.	WAP that takes an array of size n and q queries as input. For each query you will be
given a number. For each query you have to print ‘YES’ if the number is present in the
array, otherwise print ‘No’. Solve this problem in optimized way.

Sample input:
5
6 3 2 1 8
4
1
5
2
9

Sample output:
YES
NO
YES
NO


*/

#include <iostream>  // cin and cout
#include <vector>    // vector
#include <algorithm> // sort()
#include <string>    // not needed here
using namespace std; // lets us drop the std:: prefix


/*
 * Many "is x in the array?" questions: sort once, then answer each one with
 * binary search in O(log n) instead of scanning all n values.
 */

// Returns true when target is in the SORTED vector arr.
// Note: arr is passed by value, so every call copies the whole vector
// (O(n)). Writing `const vector<int>& arr` would avoid the copy.
// Parameters: arr = the sorted numbers, target = the value to look for.
// Return: true (found) or false (not found).
bool binarySearch(vector<int> arr, int target){
    // The answer, if it exists, is somewhere in arr[left..right].
    int left = 0; // first index of the window
    int right = arr.size() - 1; // last index of the window

    while(left <= right){               // at least one value left to check
        int mid = (left + right) / 2; // middle index (rounds down)

        if(arr[mid] == target){ // exact hit
            return true;                // found it
        } else if(arr[mid] < target){ // middle too small
            left = mid + 1;             // mid and everything left of it are too small
        } else{ // middle too big
            right = mid - 1;            // mid and everything right of it are too big
        }
    }
    return false;                       // the window became empty
}

int main() { // the program starts running here
    int n; // array size
    cin >> n; // read n

    vector<int> arr(n); // n slots
    for(int i=0; i<n; i++){ // read the numbers
        cin >> arr[i]; // into slot i
    }

    // Binary search only works on sorted data, so sort once, before the queries.
    // 6 3 2 1 8 becomes 1 2 3 6 8.
    // arr.begin() / arr.end() mark the first element and one past the last.
    sort(arr.begin(), arr.end());

    int q; // number of queries
    cin >> q; // read q

    // while(q--): test q, then subtract 1. Runs exactly q times (q, q-1, ..., 1),
    // and stops when q was 0.
    while(q--){
        int target; // value asked about
        cin >> target; // read it

        if(binarySearch(arr, target)){ // present?
            cout << "YES" << endl;
        } else { // not present
            cout << "NO" << endl; // (the sample output uses "NO", so that is printed)
        }
    }

    return 0; // program finished successfully
}
