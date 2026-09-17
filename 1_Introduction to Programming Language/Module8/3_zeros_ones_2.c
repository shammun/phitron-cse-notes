/*

In this problem you will be given an integer N, followed by an array containing N 
numbers.

Each numbers will be either 0 or 1.

You will also be an integer X.

You will have to toggle the X_th value in the array. Toggle means if the value is 0, you will make it 1 and if it is 1 you have to make it 0.

Then you have to print the array.

Input Format

The first line will contain a single integer N.
The second line will contain N integers.
The third line will contain a single integer X.
Constraints

1 <= N, X <= 100000
Each N numbers will be either 0 or 1.
Output Format

Print the array after updating.
Sample Input 0

5
0 1 1 0 0
4
Sample Output 0

0 1 1 1 0

Sample Input 1

4
0 1 1 1
1
Sample Output 1

1 1 1 1

 */

#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);
    int position;
    int numbers[n];

    for(int i = 0; i < n; i++){
        scanf("%d", &numbers[i]);
    }

    scanf("%d", &position);

    numbers[position - 1] = 1 - numbers[position - 1];
    
    for(int i = 0; i < n; i++){
        printf("%d ", numbers[i]);
    }
}