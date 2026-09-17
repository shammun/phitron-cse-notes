#include <iostream> // Include the iostream library to allow input/output operations
using namespace std; // Use the standard namespace to avoid prefixing 'std::' before cin, cout, etc.

int main() {
    int x; // Declare an integer variable 'x' to store input values

    // Start a while loop to continuously read input from the user
    // 'cin >> x' reads an integer from the standard input (keyboard) and stores it in 'x'
    // The loop runs as long as a valid integer is provided as input
    while (cin >> x) {
        // Output the value of 'x' using 'cout' and add a newline character
        // This prints the input number and moves to the next line
        cout << x << endl;

        // Explanation of different formatters:
        // - 'cin' is used to read input data from the user. It works by extracting the next input and storing it in the specified variable.
        // - 'cout' is used to display output to the user. Here, it outputs the value of 'x' followed by a newline ('endl').
        // Using these formatters ensures the program handles input and output in a structured way.
        // The loop enables continuous input handling, which stops when an invalid input (non-integer) is encountered or the user signals EOF (End of File, e.g., Ctrl+D or Ctrl+Z).
    }

    // Return 0 indicates that the program executed successfully
    return 0;
}
