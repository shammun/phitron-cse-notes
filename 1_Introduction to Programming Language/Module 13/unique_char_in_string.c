#include <stdio.h>
#include <string.h>

/* This program finds unique characters in a string and counts them
 * For example, if input is "aaaaaagggggccjcc"
 * Output will show which letters appear (regardless of frequency)
 * and total count of unique letters
 */

int main() {
    /* Declare a string with max size 100000 and initialize with test value
     * In real applications, you may want to get input from user instead
     */
    char str[100000] = "aaaaaagggggccjcc";
    
    /* Create an array of size 26 (one for each lowercase letter)
     * Initialize all elements to 0 using {0}
     * This array will act as a presence checker for each letter
     */
    int f[26] = {0};
    
    /* Get length of string to know how many characters to process */
    int len = strlen(str);

    /* First loop: Mark presence of each character
     * For each character in string:
     * 1. Get the character and store in ch
     * 2. Convert character to array index (0-25) by subtracting 'a'
     *    For example: 'a'-'a'=0, 'b'-'a'=1, etc.
     * 3. Set corresponding array position to 1 to mark presence
     */
    for (int i=0; i<len; i++){
        char ch = str[i];
        int index = ch - 'a';
        f[index] = 1;
    }

    /* Initialize counter for unique characters */
    int cnt = 0;
    
    /* Second loop: Count and print unique characters
     * For each position in frequency array (0-25):
     * 1. If f[i]=1, that letter exists in string
     * 2. Add 1 to total count
     * 3. Print the letter (convert index back to char by adding 'a')
     *    and its presence value
     */
    for(int i=0; i < 26; i++){
        cnt += f[i];
        if(f[i] == 1){
            printf("%c %d\n", i + 'a', f[i]);
        }
    }

    /* Print total count of unique characters found */
    printf("%d\n", cnt);

    return 0;
}