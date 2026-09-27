/*
This program will ask users for a number and will sum all the numbers from 1 to that number.

Idea: there are two ways to get 1 + 2 + ... + num.
  1. A loop that adds every number one by one  -> num steps  -> O(n) time.
  2. The formula num * (num + 1) / 2             -> 1 step    -> O(1) time.
The loop version is kept below inside a comment so you can compare; the
formula version is the one that actually runs.
Example: num = 5 -> 5 * 6 / 2 = 15, and 1+2+3+4+5 = 15 too.
*/

#include <iostream> // brings in cin (keyboard input) and cout (screen output)
using namespace std; // lets us write cout / cin / endl instead of std::cout / std::cin / std::endl

// main() is where every C++ program starts running; it returns an int to the operating system
int main() {
    int num, sum = 0; // num = the number the user types; sum starts at 0 (nothing added yet)
    cout << "Enter a number: "; // print a prompt so the user knows to type something
    cin >> num; // read one whole number from the keyboard into num (cin skips spaces/newlines before it)

    // The slow way, switched off by putting it inside /* ... */ (a block comment).
    // If it were on, it would add i = 1, 2, ..., num to sum, one per loop pass:
    // num passes -> O(n) time. The formula below gives the same answer in O(1).
    /*
    for(int i=1; i<=num; i++){
        sum += i;
    }
    */

    // Using the formula for sum of n numbers
    // Why it works: write 1..num forwards and backwards and add them in pairs:
    // (1 + num) + (2 + num-1) + ... -> num pairs, each equal to (num + 1),
    // which counts every number twice, so divide by 2.
    // Multiply first, then divide: num * (num + 1) is always even, so /2 is exact.
    // Note: int holds up to about 2.1 * 10^9, so num * (num + 1) overflows when
    // num is bigger than about 46340; use long long for bigger inputs.
    sum = (num * (num + 1)) / 2;

    // Print the answer. endl ends the line (moves to a new line) and flushes the output.
    cout << "Sum of numbers from 1 to " << num << " is " << sum << endl;

    return 0; // 0 tells the operating system "the program finished without errors"
}
