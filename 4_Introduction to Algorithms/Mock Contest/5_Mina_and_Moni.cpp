/*

Problem Statement

Mina and Moni are two sisters who share a deep bond of love, and they extend this love even to their food. They have a habit of 
splitting everything equally between them. One fine day, their father gave them a total of  coins and asked them to divide it 
amongst themselves. However, there's a twist - the coins they received are not of equal value; they can have different 
denominations. This presents a challenge because there is no guarantee that they can divide the coins equally.

So, Mina and Moni devised a plan to divide the coins in a way that minimizes the difference between the sums of the coins they 
receive. They agreed that each of them should get  coins (if  is even). In case  is odd, one of them will receive an extra coin. 
However, they are not sure how to execute this plan efficiently. Can you help them achieve their goal?

For example: Let's consider a scenario where their father gives them 8 coins with the following denominations: 23, 45, 34, 12, 
0, 3, 1, and 4. They can divide these coins among themselves in the following manner:

Mina: 45, 12, 3, 1
Moni: 23, 34, 0, 4
In this division, both Mina and Moni receive subsets of equal size, each containing 4 coins. Remarkably, the sum of coins in 
both parts is identical, amounting to 61 for each of them. Consequently, the minimum difference in the sum of coins between the 
two parts is 0.

This example illustrates their strategy for dividing the coins, ensuring that the difference in the sum of coins is minimized.

Input Format

First line will contain an integer T, the number of test cases.
For each test case, the first line will contain an integer N - number of coins need to be divided.
For each test case, the second line will contain the value (Ei) of the coins.
Constraints

Output Format

For each test case, output a single line - the minimum difference described in the statement.

Sample Input 0

3
8
23 45 34 12 0 3 1 4
5
10 20 30 40 50
4
1 2 3 10
Sample Output 0

0
10
6
Explanation 0

The first test case was explained in the problem statement. For the second test case, one possible answer is Mina takes 
{10,30,40} and Moni takes {20,50}. For the third test case, one possible answer is Mina take {1,10} and Moni takes {2,3}


*/

// Solution idea: subset sum (Module 17) with one extra condition - the size.
// Mina must get exactly k = N / 2 coins (Moni gets the rest). If Mina's coins
// add up to s, Moni's add up to total - s, and the difference is
// |total - 2s|. So we need to know every sum s that EXACTLY k coins can make,
// and then pick the s that makes |total - 2s| smallest.
//
// The table reach[c][s] = "can some c of the coins seen so far add up to s?"
// is built one coin at a time, like the "which totals are reachable" table of
// Module 17: for each new coin, every old answer stays true (skip the coin),
// and every old true at (c-1, s-v) makes (c, s) true (take the coin).
//
// Example 1 2 3 10: k = 2, total = 16. Two coins can make 3, 4, 5, 11, 12, 13.
// s = 5 gives |16 - 10| = 6 and s = 11 gives |16 - 22| = 6, so the answer is 6.

#include <iostream>
#include <vector>
#include <cstdlib>

using namespace std;

int main(){
    int T;
    cin >> T;

    while(T--){
        int n;
        cin >> n;

        vector<int> coin(n);
        int total = 0;
        for(int i = 0; i < n; i++){
            cin >> coin[i];
            total += coin[i];
        }

        int k = n / 2;   // Mina's share of coins; with n odd, Moni gets the extra one

        // reach[c][s], c = 0..k coins, s = 0..total. Only 0 coins making 0
        // is possible before any coin is looked at: the empty choice.
        vector<vector<bool>> reach(k + 1, vector<bool>(total + 1, false));
        reach[0][0] = true;

        for(int i = 0; i < n; i++){
            int v = coin[i];
            // Build the next table from the current one.
            // Start from a copy: every choice that skips coin i still works.
            vector<vector<bool>> next = reach;
            // Take coin i: from c-1 coins making s-v we get c coins making s.
            // Reading from the OLD table (reach) guarantees coin i is used at
            // most once.
            for(int c = 1; c <= k; c++){
                for(int s = v; s <= total; s++){
                    if(reach[c-1][s-v]){
                        next[c][s] = true;
                    }
                }
            }
            reach = next;
        }

        // Every sum exactly k coins can make is a possible share for Mina.
        int best = total;   // the worst case: one side gets everything
        for(int s = 0; s <= total; s++){
            if(reach[k][s]){
                int diff = abs(total - 2 * s);
                if(diff < best){
                    best = diff;
                }
            }
        }

        cout << best << endl;
    }

    // O(n * k * total) time per test case, O(k * total) memory.
    return 0;
}
