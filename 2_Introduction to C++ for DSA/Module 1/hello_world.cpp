// Topic: the smallest complete C++ program - print one line of text.
// Output: Hello, World!

#include <iostream> // This is the header file that allows us to use
//input and output objects like std::cout
// (#include copies the contents of that header into this file before compiling;
//  "iostream" = input/output streams.)

// main() is where every C++ program starts running.
// "int" before main means main gives back an integer to the operating system when it ends.
int main(){
    // std::cout is the standard character output stream in C++ (it prints to the screen).
    // "std::" says cout lives in the "std" (standard library) namespace; this file has no
    // "using namespace std;" line, so we must write the std:: prefix ourselves.
    // The '<<' operator is used to send the string "Hello, World!" to the output stream.
    // The text in double quotes is a string literal. No newline is printed after it.
    std::cout << "Hello, World!";

    // return 0 indicates that the program ended successfully
    return 0;
}