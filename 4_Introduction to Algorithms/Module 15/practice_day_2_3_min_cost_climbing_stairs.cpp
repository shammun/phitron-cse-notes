/*

https://leetcode.com/problems/min-cost-climbing-stairs/description/

746. Min Cost Climbing Stairs

You are given an integer array cost where cost[i] is the cost of ith step on a staircase. Once 
you pay the cost, you can either climb one or two steps.

You can either start from the step with index 0, or the step with index 1.

Return the minimum cost to reach the top of the floor.

 

Example 1:

Input: cost = [10,15,20]
Output: 15
Explanation: You will start at index 1.
- Pay 15 and climb two steps to reach the top.
The total cost is 15.

Example 2:

Input: cost = [1,100,1,1,1,100,1,1,100,1]
Output: 6
Explanation: You will start at index 0.
- Pay 1 and climb two steps to reach index 2.
- Pay 1 and climb two steps to reach index 4.
- Pay 1 and climb two steps to reach index 6.
- Pay 1 and climb one step to reach index 7.
- Pay 1 and climb two steps to reach index 9.
- Pay 1 and climb one step to reach the top.
The total cost is 6.
 

Constraints:

- 2 <= cost.length <= 1000
- 0 <= cost[i] <= 999

*/

// Solution idea (bottom-up DP with two variables).
// Let best(i) = the cheapest cost to stand on step i ("the top" is step n).
// You arrive at i either from i-1 (paying cost[i-1]) or from i-2 (paying
// cost[i-2]), so best(i) = min(best(i-2) + cost[i-2], best(i-1) + cost[i-1]).
// Steps 0 and 1 are free starting points: best(0) = best(1) = 0.
// Each value only needs the two before it, so two variables replace the table.

class Solution {
    public:
        int minCostClimbingStairs(vector<int>& cost) {
            int n = cost.size();

            // Edge cases (LeetCode promises n >= 2, so these never fire there)
            if(n==0) return 0;
            if(n==1) return cost[0];

            int first = 0;    // best(i-2)
            int second = 0;   // best(i-1)

            for(int i=2; i<=n; i++){
                // Two ways onto step i; keep the cheaper.
                int current = min(first + cost[i-2], second + cost[i-1]);
                // Slide the window one step up.
                first = second;
                second = current;
            }

            return second;   // best(n): standing on the top
            // Cost: O(n) time, O(1) memory.
        }
    };
