/*
 * ============================================================================
 *  SECTION 1 — DOCUMENTATION SECTION
 * ============================================================================
 *  author : name
 *  date   : --:--:--
 *  code   : a basic C program
 *
 *  What is this section?
 *  ---------------------
 *  Anything between  /*  and  *\/  is a "block comment" (multi-line comment).
 *  The compiler completely ignores it. It exists only for the humans who read
 *  your code later (including future-you, six months from now).
 *
 *  What belongs here?
 *  ------------------
 *   - Who wrote the file
 *   - When it was written / last modified
 *   - What the program does (one or two sentences)
 *   - Any license notice, assumptions, or warnings
 *
 *  Why bother?
 *  -----------
 *  Code is read far more often than it is written. A five-line header saves
 *  minutes of detective work every time someone opens this file.
 *
 *  This whole section is OPTIONAL — the program will compile fine without it —
 *  but writing one is a professional habit worth building from day one.
 * ============================================================================
 */


/* This is also a block comment — you can use /* ... *\/ anywhere.  */

// This is a single-line comment. Everything after the two slashes on THIS line
// is ignored by the compiler. Use these for short inline notes.


/*
 * ============================================================================
 *  SECTION 2 — LINKING / PREPROCESSOR SECTION   (the #include lines)
 * ============================================================================
 *
 *  These lines begin with '#' — they are NOT C statements. They are
 *  instructions to a separate tool called the "preprocessor" that runs
 *  BEFORE the compiler sees your code.
 *
 *  #include <stdio.h>   ->  "Paste the contents of the standard I/O header
 *                           file here, so I can use printf, scanf, etc."
 *
 *  Why do we need it?
 *  ------------------
 *  C is a small language. Printing to the screen, doing math, handling
 *  strings — none of that is built into the language itself. It lives in
 *  LIBRARIES. A header file (.h) tells the compiler what functions exist
 *  in a library and what arguments they take.
 *
 *  <angle brackets>  -> look in the system/standard include folders
 *  "double quotes"   -> look in the current project folder first
 *
 *  Common headers you will meet very soon:
 *      <stdio.h>   input / output   (printf, scanf, fopen, ...)
 *      <stdlib.h>  general utility  (malloc, free, exit, rand, ...)
 *      <string.h>  C strings        (strlen, strcpy, strcmp, ...)
 *      <math.h>    math functions   (sqrt, sin, pow, ...)
 * ============================================================================
 */
#include <stdio.h>
#include <math.h>
/* #include <abcd.h>   <-- this was in the lesson only as an EXAMPLE of
                          where a third-party or custom header would go.
                          "abcd.h" does not actually exist, so the line is
                          commented out — leaving it in would break the build. */


/*
 * ============================================================================
 *  SECTION 3 — DEFINITION SECTION   (the #define lines, aka macros)
 * ============================================================================
 *
 *  #define NAME value
 *
 *  This is still the preprocessor talking. It says: "Before compiling,
 *  find every occurrence of NAME in the code and textually replace it
 *  with 'value'." It is a pure find-and-replace. No memory is allocated,
 *  there is no variable, there is no type.
 *
 *  Examples below:
 *      PI   becomes 3.1416 everywhere it appears
 *      ll   becomes 'long long' everywhere — a handy shortcut for
 *           competitive programming where you want 64-bit integers.
 *
 *  Two conventions worth remembering:
 *    1. Macro names are written in ALL_CAPS so the reader instantly knows
 *       "this is a macro, not a regular variable."
 *    2. No semicolon at the end of a #define — it is a preprocessor
 *       directive, not a C statement.
 * ============================================================================
 */
#define PI 3.1416
#define ll long long


