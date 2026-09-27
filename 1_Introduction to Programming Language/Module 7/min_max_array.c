/*
  The smallest and the largest value of an array, found in one walk.

  Reading n and filling `int a[n]` is the pattern from the two files above,
  so only the new part is commented here.

  The idea is worth a name, because it comes back constantly: keep the best
  value seen so far in a variable, and replace it whenever something better
  turns up. When the loop ends, the variable holds the best of the whole
  array. Nothing is sorted and nothing is searched twice.

  Example run:  input 5 / 3 9 -2 7 4  ->  Minimum = -2, Maximum = 9
*/

/* stdio.h ("standard input output") declares scanf and printf. */
#include <stdio.h>
#include <limits.h>
/* <limits.h> only supplies names: INT_MAX is the largest number an int can
   hold, INT_MIN the smallest. */

int main()          /* the program starts running here */
{
    int n;          /* how many numbers */
    
    scanf("%d", &n);    /* %d = read a whole number; &n = where to put it */
    
    int a[n];       /* n boxes, a[0] .. a[n-1] (size from input, C99) */
    
    /* Pass i reads one number into a[i]; &a[i] is that box's address. */
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    
    /* Start each one at the worst possible value, so the very first element
       is certain to beat it.
       Starting min at 0 instead is a common bug: if every element were
       positive, nothing would ever be smaller than 0 and the program would
       report a minimum of 0, a number that is not even in the array.
       The other safe start is min = max = a[0], with the loop beginning at
       i = 1.
       INT_MAX is 2147483647 and INT_MIN is -2147483648. */
    int min = INT_MAX, max = INT_MIN;
    
    /* One pass, both jobs. The two ifs are separate questions, not an
       if/else: for an array with a single element that element is both the
       minimum and the maximum, and both ifs must fire. */
    for (int i = 0; i < n; i++) {
        if (a[i] < min) {
            min = a[i];     /* smaller than anything so far */
        }
        
        if (a[i] > max) {
            max = a[i];     /* bigger than anything so far */
        }
    }
    
    /* The two %d are filled with min and max, in that order. */
    printf("Minimum = %d, Maximum = %d\n", min, max);
    
    return 0;   /* 0 = the program finished normally */
}