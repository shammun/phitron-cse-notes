// Topic: the "string after int" problem. After cin >> x, the Enter key ('\n') is left
// in the input, so a following getline would read an empty line. cin.ignore() fixes it.
// Example input:
//   5
//   Hello World
//   7 Phitron
// Example output:
//   5
//   Hello World
//   7
//   Phitron

#include <iostream> // This header file is used to perform input and output operations
using namespace std; // This line allows us to use names for objects and variables from the standard library without the 'std::' prefix

// main() is where the program starts running.
int main(){
    int x; // Declaring an integer variable x to store the user input
    cin >> x; // Taking input from the user and storing it in variable x (stops just before the '\n')

    // cin.ignore() is used to ignore the newline character left in the input buffer after reading the integer
    // This is necessary because the newline character would otherwise be read by the next input operation
    // (getline would see that '\n' at once and return an empty line.)
    // cin.ignore() with no arguments throws away exactly one character.
    cin.ignore();

    char s[100]; // Declaring a character array s to store the string input
    // cin.getline() is used to read a line of text from the user, including spaces
    // The first argument is the character array to store the input
    // The second argument is the size of the array: at most 99 characters are read, leaving room for '\0'
    cin.getline(s, 100);

    // Printing the integer and the string on separate lines
    // The endl manipulator is used to insert a newline character and flush the output buffer
    cout << x << endl << s << endl;

    // Another way to store string input:
    // We don't need to use char array or cin.getline(), the C++ 'string' type grows by itself.
    // NOTE: cin >> s2 still reads only ONE word (it stops at a space). It does NOT take
    // input with spaces; for a whole line into a string use getline(cin, s2).
    // Also, cin >> skips leading spaces/newlines, so no cin.ignore() is needed between cin >> y and cin >> s2.
    string s2; // Declaring a string variable s2 to store the user input
    int y; // Another integer
    cin >> y; // Read an integer into y
    cin >> s2; // Taking input from the user and storing it in variable s2 (one word only)

    cout << y << endl << s2 << endl; // Printing y and the word, each on its own line

    return 0; // return 0 indicates that the program ended successfully
}