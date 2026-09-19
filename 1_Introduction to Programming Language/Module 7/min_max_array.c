/*
  The smallest and the largest value of an array, found in one walk.

  Reading n and filling `int a[n]` is the pattern from the two files above,
  so only the new part is commented here.

  The idea is worth a name, because it comes back constantly: keep the best
  value seen so far in a variable, and replace it whenever something better
  turns up. When the loop ends, the variable holds the best of the whole
  array. Nothing is sorted and nothing is searched twice.
*/

#include <stdio.h>
#include <limits.h>
/* <limits.h> only supplies names: INT_MAX is the largest number an int can
   hold, INT_MIN the smallest. */

int main()
{
    int n;
    
    scanf("%d", &n);
    
    int a[n];
    
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    
    /* Start each one at the worst possible value, so the very first element
       is certain to beat it.
       Starting min at 0 instead is a common bug: if every element were
       positive, nothing would ever be smaller than 0 and the program would
       report a minimum of 0, a number that is not even in the array.
       The other safe start is min = max = a[0], with the loop beginning at
       i = 1. */
    int min = INT_MAX, max = INT_MIN;
    
    /* One pass, both jobs. The two ifs are separate questions, not an
       if/else: for an array with a single element that element is both the
       minimum and the maximum, and both ifs must fire. */
    for (int i = 0; i < n; i++) {
        if (a[i] < min) {
            min = a[i];
        }
        
        if (a[i] > max) {
            max = a[i];
        }
    }
    
    printf("Minimum = %d, Maximum = %d\n", min, max);
    
    return 0;
}