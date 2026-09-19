/*
Print the numbers 1 to N using recursion.

The two files before this one, practice_add.c and practice_swap.c, showed a
function being called by main. Recursion is the same machinery with one
twist: a function is allowed to call itself.

Why that helps here. "Print 1 to n" can be said as "print 1, then print 2 to
n". The second half is the same job again, only shorter. So the function
does one number and asks a copy of itself to do the rest.

Every recursive function needs two things:

  1. A base case - a situation it can answer without calling itself again.
     Here it is x > n: there is nothing left to print, so return. Without a
     base case the calls never stop, and the program dies when it runs out of
     stack space.

  2. A step that moves towards the base case. Here x + 1 climbs towards n. A
     step that did not move closer would loop for ever just as surely as a
     missing base case.

The call stack. Each call keeps its own private copies of x and n, stacked
on top of the calls that are still waiting. A call that has called someone
else is not finished: it is parked, and it carries on at the next line once
the inner call returns. For n = 3:

    print_1_to_N(1, 3)          prints 1, then calls
        print_1_to_N(2, 3)      prints 2, then calls
            print_1_to_N(3, 3)  prints 3, then calls
                print_1_to_N(4, 3)   4 > 3, base case, returns
            returns
        returns
    returns

That is 4 calls for n = 3: one per number, plus the one that stops the
chain. It is also the cost of recursion - n parked calls on the stack at the
deepest moment, where a plain loop would have needed none.

The printf sits before the recursive call, so every number is printed on the
way down, in the order the calls are made: 1 2 3. Moving that single line
below the call reverses the output, which is exactly the next file,
recursion_print_N_to_1.c.
*/

#include <stdio.h>

/*
Function name: print_1_to_N
Parameters:
    - x: the number this call is responsible for printing
    - n: the last number to print; passed along unchanged so that every call
         knows where the job ends
Return value: none (void) - the work is the printing itself
*/
void print_1_to_N(int x, int n){
    // Base case: x has gone past n, so there is nothing left to print.
    if(x > n){
        return;
    }
    // The small piece of work this particular call does.
    printf("%d ", x);
    // The rest of the job, handed to a copy of this function.
    // x+1 is what makes the problem smaller each time.
    print_1_to_N(x+1, n);
}

int main(){
    int n;
    // A prompt for a human at the keyboard. An online judge counts it as
    // extra output and would mark the answer wrong, which is why
    // practice_print_1_to_N.c - the judge version of this program - has no
    // prompt.
    printf("Enter the value of n: ");
    scanf("%d", &n);
    // Start the chain at x = 1.
    print_1_to_N(1, n);
    return 0;
}