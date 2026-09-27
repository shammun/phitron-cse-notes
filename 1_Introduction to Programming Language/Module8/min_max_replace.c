/*
===============================================================================
  Minimum and maximum, and the position of each
===============================================================================

  Reading n and then n values into `int a[n]` is the array pattern from
  Module 7, so it is not spelled out again here. Two things are new.

  1. min and max start at a[0] instead of at INT_MAX / INT_MIN. Any real
     element of the array is a safe starting point, and it saves including
     <limits.h>. The scan below still begins at i = 0, which simply compares
     a[0] with itself once - harmless, just one wasted comparison.

  2. Alongside each value the program remembers where it was found. min_pos
     and max_pos therefore start at 0, matching the starting values.

  About the file name: it says "replace", but the program stops once it has
  found the two values and their positions. To finish a "swap the minimum
  and the maximum" task you would exchange a[min_pos] and a[max_pos] through
  a temporary variable and then print the array.
===============================================================================
*/

/* stdio.h ("standard input output") declares scanf and printf; #include
   pastes it in before compiling so the compiler knows those names. */
#include <stdio.h>

int main()              /* the program starts running here */
{
    int n;              /* how many numbers */
    scanf("%d", &n);    /* %d = read a whole number; &n = where to put it */
    
    int a[n];       /* n boxes a[0] .. a[n-1]; size from the input (C99) */
    
    /* Pass i reads one number into a[i]; &a[i] is that box's address. */
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    
    /* The first element is the best candidate so far, by default. This is
       only safe because the task guarantees at least one element; for n = 0
       a[0] would not exist. */
    int min = a[0], max = a[0];
    int min_pos = 0, max_pos = 0;
    
    /* One walk, both answers, and the position recorded next to each value
       so the two never drift apart.
       The comparisons are strict, < and >, so a value has to beat the best
       so far, not merely equal it. That is what makes the positions those of
       the FIRST smallest and the FIRST largest element: a later copy of the
       same value finds no strict improvement and is ignored. Using <= and >=
       instead would report the last ones. */
    for (int i = 0; i < n; i++) {
        
        if (a[i] < min) {
            min = a[i];     /* new smallest value */
            min_pos = i;    /* and where it is */
        }
        
        
        if (a[i] > max) {
            max = a[i];     /* new largest value */
            max_pos = i;    /* and where it is */
        }
    }
    
    
    /* First line: the two values. Second line: where they were found,
       counted from 0 like every array index.
       Example: 5 numbers 4 1 9 1 9 -> "1 9" then "1 2". */
    printf("%d %d\n", min, max);
    
    printf("%d %d\n", min_pos, max_pos);
    
    return 0;   /* 0 = the program finished normally */
}