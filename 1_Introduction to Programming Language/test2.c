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
 */

#include<stdio.h>   /* printf and scanf both come from this header */

int main() {
    /* Ask for a box big enough to hold one whole number and call it a.
     * Nothing has been put in it yet, so at this moment it holds
     * whatever rubbish was in that memory before. */
    int a;

    /* Stop here until you type something and press Enter.
     *   "%d"  says what to expect: one whole number written in digits.
     *   &a    means "the address of the box a". scanf has to put a value
     *         INTO that box, so it must be told where the box is.
     * The missing & is the classic first-week mistake. */
    scanf("%d", &a);

    /* Print it again. Here a is written without &, because printf only
     * reads the value; it never changes the variable, so it does not
     * need the address.
     * There is no \n at the end, so when the program stops your terminal
     * prompt appears on the same line as the answer. */
    printf("a = %d", a);

    return 0;   /* finished successfully */
}
