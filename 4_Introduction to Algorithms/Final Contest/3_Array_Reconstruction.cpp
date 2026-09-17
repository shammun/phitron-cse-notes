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


#include <iostream>

using namespace std;

long long possible_ways(int n){
    long long rest[n-2];
    long long deleted_sum = 0;

    for(int i=0; i<n-2; i++){
        cin >> rest[i];
        deleted_sum += rest[i];
    }

    long long original_sum;
    cin >> original_sum;

    long long sum_of_deleted_elements = original_sum - deleted_sum;

    return sum_of_deleted_elements + 1;
}

int main() {
    int t;
    cin >> t;
    
    while (t--) {
        int n;
        cin >> n;  
        
        long long result = possible_ways(n);
        cout << result << endl;
    }
    
    return 0;
}