/*

This year abul is giving his cousins salami.

But one of his cousins has came to him and complained that he gave everyone different 
amounts of salami, so some got more and some got less.

So abul decided he will give everyone equal salami. He told his cousins to find out 
who got the maximum salami and to tell him how much more everyone else need to get 
equal salami. They came to you for help. Now you have an array containing N integers, 
the amount of salami of each cousin.

You need to print N integers in a line, for each salami amount, the difference of it 
from the maximum amount.


Input Format
The first line of input will contain an integer N.
The second line of input will contain N integers.


Constraints
1 <= N <= 100000
Each salami amount will be positive and less than 10^9


Output Format
Print N space seperated integers, i_th of which will be the difference of the maximum amount and i_th cousin's salami amount.

Sample Input 0
5
5 2 8 3 4

Sample Output 0
3 6 0 5 4

*/

/* stdio.h ("standard input output") declares scanf and printf; #include
   pastes it in before compiling so the compiler knows those names. */
#include <stdio.h>

int main() {            /* the program starts running here */
    int n;              /* the input number N */
    scanf("%d", &n);    /* %d = read a whole number; &n = where to put it */

    int salami[n];      /* n boxes salami[0..n-1]; size from the input (C99) */

    /* The largest amount seen so far. Every amount is positive, so any
       negative start is beaten by the very first value. */
    int max = -10;

    /* Walk 1: read the amounts and keep the maximum up to date. We cannot
       print anything yet, because the maximum is only known at the end. */
    for(int i = 0; i < n; i++) {
        scanf("%d", &salami[i]);      /* &salami[i] = address of box i */
        if (salami[i] > max) {          /* bigger than the best so far? */
            max = salami[i];            /* then it is the new best */
        }
    }

    /* Walk 2: now the maximum is final, so each cousin's shortfall is
       max - salami[j]. The person with the most gets 0. This second walk is
       why the amounts had to be kept in an array. */
    for (int j = 0; j < n; j++) {
        /* Sample 5 2 8 3 4: max = 8 -> 3 6 0 5 4. */
        printf("%d ", max - salami[j]);    /* the difference, then a space */
    }

    return 0;   /* 0 = the program finished normally */

}
