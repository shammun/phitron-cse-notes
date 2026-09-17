/*

In this problem you will be given an integer N and you will have to print a pattern 
with N numbers.

for example if N = 4, the pattern will be.

1
12
123
1234
 123
  12
   1
See input samples for better understanding.

Input Format

The input will contain a single integer N.
Constraints

1 <= N <= 9
Output Format

Print a pattern with N numbers according to the description.

Sample Input 0
3

Sample Output 0
1
12
123
 12
  1

Sample Input 1
5


Sample Output 1
1
12
123
1234
12345
 1234
  123
   12
    1

*/

#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= i; j ++) {
            printf("%d", j);
        }
        printf("\n");
    }

    for(int i = 1; i < n; i++) {
        for(int j = 0; j < i; j ++) {
            printf(" ");
        }
        for(int j = 1; j < n - i + 1; j++) {
            printf("%d", j);
        }
        printf("\n");
    }

    return 0;
}