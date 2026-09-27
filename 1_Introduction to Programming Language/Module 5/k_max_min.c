/* 

Given 3 numbers A, B and C, Print the minimum and the maximum numbers.

Input
Only one line containing 3 numbers A, B and C (-10^5 <= A, B, C <= 10^5)

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

/* The idea: find the maximum and the minimum separately, each with an
   if / else-if / else ladder that asks "is this one at least as big (or
   small) as both of the others?".
   Trace with 10 20 -5: max -> is 10 >= 20? no; is 20 >= 10 and 20 >= -5?
   yes -> max = 20. min -> is 10 <= 20 and 10 <= -5? no; is 20 <= ...? no;
   so min = c = -5. Output: -5 20 */

/* stdio.h ("standard input output") declares scanf and printf; #include
   pastes it in before compiling. */
#include <stdio.h>

int main()      /* every C program starts running at main */
{
    int a, b, c;    /* three whole numbers (int = integer) */
    /* %d %d %d = read three whole numbers; & gives the address of each
       variable so scanf can store the values in them. */
    scanf("%d %d %d", &a, &b, &c);
    int min, max;   /* boxes for the answers, filled in below */

    /* The maximum: an if-else ladder asks "is a the biggest?", then "is b the
       biggest?". Only one branch runs, and if neither a nor b won, c must be
       the biggest, so the last branch needs no test at all.
       >= and not >: with 5 5 3, a and b tie for the top, and >= still lets a
       win instead of falling through to c by mistake. */
    if (a >= b && a >= c)
    {
        max = a;    /* a is at least as big as b and c */
    }
    else if (b >= a && b >= c)
    {
        max = b;    /* b is at least as big as a and c */
    }
    else {
        max = c;    /* neither a nor b, so c */
    }

    /* The minimum: the same ladder with every >= turned into <=. */
    if (a <= b && a <= c)
    {
        min = a;    /* a is no bigger than b and c */
    }
    else if (b <= a && b <= c)
    {
        min = b;    /* b is no bigger than a and c */
    }
    else
    {
        min = c;    /* neither a nor b, so c */
    }
    
    /* Minimum first, then one space, then the maximum. Each %d is
       replaced by the matching value after the comma, in order. */
    printf("%d %d", min, max);
    return 0;   /* 0 = the program finished normally */
}
