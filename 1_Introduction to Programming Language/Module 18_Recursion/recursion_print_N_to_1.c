/*
  The same function as recursion_print_1_to_N.c with exactly one line moved:
  the printf now sits AFTER the recursive call instead of before it.

  Nothing else changes. The base case is still x > n, the step is still x+1,
  and the calls are still made in the order 1, 2, 3, ... n. What changes is
  WHEN the printing happens.

  A call that has already made its recursive call is parked until that call
  returns. The printf is now on the far side of that wait, so nothing is
  printed on the way down. All the printing happens on the way back up, and
  calls return in the opposite order to the one they were made in - the
  deepest one first. For n = 3:

      print_N_to_1(1,3)       calls                (prints nothing yet)
        print_N_to_1(2,3)     calls                (prints nothing yet)
          print_N_to_1(3,3)   calls                (prints nothing yet)
            print_N_to_1(4,3) base case, returns
          prints 3, returns
        prints 2, returns
      prints 1, returns

  Output: 3 2 1. This pair of files is one lesson in two halves - work placed
  before the call happens in call order, work placed after it happens in
  reverse call order. It is worth knowing by heart, because it is the only
  difference between many recursive programs.
*/

#include <stdio.h>

void print_N_to_1(int x, int n){
    /* Same base case as before: past n, nothing left to do. */
    if(x > n){
        return;
    }
    /* Go all the way down first. This call does not return until every
       number above x has been printed. */
    print_N_to_1(x+1, n);
    /* ... and only then print x. The deepest call, the one with x = n,
       reaches its printf first, so n comes out first and 1 comes out last. */
    printf("%d ", x);
}

int main(){
    int n;
    printf("Enter the value of n: ");
    scanf("%d", &n);
    /* The chain still starts at x = 1, even though 1 is printed last. */
    print_N_to_1(1, n);
    return 0;
}