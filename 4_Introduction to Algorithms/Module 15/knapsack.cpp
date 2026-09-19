// 0-1 KNAPSACK, the plain recursive version.
//
// The problem: a bag that can carry max_weight kilos, and n items, each with a
// weight and a value. Pack the bag so the total value is as large as possible.
// "0-1" means each item goes in whole or stays out whole - no halves, and no
// taking the same item twice.
//
// The idea is the same "make a choice, keep the better result" shape that runs
// through the whole module. Look at the last item and ask one question: do I take
// it or leave it?
//   * take it   -> I gain its value, but lose weight[i] kilos of room, and the
//                  item is gone, so the rest of the packing uses items 0..i-1.
//   * leave it  -> I gain nothing, keep all my room, and again carry on with
//                  items 0..i-1.
// Either way the leftover problem is the same KIND of problem, just smaller, so
// the function can call itself. Try both, keep the bigger answer.
//
// No table here: this file is the slow starting point, the way
// fibonacci_recursion.cpp was in Module 14. knapsack_using_dp.cpp adds the table.

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

// Global so every recursive call can read them without passing them around.
int val[1005], weight[1005];

// The two arguments ARE the state of the problem:
//   i          = the highest item still allowed (items 0..i are on offer)
//   max_weight = how many kilos of room are left in the bag right now
// The return value is the best total value reachable from that situation.
int knapsack(int i, int max_weight){
    // Two ways to be finished, and both are worth 0:
    //   i < 0            - no items left to consider
    //   max_weight <= 0  - the bag is full, nothing more will fit
    // Without these the calls would never stop.
    if(i < 0 || max_weight <= 0){
        return 0;
    }

    if(weight[i] <= max_weight){ // when we still have space in the bag, we can either take 
        // the current item or not
        // op1 = TAKE item i. Bank val[i], use the item up (so the next call may
        // only choose among 0..i-1), and lose weight[i] kilos of room.
        int op1 = knapsack(i-1, max_weight - weight[i]) + val[i]; // taking the current item
        // op2 = LEAVE item i. Bank nothing, keep all the room, same items 0..i-1.
        int op2 = knapsack(i-1, max_weight); // not taking the current item
        // Whichever turned out better is the answer for this state.
        return max(op1, op2);
    } else{
        // Item i does not fit in the room that is left, so there is no choice to
        // make: leaving it is the only legal move.
        return knapsack(i-1, max_weight);
    }

    // Why this is slow: every item that fits splits into two calls, so the calls
    // form a tree that nearly doubles at each level - O(2^n). And as in plain
    // Fibonacci the work is repeated: taking item 3 and leaving item 2 lands on
    // the same (i, w) state as leaving 3 and taking 2, and each is worked out
    // from scratch. Remembering states is the fix, and that is the next file.
}

int main(){
    int n, max_weight;
    cin >> n;
    
    // Input order here: n, then all n values, then all n weights, then the bag
    // capacity. (codeforces_knapsack.cpp reads the judge's order instead.)
    for(int i=0; i<n; i++){
        cin >> val[i];
    }
    for(int i=0; i<n; i++){
        cin >> weight[i];
    }
    cin >> max_weight;

    // Start from the LAST item with the bag empty; the recursion works its way
    // down to item 0.
    // BUG, left in place: the answer is computed and then thrown away - there is
    // no cout, so this program prints nothing at all. For the sample input the
    // answer would be 90 (the weight-3 and weight-5 items, 30 + 60).
    // The fix is to wrap the call: cout << knapsack(n-1, max_weight) << endl;
    knapsack(n-1, max_weight);

    return 0;
}