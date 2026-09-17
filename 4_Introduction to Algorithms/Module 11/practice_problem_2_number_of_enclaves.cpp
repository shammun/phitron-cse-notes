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

class Solution {
    public:
        vector<pair<int, int>> directions = {{-1,0},{1,0},{0,-1},{0,1}};
        int rows, cols;
        bool vis[505][505];
    
        bool valid(int i, int j){
            if(i < 0 || i >= rows || j < 0 || j >= cols){
                return false;
            }
            return true;
        }
    
        void dfs(vector<vector<int>>& grid, int si, int sj){
            vis[si][sj] = true;
    
            for(int i=0; i<4; i++){
                int ci = si + directions[i].first;
                int cj = sj + directions[i].second;
                if(valid(ci, cj) && grid[ci][cj] == 1 && !vis[ci][cj]){
                    dfs(grid, ci, cj);
                }
            }
        }
    
        int numEnclaves(vector<vector<int>>& grid) {
            rows = grid.size();
            cols = grid[0].size();
    
            memset(vis, false, sizeof(vis));
    
            // Check first and last row
            for(int j=0; j<cols; j++){
                if(grid[0][j] == 1 && !vis[0][j]){
                    dfs(grid, 0, j);
                }
                if(grid[rows-1][j] == 1 && !vis[rows-1][j]){
                    dfs(grid, rows-1, j);
                }
            }
    
            // Check first and last column
            for(int i=0; i<rows; i++){
                if(grid[i][0] == 1 && !vis[i][0]){
                    dfs(grid, i, 0);
                }
                if(grid[i][cols-1] == 1 && !vis[i][cols-1]){
                    dfs(grid, i, cols-1);
                }
            }
            
            // count unvisited land cells
            int enclaves = 0;
            for(int i=0; i<rows; i++){
                for(int j=0; j<cols; j++){
                    if(grid[i][j] == 1 && !vis[i][j]){
                        enclaves++;
                    }
                }
            }
    
            return enclaves;
        }
    };