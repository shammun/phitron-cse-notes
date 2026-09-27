/*

In this problem you will be given an integer N, followed by an array containing N 
numbers.

Each numbers will be either 0 or 1.

You will also be an integer X.

You will have to toggle the X_th value in the array. Toggle means if the value is 0, you will make it 1 and if it is 1 you have to make it 0.

Then you have to print the array.

Input Format

The first line will contain a single integer N.
The second line will contain N integers.
The third line will contain a single integer X.
Constraints

1 <= N, X <= 100000
Each N numbers will be either 0 or 1.
Output Format

Print the array after updating.
Sample Input 0

5
0 1 1 0 0
4
Sample Output 0

0 1 1 1 0

Sample Input 1

4
0 1 1 1
1
Sample Output 1

1 1 1 1

 */

/* stdio.h ("standard input output") declares scanf and printf; #include
   pastes it in before compiling so the compiler knows those names. */
#include <stdio.h>

int main() {                /* the program starts running here */
    int n;                  /* how many values */
    scanf("%d", &n);        /* %d = read a whole number; &n = where to put it */
    int position;           /* X, read after the array */
    int numbers[n];         /* n boxes numbers[0..n-1]; size from input (C99) */

    /* Pass i reads one value into numbers[i]. */

    for(int i = 0; i < n; i++){
        scanf("%d", &numbers[i]);
    }

    /* X is given counting from 1 (the first value is "1st"). */
    scanf("%d", &position);

    /* Two small tricks on one line:
       - position - 1 turns the 1-based X into a 0-based array index, so
         X = 1 means numbers[0].
       - 1 - value toggles a 0/1 value without any if: 1 - 0 = 1 and
         1 - 1 = 0.
       Sample: 0 1 1 0 0 with X = 4 -> numbers[3] = 1 - 0 = 1 -> 0 1 1 1 0. */
    numbers[position - 1] = 1 - numbers[position - 1];
    
    /* Print the whole array, one space after each value. */
    for(int i = 0; i < n; i++){
        printf("%d ", numbers[i]);     /* value, then a space */
    }
}   /* no return 0: reaching the end of main counts as returning 0 */
