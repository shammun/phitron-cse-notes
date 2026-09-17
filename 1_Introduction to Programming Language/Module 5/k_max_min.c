/* 

Given 3 numbers A, B and C, Print the minimum and the maximum numbers.

Input
Only one line containing 3 numbers A, B and C ( - 105 ≤ A, B, C ≤ 105)

Output
Print the minimum number followed by a single space then print the maximum number.

Examples

1 2 3

Output

1 3

Input

-1 -2 -3

Output

-3 -1

Input

10 20 -5

Output

-5 20


*/

#include <stdio.h>

int main()
{
    int a, b, c;
    scanf("%d %d %d", &a, &b, &c);
    int min, max;

    if (a >= b && a >= c)
    {
        max = a;
    }
    else if (b >= a && b >= c)
    {
        max = b;
    }
    else {
        max = c;
    }

    if (a <= b && a <= c)
    {
        min = a;
    }
    else if (b <= a && b <= c)
    {
        min = b;
    }
    else
    {
        min = c;
    }
    
    printf("%d %d", min, max);
    return 0;
}