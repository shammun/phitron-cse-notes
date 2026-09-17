/* 

In this problem you will be given an integer N, followed by N numbers.

Each numbers will be either 0 or 1.

You need to print two integers, The first one will be the number of 0's and the second one will be the number of 1' s in the input.

Input Format

The first line will contain a single integer N.
The second line will contain N integers.
Constraints

1 <= N <= 100000
Each N numbers will be either 0 or 1.
Output Format

Print two space separated integers, total number of 0's and 1's.

Sample Input 0
10
0 0 1 0 1 0 0 0 1 1

Sample Output 0
6 4

*/

#include <stdio.h>

/**
 * @brief This program reads a number N and then N numbers from the user.
 *        It then prints out the number of 0's and 1's in the input.
 *        The first number will be the number of 0's and the second one will be the number of 1's.
 * 
 * @author Shammunul Islam <shais13irs@gmail.com>
 * @date 2024-10-13
 */
int main() {
    int n;
    scanf("%d", &n);

    int numbers[n];
    int number_of_ones = 0;
    int number_of_zeros;

    for(int i = 0; i < n; i++){
        scanf("%d", &numbers[i]);
        number_of_ones += numbers[i];
    }

    number_of_zeros = n - number_of_ones;
    printf("%d %d", number_of_zeros, number_of_ones);

    return 0;
}