
// Linear time complexity, O(n): the work grows in a straight line with n.
// If n doubles, the number of loop passes (roughly) doubles too.
// Every loop below runs "some constant times n" passes, and Big-O drops
// constants (n-5, n/2, 2n, n/2+1 are all just O(n)).

#include <iostream> // gives us cin (read input) and cout (print output)
using namespace std; // so we can write cin/cout instead of std::cin/std::cout

int main() { // the program starts running here
    int n; // O(1) -- making one variable takes the same time no matter what n is
    cin >> n; // O(1) -- reading one number is a single step

    // O(n)
    // i goes 0, 1, 2, ..., n-1 -> exactly n passes. Each pass prints i and a space.
    // Example n = 4: prints "0 1 2 3 ".
    for(int i = 0; i < n; i++) {
        cout << i << " "; // one print = constant work per pass
    }

    // O(n)
    // i goes 0 .. n-6 -> n-5 passes. Subtracting a constant does not change
    // how the count grows, so it is still O(n). (If n < 5, it runs 0 times.)
    for(int i = 0; i < n-5; i++) {
        cout << i << " "; // print i
    }

    // O(n)
    // i goes 0 .. n/2 - 1 -> n/2 passes. Half of n is still "a constant times n",
    // so O(n/2) = O(n). (n/2 is integer division: 7/2 = 3.)
    for(int i = 0; i < n/2; i++) {
        cout << i << " "; // print i
    }

    // O(n)
    // i goes 0 .. 2n-1 -> 2n passes. Twice n is still linear: O(2n) = O(n).
    for(int i = 0; i < 2*n; i++) {
        cout << i << " "; // print i
    }

    // O(n)
    // i += 2 means i jumps by 2 each pass: 0, 2, 4, ..., up to n.
    // That is about n/2 + 1 passes -> still O(n).
    // Example n = 6: prints "0 2 4 6 " (4 passes).
    for(int i = 0; i <= n; i+=2) {
        cout << i << " "; // print i
    }

    return 0; // program finished successfully
}

// Time complexity: O(n) -- consider the worst case scenario and ignore the constants
// or consider the most dominant term
// Here: n + (n-5) + n/2 + 2n + (n/2+1) is about 5n, and 5n -> O(n).
