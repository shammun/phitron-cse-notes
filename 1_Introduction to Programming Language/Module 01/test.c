/*
 * Hello World once more, this time inside the Module 01 folder.
 *
 * Nothing new here: it is the same file as test.c at the course root.
 * Run it once from this folder so you know the compiler works here too,
 * then move on to the real lessons of the module - basic.c and
 * c_program_structure.c for the shape of a C file, and input_output.c
 * for the types and their format specifiers.
 *
 * Output:
 *     Hello World!
 */

/* #include pastes in the header stdio.h ("standard input output")
 * before compiling; it is what tells the compiler that printf exists. */
#include <stdio.h>      /* brings in printf */

/* main is where every C program starts. int = main returns a whole
 * number to the operating system when it ends. */
int main() {                        /* the program starts here */
    /* printf prints the text between the double quotes.
     * \n is one "newline" character: it ends the line. */
    printf("Hello World!\n");       /* \n ends the line */
    return 0;                       /* 0 = finished without errors */
}                                   /* end of main */
