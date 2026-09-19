/*
Print the numbers N down to 1 using recursion.

This is recursion_print_1_to_N.c with exactly one line moved: the printf now
sits after the recursive call instead of before it. Everything else - the
base case x > n, the step x + 1, the starting call with x = 1 - is the same,
so only the difference is commented here.

What changes is WHEN the printing happens. A call that has already made its
recursive call is parked until that call returns, and the printf is now on
the far side of that wait. So nothing is printed on the way down; all the
printing happens on the way back up, and calls return in the opposite order
to the one they were made in - the deepest first. For n = 3:

    print_N_to_1(1, 3)          calls              (prints nothing yet)
        print_N_to_1(2, 3)      calls              (prints nothing yet)
            print_N_to_1(3, 3)  calls              (prints nothing yet)
                print_N_to_1(4, 3)  base case, returns
            prints 3, returns
        prints 2, returns
    prints 1, returns

Output: 3 2 1. The rule worth remembering from this pair of files is that
work placed before the recursive call happens in call order, and work placed
after it happens in reverse call order.
*/

#include <stdio.h>

/*
Function name: print_N_to_1
Parameters:
    - x: the number this call will print, but only after the calls above it
         have finished
    - n: the largest number, and the stopping point
Return value: none (void)
*/
void print_N_to_1(int x, int n){
    // Same base case as the other file: past n, nothing left to do.
    if(x > n){
        return;
    }
    // Go all the way down first. This call does not return until every
    // number above x has been printed.
    print_N_to_1(x+1, n);
    // ... and only then print x. The deepest call, the one holding x = n,
    // reaches its printf first, so n comes out first and 1 comes out last.
    printf("%d ", x);
}

int main(){
    int n;
    printf("Enter the value of n: ");
    scanf("%d", &n);
    // The chain still starts at x = 1, even though 1 is printed last.
    print_N_to_1(1, n);
    return 0;
}