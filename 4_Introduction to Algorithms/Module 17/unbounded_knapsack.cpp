// UNBOUNDED KNAPSACK: the same bag and the same items as Module 15, except that
// each item may now be taken as many times as you like - think of coins, or of a
// shop with unlimited stock, rather than n one-off objects.
//
// Astonishingly, one token changes 0-1 knapsack into this. In the take branch,
// 0-1 knapsack moved on with knapsack(i-1, ...) because the item was used up;
// here it stays at knapsack(i, ...), so item i is still on offer and can be
// taken again. The leave branch still moves to i-1 - otherwise the recursion
// would never work its way down to the base case.
//
// The state is still (i, room left) and the table is still n x (W+1), so the cost
// stays O(n x W) even though far more combinations are now allowed.

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int val[1005], weight[1005];
// dp[i][w] = "with items 0..i available (each unlimited) and w kilos of room,
// what is the best value?" -1 means not worked out yet.
int dp[1005][1005];

//   i          = the highest item still on offer (0..i, each available freely)
//   max_weight = how many kilos of room are left
int knapsack(int i, int max_weight){
    // No items left, or no room left: nothing more can be gained.
    if(i < 0 || max_weight <= 0){
        return 0;
    }

    if(dp[i][max_weight] != -1){
        return dp[i][max_weight];
    }

    if(weight[i] <= max_weight){ // when we still have space in the bag, we can either take 
        // the current item or not
        // op1 = TAKE one copy of item i. Bank val[i], lose weight[i] of room -
        // and note the i, not i-1: item i is still available, so the very next
        // call may take it again. This single character is the whole difference
        // from 0-1 knapsack.
        int op1 = knapsack(i, max_weight - weight[i]) + val[i]; // taking the current item
        // op2 = have no more of item i at all, and move on to items 0..i-1. This
        // is the branch that makes the recursion shrink and eventually stop.
        int op2 = knapsack(i-1, max_weight); // not taking the current item
        dp[i][max_weight] = max(op1, op2);
        return dp[i][max_weight];
    } else{
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

    // BUG, left in place - the same one as Module 15's knapsack_using_dp.cpp.
    // The inner loop stops at j < max_weight, so the column j == max_weight keeps
    // the global starting value 0 instead of -1. The first call made below is
    // knapsack(n-1, max_weight), whose memo check reads that 0, takes it for a
    // finished answer and returns 0 without doing anything. That is why this
    // program prints 0 rather than 35. Fix: j <= max_weight.
    for(int i=0; i<n; i++){
        for(int j=0; j<max_weight; j++){
            dp[i][j] = -1;
        }
    }

    cout << knapsack(n-1, max_weight) << endl;

    return 0;
}