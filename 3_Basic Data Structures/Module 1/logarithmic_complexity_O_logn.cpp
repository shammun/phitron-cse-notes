// Logarithmic time complexity, O(log n): the loop variable is MULTIPLIED or
// DIVIDED by a constant each pass, so it covers the distance to n in very few
// steps. log2(1,000,000) is only about 20.
// Rule: if i is multiplied/divided by k each pass, the loop runs about log_k(n)
// times ("log base k of n"). All log bases differ only by a constant factor, so
// Big-O just writes O(log n).

#include <iostream> // gives us cin (read input) and cout (print output)
using namespace std; // so we can write cin/cout instead of std::cin/std::cout

int main() { // the program starts running here
    int n; // O(1) -- one variable
    cin >> n; // O(1) -- read one number

    // O(log n)
    // i = 1, 2, 4, 8, ... (i *= 2 doubles i) while i <= n.
    // Example n = 20: prints "1 2 4 8 16 " -> 5 passes, log2(20) is about 4.3.
    for(int i = 1; i <= n; i *= 2) {
        cout << i << " "; // print the current i
    }

    // O(log n) -- log 3 base n
    // (i.e. log base 3 of n.) i starts at n and is divided by 3 each pass
    // (i /= 3 is integer division, the remainder is thrown away) until it drops below 1.
    // Example n = 30: 30, 10, 3, 1 -> 4 passes.
    for(int i=n; i>=1; i/=3){
        cout << i << " "; // print the current i
    }

    // O(log n) -- log 2 base n
    // (i.e. log base 2 of n.) Here i changes twice per pass: first i *= 2 in the
    // body, then i++ in the loop header. So i goes 1 -> 2+1 = 3 -> 6+1 = 7 -> 15 ...
    // (i becomes 2*i + 1): it roughly doubles each pass -> about log2(n) passes.
    // Example n = 20: prints "1 3 7 15 ".
    for(int i=1; i<n; i++){
        cout  << i << " "; // print the current i
        i *= 2; // double i (then the header's i++ adds 1)
    }

    // O(log n) -- log k base n
    // (i.e. log base k of n.) Same idea with k = 3: i becomes 3*i + 1 each pass,
    // so it grows by about 3 times -> about log3(n) passes.
    // Example n = 50: prints "1 4 13 40 ".
    int k = 3; // the growth factor
    for(int i=1; i<n; i++){
        cout  << i << " "; // print the current i
        i *= k; // multiply i by k (then the header's i++ adds 1)
    }

    return 0; // program finished successfully
}
// Whole program: four O(log n) loops one after another -> 4 log n -> O(log n).
