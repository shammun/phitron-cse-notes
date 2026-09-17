/*

https://leetcode.com/problems/maximum-number-of-fish-in-a-grid/description/

2658. Maximum Number of Fish in a Grid

You are given a 0-indexed 2D matrix grid of size m x n, where (r, c) represents:

A land cell if grid[r][c] = 0, or
A water cell containing grid[r][c] fish, if grid[r][c] > 0.
A fisher can start at any water cell (r, c) and can do the following operations any number of 
times:

- Catch all the fish at cell (r, c), or
- Move to any adjacent water cell.
Return the maximum number of fish the fisher can catch if he chooses his starting cell 
optimally, or 0 if no water cell exists.

An adjacent cell of the cell (r, c), is one of the cells (r, c + 1), (r, c - 1), (r + 1, c) or 
(r - 1, c) if it exists.

*/

class Solution {
    public:
        bool vis[55][55];
            vector<pair<int, int>> d = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}};
            int n, m, total, mx;
        
            bool valid(int i, int j){
                if(i<0 || i >= n || j<0 || j >= m){
                    return false;
                } else{
                    return true;
                }
            }
        
            void dfs(int si, int sj, vector<vector<int>> &grid){
                vis[si][sj] = true;
                total = total + grid[si][sj];
        
                for(int i=0; i<4; i++){
                    int ci = si + d[i].first;
                    int cj = sj + d[i].second;
                    if(valid(ci, cj) && !vis[ci][cj] && grid[ci][cj] > 0){
                        dfs(ci, cj, grid);
                    }
                }
            }
    
        int findMaxFish(vector<vector<int>>& grid) {
            n = grid.size();
                m = grid[0].size();
                mx = 0;
        
                memset(vis, false, sizeof(vis));
        
                for(int i=0; i<n; i++){
                    for(int j=0; j<m; j++){
                        if(!vis[i][j] && grid[i][j] > 0){
                            total = 0;
                            dfs(i, j, grid);
                            mx = max(total, mx);
                        }
                    }
                }
        
                return mx;
        }
    };