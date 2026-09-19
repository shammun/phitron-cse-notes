/*
 * A quiz: which if does that else belong to?
 *
 * Two ifs, written one after the other. The first has no else at all;
 * the second has one. They are not a chain - no "else if" joins them -
 * so both questions are asked, and with x = 5 both are true.
 *
 * The answer to the quiz: an else always belongs to the nearest if above
 * it that does not already have one. Here that is the second if, the
 * x == 5 one. The else has nothing to do with x < 10, however much the
 * layout might suggest otherwise.
 */

#include <stdio.h>
    /* The indentation in this file is off: main and everything in it are
     * pushed in by four spaces for no reason. C ignores spaces and line
     * breaks entirely, so this compiles and runs exactly as if it were
     * lined up properly. It is only harder for a human to read, which is
     * reason enough not to write it this way. */
    int main()
    {
        int x = 5;

        /* True, so "hello " is printed. Had it been false, nothing would
         * be printed here - there is no else - and the program would
         * simply carry on to the next if. */
        if (x < 10) {
            printf("hello ");
        }

        /* Also true, so "hi" joins it on the same line: neither string
         * ends with \n, so nothing moves the cursor down.
         * Output: hello hi
         *
         * Trace it for x = 12 instead: the first if prints nothing, and
         * this else prints "no", so the whole output would be just no. */
        if (x == 5) {
            printf("hi");
        }
        else {
            printf("no");
        }
    }   /* no return 0; - reaching the end of main counts as success */
