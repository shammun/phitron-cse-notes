/*

https://leetcode.com/problems/count-sub-islands/description/

1905. Count Sub Islands

You are given two m x n binary matrices grid1 and grid2 containing only 0's (representing 
water) and 1's (representing land). An island is a group of 1's connected 4-directionally 
(horizontal or vertical). Any cells outside of the grid are considered water cells.

An island in grid2 is considered a sub-island if there is an island in grid1 that contains 
all the cells that make up this island in grid2.

Return the number of islands in grid2 that are considered sub-islands.

Input: grid1 = [[1,1,1,0,0],[0,1,1,1,1],[0,0,0,0,0],[1,0,0,0,0],[1,1,0,1,1]], grid2 = 
[[1,1,1,0,0],[0,0,1,1,1],[0,1,0,0,0],[1,0,1,1,0],[0,1,0,1,0]]

Output: 3
Explanation: In the picture above, the grid on the left is grid1 and the grid on the right is 
grid2.

The 1s colored red in grid2 are those considered to be part of a sub-island. There are three 
sub-islands.

Input: grid1 = [[1,0,1,0,1],[1,1,1,1,1],[0,0,0,0,0],[1,1,1,1,1],[1,0,1,0,1]], 
grid2 = [[0,0,0,0,0],[1,1,1,1,1],[0,1,0,1,0],[0,1,0,1,0],[1,0,0,0,1]]

Output: 2 
Explanation: In the picture above, the grid on the left is grid1 and the grid on the right is 
grid2.
The 1s colored red in grid2 are those considered to be part of a sub-island. There are two 
sub-islands.

*/

class Solution {
    public:
        bool vis[505][505];
        vector<pair<int, int>> d = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        int n, m;
        bool flag; 
    
        bool valid(int i, int j){
            if(i<0 || i >= n || j<0 || j>=m){
                return false;
            }
            return true;
        }
    
        void dfs(vector<vector<int>>& grid1, vector<vector<int>>& grid2, int si, int sj){
            vis[si][sj] = true;
            if(grid1[si][sj] == 0){
                flag = false;
            }
            for(int i=0; i<4; i++){
                int ci = si + d[i].first;
                int cj = sj + d[i].second;
                if(valid(ci, cj) && !vis[ci][cj] && grid2[ci][cj]==1){
                    dfs(grid1, grid2, ci, cj);
                }
            }
        }
    
        int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
            int cnt = 0;
            n = grid1.size();
            m = grid1[0].size();
            memset(vis, false, sizeof(vis));
    
            for(int i=0; i<n; i++){
                for(int j=0; j<m; j++){
                    if(!vis[i][j] && grid2[i][j]==1){
                        flag = true;
                        dfs(grid1, grid2, i, j);
                        if(flag==true){
                            cnt++;
                        }
                    }
                }
            }
            return cnt;
        }
    };