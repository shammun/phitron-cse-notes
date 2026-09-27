// Topic: the same program as input.cpp, but shorter to type thanks to "using namespace std;".
// Example input:  42
// Example output: 42

#include <iostream> // Header that gives us cin (keyboard input), cout (screen output) and endl
// cin, cout and endl all live inside the "std" namespace (a named group of standard names).
// This line lets us write cin instead of std::cin, cout instead of std::cout, and so on.
using namespace std;

// main() is where the program starts running.
int main(){
    int x; // Declare an integer variable x to hold the number the user types
    // In C, scanf("%d", &x) is used to take input from the user
    // In C++, cin >> x is used to take input from the user
    // std::cin >> x; // cin is used to take input from the user  (the long form, no longer needed)
    cin >> x; // Read an integer from the keyboard into x (cin knows x's type, so no %d and no &)
    // std::cout << x << std::endl;  (the long form, no longer needed)
    cout << x << endl; // Print x, then endl = newline + flush
    return 0; // Program ended successfully
}