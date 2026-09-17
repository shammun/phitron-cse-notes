#include <stdio.h>

/* This program checks for presence of numbers in an array
 * It uses a frequency array approach where:
 * - Index represents the number
 * - Value at index represents if number exists (1) or not (0)
 */

int main(){
    /* Get size of input array from user
     * n represents how many numbers we'll read
     */
    int n;
    scanf("%d", &n);

    /* Create array to store input numbers
     * Size is n+5 to have some buffer space
     * Note: Variable length arrays are a C99 feature
     * and may not work in all compilers
     */
    int a[n + 5];
    for(int i=0; i<n; i++){
        scanf("%d", &a[i]);
    }

    /* Create frequency array initialized to all zeros
     * Size 100000 assumes no number > 99999
     * Each index i will store:
     * - 1 if number i exists in input array
     * - 0 if number i does not exist
     */
    int freq[100000] = {0};

    /* Mark presence of each number from input array
     * For each number x in array a:
     * Set freq[x] = 1 to show x exists
     */
    for(int i=0; i<n; i++){
        freq[a[i]] = 1;
    }

    /* Print first 10 entries of frequency array
     * Shows presence/absence of numbers 0-9
     * Format: "number presence_value"
     */
    for(int i=0; i<10; i++){
        printf("%d %d\n", i, freq[i]);
    }

    /* Get number of queries from user
     * Each query will ask if a number exists
     */
    int m;
    scanf("%d", &m);

    /* Process each query
     * For each query:
     * 1. Read number x to check
     * 2. Print the number
     * 3. Check freq[x]:
     *    - If 1, number exists -> print YES
     *    - If 0, number absent -> print NO
     */
    for(int i=0; i<m; i++){
        int x;
        scanf("%d", &x);
        printf("%d ", x);

        if (freq[x] == 1){
            printf("YES\n");
        } else{
            printf("NO\n");
        }
    }
}