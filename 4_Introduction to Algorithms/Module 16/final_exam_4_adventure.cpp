/*

https://www.hackerrank.com/contests/final-exam-a-introduction-to-algorithms-a-batch-06/challenges/adventure-1

Adventure

Problem Statement

Once upon a time, there was a treasure hunter who ventured into an ancient temple in search of a 
valuable artifact. The temple was filled with traps and obstacles, and the treasure hunter had to 
carry all of his equipment with him.

The treasure hunter had a backpack with a limited weight capacity, and he could only carry a 
certain amount of equipment with him. Each piece of equipment had its own weight and value, and 
the treasure hunter needed to choose which items to bring to maximize the total value while 
keeping the total weight under the limit.

Help the treasure hunter to choose which items to bring in his backpack to maximize their total 
value while keeping the total weight of his backpack under a certain limit. Each item can only be 
included once.

Input Format

- First line will contain T, the number of test cases.
- The first line of each test case will contain N(Number of items) and W(Total weight of backpack).
- Second line of each test case will contain an array w containing the weights of all items.
- Third line of each test case will contain an array v containting the values of all items.

Constraints
1. 1 <= T <= 10^3
2. 1 <= N <= 10^3
3. 1 <= W <= 10^3
4. 0 <= w[i] <= 10^3; Here 0 <= i < N
5. 0 <= v[i] <= 10^3; Here 0 <= i < N;

Output Format
- Output the maximum total value you can obtain in the backpack for each test case.

Sample Input 0
2
4 7
2 3 4 5
4 7 6 5
4 17
10 1 6 9
6 10 10 8

Sample Output 0
13
28

Explanation 0
In the first test case case, he can take 2nd and 3rd item which total weight is 3+4=7 and total 
value is 7+6=13 and its the maximum value possible.

*/

// Solution idea: this is the 0-1 knapsack of Module 15 (knapsack_using_dp.cpp)
// with a story around it. For item i there are two choices: take it (if it
// fits) and add its value, or skip it. knapsack(i, W) = best value using items
// 0..i with W weight left; dp[][] remembers every answer so each state is
// solved once.

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cstring>

using namespace std;

int val[1005], weight[1005];
int dp[1005][1005];   // dp[i][w] = knapsack(i, w), or -1 if not computed yet

int knapsack(int i, int max_weight){
    // Base case: no items left to look at, or no room left in the bag.
    if(i < 0 || max_weight == 0){
        return 0;
    }

    // Already solved this exact state (same item, same room left)? Reuse it.
    if(dp[i][max_weight] != -1){
        return dp[i][max_weight];
    }

    if(weight[i] <= max_weight){
        // Item i fits, so both choices are open.
        // op1: take it - earn val[i], lose weight[i] of room, move on to item i-1.
        int op1 = knapsack(i-1, max_weight - weight[i]) + val[i];
        // op2: leave it - same room, move on to item i-1.
        int op2 = knapsack(i-1, max_weight);
        dp[i][max_weight] = max(op1, op2);
        return dp[i][max_weight];
    } else {
        // Item i is too heavy for the room left: skipping is the only choice.
        dp[i][max_weight] = knapsack(i-1, max_weight);
        return dp[i][max_weight];
    }
}

int main(){
    int t;
    cin >> t;

    while(t--){
        int n, max_weight;
        cin >> n >> max_weight;

        // Note the input order: all the weights first, then all the values.
        for(int i=0; i<n; i++){
            cin >> weight[i];
        }

        for(int i=0; i<n; i++){
            cin >> val[i];
        }

        // Reset the part of dp this test case uses to "unknown".
        // Answers left over from the previous case belong to different items.
        for(int i=0; i<n; i++){
            for(int j=0; j<=max_weight; j++){
                dp[i][j] = -1;
            }
        }

        // Start from the last item with the full capacity.
        // Sample 1: weights 2 3 4 5, values 4 7 6 5, W = 7 -> take the 3 and the 4 -> 13.
        cout << knapsack(n-1, max_weight) << endl;
    }
    // At most N * (W+1) states with O(1) work each: O(N * W) per test case.
}
