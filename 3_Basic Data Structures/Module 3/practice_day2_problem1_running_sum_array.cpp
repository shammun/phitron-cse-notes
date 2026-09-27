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

#include <iostream>  // cin and cout
#include <vector>    // vector
#include <algorithm> // not needed here, kept from the template
#include <string>    // not needed here
using namespace std; // lets us drop the std:: prefix

// Note: the sheet asks for a function; this solution does the work in main(),
// which gives the same output.
int main() { // the program starts running here
    int n; // size of the array
    cin >> n; // read n
    vector<int> nums(n); // n slots, all 0 for now

    // Read the n numbers into nums[0..n-1].
    for(int i=0; i<n; i++){
        cin >> nums[i]; // read one number
    }

    /*
     * A running sum is a prefix sum: each answer is the previous answer
     * plus one more number, so we never add the same numbers twice.
     * 1 2 3 4 -> 1, 1+2 = 3, 3+3 = 6, 6+4 = 10. One pass: O(n).
     */
    vector<int>runningSum(n); // runningSum[i] will hold nums[0] + ... + nums[i]
    runningSum[0] = nums[0];            // the first sum is just the first value

    // i starts at 1 because index 0 is already done; each pass fills one slot.
    for(int i=1; i<n; i++){
        // sum of nums[0..i] = sum of nums[0..i-1] + nums[i]
        runningSum[i] = runningSum[i-1] + nums[i];
    }

    // Print all running sums, space separated.
    for(int i=0; i<n; i++){
        cout << runningSum[i] << " "; // one value and a space
    }

    cout << endl; // finish the line

    return 0; // program finished successfully
}
