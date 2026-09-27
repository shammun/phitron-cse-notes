// Topic: reading numbers until the input ends (EOF = End Of File), without knowing
// in advance how many numbers there are.
// Example input:  10 20 30
// Example output:
//   10
//   20
//   30

#include <iostream> // Include the iostream library to allow input/output operations (cin, cout, endl)
using namespace std; // Use the standard namespace to avoid prefixing 'std::' before cin, cout, etc.

// main() is where the program starts running; it returns an int to the operating system.
int main() {
    int x; // Declare an integer variable 'x' to store input values (one number at a time)

    // --- Block: keep reading until input runs out ---
    // Start a while loop to continuously read input from the user.
    // 'cin >> x' reads an integer from the standard input (keyboard or a file) and stores it in 'x'.
    // The expression 'cin >> x' itself gives back cin, and cin used as a condition is
    //   true  -> the read succeeded, a number is now in x
    //   false -> the read failed (input ended, or the next thing was not a number).
    // So one pass of the loop = read one number and print it; the loop stops at EOF.
    // This is the C++ version of C's: while (scanf("%d", &x) != EOF)
    while (cin >> x) {
        // Output the value of 'x' using 'cout' and add a newline character.
        // This prints the input number and moves to the next line.
        cout << x << endl;

        // Explanation of the input/output objects used here:
        // - 'cin' is used to read input data from the user. It works by extracting the next input and storing it in the specified variable.
        //   It skips spaces, tabs and newlines between numbers, so "10 20 30" and one number per line work the same.
        // - 'cout' is used to display output to the user. Here, it outputs the value of 'x' followed by a newline ('endl').
        // The loop enables continuous input handling, which stops when an invalid input (non-integer) is encountered
        // or the user signals EOF (End of File): Ctrl+Z then Enter on Windows, Ctrl+D on Linux/macOS.
        // When input comes from a file, EOF simply happens after the last number.
    }

    // Return 0 indicates that the program executed successfully
    return 0;
}
