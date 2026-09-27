// Topic: characters are stored as numbers (their ASCII codes), and typecasting lets us
// look at the same value either as a number or as a character.
// Example input: 5
// Example output:
//   5
//   65
//   65
//   A

#include <iostream> // This is the header file that allows us to use input and output objects like std::cin and std::cout
using namespace std; // This line allows us to use names for objects and variables from the standard library without the 'std::' prefix

// main() is where every C++ program starts running. It returns an int to the operating system.
int main(){
    int x; // Declare an integer variable x (a whole number); it holds garbage until we store something in it
    // Taking input from the user and storing it in variable x.
    // cin >> x skips any spaces/newlines, reads the digits typed, converts them to an int and stores them in x.
    // It is the C++ version of C's scanf("%d", &x) - no format string and no & are needed,
    // because cin already knows the type of x.
    cin >> x;
    // Printing the value of x followed by a new line.
    // cout << sends a value to the screen; endl prints a newline and flushes (forces the text out immediately).
    cout << x << endl;

    // --- Block: a char is really a small integer ---
    // Every character is stored in memory as a number called its ASCII code:
    // 'A' = 65, 'B' = 66, ..., 'a' = 97, '0' = 48.
    char c = 'A'; // Initializing character variable c with 'A' (single quotes = one character; memory holds 65)
    int ASCII_value = c; // Storing the ASCII value of character c in integer variable ASCII_value (automatic char -> int conversion, so 65)
    // Printing the ASCII value of character c.
    // Because ASCII_value is an int, cout prints it as a number: 65
    cout << ASCII_value << endl;

    // Typecasting character c to its integer ASCII value and printing it.
    // (int)c means "treat c as an int just for this expression"; c itself stays a char.
    // Without the cast, cout << c would print the letter A; with it, cout prints 65.
    cout << (int)c << endl;

    int y = 65; // Initializing integer variable y with 65
    // Typecasting integer y to its corresponding character and printing it.
    // (char)y means "treat 65 as a character", and character code 65 is 'A', so this prints A.
    cout << (char)y << endl;

    return 0; // return 0 tells the operating system that the program ended successfully
}