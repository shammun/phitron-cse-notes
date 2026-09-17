/*
 * This program calculates factorial of a number using recursion
 * Important concepts shown:
 * 1. Use of long long data type for large numbers
 * 2. Different format specifiers in scanf/printf
 * 3. Recursive function implementation
 */

#include <stdio.h>

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
 */
long long factorial(int n){
    if(n == 0){
        return 1;  // Base case: factorial of 0 is 1
    }
    return n * factorial(n - 1);  // Recursive case: n! = n * (n-1)!
}

int main(){
    int n;
    /* scanf with %d format specifier:
     * %d is used for reading integer value
     * &n passes address where input should be stored
     */
    scanf("%d", &n);

    /* printf with %lld format specifier:
     * %lld is used because factorial returns long long
     * Regular %d can't handle such large numbers
     * \n adds newline after printing result
     */
    printf("%lld\n", factorial(n));
    return 0;
}