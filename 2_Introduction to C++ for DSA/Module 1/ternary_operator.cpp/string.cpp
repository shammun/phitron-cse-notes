// Topic: reading a whole line of text (with spaces) into a char array using cin.getline.
// Example input:  I love C plus plus
// Example output: I love C plus plus

#include <iostream> // Gives us cin, cout and endl
#include <string> // The C++ string type (not actually used below; this file uses a char array)
using namespace std; // Lets us write cin/cout instead of std::cin/std::cout

// main() is where the program starts running.
int main(){
    char s[100]; // A C-style string: an array of 100 chars (room for 99 letters + the ending '\0')
    // cin >> s; // cin is like scanf in C, can't take string with spaces as input. It just takes the first word.
    // cin and scanf can't take string with spaces as input. It just takes the first word.
    // In C, we can use fgets to take string with spaces as input.
    // In C, this is fgets(s, 100, stdin);

    // In C++, we can use getline to take string with spaces as input
    // In C++, this is cin.getline(s, 100);

    // Reading a line of text from the user:
    // cin.getline(s, 100) reads characters up to the Enter key (spaces included),
    // stores at most 99 of them in s, adds '\0', and throws the newline away.
    cin.getline(s, 100);
    cout << s << endl; // Print the line that was read, then a newline

    return 0; // Program ended successfully
}