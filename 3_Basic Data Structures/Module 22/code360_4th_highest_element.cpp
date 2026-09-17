/*

https://www.naukri.com/code360/problems/fourth-largest-element-in-the-array_1792782?leftPanelTabValue=PROBLEM

4th Largest Element In The Array

*/


#include <algorithm>
#include <climits>
#include <vector>

using namespace std;

int getFourthLargest(int arr[], int n)
{

    sort(arr, arr + n, greater<int>());

    vector<int> vec_arr;
    for (int i = 0; i < n; i++) {
        vec_arr.push_back(arr[i]);
    }

    if (vec_arr.size() < 4) {
        return -2147483648;
    }

    return vec_arr[3];
}