// Topic: reading a whole line of text (with spaces) into a char array using cin.getline.
// Example input:  Hello World from Phitron
// Example output: Hello World from Phitron

#include <iostream> // Gives us cin, cout and endl
using namespace std; // Lets us write cin/cout instead of std::cin/std::cout

// main() is where the program starts running.
int main(){
    char s[100]; // A C-style string: an array of 100 chars (room for 99 letters + the ending '\0')
    // cin >> s;
    // In C, when there are spaces or space
    // between inputs, it reads only the first word
    // (the same is true for cin >> s in C++: it stops at the first space,
    //  so "Hello World" would give just "Hello").
    // To overcome this in C, we use
    // fgets(s, 100, stdin);

    // We can also use this in C++
    // But C++ has a better way:
    // cin.getline(s, 100) reads characters until the end of the line (Enter),
    // keeping the spaces, stores at most 99 of them in s, adds '\0' at the end,
    // and throws away the newline (fgets would keep the '\n' inside s).
    cin.getline(s, 100);

    // But if there were no spaces, we could
    // have used just cin
    // cin >> s;

    cout << s << endl; // Print the whole line that was read, then a newline

    return 0; // Program ended successfully
}