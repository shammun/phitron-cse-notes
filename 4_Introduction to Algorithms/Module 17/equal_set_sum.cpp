// EQUAL SUM PARTITION: can the n numbers be split into two groups with the same
// total?
//
// The insight that makes this easy: the two groups together are the whole array,
// so each must add up to total / 2. Which means:
//   * an odd total is hopeless - halves of it are not whole numbers, so NO;
//   * an even total is a subset-sum question in disguise. If some subset reaches
//     total / 2 then whatever is left over reaches total / 2 as well, and the
//     split exists.
// So the only new code is in main; subset_sum() below is exactly the memoized
// version from subset_sum_using_dp.cpp.

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int val[1005];
// dp[i][s] = "using only items 0..i, can s still be made?" -1 means unknown.
int dp[1005][1005];

//   i   = highest item still on offer
//   sum = how much of the target is still to be made
bool subset_sum(int i, int sum){
    if(i < 0){
        if(sum == 0){
            return true;
        } else{
            return false;
        }
    }

    if(dp[i][sum] != -1){
        return dp[i][sum];
    }

    if(val[i] <= sum){
        // op1 = TAKE item i; op2 = LEAVE it. Either route is good enough.
        bool op1 = subset_sum(i-1, sum-val[i]);
        bool op2 = subset_sum(i-1, sum);
        dp[i][sum] = op1 || op2;
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
    int sum = 0;
    // BUG 1, left in place. A second array named val, local to main. Inside main
    // the name now refers to this one, so the loop below fills it - while
    // subset_sum() above goes on reading the global val[1005], which stays all
    // zeros. Deleting this single line makes the function see the real numbers.
    int val[n];

    // Read the numbers and add up the total in the same pass.
    for(int i = 0; i < n; i++){
        cin >> val[i];
        sum += val[i];
    }


    // An odd total can never be cut into two equal whole halves.
    if(sum %2 != 0){
        cout << "NO\n";
        return 0;
    } else{

        // The real target: reach exactly half the total.
        int half = sum / 2;

        // Only the columns 0..half are ever needed, so only those are marked
        // unknown. That is correct - as long as nothing asks about a bigger
        // target, which is exactly what goes wrong on the next line.
        for(int i = 0; i < n; i++){
            for(int j = 0; j <= half; j++){
                dp[i][j] = -1;
            }
        }

        // BUG 2, left in place: this passes the FULL total, not half of it. Two
        // things then go wrong at once. The question asked is "can some subset
        // add up to the whole total?", which is not the question at all; and
        // dp[n-1][sum] was never set to -1 by the loop above, so it still holds
        // the global 0, the memo check reads it as a stored "false", and the
        // function returns straight away without looking at a single item.
        // The line should read subset_sum(n-1, half).
        if(subset_sum(n-1, sum)){
            cout << "YES\n";
        } else{
            cout << "NO\n";
        }
    }
}