// Linearithmic time complexity, O(n log n): a loop of n passes, where each
// pass runs an inner loop of only log n passes. It sits between O(n) and O(n^2).
// This file compares an O(n^2) double loop with an O(n log n) double loop.

#include <iostream> // gives us cin (read input) and cout (print output)
using namespace std; // so we can write cin/cout instead of std::cin/std::cout

int main() { // the program starts running here
    int n; // O(1) -- one variable
    cin >> n; // O(1) -- read one number

    // O(n^2)
    // Outer loop: i = 0 .. n-1 -> n passes.
    // Inner loop: for EACH i, j = 0 .. n-1 -> n passes.
    // Total prints = n * n = n^2. Example n = 3: 9 lines.
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cout << i << "Hello" << j << endl; // e.g. "0Hello2"; endl = new line + flush
        }
    }

    // O(n*log n)
    // Outer loop: n passes, same as before.
    // Inner loop: j starts at 1 and is DOUBLED each pass (j *= 2 means j = j * 2):
    // 1, 2, 4, 8, ... while j < n. Doubling reaches n after about log2(n) steps.
    // Example n = 16: j = 1, 2, 4, 8 -> 4 passes, and log2(16) = 4.
    // Total = n passes * log n passes each = n log n.
    // (j must start at 1, not 0: 0 * 2 = 0 would loop forever.)
    for(int i = 0; i < n; i++) {
        for(int j = 1; j < n; j *= 2) {
            cout << i << "Hello" << j << endl; // print the pair (i, j)
        }
    }

    return 0; // program finished successfully
}
// Whole program: n^2 + n log n. Keep the biggest term -> O(n^2).
