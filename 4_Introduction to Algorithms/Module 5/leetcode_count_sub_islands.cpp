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

// Idea: flood each island of grid2 with the usual template, and while flooding
// check grid1 underneath: if ANY cell of this grid2 island is water in grid1,
// the island is not a sub-island. A bool flag starts true for each island and
// is switched off by the first bad cell; after the flood, count the island
// only if the flag survived.
//
// Example 1 from LeetCode: 3 of grid2's islands lie completely on grid1 land.

class Solution {
    public:
        bool vis[505][505];
        vector<pair<int, int>> d = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        int n, m;
        bool flag;                // still a sub-island? (for the island being flooded)

        bool valid(int i, int j){
            if(i<0 || i >= n || j<0 || j>=m){
                return false;
            }
            return true;
        }

        void dfs(vector<vector<int>>& grid1, vector<vector<int>>& grid2, int si, int sj){
            vis[si][sj] = true;
            // This cell is land in grid2; is it land in grid1 as well?
            if(grid1[si][sj] == 0){
                flag = false;     // no -> the whole island fails
            }
            // Keep flooding anyway, even after a failure: if we stopped here,
            // the rest of this island would stay unvisited and later be taken
            // for a separate island.
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
                    // A new island of grid2.
                    if(!vis[i][j] && grid2[i][j]==1){
                        flag = true;                 // innocent until a cell fails
                        dfs(grid1, grid2, i, j);
                        if(flag==true){
                            cnt++;                   // every cell sat on grid1 land
                        }
                    }
                }
            }
            return cnt;           // Cost: O(n * m)
        }
    };
