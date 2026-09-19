/*
 * Two labels for one number: even or odd, then positive or negative.
 *
 * The thing to notice is that these are two separate if/else blocks, not
 * one ladder. There is no else joining them, so the first finishes
 * completely and then the second starts from scratch on the same x.
 * Both always print something, and the output is two words on one line.
 */

#include <stdio.h>

int main() {

    int x = 4;

    /* x % 2 != 0 is true when dividing by 2 leaves something over - that
     * is, when x is odd.
     *
     * Bug, left in on purpose: the two labels are the wrong way round.
     * The true branch is the odd one, yet it prints "Even". So x = 4,
     * which really is even, fails the test, takes the else, and gets
     * announced as "Odd". The logic is sound; only the words are
     * swapped. The fix is to test x % 2 == 0 for "Even".
     *
     * This is the kind of bug the compiler can never find for you: both
     * branches are perfectly legal C. */
    if(x%2!=0)
    {
        printf("Even ");
    }
    else
    {
        printf("Odd ");
    }

    /* The second question, asked of the same x. Mind the gap here:
     * there are three possible cases - above zero, below zero, and zero
     * itself - but only two branches, so 0 quietly falls into the else
     * and is labelled "Negative". Being right would need a third case,
     * else if (x == 0), in between. */
    if(x>0)
    {
        printf("Positive ");
    }
    else
    {
        printf("Negative ");
    }
    return 0;
}
