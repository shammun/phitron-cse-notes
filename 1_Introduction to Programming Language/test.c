/*
 * Hello World - the very first program of the course.
 *
 * It does exactly one thing: print a line of text. That is the point. If
 * this runs, then the compiler, the editor and the Run button are all
 * working, and from here on you can blame your own code instead of the
 * setup.
 *
 * Running it is always two steps, never one:
 *     gcc test.c -o test.exe     translate this text into a program
 *     ./test.exe                 run that program
 * A Run button simply does both for you in one click.
 *
 * What you should see on the screen:
 *     Hello World!
 */

/* printf is not part of the C language itself; printing lives in a
 * library. This line pastes in <stdio.h> ("standard input output"),
 * which tells the compiler that printf exists and how it is called.
 * Leave it out and the compiler does not recognise the name at all.
 * Lines that start with # are handled before the real compiling starts,
 * by a helper called the preprocessor; #include literally copies the
 * named file into this spot. */
#include <stdio.h>

/* Execution starts here. Every C program has exactly one function called
 * main, and the curly braces hold the steps it runs, in order, from top
 * to bottom. The int in front says main hands a whole number back when
 * it finishes. The empty () means main takes no inputs. */
int main() {
    /* Send the text to the screen. printf = "print formatted".
     * Everything between the double quotes is printed exactly as written,
     * except for special pieces that start with a backslash or a %.
     * \n is not two characters: inside a string it means one "newline",
     * which moves the cursor to the start of the next line. Leave it out
     * and whatever prints next sticks straight onto Hello World!.
     * The ; at the end finishes the statement, like a full stop ends a
     * sentence; every statement in C needs one. */
    printf("Hello World!\n");

    /* Hand 0 back to the operating system: "I finished, nothing went
     * wrong". Any other number would be a way of reporting a failure.
     * return also ends main right here, so the program is over. */
    return 0;
}   /* this closing brace ends the body of main */
