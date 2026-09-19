// Fibonacci the obvious way: 0, 1, 1, 2, 3, 5, 8, 13, ... where each number is
// the sum of the two before it. This file is here to be SLOW, on purpose - the
// two files after it fix exactly the problem it shows.

#include <iostream>
#include <vector>
#include <algorithm>    
#include <string>

using namespace std;

// Two base cases are needed, not one, because the recursive step reaches two
// steps back: fib(2) asks for fib(1) and fib(0), so both must be known outright.
// Conveniently fib(0) = 0 and fib(1) = 1, so `return n;` covers both.
//
// Where the time goes. Every call that is not a base case makes two more calls,
// so the calls form a branching tree rather than a chain. Counting them:
//     calls(0) = calls(1) = 1,  calls(n) = 1 + calls(n-1) + calls(n-2)
// which works out to 2 * fib(n+1) - 1 calls in total.
//     fib(10) -> 177 calls
//     fib(30) -> about 2.7 million calls
//     fib(40) -> about 331 million calls, several seconds of waiting
// The tree very nearly doubles at each level, so the cost grows like 1.6^n.
//
// And it is all wasted work: fib(n-1) internally computes fib(n-2) all over
// again, fib(n-2) computes fib(n-3) twice, and so on. fib(5) alone is worked out
// from scratch eight times inside fib(10). Nothing is remembered between calls,
// which is precisely what fibonacci_with_memoization.cpp changes.
int fib(int n){
    if(n == 0 || n == 1){ // or, we can also write if(n < 2)
        return n;
    }
    return fib(n-1) + fib(n-2);
}

int main(){
    int n;
    cin >> n;
    cout << fib(n) << endl;

    return 0;
}