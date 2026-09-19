// SUBSET SUM: given n numbers, is there some group of them that adds up exactly
// to a given target?
//
// This is knapsack (Module 15) with the question changed. The shape is identical
// - walk through the items, and for each one decide TAKE IT or LEAVE IT - but
// instead of "how much value can I pile up?" the question is now "can I land on
// this number exactly?", so the answer is a yes/no rather than a total.
//
// As in Module 15, this first file is the plain recursion with nothing
// remembered; subset_sum_using_dp.cpp adds the table.

#include <iostream>
#include <vector>
#include <algorithm>    
#include <string>

using namespace std;
// The numbers, global so every recursive call can read them.
// Note carefully: main declares its own val as well, which is the bug this file
// is known for - see the comment down there.
int val[1005];

// The two arguments are the whole state:
//   i   = the highest item still on offer (items 0..i may still be used)
//   sum = how much of the target is STILL TO BE MADE, not how much is made so
//         far. Taking an item lowers it; reaching 0 means the target is met.
bool subset_sum(int i, int sum){ // O(2^n)
    // Ran out of items. This is a success only if nothing is left to make.
    // If sum is still positive the chosen group falls short, so: false.
    if(i<0){
        if(sum == 0){
            return true;
        } else{
            return false;
        }
    }
    // Item i can only be taken if it does not overshoot what is left. (This
    // assumes the numbers are not negative, which subset sum normally does.)
    if(val[i] <= sum){
        // op1 = TAKE item i: the remaining target shrinks by val[i], and the item
        // is used up, so only 0..i-1 are left to choose from.
        bool op1 = subset_sum(i-1, sum-val[i]);
        // op2 = LEAVE item i: the target is untouched, items 0..i-1 remain.
        bool op2 = subset_sum(i-1, sum);
        // Either route reaching the target is enough, hence OR - where knapsack
        // used max() because it wanted the better of two totals.
        return op1 || op2;
    }
    else{
        // Too big to take, so leaving it is the only move.
        return subset_sum(i-1, sum);
    }

    // Cost: two branches per item, so up to 2^n calls, and the same (i, sum)
    // pairs come up again and again on different branches. The next file fixes
    // that with a table.
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
    // Small blemish: "YES\n" already ends the line and endl ends it again, so the
    // output carries a stray blank line. One or the other is enough.
    if(subset_sum(n-1, sum)){
        cout << "YES\n" << endl;
    } else{
        cout << "NO\n" << endl;
    }

    return 0;
}