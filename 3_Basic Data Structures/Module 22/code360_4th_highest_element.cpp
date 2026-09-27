/*

https://www.naukri.com/code360/problems/fourth-largest-element-in-the-array_1792782?leftPanelTabValue=PROBLEM

4th Largest Element In The Array

*/


#include <algorithm>    // sort, greater
#include <climits>      // INT_MIN (the smallest int, -2147483648)
#include <vector>       // vector

using namespace std;    // write sort, vector ... without std::

/*
 * Task in short: return the 4th largest value of arr (repeats count, so in
 * [9 9 5 3] the 4th largest is 3). If arr has fewer than 4 values, return
 * INT_MIN (-2147483648). Example: [3 6 1 9 5] -> 3.
 *
 * Idea: sort the array from biggest to smallest. Then the largest value sits
 * at index 0, the 2nd largest at index 1, ... and the 4th largest at index 3.
 */
// arr = the array (really a pointer to its first element, so sorting it
// changes the caller's array), n = how many values it has.
// (The judge's hidden main calls this function.)
int getFourthLargest(int arr[], int n)
{

    // greater<int>() makes sort put bigger values first (descending order).
    // arr and arr + n are the start and one-past-the-end of the array.
    sort(arr, arr + n, greater<int>());

    // Copy the sorted values into a vector (arr[3] would do the same job;
    // the vector just gives us .size()).
    vector<int> vec_arr;                 // starts empty
    for (int i = 0; i < n; i++) {        // i = index of the value being copied
        vec_arr.push_back(arr[i]);       // push_back adds at the end
    }

    // Fewer than 4 values: there is no 4th largest, so return INT_MIN.
    if (vec_arr.size() < 4) {
        return -2147483648;          // the value of INT_MIN, written out by hand
    }

    // Index 3 = the 4th value in descending order = the 4th largest.
    return vec_arr[3];
}