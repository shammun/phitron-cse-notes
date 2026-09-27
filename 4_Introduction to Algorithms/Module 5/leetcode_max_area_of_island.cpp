/*

https://leetcode.com/problems/max-area-of-island/description/

695. Max Area of Island

You are given an m x n binary matrix grid. An island is a group of 1's (representing land)
connected 4-directionally (horizontal or vertical.) You may assume all four edges of the grid
are surrounded by water.

The area of an island is the number of cells with a value 1 in the island.

Return the maximum area of an island in grid. If there is no island, return 0.

Input: grid = [[0,0,1,0,0,0,0,1,0,0,0,0,0],[0,0,0,0,0,0,0,1,1,1,0,0,0],[0,1,1,0,1,0,0,0,0,0,0,0,0],[0,1,0,0,1,1,0,0,1,0,1,0,0],[0,1,0,0,1,1,0,0,1,1,1,0,0],[0,0,0,0,0,0,0,0,0,0,1,0,0],[0,0,0,0,0,0,0,1,1,1,0,0,0],[0,0,0,0,0,0,0,1,1,0,0,0,0]]
Output: 6
Explanation: The answer is not 11, because the island must be connected 4-directionally.
Example 2:

Input: grid = [[0,0,0,0,0,0,0,0]]
Output: 0

*/

// Idea: the island template from leetcode_number_of_islands.cpp, with one
// change: instead of counting islands, count the CELLS each flood enters. That
// count is the island's area. Keep the biggest one seen.
//
// Example: an island of 6 connected cells beats all the smaller ones -> 6.
// (Cells touching only at a corner are NOT connected: only 4 directions.)
//
// Grid as a graph: each cell is a node with edges to its 4 side neighbours.
// An island is one connected component of land cells; a DFS from one land
// cell visits exactly that component, one call per cell.
//
// Tiny trace, grid = [[1,1,0],
//                     [0,0,1]]
//   (0,0) is new land: cnt = 0, dfs enters (0,0) cnt=1, then (0,1) cnt=2 -> mx = 2
//   (1,2) is new land: cnt = 0, dfs enters (1,2) cnt=1              -> mx stays 2
//   answer 2.
//
// No #include or "using namespace std;": LeetCode's hidden driver code
// already includes the standard library and opens namespace std.

// LeetCode creates an object of this class and calls maxAreaOfIsland() on it.
class Solution {
    public:                                   // members below are usable from outside the class
        bool vis[55][55];                     // vis[i][j] = DFS already entered (i, j); grid is at most 50 x 50
        // Direction array: {row change, column change} for left, right, up, down.
        vector<pair<int, int>> d = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}};
        int n, m, cnt, mx;        // cnt = area of the current island, mx = best so far

        // valid(i, j): is (i, j) inside the grid?
        bool valid(int i, int j){
            if(i<0 || i >= n || j<0 || j >= m){   // off any edge
                return false;
            } else{
                return true;
            }
        }

        // dfs(si, sj): flood the island containing land cell (si, sj), adding 1
        // to cnt for every cell entered. The recursion stops by itself when no
        // unvisited land neighbour is left. grid is passed by reference (&) so
        // it is not copied on each call.
        void dfs(int si, int sj, vector<vector<int>> &grid){
            vis[si][sj] = true;   // mark on entry so this cell is counted only once
            cnt++;                // one more cell belongs to this island

            for(int i=0; i<4; i++){               // i = which of the 4 neighbours
                int ci = si + d[i].first;         // neighbour row
                int cj = sj + d[i].second;        // neighbour column
                // Here the grid holds numbers, so land is 1 (not '1').
                // valid() is tested first, so grid is never read out of range.
                if(valid(ci, cj) && !vis[ci][cj] && grid[ci][cj] == 1){
                    dfs(ci, cj, grid);            // trust it to add the rest of the island to cnt
                }
            }
        }

        // Called by LeetCode. Returns the largest island's area (0 if none).
        int maxAreaOfIsland(vector<vector<int>>& grid) {
            n = grid.size();                      // rows
            m = grid[0].size();                   // columns (length of row 0)
            mx = 0;               // no land at all -> the answer stays 0

            // memset sets every byte of vis to 0 (false); sizeof(vis) = its size in
            // bytes. Class members are not zeroed automatically.
            memset(vis, false, sizeof(vis));

            // Scan every cell; each unvisited land cell starts a new island.
            for(int i=0; i<n; i++){
                for(int j=0; j<m; j++){
                    if(!vis[i][j] && grid[i][j] == 1){
                        cnt = 0;              // a new island starts at area 0
                        dfs(i, j, grid);      // cnt is its area afterwards
                        mx = max(cnt, mx);    // keep the largest (max returns the bigger of the two)
                    }
                }
            }

            return mx;            // Cost: O(n * m)
        }
    };                                        // a class definition ends with ;
