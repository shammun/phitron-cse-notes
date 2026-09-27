/*

Problem Statement: Given a string of length N. Print the unique characters in the string in increasing alphabetical order.

Sample Input:
3
abc

Sample Output:
abc


Sample Input:
5
apple

Sample Output:
aelp

Sample Input:
7
abbgaab

Sample Output:
abg
*/

#include <stdio.h>  // standard input/output library: scanf and printf
#include <string.h> // string library: strlen

int main() { // program execution starts here
    /* The first number is the length N of the word. It is used to size the
       char array: N letters plus one slot for the '\0' that ends a string.
       (An array sized by a value read at run time is a C99 variable length array.) */
    int length;
    scanf("%d", &length); // &length = address where scanf stores N
    char str[length +1];

    /* One box per small letter: freq[0] is 'a', freq[25] is 'z'. Here a box
       only needs to say "seen" (1) or "not seen" (0), not how many times.
       = {0} starts every box at "not seen". */
    int freq[26] = {0};

    /* %s reads the word; an array name needs no &. */
    scanf("%s", str);
    int len = strlen(str); // number of characters before the '\0'

    /* The same marking loop written with while, kept from the lesson:
       (it is switched off; to use it, an "int i = 0;" would have to be
       declared before it, because no i exists at this point)
    while(str[i] != '\0'){
        if(str[i] >= 'a' && str[i] <= 'z'){
            freq[str[i] - 'a'] = 1;
        }
        i++;
    }
    */

    /* Mark every letter of the word. str[i] - 'a' turns the letter into its
       box number ('a' -> 0, 'b' -> 1, ...). A letter that appears several
       times just sets the same box to 1 again, so repeats cost nothing.
       The range check makes sure only small letters are used as indexes. */
    for(int i=0; i<len; i++){
        if(str[i] >= 'a' && str[i] <= 'z'){ // is it a lowercase letter?
            freq[str[i] - 'a'] = 1; // mark it as seen
        }
    }


    /* Walk the 26 boxes from 'a' to 'z' and print the marked letters. Going
       through the boxes in order is what makes the output come out in
       alphabetical order, without any sorting. i + 'a' turns the box number
       back into its letter.
       Trace with "apple": boxes a(0), e(4), l(11), p(15) are marked -> "aelp". */
    for(int i=0; i < 26; i++){
        if(freq[i] == 1){
            printf("%c", i + 'a'); // %c prints one character
        }
    }

    printf("\n"); // finish the line

    return 0; // program ended successfully
}
