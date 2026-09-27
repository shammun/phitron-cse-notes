// Quadratic time complexity, O(n^2): a loop inside a loop, both running n times.
// For each of the n outer passes, the inner loop does all n of its passes,
// so the body runs n * n times. Doubling n makes the work 4 times bigger.
// The file also shows O(n*m) (two different sizes) and O(n^3) (three nested loops).

#include <iostream> // gives us cin (read input) and cout (print output)
using namespace std; // so we can write cin/cout instead of std::cin/std::cout

int main() { // the program starts running here
    int n, m; // O(1) -- two size variables
    cin >> n >> m; // O(1) -- read two numbers separated by a space or newline

    // O(n^2)
    // Outer i: n passes. Inner j: n passes for EVERY i -> n * n prints.
    // Example n = 2: prints "0 0", "0 1", "1 0", "1 1" (4 lines).
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cout << i << " " << j << endl; // print the pair; endl = new line + flush
        }
    }

    // O(n^2)
    // Same shape; what the body prints does not matter, only how often it runs.
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cout << "Hello" << endl; // runs n * n times
        }
    }

    // O(nxm)
    // Outer loop n passes, inner loop m passes -> n * m. We cannot write n^2
    // because m is a different, independent input size.
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cout << "Hello" << endl; // runs n * m times
        }
    }

    // O(n^3)
    // Three loops, each n passes, nested -> n * n * n. Example n = 10: 1000 prints.
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            for(int k = 0; k < n; k++) {
                cout << "Hello" << endl; // runs n^3 times
            }
        }
    }

    return 0; // program finished successfully
}
// Whole program: n^2 + n^2 + n*m + n^3 -> the dominant term is O(n^3)
// (assuming m is not bigger than n^2; formally O(n^3 + n*m)).
