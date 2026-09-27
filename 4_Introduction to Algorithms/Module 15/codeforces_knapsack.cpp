// Codeforces Group - U. Knapsack
// https://codeforces.com/group/MWSDmqGsZm/contest/223339/problem/U
//
// The same memoized 0-1 knapsack as knapsack_using_dp.cpp; see that file for what
// dp[i][w] means and why the recursion looks the way it does. The only real
// difference is the input format, which follows the judge:
//     first line   N W          (how many items, and the bag's capacity)
//     next N lines weight value (one pair per item, weight FIRST)
// - where knapsack_using_dp.cpp read all the values, then all the weights, then
// the capacity. Getting this order wrong is the usual way to fail such a problem
// with otherwise correct code.
//
// The DP in brief (this file stands alone, so here it is):
//   meaning     dp[i][w] = best total value using only items 0..i with w kilos
//               of room left
//   base cases  no items left (i < 0) or no room (w <= 0) -> 0
//   transition  dp[i][w] = max(val[i] + dp[i-1][w - weight[i]],  (take i)
//                              dp[i-1][w])                       (leave i)
//               and only the "leave" option if item i does not fit.
// Sample: 3 8 / (3,30) (4,50) (5,60) -> best is items of weight 3 and 5 = 90.
// This file prints 0 because of the BUG in main (see below).

#include <iostream>     // cin, cout, endl
#include <vector>       // not used here
#include <algorithm>    // max
#include <string>       // not used here

using namespace std;    // no std:: prefix

int val[1005], weight[1005];   // val[i], weight[i] = value and weight of item i

// The notebook. dp[i][w] is the answer to exactly one question: "using only items
// 0..i, with w kilos of room left, what is the best value I can reach?" - the two
// indexes are the two arguments of knapsack(), nothing else. -1 means "not worked
// out yet" (safe, because a value total is never negative).
// 1005 x 1005 ints is about 4 MB, far too big for the stack, so it is global.
int dp[1005][1005];

// Same take-or-leave recursion as knapsack.cpp, with the dp notebook added.
//   i          = the highest item still allowed (items 0..i are on offer)
//   max_weight = how many kilos of room are left in the bag right now
// Returns the best total value reachable from that situation.
int knapsack(int i, int max_weight){
    // Nothing left to offer, or no room left: the best you can do is take
    // nothing, which is worth 0.
    if(i < 0 || max_weight <= 0){   // base case
        return 0;
    }

    // Seen this exact (item, room) pair before? Then the answer is already known.
    // This is the line that turns 2^n into n x W: the plain recursion reaches the
    // same (i, w) pair over and over on different branches, and now every repeat
    // stops here.
    if(dp[i][max_weight] != -1){    // already solved?
        return dp[i][max_weight];   // reuse the stored answer
    }

    if(weight[i] <= max_weight){ // when we still have space in the bag, we can either take 
        // the current item or not
        // op1 = TAKE item i. Its value is banked, item i is used up so the next
        // call may only use 0..i-1, and the room drops by weight[i].
        int op1 = knapsack(i-1, max_weight - weight[i]) + val[i]; // taking the current item
        // op2 = LEAVE item i. Nothing banked, same room, items 0..i-1 remain.
        int op2 = knapsack(i-1, max_weight); // not taking the current item
        // Keep whichever choice ended up better, and write it down before
        // returning so this state is never recomputed.
        dp[i][max_weight] = max(op1, op2);   // remember the better choice
        return dp[i][max_weight];
    } else{
        // Item i is heavier than the room left, so there is no choice to make:
        // leaving it is the only legal move. Still worth storing.
        dp[i][max_weight] = knapsack(i-1, max_weight);   // only "leave" is possible
        return dp[i][max_weight];
    }
}

int main(){
    int n, max_weight;             // number of items, bag capacity W

    cin >> n >> max_weight;        // first line: N W

    // One line per item, weight before value - the judge's order.
    for(int i=0; i<n; i++){
        cin >> weight[i];          // weight of item i
        cin >> val[i];             // value of item i
    }

    // Mark every state "not solved yet".
    //
    // BUG, left in place: the inner loop stops at j < max_weight, so the column
    // j == max_weight is never touched. dp is global, so those boxes still hold 0
    // from program start. The very first call made below is
    // knapsack(n-1, max_weight) - which looks up dp[n-1][max_weight], finds 0
    // instead of -1, decides the state is already solved, and returns 0 without
    // doing any work at all. That is why this program prints 0 instead of 90.
    // One character fixes it: j <= max_weight.
    // -1 is the "not solved yet" marker: a real best value is never negative,
    // so -1 can never be confused with a stored answer. (0 would be a bad
    // marker - 0 IS a real answer when nothing fits.)
    for(int i=0; i<n; i++){                    // every item index 0..n-1
        for(int j=0; j<max_weight; j++){       // BUG: should be j <= max_weight - column max_weight stays 0
            dp[i][j] = -1;
        }
    }

    // Start with every item on offer (0..n-1) and the full capacity.
    cout << knapsack(n-1, max_weight) << endl; // BUG: prints 0 because dp[n-1][max_weight] was never set to -1

    return 0;   // success
}