/*

https://codeforces.com/group/MWSDmqGsZm/contest/223339/problem/U

Knapsack

There are N  items numbered from 1 to N. The ith item has a weight of wi and a value of vi.

You have to choose some items out of the N  items and carry them home in a knapsack. The capacity 
of the knapsack is W which donate the maximum weight that can be carried inside the knapsack. In 
other words, W means the total summation of all weights of items that can be carried in the 
knapsack.

Print maximum possible sum of values of items that you can take home.

Note: Solve this problem using recursion.

Input
First line contains two numbers N and W (1≤N≤20,1≤W≤100) number of items and the capacity of the 
knapsack.

Next N lines will contain two numbers wi and vi (1≤wi≤50,1≤vi≤1000)

Output
Print maximum possible sum of values of items that you can take home.

Examples

Input
3 8
3 30
4 50
5 60

Output
90

Input
6 15
6 5
5 6
6 4
6 6
3 5
7 2

Output
17

*/

// The practice-day copy of codeforces_knapsack.cpp: the same memoized 0-1
// knapsack, re-typed. Only small things differ: the arrays are sized from the
// constraints (N <= 20, W <= 100) instead of 1005, and the values live in
// value[] instead of val[]. See codeforces_knapsack.cpp for the full walk-through.

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

int weight[25], value[25];   // N <= 20 items
int dp[25][105];             // dp[i][w] = best value from items 0..i with w room; -1 = unknown

int knapsack(int i, int max_weight){
    // No items left or no room left: nothing more can be gained.
    if(i < 0 || max_weight <= 0){
        return 0;
    }

    // Already solved this (item, room) state.
    if(dp[i][max_weight] != -1){
        return dp[i][max_weight];
    }

    if(weight[i] <= max_weight){
        // Item i fits: try both choices and keep the better one.
        int op1 = knapsack(i-1, max_weight - weight[i]) + value[i]; // taking the current item
        int op2 = knapsack(i-1, max_weight); // not taking the current item
        dp[i][max_weight] = max(op1, op2);
        return dp[i][max_weight];
    } else{
        // Too heavy: leaving it is the only option.
        dp[i][max_weight] = knapsack(i-1, max_weight);
        return dp[i][max_weight];
    }
}

int main(){
    int n, max_weight;
    cin >> n >> max_weight;

    for(int i=0; i<n; i++){
        cin >> weight[i] >> value[i];   // judge order: weight, then value
    }

    // Mark every state "not solved yet".
    // BUG, the same one as in codeforces_knapsack.cpp and knapsack_using_dp.cpp:
    // j < max_weight leaves the column j == max_weight at the global 0, so the
    // first call knapsack(n-1, max_weight) thinks it is already solved and the
    // program prints 0. The fix is j <= max_weight (done in Module 16).
    for(int i=0; i<n; i++){
        for(int j=0; j<max_weight; j++){
            dp[i][j] = -1;
        }
    }

    cout << knapsack(n-1, max_weight) << endl;

    return 0;
}
