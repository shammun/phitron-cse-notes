/* 

In this problem you will be given an integer N, followed by N numbers.

Each numbers will be either 0 or 1.

You need to print two integers, The first one will be the number of 0's and the second one will be the number of 1' s in the input.

Input Format

The first line will contain a single integer N.
The second line will contain N integers.
Constraints

1 <= N <= 100000
Each N numbers will be either 0 or 1.
Output Format

Print two space separated integers, total number of 0's and 1's.

Sample Input 0
10
0 0 1 0 1 0 0 0 1 1

Sample Output 0
6 4

*/

/* stdio.h ("standard input output") declares scanf and printf; #include
   pastes it in before compiling so the compiler knows those names. */
#include <stdio.h>

/**
 * @brief This program reads a number N and then N numbers from the user.
 *        It then prints out the number of 0's and 1's in the input.
 *        The first number will be the number of 0's and the second one will be the number of 1's.
 * 
 * @author Shammunul Islam <shais13irs@gmail.com>
 * @date 2024-10-13
 */
int main() {            /* the program starts running here */
    int n;              /* how many values follow */
    scanf("%d", &n);    /* %d = read a whole number; &n = where to put it */

    /* An array of n ints, numbers[0] .. numbers[n-1]; its size comes from
       the input, which C allows since C99. */
    int numbers[n];

    /* The trick: every value is 0 or 1, so ADDING them up counts the ones.
       A 1 adds one to the total and a 0 adds nothing. The counter must start
       at 0, or the count would begin from leftover rubbish. */
    int number_of_ones = 0;
    int number_of_zeros;        /* worked out after the loop */

    /* Read and count in the same loop. */
    for(int i = 0; i < n; i++){
        scanf("%d", &numbers[i]);      /* store the value in box i */
        number_of_ones += numbers[i];   /* adds 1 for a one, 0 for a zero */
    }

    /* Whatever is not a one is a zero, so no second count is needed. */
    number_of_zeros = n - number_of_ones;
    /* Sample: 10 values with four 1s -> zeros = 10 - 4 = 6 -> prints "6 4". */
    printf("%d %d", number_of_zeros, number_of_ones);

    return 0;   /* 0 = the program finished normally */
}
