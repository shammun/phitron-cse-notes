// Fibonacci a third time: BOTTOM-UP dynamic programming, also called tabulation.
//
// Memoization worked top-down - ask for fib(n), and the recursion dug downwards
// until it hit values it already knew. But look at what it actually ended up
// storing: dp[0], dp[1], dp[2], ... every box from the bottom up, and dp[i] never
// depends on anything above i. So the digging is unnecessary. Start at the bottom
// and walk upwards with a plain loop, and by the time i is reached the two values
// it needs are already sitting in the table.
//
// Same O(n) time, same table, but no recursion at all: no call stack, no risk of
// a stack overflow, and no function-call overhead. In exchange you have to work
// out the filling order yourself, which the recursion used to do for you.

#include <iostream>
#include <vector>
#include <algorithm>    
#include <string>

using namespace std;

int main(){
    int n;
    cin >> n;
    // Boxes 0..n, so n+1 of them - fibo[n] is the answer being asked for.
    // BUG, left in place: the two lines below always write fibo[1]. For n = 0 the
    // array has just one box, fibo[0], so fibo[1] is out of bounds. Sizing it
    // fibo[n+2], or handling n = 0 on its own, would fix it.
    int fibo[n+1];

    // The two values the definition gives outright - the same two base cases the
    // recursive version returned from, only written into the table instead.
    fibo[0] = 0;
    fibo[1] = 1;

    // Fill upwards from 2. Going in this direction is what makes the loop legal:
    // when i is reached, i-1 and i-2 are smaller, so they were filled on earlier
    // turns and are ready to be read. Run the loop downwards and it would be
    // reading boxes that nothing has written yet.
    // `i <= n` and not `i < n`, because fibo[n] itself is the answer wanted.
    for(int i=2; i<=n; i++){
        fibo[i] = fibo[i-1] + fibo[i-2];
    }

    // Only fibo[i-1] and fibo[i-2] are ever read, so the whole array is not
    // really needed: two variables, updated as the loop turns, would give the
    // same answer in O(1) memory.

    cout << fibo[n] << endl;
    return 0;
}