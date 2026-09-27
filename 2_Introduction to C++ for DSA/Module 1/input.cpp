// Topic: reading one integer with std::cin and printing it with std::cout.
// Example input:  42
// Example output: 42

#include <iostream> // Header that gives us std::cin (keyboard input), std::cout (screen output) and std::endl

// main() is where the program starts running.
int main(){
    int x; // Declare an integer variable x to hold the number the user types
    // In C, scanf("%d", &x) is used to take input from the user
    // In C++, cin >> x is used to take input from the user
    // (cin knows x is an int, so there is no "%d" and no "&x"; >> points the data INTO x.
    //  "std::" is needed because this file has no "using namespace std;" line.)
    std::cin >> x; // cin is used to take input from the user
    // Print x, then std::endl, which moves to a new line and flushes the output.
    std::cout << x << std::endl;

    return 0; // Program ended successfully
}