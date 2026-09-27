/*

https://leetcode.com/problems/maximum-number-of-fish-in-a-grid/

2658. Maximum Number of Fish in a Grid

You are given a 0-indexed 2D matrix grid of size m x n, where (r, c) represents:

A land cell if grid[r][c] = 0, or
A water cell containing grid[r][c] fish, if grid[r][c] > 0.
A fisher can start at any water cell (r, c) and can do the following operations any
number of times:

Catch all the fish at cell (r, c), or
Move to any adjacent water cell.
Return the maximum number of fish the fisher can catch if he chooses his starting cell
optimally, or 0 if no water cell exists.

An adjacent cell of the cell (r, c), is one of the cells (r, c + 1), (r, c - 1),
(r + 1, c) or (r - 1, c) if it exists.

Example 1:
Input: grid = [[0,2,1,0],[4,0,0,3],[1,0,0,4],[0,3,2,0]]
Output: 7
Explanation: The fisher can start at cell (1,3) and collect 3 fish, then move to cell
(2,3) and collect 4 fish.

Example 2:
Input: grid = [[1,0,0,0],[0,0,0,0],[0,0,0,0],[0,0,0,1]]
Output: 1
Explanation: The fisher can start at cells (0,0) or (3,3) and collect a single fish.

*/

// Idea: Max Area of Island again, but each water cell holds some fish and
// "land" is now any cell with fish (> 0). While flooding one connected region,
// add the cell's VALUE instead of 1. The region with the largest total wins.
//
// Example: a pond of cells 3 and 4 side by side holds 7 fish; if no other pond
// holds more, the answer is 7.
//
// Grid as a graph: each cell is a node with edges to its 4 side neighbours.
// A "pond" is a connected component of cells with fish; a DFS started in a
// pond visits exactly that pond, so the fisher can collect all of it.
//
// Tiny trace, Example 1: ponds are {2,1} (row 0) = 3, {4,1} (column 0) = 5,
// {3,4} (column 3) = 7, {3,2} (row 3) = 5  -> the best is 7.
//
// No #include or "using namespace std;": LeetCode's hidden driver code
// already includes the standard library and opens namespace std.

// LeetCode creates an object of this class and calls findMaxFish() on it.
class Solution {
    public:                                   // members below are usable from outside the class
        bool vis[55][55];                     // vis[i][j] = DFS already entered (i, j); grid is at most 10 x 10, 55 is plenty
        // Direction array: {row change, column change} for left, right, up, down.
        vector<pair<int, int>> d = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}};
        int n, m, total, mx;      // total = fish in the current pond, mx = best so far

        // valid(i, j): is (i, j) inside the grid?
        bool valid(int i, int j){
            if(i<0 || i >= n || j<0 || j >= m){   // off any edge
                return false;
            } else{
                return true;
            }
        }

        // dfs(si, sj): flood the pond containing (si, sj), adding every cell's
        // fish to total. Ends by itself when no unvisited fishy neighbour is left.
        // grid is passed by reference (&) so it is not copied on each call.
        void dfs(int si, int sj, vector<vector<int>> &grid){
            vis[si][sj] = true;                  // mark on entry: each cell's fish are caught only once
            total = total + grid[si][sj];    // catch every fish in this cell

            for(int i=0; i<4; i++){              // i = which of the 4 neighbours
                int ci = si + d[i].first;        // neighbour row
                int cj = sj + d[i].second;       // neighbour column
                // A 0 cell is land (no fish): it blocks the flood like a wall.
                // valid() first, so grid is never read out of range.
                if(valid(ci, cj) && !vis[ci][cj] && grid[ci][cj] > 0){
                    dfs(ci, cj, grid);           // trust it to add the rest of the pond
                }
            }
        }

        // Called by LeetCode. Returns the most fish one pond holds (0 if none).
        int findMaxFish(vector<vector<int>>& grid) {
            n = grid.size();                     // rows
            m = grid[0].size();                  // columns (length of row 0)
            mx = 0;               // no water anywhere -> 0 fish

            // memset sets every byte of vis to 0 (false); sizeof(vis) = its size in
            // bytes. Class members are not zeroed automatically.
            memset(vis, false, sizeof(vis));

            for(int i=0; i<n; i++){
                for(int j=0; j<m; j++){
                    // An unvisited fishy cell starts a new pond.
                    if(!vis[i][j] && grid[i][j] > 0){
                        total = 0;                   // new pond, nothing caught yet
                        dfs(i, j, grid);             // total = all fish in this pond afterwards
                        mx = max(total, mx);         // keep the larger of the two
                    }
                }
            }

            return mx;            // Cost: O(n * m)
        }
    };                                        // a class definition ends with ;
