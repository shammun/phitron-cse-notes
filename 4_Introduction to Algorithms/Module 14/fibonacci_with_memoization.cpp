// Fibonacci again, with MEMOIZATION - the recursion of fibonacci_recursion.cpp
// plus a notebook. This is top-down dynamic programming, and it is the whole of
// DP in one idea: work out each distinct subproblem once, write the answer down,
// and look it up ever after.
//
// Nothing about the recursion changes. Only two lines are added: one that checks
// the notebook before working, one that writes the result into it afterwards.

#include <iostream>
#include <vector>
#include <algorithm>    
#include <string>

using namespace std;

// The notebook. Read dp[i] as "the answer to fib(i)" - it is indexed by the
// QUESTION, not by position in some list of results. dp[7] is fib(7), whether or
// not fib(7) was the seventh thing computed. That is what makes the lookup work:
// any call that wants fib(7) knows exactly which box to look in.
//
// 1005 boxes is a fixed size chosen to be comfortably above the n the lesson
// uses; it is global, so there is no worry about putting a big array on the
// stack. -1 will mean "not worked out yet" (see memset in main).
int dp[1005];

int fib(int n){
    // Same two base cases as before.
    if(n < 2){ // or, we can also write if(n == 0 || n == 1)
        return n;
    }
    // Already worked out? Then hand back the saved answer and make no calls at
    // all. This single line is what cuts the branching tree down.
    if(dp[n] != -1){
        return dp[n];
    }
    // First time for this n: do the work once, and write it down before
    // returning, so no later call ever repeats it.
    dp[n] = fib(n-1) + fib(n-2);
    return dp[n];
}

// Why the count collapses. In fibonacci_recursion.cpp fib(40) made about 331
// million calls. Here each value 2..n can reach the two-call line only once -
// every later visit is stopped by the dp check - so there are at most 2n-2 calls
// beyond the first, fewer than 100 for n = 40. The cost drops from about 1.6^n
// to O(n) time and O(n) memory: the array plus a call stack n deep on the first
// descent.

int main(){
    // Mark every box "not worked out yet". memset fills BYTES, and the byte
    // 11111111 makes the int -1 as well, so this genuinely stores -1 everywhere.
    // -1 is a safe marker because a Fibonacci number is never negative, so it can
    // never be confused with a real answer.
    // Leaving this line out would be a silent disaster, not a crash: a global
    // array starts as all zeros, and 0 != -1, so every fib(n) would be "found" in
    // the notebook and the program would print 0 for everything.
    // (memset belongs to <cstring>, which this file does not include; it only
    // compiles because another header brings it in.)
    memset(dp, -1, sizeof(dp));
    int n;
    cin >> n;
    cout << fib(n) << endl;

    return 0;
}