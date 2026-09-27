/*
 * input_output.c - reading and printing values of different TYPES.
 *
 * A variable's type says what kind of value its box holds and how big the
 * box is. scanf (read) and printf (print) are told the type of each value
 * by a "format specifier" - a % followed by a letter or two - and it must
 * match the variable, or the value comes out wrong.
 *
 * What was actually seen when this was run with the input
 *     1 2 3 4
 *     x
 *     3.14159
 *     2.5
 * is
 *     a = 1, b = 2, c = 3, d = 4, ch = x
 *     , f = 0.000000, g = 3.141590
 *     d = 4, c = 3, a = 1, b = 2, e = -32
 * Two surprises there (f is not 3.14 and g got 3.14159) come from the
 * bug marked below in the third scanf.
 */

/* stdio.h ("standard input output") declares scanf and printf. #include
 * pastes that header in before compiling. */
#include <stdio.h>

int main() {    /* the program starts running here */

    /* int: a whole number (no decimal point), 4 bytes, about -2.1e9..2.1e9.
     * One line can declare several variables of the same type. */
    int a, b, c;
    /* short int (or just short): a smaller whole number, 2 bytes, range
     * -32768..32767. e gets its value right away ("initialised"). */
    short int e = -32;
    short int d;    /* another short, filled later by scanf */
    /* char: one character, 1 byte (stored as its ASCII code, 'x' = 120). */
    char ch;

    /* float: a number with a decimal part, 4 bytes, about 6-7 correct
     * digits. double: the same idea with 8 bytes and about 15 correct
     * digits - "double" precision. Prefer double unless told otherwise. */
    float f;
    double g;

    /* Read four whole numbers. Each %... tells scanf the type of the box:
     * %d for int, %hd for short int (h = "half"). & gives the ADDRESS of
     * each variable, because scanf must write into it. Spaces or Enter
     * between the typed numbers are all fine. */
    scanf("%d %d %d %hd", &a, &b, &c, &d);
    /* %c reads ONE character - and a space or the Enter key is also a
     * character. The Enter pressed after the four numbers is still
     * waiting to be read, so the \n (any whitespace in a scanf format)
     * first skips all spaces/newlines, then %c takes the real letter. */
    scanf("\n%c", &ch);
    /* BUG: the .2 precision exists only for printf
     * ("print 2 decimal places", e.g. printf("%.2f", f) shows 3.14).
     * scanf does not understand %.2f, so it gives up at that point and
     * reads nothing: f keeps its random starting value, and the number
     * typed for f stays waiting and is read by the NEXT scanf into g.
     * The fix: scanf("%f", &f); and use %.2f only in printf. */
    scanf("\n%.2f", &f); // BUG: meant to read a float; %.2f is not valid in scanf
    /* %lf ("long float") is how scanf reads a double. For scanf the
     * difference matters: %f is for float, %lf is for double. */
    scanf("%lf", &g);
    /* printf replaces each placeholder, left to right, with the values
     * after the format, in the same order: %d <- a, %d <- b, %d <- c,
     * %hd <- d, %c <- ch, %f <- f, %lf <- g. %f prints 6 digits after
     * the point by default (3.141590). In printf, %f and %lf both work
     * for a double.
     * Note the \n sits BEFORE ", f =", so the second line of the output
     * starts with a comma. */
    printf("a = %d, b = %d, c = %d, d = %hd, ch = %c\n, f = %f, g = %lf", a, b, c, d, ch, f, g);
    /* The same values in a different order - the order of the
     * placeholders just has to match the order of the variables.
     * The leading \n starts a fresh line. */
    printf("\nd = %hd, c = %d, a = %d, b = %d, e = %hd", d, c, a, b, e);

    /* (Commented-out extra examples - kept for reference, not run.
       %04d prints an int at least 4 wide, padded with zeros on the
       left: 10 -> 0010. long long int is an 8-byte whole number
       (about +-9.2e18), read and printed with %lld.)

    int a = 10;
    printf("%04d", a); // 00010

    long long int num;
    scanf("%lld", &num);
    printf("%lld", num);


    */

    return 0;   /* 0 = the program finished normally */
}

/*

Format specifier
(what goes after % in scanf/printf, one per value)

%d - int
%hd - short int
%ld - long int
%lld - long long int
%d - integer
%lf - double
%Lf - long double
%c - char
%f - float

%u - unsigned int
%hu - unsigned short int
%lu - unsigned long int
%llu - unsigned long long int
(unsigned = no negative values, so the positive range is twice as big)


%s - string
%c - character
%lf - double (the l is read as "long float")
%Lf - long double
%lld - long long
%p - pointer
      (prints an address, e.g. printf("%p", &a))
%x - hexadecimal
      (whole number in base 16: 255 -> ff)
%o - octal
      (whole number in base 8: 8 -> 10)
%e - exponential
      (scientific notation: 1500.0 -> 1.500000e+03)
%g - general
      (whichever of %f / %e is shorter)
%u - unsigned integer
%n - number of characters written so far
      (it prints nothing; it stores that count into an int you pass by
       address)
%i - integer
      (same as %d in printf; in scanf %i also accepts 0x1f or 017 style)
%f - float
      (in printf, %f prints both float and double)


 */