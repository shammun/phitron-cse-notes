// Subset sum with MEMOIZATION. Identical recursion to subset_sum.cpp, with the
// state (i, sum) used as the address of a table cell, so each distinct question
// is answered once. Cost drops from O(2^n) to O(n x sum).
//
// Read subset_sum.cpp first; mostly the table is new here.
//
// The DP in three parts:
//   meaning     dp[i][s] = can some subset of items 0..i add up to exactly s?
//   base case   i < 0 (no items left): yes only if s == 0
//   transition  dp[i][s] = dp[i-1][s - val[i]] (take, if val[i] <= s)
//                          OR dp[i-1][s]       (leave)
// Example: numbers 6 2 3, target 5 -> YES (2 + 3). This program prints NO
// because of the BUG in main.

#include <iostream>     // cin, cout, endl
#include <vector>       // not used here
#include <algorithm>    // not used here
#include <string>       // not used here

using namespace std;    // no std:: prefix
int val[1005];          // the numbers (global; read by subset_sum)
// dp[i][s] answers exactly one question: "using only items 0..i, can I still make
// s?" The two indexes are the two arguments of subset_sum(), nothing else.
// A bool fits in this int table because true and false are stored as 1 and 0,
// which leaves -1 free to mean "not worked out yet".
int dp[1005][1005];

//   i   = highest item still on offer
//   sum = how much of the target is still to be made
bool subset_sum(int i, int sum){ // O(N * sum)
    if(i<0){                 // base case: no items left
        if(sum == 0){
            return true;     // target met exactly
        } else{
            return false;    // still short
        }
    }
    // Answered before? Hand the saved answer back and make no calls. This is the
    // line that collapses the branching tree: there are only n x (sum+1) distinct
    // states, so that is the most work that can ever be done.
    if(dp[i][sum] != -1){
        return dp[i][sum];
    }
    if(val[i] <= sum){
        // op1 = TAKE item i (target shrinks by val[i], items 0..i-1 remain).
        bool op1 = subset_sum(i-1, sum-val[i]);
        // op2 = LEAVE item i (target unchanged, items 0..i-1 remain).
        bool op2 = subset_sum(i-1, sum);
        // Write the answer down before returning, so this state is never redone.
        dp[i][sum] = op1 || op2;
        return dp[i][sum];
    }
    else{
        // Too big to take; only the leave branch is legal. Still worth storing.
        dp[i][sum] = subset_sum(i-1, sum);
        return dp[i][sum];
    }
}

int main(){
    int n;              // how many numbers

    cin >> n;
    // BUG, left in place. This declares a SECOND array called val, local to main.
    // Inside main the name val now means this local one, so the loop below fills
    // it - while subset_sum() above still reads the global val[1005], which stays
    // all zeros. The function therefore answers a question about n zeros, and the
    // only target it can reach is 0. That is why the program prints NO for input
    // that plainly has an answer.
    // The fix is to delete this one line, so that the input lands in the global
    // array the function actually reads.
    int val[n];         // BUG: shadows the global val - delete this line
    for(int i=0; i<n; i++){
        cin >> val[i];  // fills the LOCAL array only
    }

    int sum;            // the target
    cin >> sum;

    // Mark every state "not worked out yet". Both loops use <=, so the column
    // j == sum is included - and that matters, because the very first call asks
    // about exactly that column. (Module 15's knapsack_using_dp.cpp used < here
    // and got 0 for its trouble.)
    for(int i=0; i<=n; i++){
        for(int j=0; j<=sum; j++){
            dp[i][j] = -1;
        }
    }

    // Small blemish: "YES\n" already ends the line and endl ends it again, so the
    // output carries a stray blank line. One or the other is enough.
    if(subset_sum(n-1, sum)){       // all items on offer, full target
        cout << "YES\n" << endl;
    } else{
        cout << "NO\n" << endl;
    }

    return 0;   // success
}