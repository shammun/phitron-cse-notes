#include <stdio.h> // standard input/output library: scanf and printf

/* This program checks for presence of numbers in an array
 * It uses a frequency array approach where:
 * - Index represents the number
 * - Value at index represents if number exists (1) or not (0)
 *
 * Why: without it, answering "is x in the array?" means scanning all n
 * numbers for every question. With the frequency array we do the work once,
 * and then every question is a single look-up: freq[x].
 * Example: a = {3, 1, 3} -> freq[1] = 1, freq[3] = 1, every other freq[i] = 0.
 */

int main(){ // program execution starts here
    /* Get size of input array from user
     * n represents how many numbers we'll read
     */
    int n;
    scanf("%d", &n); // %d reads an int; &n is the address of n so scanf can fill it

    /* Create array to store input numbers
     * Size is n+5 to have some buffer space
     * Note: Variable length arrays are a C99 feature
     * and may not work in all compilers
     * (A "variable length array" is an array whose size is only known while
     * the program runs - here it depends on n, which the user types.)
     */
    int a[n + 5];
    for(int i=0; i<n; i++){ // one pass reads one number into a[i], i = 0 .. n-1
        scanf("%d", &a[i]); // &a[i] = address of slot i
    }

    /* Create frequency array initialized to all zeros
     * Size 100000 assumes no number > 99999
     * (so every input number must be between 0 and 99999, or freq[a[i]] below
     * would write outside the array)
     * Each index i will store:
     * - 1 if number i exists in input array
     * - 0 if number i does not exist
     * `= {0}` sets the first element to 0 and, by the rules of C, every
     * element not listed is also set to 0 - so the whole array starts at 0.
     */
    int freq[100000] = {0};

    /* Mark presence of each number from input array
     * For each number x in array a:
     * Set freq[x] = 1 to show x exists
     * (a[i] is used as an INDEX into freq: the number itself says which box to mark.
     * A number that appears twice just sets the same box to 1 again.)
     */
    for(int i=0; i<n; i++){
        freq[a[i]] = 1; // mark "the number a[i] was seen"
    }

    /* Print first 10 entries of frequency array
     * Shows presence/absence of numbers 0-9
     * Format: "number presence_value"
     */
    for(int i=0; i<10; i++){ // i is both the number being shown and the index into freq
        printf("%d %d\n", i, freq[i]); // e.g. "3 1" means 3 is present
    }

    /* Get number of queries from user
     * Each query will ask if a number exists
     */
    int m;
    scanf("%d", &m); // how many questions will follow

    /* Process each query
     * For each query:
     * 1. Read number x to check
     * 2. Print the number
     * 3. Check freq[x]:
     *    - If 1, number exists -> print YES
     *    - If 0, number absent -> print NO
     * Each answer is printed right after its query is read, so on a terminal
     * the typed input and the output lines appear mixed together.
     */
    for(int i=0; i<m; i++){ // one pass = one query
        int x; // the number asked about
        scanf("%d", &x);
        printf("%d ", x); // echo the number, then YES or NO on the same line

        if (freq[x] == 1){ // the box for x was marked while reading the array
            printf("YES\n");
        } else{ // box still 0: x never appeared
            printf("NO\n");
        }
    }
} // no "return 0;" here: in C (C99 and later) reaching the end of main counts as return 0