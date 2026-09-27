/*

Array Reconstruction

Problem Statement

Dablu recently starts learning programming. Today he learns about array. While working with an array he 
accidently deleted two non-negative elements from that array. The array has n elements. But fortunately he has 
the sum of the main array (before deleting the two elements).

Now he is wondering how many ways he can put two elements (0 <= element <= 10^18) to that array so that the sum 
of both versions of the array remain same. For example if the main array a = [5,3,1,4,2] and after losing two 
elements (3 and 1), a = [5,4,2]. The previous sum was 15 and the current sum is 11 (after losing two elements). 
He can put (0,4), (2,2), (3,1), (4,0) and (1,3) so that the sum doesn't get change. So here 5 ways are 
possible.

Now you have to help Dablu to figure out the number of ways possible to reconstruct the array.

Input Format

- First line of input contains an integer t, number of test cases.
- First line of each test case contains an integer n the number of elements in the array before deleting.
- Second line of each testcase consists n-2 integers, the remaining elements of the array.
- Third line of each testcases consists an integer, the sum of the main array.

Constraints
1 <= t<= 100
3 <= n <= 2 X 10^5
0 <= a[i] <= 10^5 (But there is no guarantee that the missing two values will be from this range)
1 <= sum <= 10^18
Summation of n over all test cases doesn't exceed 2 X 10^5

Output Format
For each test case output an integer,the number of ways possible to reconstruct the array so that the sum 
remains same. Don't forget to print a newline after each test case.

Sample Input 0
3
5
5 4 2
15
6
0 4 3 1
15
3
0
100000000

Sample Output 0
5
8
100000001

*/

// Solution idea: no searching is needed, only counting. The two lost numbers
// must add up to S = (original sum) - (sum of what is left). How many ordered
// pairs (x, y) of non-negative numbers have x + y = S? x can be 0, 1, ..., S
// and then y = S - x is forced, so there are exactly S + 1 pairs.
// In the example S = 15 - 11 = 4, and the pairs are (0,4) ... (4,0): 5 ways.

#include <iostream>     // cin, cout, endl

using namespace std;    // no std:: prefix

// Reads one test case (the n-2 remaining values and the original sum) and
// returns the number of ways.
long long possible_ways(int n){
    // The n-2 values still in the array (variable length array, g++ extension).
    long long rest[n-2];
    // Sum of the values still in the array. (The name says "deleted", but it
    // is the total of the elements that were NOT deleted.)
    long long deleted_sum = 0;

    for(int i=0; i<n-2; i++){       // read and add up each remaining value
        cin >> rest[i];
        deleted_sum += rest[i];
    }

    // Up to 10^18, so it needs long long.
    long long original_sum;
    cin >> original_sum;

    // What the two lost numbers must add up to.
    long long sum_of_deleted_elements = original_sum - deleted_sum;

    // x = 0, 1, ..., S gives S + 1 choices.
    return sum_of_deleted_elements + 1;
}

int main() {
    int t;              // number of test cases
    cin >> t;

    while (t--) {
        int n;          // array size before the deletion
        cin >> n;

        long long result = possible_ways(n);
        cout << result << endl;
    }

    // O(n) per test case: one pass to add up the values.
    return 0;
}
