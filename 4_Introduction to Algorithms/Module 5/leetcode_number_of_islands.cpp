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

class Solution {
    public:
        bool vis[300][300];
        vector<pair<int, int>> d = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}};
        int n, m;
    
        bool valid(int i, int j){
            if(i<0 || i>=n || j < 0 || j>=m){
                return false;
            }
            return true;
        }
    
        void dfs(vector<vector<char>> &grid, int si, int sj){
            vis[si][sj] = true;
    
            for(int i=0; i<4; i++){
                int ci = si + d[i].first;
                int cj = sj + d[i].second;
                if(valid(ci, cj) && !vis[ci][cj] && grid[ci][cj] == '1'){
                    dfs(grid, ci, cj);
                }
            }
        }
    
        int numIslands(vector<vector<char>>& grid) {
            n = grid.size();
            m = grid[0].size();
            if(n==0) return 0;
    
            int islands = 0;
            memset(vis, false, sizeof(vis));
    
            for(int i=0; i<n; i++){
                for(int j=0; j<m; j++){
                    if(!vis[i][j] && grid[i][j]=='1'){
                        dfs(grid, i, j);
                        islands++;
                    }
                }
            }
            return islands;
        }
    };