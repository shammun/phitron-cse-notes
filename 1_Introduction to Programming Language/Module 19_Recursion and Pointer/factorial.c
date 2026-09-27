/*
 * This program calculates factorial of a number using recursion
 * Important concepts shown:
 * 1. Use of long long data type for large numbers
 * 2. Different format specifiers in scanf/printf
 * 3. Recursive function implementation
 *
 * Example: input 5 -> output 120.
 * Limit: 20! = 2432902008176640000 is the largest factorial that fits in a
 * long long; from 21 on the result overflows and prints a wrong number.
 */

#include <stdio.h> // standard input/output library: scanf and printf

/* Function that calculates factorial recursively:
 * Parameter:
 * n: Integer number whose factorial needs to be calculated
 * Returns: long long because factorial can be a very large number
 *
 * Uses recursion by calling itself with (n-1) until n becomes 0
 * For example: factorial(5) = 5 * factorial(4)
 *                           = 5 * 4 * factorial(3)
 *                           = 5 * 4 * 3 * factorial(2)
 *                           = 5 * 4 * 3 * 2 * factorial(1)
 *                           = 5 * 4 * 3 * 2 * 1 * factorial(0)
 *                           = 5 * 4 * 3 * 2 * 1 * 1
 *                           = 120
 * The recursive call trusts that factorial(n - 1) returns (n-1)!; this call
 * only multiplies that answer by n.
 */
long long factorial(int n){
    if(n == 0){
        return 1;  // Base case: factorial of 0 is 1
    }
    return n * factorial(n - 1);  // Recursive case: n! = n * (n-1)!
}

int main(){ // program execution starts here
    int n; // the number whose factorial we want
    /* scanf with %d format specifier:
     * %d is used for reading integer value
     * &n passes address where input should be stored
     */
    scanf("%d", &n);

    /* printf with %lld format specifier:
     * %lld is used because factorial returns long long
     * %d is only for int; handing a long long to %d makes printf read the
     * value wrongly, so each type must be matched with its own specifier
     * \n adds newline after printing result
     */
    printf("%lld\n", factorial(n));
    return 0; // program ended successfully
}
