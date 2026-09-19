/*
  Sum and average of n numbers.

  Reading the array is the pattern from input_output_array.c, with one
  change: the size is read first, so `int a[n]` asks for exactly as many
  boxes as there are numbers. C has allowed that since C99. n must already
  hold its value by the time the line runs, which is why the scanf for n
  comes before the declaration.

  The new idea is the accumulator: a variable that starts at 0 and grows by
  one element per pass, so the whole total is ready after a single walk over
  the array.

  The trap is in the average, not in the sum. See the (double) cast below.
*/

#include <stdio.h>

int main()
{
    int n;
    
    scanf("%d", &n);
    
    int a[n];
    
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    
    /* The running total, and it must start at 0. An uninitialised variable
       holds whatever was left in that memory, and adding to rubbish gives
       rubbish.
       int is enough for the small inputs used here. If n and the values were
       large - say 10^5 values of 10^9 each - the total would pass what an int
       can hold and long long would be needed. */
    int sum = 0;
    
    /* One pass, one element added. `sum += a[i]` is short for
       `sum = sum + a[i]`. */
    for (int i = 0; i < n; i++) {
        sum += a[i];
    }
    
    printf("%d\n", sum);
    
    /* Both sum and n are ints, and int / int in C throws the fraction away:
       105 / 4 would be 26, not 26.25. The (double) cast turns sum into a real
       number first, so the division keeps the fraction.
       Casting afterwards, `(double)(sum / n)`, would be too late: by then the
       .25 is already gone. */
    double avg = (double) sum / n;
    
    /* %lf prints a double, and by default it shows six digits after the
       point: 26.250000. */
    printf("%lf\n", avg);
    
    return 0;
}