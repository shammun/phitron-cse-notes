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


bool binarySearch(vector<int> arr, int target){
    int left = 0;
    int right = arr.size() - 1;

    while(left <= right){
        int mid = (left + right) / 2;

        if(arr[mid] == target){
            return true;
        } else if(arr[mid] < target){
            left = mid + 1;
        } else{
            right = mid - 1;
        }
    }
    return false;
}

int main() {
    int n;
    cin >> n;

    vector<int> arr(n);
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }

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