/*
 * ============================================================================
 *  SECTION 4 — GLOBAL DECLARATION SECTION
 * ============================================================================
 *
 *  Anything declared OUTSIDE of any function, but inside the .c file, is
 *  called "global". Two kinds of things typically live here:
 *
 *  (a) Global variables
 *      int N = 100;
 *      Any function in this file can read or modify N.
 *      Powerful — but also dangerous, because a bug in one function can
 *      silently corrupt data that another function depends on.
 *      Beginner rule: use globals sparingly. Prefer passing values as
 *      function arguments whenever you can.
 *
 *  (b) Function prototypes (a.k.a. forward declarations)
 *      int sum(int x, int y);          <-- just the signature, note the ';'
 *      This tells the compiler: "a function named 'sum' exists somewhere,
 *      it takes two ints, and it returns an int."
 *
 *      Why? Because the C compiler reads the file top to bottom, ONCE.
 *      If main() calls sum() but sum() is defined BELOW main(), the
 *      compiler hasn't met sum() yet when it reaches the call — and it
 *      will complain. The prototype is a promise: "don't worry, the full
 *      definition is coming later in the file."
 * ============================================================================
 */
int N = 100;                /* a global variable                     */
int sum(int x, int y);      /* a prototype — full definition is below */


/*
 * ============================================================================
 *  SECTION 5 — MAIN FUNCTION
 * ============================================================================
 *
 *  Every C program must have exactly ONE function named main. This is the
 *  "entry point" — when you run the compiled program, the operating system
 *  calls main() for you, and execution begins at the first statement inside
 *  its curly braces.
 *
 *  Anatomy:
 *      int main(void)   -> returns an int to the OS, takes no arguments
 *      {                -> open brace: start of function body
 *          ...          -> your statements, each ending with a ';'
 *          return 0;    -> hand 0 back to the OS. By convention,
 *                          0 = "program finished successfully"
 *                          non-zero = "something went wrong"
 *      }                -> close brace: end of function body
 *
 *  You can also write   int main(int argc, char *argv[])   to accept
 *  command-line arguments. You'll meet that form later.
 * ============================================================================
 */
int main(void)
{
    /* ---- a tiny demo so this file actually does something visible ---- */

    int a = 7, b = 5;                   /* two local variables         */
    int s = sum(a, b);                  /* call our helper function    */
    double area = PI * N;               /* uses the PI macro and N     */
    ll big = 1000000000;                /* uses the 'll' macro shortcut */
    big = big * big;                    /* 1e18 — would overflow a 32-bit int */

    printf("Hello, C!\n");
    printf("sum(%d, %d) = %d\n", a, b, s);
    printf("PI * N    = %f\n", area);
    printf("big       = %lld\n", big);
    printf("sqrt(2)   = %f\n", sqrt(2.0));   /* from <math.h> */

    return 0;   /* 0 tells the OS: "all good, program exited cleanly" */
}


/*
 * ============================================================================
 *  SECTION 6 — SUB-PROGRAM SECTION   (your own helper functions)
 * ============================================================================
 *
 *  Any function you write other than main() is a "sub-program" (also called
 *  a user-defined function). This is where you break a big problem into
 *  small, named, reusable pieces.
 *
 *  Full function definition format:
 *
 *      return_type  name(parameter_list)
 *      {
 *          ... body ...
 *          return some_value;     // if return_type is not 'void'
 *      }
 *
 *  Notice we already PROMISED this function up in Section 4 with a
 *  prototype. Here we keep the promise by providing the actual body.
 *  You could instead put the full definition above main() and skip the
 *  prototype entirely — both styles are valid.
 * ============================================================================
 */
int sum(int x, int y)
{
    return x + y;
}


/*
 * ============================================================================
 *  RECAP — the 6 sections, in the order they appear:
 *
 *    1. Documentation      /* what, who, when, why *\/
 *    2. Linking            #include <...>
 *    3. Definition         #define NAME value
 *    4. Global declaration global variables + function prototypes
 *    5. Main function      int main(void) { ... return 0; }
 *    6. Sub-programs       your own helper functions
 *
 *  Only Section 5 (main) is strictly REQUIRED. The other five are optional,
 *  but a well-structured real-world C file almost always contains all of
 *  them, in exactly this order.
 *
 *  How to build and run (Windows, Git Bash, from the folder of this file):
 *      gcc c_program_structure.c -o c_program_structure.exe
 *      ./c_program_structure.exe
 *
 *  Or simply press the Code Runner "Run" button in VS Code — the executor
 *  map you configured earlier will do both steps for you.
 * ============================================================================
 */
