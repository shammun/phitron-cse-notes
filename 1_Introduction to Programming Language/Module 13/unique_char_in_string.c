#include <stdio.h>  // standard input/output library: printf
#include <string.h> // string library: strlen

/* This program finds unique characters in a string and counts them
 * For example, if input is "aaaaaagggggccjcc"
 * Output will show which letters appear (regardless of frequency)
 * and total count of unique letters
 * For that string the output is:
 *   a 1
 *   c 1
 *   g 1
 *   j 1
 *   4
 * (letters come out in alphabet order, because we walk the boxes 0..25)
 */

int main() { // program execution starts here
    /* Declare a string with max size 100000 and initialize with test value
     * In real applications, you may want to get input from user instead
     * (the literal fills the first 16 slots plus a '\0'; all other slots become 0)
     */
    char str[100000] = "aaaaaagggggccjcc";

    /* Create an array of size 26 (one for each lowercase letter)
     * Initialize all elements to 0 using {0}
     * This array will act as a presence checker for each letter
     * f[0] is the box for 'a', f[1] for 'b', ..., f[25] for 'z'.
     */
    int f[26] = {0};

    /* Get length of string to know how many characters to process */
    int len = strlen(str); // strlen counts characters up to the '\0': 16 here

    /* First loop: Mark presence of each character
     * For each character in string:
     * 1. Get the character and store in ch
     * 2. Convert character to array index (0-25) by subtracting 'a'
     *    For example: 'a'-'a'=0, 'b'-'a'=1, etc.
     *    (this works because characters are numbers and 'a'..'z' are consecutive: 97..122)
     * 3. Set corresponding array position to 1 to mark presence
     * This only works for lowercase letters; any other character would give an
     * index outside 0..25.
     */
    for (int i=0; i<len; i++){ // i = position in the string, 0 .. len-1
        char ch = str[i]; // current character
        int index = ch - 'a'; // e.g. 'g' (103) - 'a' (97) = 6
        f[index] = 1; // mark this letter as present
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
    for(int i=0; i < 26; i++){ // i = box number = letter number
        cnt += f[i]; // adds 1 for a present letter, 0 otherwise ("+=" means cnt = cnt + f[i])
        if(f[i] == 1){ // this letter appeared
            printf("%c %d\n", i + 'a', f[i]); // i + 'a' turns 6 back into 'g'; %c prints it as a character
        }
    }

    /* Print total count of unique characters found */
    printf("%d\n", cnt);

    return 0; // program ended successfully
}
