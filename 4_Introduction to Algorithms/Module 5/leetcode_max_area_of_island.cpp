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

class Solution {
    public:
        bool vis[55][55];
        vector<pair<int, int>> d = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}};
        int n, m, cnt, mx;
    
        bool valid(int i, int j){
            if(i<0 || i >= n || j<0 || j >= m){
                return false;
            } else{
                return true;
            }
        }
    
        void dfs(int si, int sj, vector<vector<int>> &grid){
            vis[si][sj] = true;
            cnt++;
    
            for(int i=0; i<4; i++){
                int ci = si + d[i].first;
                int cj = sj + d[i].second;
                if(valid(ci, cj) && !vis[ci][cj] && grid[ci][cj] == 1){
                    dfs(ci, cj, grid);
                }
            }
        }
    
        int maxAreaOfIsland(vector<vector<int>>& grid) {
            n = grid.size();
            m = grid[0].size();
            mx = 0;
    
            memset(vis, false, sizeof(vis));
    
            for(int i=0; i<n; i++){
                for(int j=0; j<m; j++){
                    if(!vis[i][j] && grid[i][j] == 1){
                        cnt = 0;
                        dfs(i, j, grid);
                        mx = max(cnt, mx);
                    }
                }
            }
    
            return mx;
        }
    };