/*

Problem Statement

You will be given an integer array A of size N. You need to print the prefix
sum array of the array A in reverse order.

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

/*
 * The idea: a prefix sum array P has P[i] = A[0] + A[1] + ... + A[i].
 * Each entry is just the previous entry plus one more number
 * (P[i] = P[i-1] + A[i]), so the whole array is built in one pass.
 *   A = 2 4 1 5 3  ->  P = 2 6 7 12 15  -> printed backwards: 15 12 7 6 2
 *
 * long long, not int: each A[i] can be 1e9 and there are up to 1e5 of
 * them, so a sum can reach 1e14. An int only goes to about 2.1e9.
 *
 * C++ pieces used:
 *   #include <iostream>   cin (read) and cout (print)
 *   #include <vector>     vector, an array whose size is chosen at run time
 *   #include <algorithm>, <string>   not used here (habit from a template)
 *   using namespace std;  write cin/cout/vector without the std:: prefix
 */
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int main() {                    // the program starts here
    int n;                      // number of elements
    cin >> n;                   // cin >> reads one value into n (no & needed)
    vector<long long> nums(n);  // n long long boxes, nums[0]..nums[n-1], all 0

    // Read the array: one number per round, into nums[i].
    for(int i=0; i<n; i++){
        cin >> nums[i];
    }

    // runningSum[i] will hold nums[0] + ... + nums[i].
    vector<long long>runningSum(n);
    /* The first prefix sum has nothing before it: it is just nums[0].
       It is set outside the loop because the loop reads runningSum[i-1],
       which for i = 0 would be runningSum[-1], outside the vector. */
    runningSum[0] = nums[0];

    // Each round: previous total + the next number.
    // e.g. i=1: 2 + 4 = 6;  i=2: 6 + 1 = 7;  i=3: 7 + 5 = 12 ...
    for(int i=1; i<n; i++){
        runningSum[i] = runningSum[i-1] + nums[i];
    }

    /* Print backwards: start at the last index n-1 and count down to 0.
       i >= 0 (not i > 0) so that runningSum[0] is printed too.
       Each value is followed by a space: cout << a << b prints a then b. */
    for(int i=n-1; i>=0; i--){
        cout << runningSum[i] << " ";
    }

    cout << endl;   // end the output line (endl = newline + flush)

    return 0;       // 0 = finished normally
}