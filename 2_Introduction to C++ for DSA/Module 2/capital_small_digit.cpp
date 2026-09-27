/*

Capital or Small or Digit
time limit per test: 1 second
memory limit per test: 256 megabytes

Given a letter X. Determine whether X is Digit or Alphabet and if it is Alphabet determine if it is Capital Case or Small Case.

Note:

Digits in ASCII '0' = 48,'1' = 49 ....etc
Capital letters in ASCII 'A' = 65, 'B' = 66 ....etc
Small letters in ASCII 'a' = 97,'b' = 98 ....etc
Input
Only one line containing a character X which will be a capital or small letter or digit.

Output
Print a single line contains "IS DIGIT" if X is digit otherwise, print "ALPHA" in the first line followed by a new line that contains "IS CAPITAL" if X is a capital letter and "IS SMALL" if X is a small letter.

Examples
Input
A
Output
ALPHA
IS CAPITAL

Input
9
Output
IS DIGIT

Input
a
Output
ALPHA
IS SMALL

*/

// Idea: a char is stored as a small whole number, its ASCII code.
// The digits '0'..'9' are codes 48..57, the capitals 'A'..'Z' are 65..90 and
// the small letters 'a'..'z' are 97..122 - each group is one unbroken run.
// So "is x a digit?" becomes "is x between '0' and '9'?", and the same for letters.

#include <iostream> // gives cin (read from keyboard) and cout (print to screen)
using namespace std; // lets us write cin/cout instead of std::cin/std::cout

int main(){ // the program starts running here
    char x; // a char holds exactly one character (really its ASCII code, one byte)
    cin >> x; // cin skips spaces/newlines, then reads ONE character into x - no %c needed like in C

    // First question: digit or letter?
    // '0' and '9' in single quotes are the character codes 48 and 57, so this
    // compares numbers: 48 <= x <= 57. && means both sides must be true.
    // Example: x = '7' (code 55) -> 55 >= 48 and 55 <= 57 -> true -> IS DIGIT.
    if(x >= '0' && x<= '9'){
        cout << "IS DIGIT" << endl; // endl prints a newline (and flushes the output)
    } else{
        // Not a digit, so (by the problem's promise) it is a letter
        cout << "ALPHA" << endl; // first line for every letter
    }

    // Second question, only meaningful for letters: which run is it in?
    // For a digit neither test is true, so nothing more is printed.
    // Example: x = 'A' (65) -> 65 is in 65..90 -> IS CAPITAL.
    if(x >= 'A' && x <= 'Z'){ // capital run: codes 65..90
        cout << "IS CAPITAL" << endl;
    } else if(x >= 'a' && x <= 'z'){ // small run: codes 97..122 (checked only if not capital)
        cout << "IS SMALL" << endl;
    }

    return 0; // returning 0 from main tells the system the program ended fine
}