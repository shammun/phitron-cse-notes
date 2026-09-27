// Topic: the C++ 'string' type (no fixed-size char array needed), and the fact that
// cin >> string reads only ONE word.
// Example input:
//   5
//   Hello World
// Example output:
//   Hello World!
//   Hello
// (x = 5 is read but never printed; s2 gets only "Hello" because cin stops at the space.)

#include <iostream> // Gives us cin, cout and endl (with GCC it also brings in 'string')
using namespace std; // Lets us write string/cin/cout instead of std::string/std::cin/std::cout

// main() is where the program starts running.
int main(){
    int x; // An integer variable
    cin >> x; // Read an integer from the input into x (it is not used later)

    // C++ has a string type called 'string'
    // Thus we don't need to declare a character
    // array
    // (a string grows and shrinks by itself, so there is no size like [100] to choose,
    //  and no risk of writing past the end of the array.)

    // String class is a built-in class
    // (it comes from the standard library header <string>; strictly we should
    //  #include <string>, but GCC's <iostream> already pulls it in.)
    string s = "Hello World!"; // String literal copied into the string s
    cout << s << endl; // Prints: Hello World!

    string s2; // An empty string
    // But it can't take input with spaces:
    // cin >> s2 skips leading spaces/newlines, then reads characters until the next
    // space or newline. So for "Hello World" s2 becomes just "Hello".
    // (To read a whole line into a string use getline(cin, s2).)
    cin >> s2;
    cout << s2 << endl; // Prints the one word that was read

    return 0; // Program ended successfully
}