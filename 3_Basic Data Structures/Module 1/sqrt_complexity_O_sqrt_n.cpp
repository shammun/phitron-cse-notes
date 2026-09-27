// Square-root time complexity, O(sqrt n): the loop stops once i reaches sqrt(n).
// Example n = 1,000,000: only about 1000 passes instead of 1,000,000.
// Classic use: finding all divisors of n. Divisors come in pairs (i, n/i), and
// the smaller one of each pair is always <= sqrt(n), so we only need to try
// i from 1 up to sqrt(n) and print both members of each pair.

#include <iostream> // gives us cin (read input) and cout (print output)
// sqrt() really lives in <cmath>. It works here because g++'s <iostream>
// happens to pull it in; adding #include <cmath> would be the safe way.
using namespace std; // so we can write cin/cout instead of std::cin/std::cout

int main() { // the program starts running here
    int n; // the number we work on
    cin >> n; // read n from the keyboard

    // O(sqrt(n))
    // sqrt(n) returns the square root as a decimal number (a double).
    // i goes 0, 1, 2, ... while i <= sqrt(n). Example n = 20: sqrt is 4.47,
    // so i = 0..4 -> 5 passes.
    // (sqrt(n) is recalculated every pass; it is cheap, but still extra work.)
    for(int i=0; i<=sqrt(n); i++){
        cout << i << endl; // print i on its own line
    }

    // find all the divisors of n
    // O(n)) -- the slow way: try every i from 1 to n -> n passes.
    // n % i is the remainder of n / i; remainder 0 means i divides n exactly.
    // Example n = 12: prints "1 2 3 4 6 12 ".
    for(int i=1; i<=n; i++){
        if(n%i == 0){ // i divides n with no remainder
            cout << i << " "; // so i is a divisor: print it
        }
    }

    // O(sqrt(n))
    // The fast way: only try i up to sqrt(n). When i divides n, n / i is the
    // matching divisor on the other side, so print both.
    // Example n = 12: i=1 -> "1 12", i=2 -> "2 6", i=3 -> "3 4" (i stops at 3).
    // Note: when n is a perfect square (n = 16, i = 4) the pair is "4 4", so 4
    // is printed twice. The output is not sorted either.
    for(int i=1; i<=sqrt(n); i++){
        if(n%i == 0){ // i is a divisor
            cout << i << " " << n /i << " "; // print i and its partner n/i
        }
    }

    // O(sqrt(n))
    // Same loop, but the stop test is i*i <= n instead of i <= sqrt(n).
    // Both mean the same thing, but i*i uses only whole numbers: no slow sqrt
    // call and no decimal rounding worries.
    for(int i=1; i*i<=n; i++){
        if(n%i == 0){ // i is a divisor
            cout << i << " " << n /i << " "; // print the pair (i, n/i)
        }
    }

    return 0; // program finished successfully
}
// Whole program: sqrt n + n + sqrt n + sqrt n -> the O(n) loop dominates -> O(n).
