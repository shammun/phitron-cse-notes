/* 

Given 3 numbers A, B and C, Print the minimum and the maximum numbers.

Input
Only one line containing 3 numbers A, B and C ( - 105 ≤ A, B, C ≤ 105)

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

    /* The maximum: an if-else ladder asks "is a the biggest?", then "is b the
       biggest?". Only one branch runs, and if neither a nor b won, c must be
       the biggest, so the last branch needs no test at all.
       >= and not >: with 5 5 3, a and b tie for the top, and >= still lets a
       win instead of falling through to c by mistake. */
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

    /* The minimum: the same ladder with every >= turned into <=. */
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
    
    /* Minimum first, then one space, then the maximum. */
    printf("%d %d", min, max);
    return 0;
}
