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
    // Read the elements (negative numbers are fine with cin >>).
    for(int i=0; i<n; i++){
        cin >> a[i]; // read one number
    }

    /*
     * Idea: if we know the total of the whole array and the sum of
     * everything to the LEFT of index i, the sum to the RIGHT of i is
     *     total - leftSum - a[i]
     * so a single walk from left to right is enough: O(n).
     * -7 1 5 2 -4 3 0 has total 0. At i = 3: leftSum = -7+1+5 = -1,
     * rightSum = 0 - (-1) - 2 = -1. Equal, so the answer is 3.
     */
    int totalSum = 0; // will hold a[0] + ... + a[n-1]
    for(int i=0; i<n; i++){ // add every element once
        totalSum += a[i]; // totalSum = totalSum + a[i]
    }

    int leftSum = 0;                     // nothing is left of index 0

    // Try every index i as the balance point, left to right.
    for(int i=0; i < n; i++){
        int rightSum = totalSum - leftSum - a[i]; // everything after i (a[i] itself is on neither side)

        if(leftSum == rightSum){ // both sides balance
            cout << i << endl;           // the first equilibrium index
            return 0;                    // stop the whole program here
        }

        // Before moving on, a[i] becomes part of the left side.
        leftSum += a[i];
    }

    // The loop finished without finding one.
    cout << -1 << endl; // -1 means "no equilibrium index"

    return 0; // program finished successfully
}
