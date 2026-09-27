/*

https://leetcode.com/problems/number-of-enclaves/

1020. Number of Enclaves

You are given an m x n binary matrix grid, where 0 represents a sea cell and 1 represents a land cell.

A move consists of walking from one land cell to another adjacent (4-directionally) land cell or walking off the
boundary of the grid.

Return the number of land cells in grid for which we cannot walk off the boundary of the grid in any number of
moves.

Input: grid = [[0,0,0,0],[1,0,1,0],[0,1,1,0],[0,0,0,0]]
Output: 3
Explanation: There are three 1s that are enclosed by 0s, and one 1 that is not enclosed because its on the
boundary.

Input: grid = [[0,1,1,0],[0,0,1,0],[0,0,1,0],[0,0,0,0]]
Output: 0
Explanation: All 1s are either on the boundary or can reach the boundary.

Constraints:

m == grid.length
n == grid[i].length
1 <= m, n <= 500
grid[i][j] is either 0 or 1.

*/

// Practice Day problem 2. A land cell can "walk off" the grid exactly when it is
// connected to a land cell on the border. So turn the question around: start a
// DFS from every border land cell and mark everything it reaches. Those cells
// can escape. The land cells still unmarked afterwards are the enclaves.
// (The practice day lists it under DSU, but a grid flood fill from Module 3 is
// the simpler tool here.)
//
// There are no #include lines and no main(): LeetCode adds the headers (like
// <bits/stdc++.h>) and "using namespace std;" and calls numEnclaves itself. So
// this file only compiles inside LeetCode, not on its own.
//
// Trace with example 1: the only border land cell is (1,0); its DFS marks just
// (1,0). Unmarked land: (1,2), (2,1), (2,2) -> answer 3.

// LeetCode's required class; numEnclaves is the function it calls.
class Solution {
    public:   // everything below can be used from outside the class
        // The four neighbour offsets as (row change, column change) pairs.
        // A pair holds two values: .first and .second.
        vector<pair<int, int>> directions = {{-1,0},{1,0},{0,-1},{0,1}};   // up, down, left, right
        int rows, cols;       // grid size, set in numEnclaves
        bool vis[505][505];   // grid is at most 500 x 500

        // Is (i, j) inside the grid?
        bool valid(int i, int j){
            if(i < 0 || i >= rows || j < 0 || j >= cols){   // off any edge
                return false;
            }
            return true;
        }

        // Mark every land cell connected to (si, sj).
        // grid is passed by reference (&) so the big 2D vector is not copied.
        // Recursion: mark this cell, then call dfs on each unvisited land
        // neighbour; it stops by itself when no such neighbour is left.
        void dfs(vector<vector<int>>& grid, int si, int sj){
            vis[si][sj] = true;   // this cell is reachable from the border

            for(int i=0; i<4; i++){                    // try all 4 directions
                int ci = si + directions[i].first;     // neighbour row
                int cj = sj + directions[i].second;    // neighbour column
                // Inside the grid, land, and not seen yet? Then spread there.
                // (valid is checked first; && stops early so grid[ci][cj] is
                // never read out of range.)
                if(valid(ci, cj) && grid[ci][cj] == 1 && !vis[ci][cj]){
                    dfs(grid, ci, cj);
                }
            }
        }

        int numEnclaves(vector<vector<int>>& grid) {
            rows = grid.size();       // number of rows
            cols = grid[0].size();    // number of columns (length of row 0)

            // Set every vis cell to false (byte 0 = false). Needed because the
            // same Solution object could be reused for another grid.
            memset(vis, false, sizeof(vis));

            // Check first and last row
            // Any land here touches the edge: flood its whole island as "escapes".
            for(int j=0; j<cols; j++){
                if(grid[0][j] == 1 && !vis[0][j]){             // top row
                    dfs(grid, 0, j);
                }
                if(grid[rows-1][j] == 1 && !vis[rows-1][j]){   // bottom row
                    dfs(grid, rows-1, j);
                }
            }

            // Check first and last column
            for(int i=0; i<rows; i++){
                if(grid[i][0] == 1 && !vis[i][0]){             // left column
                    dfs(grid, i, 0);
                }
                if(grid[i][cols-1] == 1 && !vis[i][cols-1]){   // right column
                    dfs(grid, i, cols-1);
                }
            }

            // count unvisited land cells
            // No border flood reached them, so they are trapped.
            int enclaves = 0;
            for(int i=0; i<rows; i++){
                for(int j=0; j<cols; j++){
                    if(grid[i][j] == 1 && !vis[i][j]){   // land, never marked
                        enclaves++;
                    }
                }
            }

            return enclaves;   // O(rows * cols)
        }
    };
