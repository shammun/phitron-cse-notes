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

// Idea: careful, the values are flipped here: 0 is LAND and 1 is water. A
// closed island is one that never touches the border of the grid. Flood each
// island of 0s with the template and a flag (as in Count Sub Islands): if the
// flood ever tries to step OFF the grid, the island reaches the border, so it
// is not closed. Count the islands whose flag stayed true.
//
// Example 1 from LeetCode: 2 islands are fully walled in by 1s.

class Solution {
    public:
        bool vis[105][105];
        vector<pair<int, int>> d = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        int n, m;
        bool flag;                // is the island being flooded still closed?

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
                // A neighbour outside the grid means this land cell sits on the
                // border: the island leaks out, so it is not closed.
                if(!valid(ci, cj)){
                    flag = false;
                }
                // Keep flooding the land (0) regardless, so the whole island is
                // marked and never counted again as a new one.
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
                    if(!vis[i][j] && grid[i][j]==0){    // a new island of land (0)
                        flag = true;
                        dfs(grid, i, j);
                        if(flag==true){
                            cnt++;                      // never touched the border
                        }
                    }
                }
            }
            return cnt;           // Cost: O(n * m)
        }
    };
