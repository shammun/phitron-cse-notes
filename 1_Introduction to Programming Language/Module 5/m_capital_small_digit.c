/* 

Given a letter X. Determine whether X is Digit or Alphabet and if it is Alphabet determine if it is Capital Case or Small Case.

Note:

Digits in ASCII '0' = 48,'1' = 49 ....etc
Capital letters in ASCII 'A' = 65, 'B' = 66 ....etc
Small letters in ASCII 'a' = 97,'b' = 98 ....etc
Input
Only one line containing a character X which will be a capital or small letter or digit.

Output
Print a single line contains "IS DIGIT" if X is digit otherwise, print "ALPHA" in the first line followed by a new line that contains "IS CAPITAL" if X is a capital letter and "IS SMALL" if X is a small letter.

Examples

Input
A

Output
ALPHA
IS CAPITAL


Input
9

Output
IS DIGIT


Input
a

Output
ALPHA
IS SMALL

This is the corrected version of Book/Module2/capital_small_digit.c: it
uses >= and <= so 'a', 'z', 'A' and 'Z' themselves are included.
*/

/* stdio.h ("standard input output") declares scanf and printf; #include
   pastes it in before compiling. */
#include <stdio.h>

int main()      /* every C program starts running at main */
{
    /* A char holds one character; %c reads exactly one. */
    char ch;
    /* &ch = the address of ch, so scanf can store the character there. */
    scanf("%c", &ch);

    /* A character is stored as its ASCII number, and the digits, the capital
       letters and the small letters each sit in one unbroken block of
       numbers ('0'..'9' is 48..57, 'A'..'Z' is 65..90, 'a'..'z' is 97..122).
       So "is it a digit?" is just "does it lie between '0' and '9'?".
       Writing '0' instead of 48 means we never have to remember the codes.
       && means "and": both comparisons must be true. */
    if (ch >= '0' && ch <= '9')
    {
        printf("IS DIGIT");     /* '0'..'9' */
    }
    else if (ch >= 'A' && ch <= 'Z')    /* tried only if not a digit */
    {
        /* \n puts the second word on its own line, as the output asks. */
        printf("ALPHA\nIS CAPITAL");
    }
    else if (ch >= 'a' && ch <= 'z')    /* tried only if not a capital */
    {
        printf("ALPHA\nIS SMALL");
    }

    /* (Any other character matches no branch, so nothing is printed;
       the problem promises that never happens.) */
    return 0;   /* 0 = the program finished normally */
}
