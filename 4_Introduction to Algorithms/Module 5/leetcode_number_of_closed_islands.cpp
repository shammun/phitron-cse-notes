/*

https://leetcode.com/problems/number-of-closed-islands/description/

1254. Number of Closed Islands

Given a 2D grid consists of 0s (land) and 1s (water).  An island is a maximal 4-directionally 
connected group of 0s and a closed island is an island totally (all left, top, right, bottom) 
surrounded by 1s.

Return the number of closed islands.

Example 1:

Input: grid = [[1,1,1,1,1,1,1,0],[1,0,0,0,0,1,1,0],[1,0,1,0,1,1,1,0],[1,0,0,0,0,1,0,1],[1,1,1,1,1,1,1,0]]
Output: 2
Explanation: 
Islands in gray are closed because they are completely surrounded by water (group of 1s).

Example 3:

Input: grid = [[1,1,1,1,1,1,1],
               [1,0,0,0,0,0,1],
               [1,0,1,1,1,0,1],
               [1,0,1,0,1,0,1],
               [1,0,1,1,1,0,1],
               [1,0,0,0,0,0,1],
               [1,1,1,1,1,1,1]]
Output: 2

*/

class Solution {
    public:
        bool vis[105][105];
        vector<pair<int, int>> d = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        int n, m;
        bool flag; 
    
        bool valid(int i, int j){
            if(i<0 || i >= n || j<0 || j>=m){
                return false;
            }
            return true;
        }
    
        void dfs(vector<vector<int>>& grid, int si, int sj){
            vis[si][sj] = true;
            for(int i=0; i<4; i++){
                int ci = si + d[i].first;
                int cj = sj + d[i].second;
                if(!valid(ci, cj)){
                    flag = false;
                }
                if(valid(ci, cj) && !vis[ci][cj] && grid[ci][cj]==0){
                    dfs(grid, ci, cj);
                }
            }
        }
    
        int closedIsland(vector<vector<int>>& grid) {
            int cnt = 0;
            n = grid.size();
            m = grid[0].size();
            memset(vis, false, sizeof(vis));
    
            for(int i=0; i<n; i++){
                for(int j=0; j<m; j++){
                    if(!vis[i][j] && grid[i][j]==0){
                        flag = true;
                        dfs(grid, i, j);
                        if(flag==true){
                            cnt++;
                        }
                    }
                }
            }
            return cnt;
        }
    };