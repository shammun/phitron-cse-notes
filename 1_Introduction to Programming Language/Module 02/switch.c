/*
 * switch: pick one case out of a list.
 *
 * An else-if ladder can test anything at all - ranges, two variables at
 * once, any expression. But when you are comparing ONE value against a
 * list of exact possibilities, a switch says it more plainly: C looks at
 * the value once, jumps straight to the matching case label, and runs
 * on from there.
 *
 * Two switches here, one on a char and one on an int.
 *
 * Example run:
 *     Enter your grade (A, B, C, D, F): B
 *     Well done!
 *     Enter your day (1-7): 3
 *     Wednesday
 */

/* stdio.h ("standard input output") declares printf and scanf. */
#include <stdio.h>

int main() {        /* the program starts here */
    char grade;     /* one character, e.g. 'A' (stored as its code, 65) */
    int day;        /* a whole number, 1..7 expected */

    /* A prompt is just ordinary printed text. There is no \n at the end,
     * so what you type - and then the answer - appears on the same line
     * as the question. */
    printf("Enter your grade (A, B, C, D, F): ");
    /* %c takes exactly one character; &grade is the address of grade,
     * which scanf needs so it can store the character there. */
    scanf("%c", &grade);   /* %c takes exactly one character */

    /* switch(grade) compares grade against each case label in turn. The
     * labels have to be constants the compiler already knows - 'A', 7,
     * and so on. A variable will not do, and neither will a range like
     * >= 80; that still needs an if ladder.
     *
     * break is what stops it. Without break, C carries straight on into
     * the lines of the next case, ignoring that case's label: grade 'B'
     * would print "Well done!" and then "Good!" as well. That is called
     * fall-through. It is occasionally what you want, which is why C
     * does not stop on its own - and why a forgotten break is such a
     * quiet bug. */
    switch(grade) {
        case 'A':                       /* grade == 'A' jumps here */
            printf("Excellent!\n");
            break;                      /* leave the switch */
        case 'B':                       /* grade == 'B' */
            printf("Well done!\n");
            break;
        case 'C':                       /* grade == 'C' */
            printf("Good!\n");
            break;
        case 'D':                       /* grade == 'D' */
            printf("Sufficient!\n");
            break;
        case 'F':                       /* grade == 'F' */
            printf("Failed!\n");
            break;
        default:
            /* default catches everything that no case matched: a
             * lowercase 'b', a digit, a stray space. It needs no break
             * because it is last, but many people write one anyway so
             * that adding a case underneath later cannot break it. */
            printf("Invalid grade!\n");
    }

    printf("Enter your day (1-7): ");   /* second prompt */

    /* Pressing Enter after the grade left a newline sitting in the
     * input, unread. A second %c would have taken that newline as "the
     * next character" and skipped your real answer. %d behaves
     * differently: it steps over spaces, tabs and newlines before it
     * starts reading digits, so this line is safe as it stands.
     * When you really do need a character after a number, write " %c"
     * with a space in front, which skips the leftover newline. */
    scanf("%d", &day);

    /* The same idea on an int. Seven else-ifs would say this too, but
     * the switch makes it obvious at a glance that all seven are exact
     * comparisons against one variable. Each case prints one day name
     * and then break leaves the switch. */
    switch(day) {
        case 1:                         /* day == 1 */
            printf("Monday\n");
            break;
        case 2:                         /* day == 2 */
            printf("Tuesday\n");
            break;
        case 3:                         /* day == 3 */
            printf("Wednesday\n");
            break;
        case 4:                         /* day == 4 */
            printf("Thursday\n");
            break;
        case 5:                         /* day == 5 */
            printf("Friday\n");
            break;
        case 6:                         /* day == 6 */
            printf("Saturday\n");
            break;
        case 7:                         /* day == 7 */
            printf("Sunday\n");
            break;
        default:
            /* 0, 8, or anything else you type. Always give a switch a
             * default: it is the only thing standing between a typo and
             * silence. */
            printf("Invalid day!\n");
    }
}   /* no return 0; - reaching the end of main counts as returning 0 */
