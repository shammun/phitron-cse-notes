/*

Problem-1: Running Sum of an Array
Description:
Given an array nums of integers, define a running sum of the array as runningSum[i] = 
sum(nums[0]…nums[i]). Write a C++ program to compute the running sum of the given array 
and print the result.

Note: Solve this problem using function and Vector. 

Input
   ●	The first line contains an integer n representing the size of the array.
   ●	The second line contains n integers representing the elements of the array nums.

Output
   ●	Print the running sum of the array as a sequence of integers separated by spaces.

Input:
4
1 2 3 4

Output:
1 3 6 10

Explanation:
Running sum is obtained as follows: [1, 1+2, 1+2+3, 1+2+3+4].

*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> nums(n);

    for(int i=0; i<n; i++){
        cin >> nums[i];
    }

    /*
     * A running sum is a prefix sum: each answer is the previous answer
     * plus one more number, so we never add the same numbers twice.
     * 1 2 3 4 -> 1, 1+2 = 3, 3+3 = 6, 6+4 = 10. One pass: O(n).
     */
    vector<int>runningSum(n);
    runningSum[0] = nums[0];            // the first sum is just the first value

    for(int i=1; i<n; i++){
        // sum of nums[0..i] = sum of nums[0..i-1] + nums[i]
        runningSum[i] = runningSum[i-1] + nums[i];
    }

    for(int i=0; i<n; i++){
        cout << runningSum[i] << " ";
    }

    cout << endl;

    return 0;
}