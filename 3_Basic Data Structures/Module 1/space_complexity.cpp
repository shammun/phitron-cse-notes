// Space complexity: how much EXTRA memory a program needs as n grows.
// A fixed number of simple variables -> O(1) space.
// An array of n items -> O(n) space; an n x n grid -> O(n^2) space.
// NOTE: this file is a set of lecture notes, not a working program. It does
// NOT compile as written (see the BUG lines below); read it for the ideas.

#include <iostream> // gives us cin (read input) and cout (print output)
using namespace std; // so we can write cin/cout instead of std::cin/std::cout

int main() { // the program starts running here
    int n; // the input size
    // BUG: m was never declared, so the compiler stops with "'m' was not declared
    // in this scope". Fix: declare it first, e.g. write "int n, m;" above.
    cin >> n >> m;
    int sum = 0; // memory space complexity O(1)
    int x; // memory space complexity O(1)
    double d = 3.14; // memory space complexity O(1)
    // (d is a double: a number with a decimal point.)
    // time complexity depends on the number of loops while
    // space complexity depends on the number of variables or the array size

    // time complexity O(n)
    // space complexity O(1)
    // The loop runs n times but only reuses sum and i -> no memory grows with n.
    for(int i = 0; i < n; i++) {
        sum += i; // add i to the running total (sum = sum + i)
    }

    // space complexity O(n)
    // int a[n] makes an array of n ints, so memory grows with n.
    // (An array whose size is a variable is a "variable-length array"; g++ allows
    // it as an extension, but it is not standard C++. vector<int> a(n) is the
    // standard way.)
    int a[n];
    // time complexity O(n)
    for(int i = 0; i < n; i++) {
        cin >> a[i]; // read the i-th number into the array
    }

    // space complexity O(n^2)
    // A 2D array of n rows and n columns = n * n ints.
    // BUG: the name a is already used by the 1D array above; the same name cannot
    // be declared twice in one scope ("conflicting declaration"). Fix: use a new
    // name such as b, or put each example in its own { } block.
    int a[n][n];

    // time complexity O(n)
    // Only the diagonal cells a[0][0], a[1][1], ... are filled -> n passes,
    // even though the grid itself takes n^2 memory. Time and space can differ.
    for(int i = 0; i < n; i++) {
        cin >> a[i][i]; // read into the diagonal cell (row i, column i)
    }

    // space complexity O(n*m)
    // n rows and m columns = n * m ints.
    // BUG: same problem again, a is declared a third time. Fix: use another name.
    int a[n][m];
    // time complexity O(n)
    // Only n cells are touched. (If m < n, a[i][i] would also go past the last column.)
    for(int i = 0; i < n; i++) {
        cin >> a[i][i]; // read into the diagonal cell
    }

    return 0; // program finished
}
