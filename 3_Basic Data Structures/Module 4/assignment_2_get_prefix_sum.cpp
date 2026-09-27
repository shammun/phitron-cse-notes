/*

Problem Statement

You will be given an integer array A of size N. You need to print the prefix sum array
of the array A in reverse order.

Input Format

First line will contain N.
Next line of contain the array A.
Constraints

1 <= N <= 10^5
1 <= A[i] <= 10^9; Where 0 <= i < N
Output Format

Output the prefix sum array in reverse order.
Sample Input 0

5
2 4 1 5 3
Sample Output 0

15 12 7 6 2
Explanation 0

The prefix sum of the given array is: 2 6 7 12 15.
The reverse order is: 15 12 7 6 2.
Sample Input 1

3
1000000000 1000000000 1000000000

Sample Output 1

3000000000 2000000000 1000000000

*/

#include <iostream>  // cin and cout
#include <vector>    // vector
#include <algorithm> // not needed here, kept from the template
#include <string>    // not needed here
using namespace std; // lets us drop the std:: prefix

int main() { // the program starts running here
    /*
     * Build the prefix sum array (each entry = previous entry + next value),
     * then print it from the last index down to the first.
     * 2 4 1 5 3 -> prefix 2 6 7 12 15 -> printed 15 12 7 6 2.
     */
    int n; // number of elements
    cin >> n; // read n

    // long long: up to 10^5 values of 10^9 add up to 10^14, too big for int
    // (the second sample already needs 3000000000).
    vector<long long> nums(n);

    for(int i=0; i<n; i++){ // read the values
        cin >> nums[i]; // into slot i
    }

    vector<long long>runningSum(n); // runningSum[i] = nums[0] + ... + nums[i]
    runningSum[0] = nums[0];            // the first prefix is the first value

    // Fill the rest left to right; each uses the one just before it.
    for(int i=1; i<n; i++){
        runningSum[i] = runningSum[i-1] + nums[i]; // previous total + this value
    }

    // Reverse order: walk the indexes backwards instead of reversing the vector.
    for(int i=n-1; i>=0; i--){
        cout << runningSum[i] << " "; // print one total and a space
    }

    cout << endl; // finish the line

    return 0; // program finished successfully
}
