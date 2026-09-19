// Counting instead of deciding: HOW MANY subsets add up to the target?
//
// The recursion is exactly subset_sum_using_dp.cpp with three small changes, and
// they are worth noticing because the same trick turns many yes/no DPs into
// counting DPs:
//   * the return type is int - a count, not a bool;
//   * the base case returns 1 for a success (one valid subset found) and 0 for a
//     failure, instead of true and false;
//   * the two branches are ADDED instead of OR-ed. Take-it and leave-it can never
//     produce the same subset, so no subset is counted twice.
//
// Note the count is of subsets by POSITION, not by content: values 1 1 1 with
// target 2 give 3, because the three 1s sit at three different indexes.

#include <iostream>
#include <vector>
#include <algorithm>    
#include <string>

using namespace std;
int val[1005];
// dp[i][s] = how many subsets of items 0..i add up to exactly s.
// The two indexes are the two arguments of subset_sum(); -1 marks "not counted
// yet", and is safe because a count is never negative.
int dp[1005][1005]; 

//   i   = highest item still on offer
//   sum = how much of the target is still to be made
// Returns the number of ways to finish from here.
int subset_sum(int i, int sum){ // O(N * sum)
    // Out of items: exactly one way (the empty choice) if nothing is left to
    // make, and no way at all otherwise.
    if(i<0){
        if(sum == 0){
            return 1;
        } else{
            return 0;
        }
    }
    // Counted this state before? Reuse it.
    if(dp[i][sum] != -1){
        return dp[i][sum];
    }
    if(val[i] <= sum){
        // op1 = ways that TAKE item i (target shrinks, items 0..i-1 remain).
        int op1 = subset_sum(i-1, sum-val[i]);
        // op2 = ways that LEAVE item i (target unchanged, items 0..i-1 remain).
        int op2 = subset_sum(i-1, sum);
        // Every subset either contains item i or does not, so the two piles do
        // not overlap and may simply be added.
        dp[i][sum] = op1 + op2;
        return dp[i][sum];
    }
    else{
        dp[i][sum] = subset_sum(i-1, sum);
        return dp[i][sum];
    }
}

int main(){
    int n;

    cin >> n;
    // BUG, left in place. This declares a SECOND array called val, local to main.
    // Inside main the name val now means this local one, so the loop below fills
    // it - while subset_sum() above still reads the global val[1005], which stays
    // all zeros. The function therefore answers a question about n zeros, and the
    // only target it can reach is 0. That is why the program prints NO for input
    // that plainly has an answer.
    // The fix is to delete this one line, so that the input lands in the global
    // array the function actually reads.
    int val[n];
    for(int i=0; i<n; i++){
        cin >> val[i];
    }

    int sum;
    cin >> sum;

    // Mark every state as uncounted. Both bounds are <=, so the column j == sum
    // that the first call needs really is set to -1.
    for(int i=0; i<=n; i++){
        for(int j=0; j<=sum; j++){
            dp[i][j] = -1;
        }
    }

    cout << subset_sum(n-1, sum) << endl; // n-1 as we are starting from the last index and
    // n is the size of the array

    return 0;
}