/*

Sum Digits  (extra practice question)

Read a whole number N and print the sum of its digits.

Example

input
13305

output
12

Note
1 + 3 + 3 + 0 + 5 = 12.

(The Codeforces sheet has a version of this, problem K of the arrays
sheet, where the digits come as one long string. Strings come later in the
course, so this file solves the version asked here: one ordinary number.)

*/

/* stdio.h ("standard input output") declares scanf and printf. The
   space in "# include" is allowed; it means the same as #include. */
# include <stdio.h>

int main() {            /* the program starts running here */
    /* long long so that a number with up to 18 digits still fits. */
    long long n;
    scanf("%lld", &n);      /* %lld = read a long long; &n = where to put it */

    /* The digit sum starts at 0 and grows by one digit per pass. */
    int sum = 0;

    /* Peel the digits off from the right, the same two moves as when a
       two-digit number was split into tens and units:
           n % 10   is the last digit        (13305 % 10 = 5)
           n / 10   drops the last digit     (13305 / 10 = 1330)
       Repeat until nothing is left. For 13305:
           5 -> 1330,  0 -> 133,  3 -> 13,  3 -> 1,  1 -> 0 (stop)
       and 5 + 0 + 3 + 3 + 1 = 12. */
    while(n > 0){
        sum += n % 10;      /* add the last digit */
        n = n / 10;         /* and chop it off */
    }

    /* For N = 0 the loop never runs and the sum stays 0, which is right. */
    printf("%d\n", sum);    /* %d = int; \n = newline */

    return 0;   /* 0 = the program finished normally */
}
