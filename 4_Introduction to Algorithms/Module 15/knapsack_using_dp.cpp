// 0-1 knapsack with MEMOIZATION - knapsack.cpp plus a notebook, exactly the step
// fibonacci_with_memoization.cpp took in Module 14.
//
// The recursion is unchanged. What is new is that its state - the pair
// (item index i, room left w) - is used as an address into a 2D table, so each
// distinct situation is solved once and looked up ever after. There are only
// n x (max_weight + 1) different situations, so the cost falls from O(2^n) to
// O(n x W).
//
// Read this file next to knapsack.cpp; the comments here cover only what is new.

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int val[1005], weight[1005];

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
    if(i < 0 || max_weight <= 0){
        return 0;
    }

    // Seen this exact (item, room) pair before? Then the answer is already known.
    // This is the line that turns 2^n into n x W: the plain recursion reaches the
    // same (i, w) pair over and over on different branches, and now every repeat
    // stops here.
    if(dp[i][max_weight] != -1){
        return dp[i][max_weight];
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
        dp[i][max_weight] = max(op1, op2);
        return dp[i][max_weight];
    } else{
        // Item i is heavier than the room left, so there is no choice to make:
        // leaving it is the only legal move. Still worth storing.
        dp[i][max_weight] = knapsack(i-1, max_weight);
        return dp[i][max_weight];
    }
}

int main(){
    int n, max_weight;

    cin >> n;
    
    for(int i=0; i<n; i++){
        cin >> val[i];
    }
    for(int i=0; i<n; i++){
        cin >> weight[i];
    }
    cin >> max_weight;

    // Mark every state "not solved yet".
    //
    // BUG, left in place: the inner loop stops at j < max_weight, so the column
    // j == max_weight is never touched. dp is global, so those boxes still hold 0
    // from program start. The very first call made below is
    // knapsack(n-1, max_weight) - which looks up dp[n-1][max_weight], finds 0
    // instead of -1, decides the state is already solved, and returns 0 without
    // doing any work at all. That is why this program prints 0 instead of 90.
    // One character fixes it: j <= max_weight.
    for(int i=0; i<n; i++){
        for(int j=0; j<max_weight; j++){
            dp[i][j] = -1;
        }
    }

    cout << knapsack(n-1, max_weight) << endl;

    return 0;
}