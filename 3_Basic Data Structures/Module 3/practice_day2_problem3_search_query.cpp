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

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;


/*
 * Many "is x in the array?" questions: sort once, then answer each one with
 * binary search in O(log n) instead of scanning all n values.
 */

// Returns true when target is in the SORTED vector arr.
// Note: arr is passed by value, so every call copies the whole vector
// (O(n)). Writing `const vector<int>& arr` would avoid the copy.
bool binarySearch(vector<int> arr, int target){
    // The answer, if it exists, is somewhere in arr[left..right].
    int left = 0;
    int right = arr.size() - 1;

    while(left <= right){               // at least one value left to check
        int mid = (left + right) / 2;

        if(arr[mid] == target){
            return true;                // found it
        } else if(arr[mid] < target){
            left = mid + 1;             // mid and everything left of it are too small
        } else{
            right = mid - 1;            // mid and everything right of it are too big
        }
    }
    return false;                       // the window became empty
}

int main() {
    int n;
    cin >> n;

    vector<int> arr(n);
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }

    // Binary search only works on sorted data, so sort once, before the queries.
    // 6 3 2 1 8 becomes 1 2 3 6 8.
    sort(arr.begin(), arr.end());

    int q;
    cin >> q;

    while(q--){
        int target;
        cin >> target;

        if(binarySearch(arr, target)){
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }

    return 0;
}