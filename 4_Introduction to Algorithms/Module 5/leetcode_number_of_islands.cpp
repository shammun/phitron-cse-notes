/*

https://leetcode.com/problems/number-of-islands/description/

200. Number of Islands

Given an m x n 2D binary grid grid which represents a map of '1's (land) and '0's (water), return the number of islands.

An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. You may assume all four edges of the grid are all surrounded by water.

 

Example 1:

Input: grid = [
  ["1","1","1","1","0"],
  ["1","1","0","1","0"],
  ["1","1","0","0","0"],
  ["0","0","0","0","0"]
]
Output: 1
Example 2:

Input: grid = [
  ["1","1","0","0","0"],
  ["1","1","0","0","0"],
  ["0","0","1","0","0"],
  ["0","0","0","1","1"]
]
Output: 3

*/

// Idea: the island-counting template that every problem in this module reuses.
// Treat the grid as a graph: each '1' cell is a node joined to the land cells
// above, below, left and right. An island is then one connected component, so
// counting islands is counting components (number_of_components.cpp, Module 3):
// walk the cells in reading order, and every unvisited land cell starts a new
// island -> count it and let a DFS flood (mark) the rest of that island.
//
// Example 2: three separate blobs of '1' -> 3.

class Solution {
    public:
        bool vis[300][300];       // vis[i][j] = already flooded (grid is at most 300 x 300)
        // The 4 moves as {row change, column change}: left, right, up, down.
        vector<pair<int, int>> d = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}};
        int n, m;                 // rows and columns, stored so valid() can see them

        // Is (i, j) inside the grid?
        bool valid(int i, int j){
            if(i<0 || i>=n || j < 0 || j>=m){
                return false;
            }
            return true;
        }

        // Flood one island: mark (si, sj) and every land cell joined to it.
        void dfs(vector<vector<char>> &grid, int si, int sj){
            vis[si][sj] = true;

            for(int i=0; i<4; i++){
                int ci = si + d[i].first;
                int cj = sj + d[i].second;
                // valid() first, so grid[ci][cj] is never read out of range.
                // The grid holds CHARACTERS, so land is '1', not the number 1.
                if(valid(ci, cj) && !vis[ci][cj] && grid[ci][cj] == '1'){
                    dfs(grid, ci, cj);
                }
            }
        }

        int numIslands(vector<vector<char>>& grid) {
            n = grid.size();
            m = grid[0].size();
            if(n==0) return 0;    // (LeetCode promises at least one row anyway)

            int islands = 0;
            // vis is a class member, not a global, so it is not zeroed for us.
            memset(vis, false, sizeof(vis));

            for(int i=0; i<n; i++){
                for(int j=0; j<m; j++){
                    // Land nobody has flooded yet = the first cell of a new island.
                    if(!vis[i][j] && grid[i][j]=='1'){
                        dfs(grid, i, j);   // flood the whole island...
                        islands++;         // ...and count it once
                    }
                }
            }
            return islands;       // Cost: O(n * m), each cell entered at most once
        }
    };
