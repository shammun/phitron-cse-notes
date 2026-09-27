/*

Babul is learning about vowels and consonants.

Now he wants you to write a program for him where he can give a letter and the program will tell if it's a vowel or a consonant.

He has given you the list of vowels to help you. (The vowels are a, e, i, o and u).

Input Format

Input will contain a single lower case letter C.
Constraints

C will be a letter between a to z (inclusive).
Output Format

Print "Vowel" if C is a vowel and "Consonant" otherwise.


Sample Input 0
a

Sample Output 0
Vowel


Sample Input 1
b

Sample Output 1
Consonant

*/

/* stdio.h ("standard input output") declares scanf and printf. The
   space in "# include" is allowed; it means the same as #include. */
# include <stdio.h>

int main() {        /* the program starts running here */
    /* One letter, so one char and %c. */
    char a;             /* the letter (a char holds one character) */
    scanf("%c", &a);    /* %c = read one character; &a = where to put it */
    
    /* There are only five vowels, so the simplest test is to compare with
       each of them and join the five checks with ||: the whole condition is
       true as soon as ONE comparison matches.
       Each letter is written in single quotes: 'a' is the character a,
       while a (no quotes) is the variable. == asks "are they equal?". */
    if(a == 'a' || a == 'e' || a == 'i' || a == 'o' || a == 'u'){
        printf("Vowel");     /* one of the five matched */
    }
    else {
        /* Anything that is not one of the five is a consonant (the input is
           promised to be a small letter). */
        printf("Consonant");
    }
}   /* no return 0: reaching the end of main counts as returning 0 */
