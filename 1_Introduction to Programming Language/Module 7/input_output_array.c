/*
  The first array program of the course.

  Until now one name held one number. An array holds many numbers under one
  name, laid out side by side, and you pick one of them by its position:

      int a[5];     ->   five boxes:  a[0] a[1] a[2] a[3] a[4]

  The 5 in the brackets is how many boxes there are, but the numbering starts
  at 0, so the last box is a[4]. a[5] is already one step past the end. C does
  not check that for you: writing a[5] would quietly read or overwrite
  whatever memory happens to sit after the array. This is the classic array
  mistake, and it is why both loops below stop at i < 5 and never at i <= 5.

  `int a[5];` only reserves the boxes. It does not put anything in them, so
  until the first loop fills them they hold leftover rubbish.

  An array and a loop fit together because the loop counter and the index are
  the same kind of thing: one pass of the loop, one box.

  The other files in this module write `int a[n]`, with n read from the input
  first. That is the same idea; only the number of boxes is decided while the
  program runs instead of being typed into the source.
*/

#include <stdio.h>

int main()
{
    int a[5];
    
    /* Reading. scanf needs the address of the place to put the number, and
       that place is the box a[i], so it is handed &a[i] - exactly as it is
       handed &n for a plain variable. i takes the values 0, 1, 2, 3, 4 and
       the loop ends when i reaches 5. */
    for (int i = 0; i < 5; i++) {
        // i
        scanf("%d", &a[i]);
    }
    
    /* Left over from the lesson: one box on its own behaves like any other
       int, so it is printed with %d. a[1] is the second number, not the
       first. */
    // printf("%d", a[1]);
    
    /* Printing. The same boxes, walked in the same order. Each number is
       followed by a space, so the line ends with a trailing space and there
       is no newline at all. */
    for (int i = 0; i < 5; i++) {
        printf("%d ", a[i]);
    }
    
    return 0;
}