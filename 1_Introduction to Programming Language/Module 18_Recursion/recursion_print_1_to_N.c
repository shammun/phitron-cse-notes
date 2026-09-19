/*
  The first recursion of the module.

  A function is allowed to call itself. That sounds like a trick, but it is
  the ordinary way of saying: do one small piece of the job, then ask for the
  rest of the job to be done the same way.

  "Print 1 to n", said that way, is "print x, then print x+1 to n". The
  second half is the same problem again, only shorter, so the function hands
  it to a fresh copy of itself.

  Two parts are always needed, and both are below.

    * The base case - a situation simple enough to answer without calling
      anyone. Here it is x > n: there is nothing left to print, so return.
      Leave it out and the calls never stop; the program keeps piling up new
      calls until it runs out of stack space and crashes.

    * The recursive step - the call that moves closer to the base case. Here
      x+1 climbs towards n. A call that did not move closer would loop for
      ever just as surely as a missing base case.

  What actually happens when a function calls itself. Each call gets its own
  private x and n, kept on a pile called the call stack. A call that has made
  another call is not finished: it is parked, waiting, and it carries on at
  the line after the call once the inner one has returned. For n = 3 the pile
  builds up and then unwinds:

      print_1_to_N(1,3)       prints 1, then calls
        print_1_to_N(2,3)     prints 2, then calls
          print_1_to_N(3,3)   prints 3, then calls
            print_1_to_N(4,3) 4 > 3, base case, returns
          returns
        returns
      returns

  So n = 3 costs 4 calls: one per number, plus the one that hits the base
  case. That is also the price of recursion - n parked calls sitting on the
  stack at the deepest moment, where a loop would have used none.

  Because the printf sits BEFORE the recursive call, each number is printed
  on the way down, in the order the calls are made: 1 2 3. Move that one line
  below the call and the order reverses. That is the whole of the next file,
  recursion_print_N_to_1.c.
*/

#include <stdio.h>

void print_1_to_N(int x, int n){
    /* Base case: x has gone past n, so there is nothing left to print. */
    if(x > n){
        return;
    }
    /* The small piece of work this particular call is responsible for. */
    printf("%d ", x);
    /* The rest of the job, handed to a copy of this function. x+1 is what
       makes the problem smaller; n is passed along unchanged, because every
       call needs to know where the job ends. */
    print_1_to_N(x+1, n);
}

int main(){
    int n;
    /* A prompt for a human sitting at the keyboard. An online judge would
       count it as extra output and mark the answer wrong, which is why the
       judge versions of these programs have no prompt. */
    printf("Enter the value of n: ");
    scanf("%d", &n);
    /* Start the chain at x = 1. */
    print_1_to_N(1, n);
    return 0;
}