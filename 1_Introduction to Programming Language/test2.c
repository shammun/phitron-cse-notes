/*
 * Read one number and print it back.
 *
 * Hello World proved that the program can talk to you. This one proves
 * that you can talk to the program. That is a separate thing and it can
 * fail on its own: some editors show a program's output in a panel that
 * can only display text and cannot accept typing, so the program waits
 * for a key that never arrives and looks as though it has frozen.
 *
 * A program that seems stuck right at the start is nearly always sitting
 * at a scanf, waiting for you.
 *
 * Example run:
 *     you type:   7   (then press Enter)
 *     it prints:  a = 7
 */

/* #include pastes in the header file stdio.h ("standard input output")
 * before compiling. printf (print to screen) and scanf (read from the
 * keyboard) both come from this header; without it the compiler does
 * not know those names. */
#include<stdio.h>

/* Every C program starts running at main. int = main gives back a whole
 * number (0 means "all went well"). The body is inside { }. */
int main() {
    /* Ask for a box big enough to hold one whole number and call it a.
     * int means "integer": a whole number such as -3, 0 or 42, with no
     * decimal point. Nothing has been put in it yet, so at this moment
     * it holds whatever rubbish was in that memory before. */
    int a;

    /* Stop here until you type something and press Enter.
     *   "%d"  says what to expect: one whole number written in digits
     *         (d stands for "decimal", i.e. base 10). Spaces and Enter
     *         keys typed before the number are skipped.
     *   &a    means "the address of the box a". scanf has to put a value
     *         INTO that box, so it must be told where the box is.
     * The missing & is the classic first-week mistake. */
    scanf("%d", &a);

    /* Print it again. Inside the quotes, "a = " is printed as plain text
     * and %d is a placeholder: printf replaces it with the value of the
     * first thing after the comma, here a, written as a whole number.
     * Here a is written without &, because printf only reads the value;
     * it never changes the variable, so it does not need the address.
     * There is no \n at the end, so when the program stops your terminal
     * prompt appears on the same line as the answer. */
    printf("a = %d", a);

    return 0;   /* finished successfully: 0 is sent back to the system */
}   /* end of main, and of the program */
