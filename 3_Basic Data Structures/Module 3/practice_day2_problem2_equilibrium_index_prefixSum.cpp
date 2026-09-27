/*

Problem 2: Equilibrium Index
Description: Given an array of integers, find the equilibrium index. An equilibrium index is an index such that the sum of elements at lower indexes is equal to the sum of elements at higher indexes.
Example:

Input:
7
-7 1 5 2 -4 3 0

Output:
3

Explanation: At index 3, the sum of elements before it is -1 and after it is also -1

-7	   1	    5	    2	   -4	    3	    0
0	   1		2		3		4		5		6

Sum of before index 3  = -7 + 1 + 5 = -1
Sum of after index    3	  = -4 + 3 + 0 = -1

*/

#include <iostream>  // cin and cout
#include <vector>    // vector
#include <algorithm> // not needed here, kept from the template
#include <string>    // not needed here
using namespace std; // lets us drop the std:: prefix

int main() { // the program starts running here
    int n; // number of elements
    cin >> n; // read n

    vector<int> a(n); // n slots
    // Read the elements.
    for(int i=0; i<n; i++){
        cin >> a[i]; // read one number
    }

    /*
     * Same problem, solved with a prefix array instead of a running total.
     * prefixSum[i] = a[0] + ... + a[i].
     *   sum left of i  = prefixSum[i-1]            (nothing when i = 0)
     *   sum right of i = prefixSum[n-1] - prefixSum[i]
     * For -7 1 5 2 -4 3 0: prefixSum = -7 -6 -1 1 -3 0 0.
     * At i = 3: left = prefixSum[2] = -1, right = 0 - 1 = -1 -> answer 3.
     */
    vector<int> prefixSum(n); // n slots for the prefix totals
    prefixSum[0] = a[0]; // the first total is just the first element
    // Each pass: total up to i = total up to i-1 plus a[i].
    for(int i=1; i<n; i++){
        prefixSum[i] = prefixSum[i-1] + a[i];
    }

    // Try every index i; each check is O(1) thanks to the prefix array.
    for(int i=0; i<n; i++){
        int leftSum = 0; // sum of a[0..i-1]
        int rightSum = 0; // sum of a[i+1..n-1]

        // Index 0 has nothing on its left, and prefixSum[-1] does not exist.
        if(i > 0){
            leftSum = prefixSum[i-1]; // everything before i
        }

        // The whole total minus everything up to and including i.
        rightSum = prefixSum[n-1] - prefixSum[i];

        if(leftSum == rightSum){ // balanced here
            cout << i << endl; // print the first such index
            return 0; // and stop the program
        }

    }

    cout << -1 << endl; // no index balanced: print -1

    return 0; // program finished successfully
}

