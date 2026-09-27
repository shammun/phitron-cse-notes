/*
Mutli-line comment
author: Shammunul Islam
date: 10-01-2022
code: nothing interesting
*/
/* (Everything from a slash-star to the next star-slash is a multi-line
   comment: the compiler throws it away, it is only for human readers.)

   What this file shows: the usual SECTIONS of a C file, in order -
   documentation, preprocessor/linking, definitions, global declarations,
   main, and your own functions. It prints nothing when run; main is empty.
   c_program_structure.c in this folder is the fuller version with a demo. */

// single-line comment
// author: Shammunul Islam
// (Two slashes start a comment that lasts to the end of that one line.)

// The below part is called preprocessor directives
// or linking section
// Lines starting with # are read by the "preprocessor", a tool that runs
// BEFORE the real compiler. #include <file.h> pastes that header file in
// here, so the compiler learns which library functions exist.
#include <stdio.h>
// standard input output library
// (stdio.h declares printf for printing and scanf for reading input.)
# include<math.h>
// math library
// (math.h declares sqrt, pow, sin, ... A space between # and include is
// allowed; it works the same as #include.)
// we can also include our own libraries
// (for your own header you write #include "myfile.h" with double quotes.)

// Definition section
// we can define values or declare macros here
// #define NAME value = before compiling, replace every NAME in the code
// with value (plain find-and-replace; no variable, no memory, no ';').
#define pi 3.14
// Meant to make ll a short name for long long.
// BUG: #define always takes the FIRST word
// as the name. So the line below makes a macro named "long" that turns
// into "long ll" - it does NOT make ll mean long long. It compiles only
// because nothing below ever uses the word long; writing "long long x;"
// later would break. The correct line is:  #define ll long long
#define long long ll

// Global declaration section
// global variable
// A variable written outside every function is "global": every function
// in this file can read and change it. int = a whole number.
int N = 100;
// define function
// (More exactly, this DECLARES the function - a "prototype". It only
// promises: a function named sum exists, takes two ints, returns an int.
// The ; at the end means "body comes later". The compiler reads top to
// bottom, so this lets main call sum even though sum is written below.)
int sum(int x, int y);

// main function section
// Every C program starts running at main. int = it returns a whole number
// to the operating system; () = it takes no inputs here.
int main(){
    // (the body is empty: this program does nothing and ends at once)
    return 0;   // 0 tells the operating system "finished successfully"
}

// Sub program section
// function definition
// Here the promise above is kept: this is sum's actual body.
// x and y are the two inputs (parameters); the result is x + y,
// e.g. sum(2, 3) gives back 5. return sends that value to the caller.
int sum(int x, int y){
    return x + y;   // add the two inputs and hand the answer back
}