// Topic: finding the smaller/larger of numbers with min() and max(), and exchanging
// two variables with swap().
// Example input:  5 2 9
// Example output:
//   2          min(a, b)
//   5          max(a, b)
//   2          min({a, b, c})
//   -100       min({20, -100, 40, 65})
//   9          max({a, b, c})
//   65         max({20, -100, 40, 65})
//              (empty line)
//   2 5        a and b after swap

#include <iostream> // Gives us cin, cout and endl
#include <algorithm> // This header file is used to use the min, max, and swap functions
using namespace std; // This line allows us to use names for objects and variables from the standard library without the 'std::' prefix

// main() is where the program starts running.
int main(){
    int a, b, c; // Three integer variables
    cin >> a >> b >> c; // Read three integers (separated by spaces or newlines) into a, b, c in that order

    /*
    In C++, min and max can be found using if else statements
    if(a <b){
        cout << a << endl;
    } else {
        cout << b << endl;
    }
    (kept commented out only to compare with the one-line built-in version below)
    */

    // In C++, min and max can be found using built-in functions:
    // min(a, b) returns the smaller value, max(a, b) the larger; both arguments must be the same type.
    cout << min(a, b) << endl; // With a=5, b=2 -> 2
    cout << max(a, b) << endl; // With a=5, b=2 -> 5

    // min and max can find minimum and maximum among more than two numbers
    // In this case, the numbers have to be passed within second or curly braces
    // (curly braces { } build an "initializer list"; min/max scan the whole list)
    cout << min({a, b, c}) << endl; // Smallest of the three variables -> 2
    cout << min({20, -100, 40, 65}) << endl; // Works with plain numbers too -> -100

    cout << max({a, b, c}) << endl; // Largest of the three variables -> 9
    cout << max({20, -100, 40, 65}) << endl; // -> 65

    cout << endl; // Print an empty line to separate the swap output

    // swap function swaps the values of two variables
    // (no temp variable needed; with a=5, b=2 -> a=2, b=5)
    swap(a, b);
    cout << a << " " << b << endl; // Print the swapped values

    return 0; // Program ended successfully
}