/*
 * data_types_variables.c - an empty placeholder, kept exactly as it was.
 *
 * There is no code in this file. It was created for the data-types part
 * of the module, but the worked examples ended up in input_output.c and
 * in the reference sheet next to it, and this one was never filled in.
 *
 * It is left empty on purpose, because the error it produces is worth
 * meeting once. Building it does not complain about a typo or a missing
 * semicolon; it gets all the way to the last step, the linker, and says:
 *
 *     undefined reference to `WinMain'
 *
 * That is the linker reporting that it cannot find where the program
 * starts. Every C program needs exactly one main, and this file has
 * none, so there is nothing to start. On Linux or macOS the same
 * complaint reads "undefined reference to `main'" instead; on Windows
 * the startup code looks for WinMain as well, which is why that is the
 * name it mentions.
 *
 * The smallest thing that would make it build, and the beginning of the
 * lesson it was meant to hold:
 *
 *     #include <stdio.h>
 *     int main() {
 *         int   age  = 20;       // 4 bytes, whole numbers to about 2.1e9
 *         char  grade = 'A';     // 1 byte, really the number 65
 *         double pi  = 3.1416;   // 8 bytes, about 15 digits of precision
 *         printf("%d %c %lf\n", age, grade, pi);
 *         return 0;
 *     }
 *
 * Type that into a scratch file of your own rather than here, so this
 * file keeps showing the error it is here to show.
 */
