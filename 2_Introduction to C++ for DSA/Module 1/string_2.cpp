// Topic: reading a number and THEN a full line of text - why cin.ignore() is needed in between.
// Example input:
//   5
//   Hello World
// Example output:
//   5
//   Hello World

#include <iostream> // Gives us cin, cout and endl
using namespace std; // Lets us write cin/cout instead of std::cin/std::cout

// main() is where the program starts running.
int main(){
    int x; // The number on the first line
    cin >> x; // Reads "5" but STOPS before the Enter key, so a '\n' is still waiting in the input

    // cin.ignore() throws away exactly one character from the input - here that leftover '\n'.
    // Without it, getline below would see the '\n' immediately, think the line is empty,
    // and s would be "" instead of "Hello World".
    cin.ignore();
    // Ignore the newline character or
    // ignore the space after the integer
    // in input.txt in first line
    // (It removes only ONE character: if there were two extra spaces after 5,
    //  one would remain and would become the start of s.)

    char s[100]; // A char array (C-style string) with room for 99 characters + '\0'
    // cin.getline(s, 100) reads the rest of the current line, spaces included, into s
    // (at most 99 characters) and discards the '\n' at the end.
    cin.getline(s, 100);
    // if the second line has more than one
    // words

    // Print x on one line and the text on the next.
    cout << x << endl <<s << endl;

    return 0; // Program ended successfully
}