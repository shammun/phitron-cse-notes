/*

https://leetcode.com/problems/island-perimeter/submissions/1536237351/

Island Perimeter

You are given row x col grid representing a map where grid[i][j] = 1 represents land and 
grid[i][j] = 0 represents water.

Grid cells are connected horizontally/vertically (not diagonally). The grid is completely 
surrounded by water, and there is exactly one island (i.e., one or more connected land cells).

The island doesn't have "lakes", meaning the water inside isn't connected to the water around 
the island. One cell is a square with side length 1. The grid is rectangular, width and height 
don't exceed 100. Determine the perimeter of the island.

Example 1:
Input: grid = [[0,1,0,0],[1,1,1,0],[0,1,0,0],[1,1,0,0]]
Output: 16
Explanation: The perimeter is the 16 yellow stripes in the image above.
Example 2:

Input: grid = [[1]]
Output: 4
Example 3:

Input: grid = [[1,0]]
Output: 4

*/

// Idea: the cleanest of the three perimeter versions. The DFS walks LAND ONLY
// (the grid[ci][cj] == 1 test in the second loop), so every cell it enters is
// land and can count its water-or-border sides without an extra if. Water
// cells are never entered, and the recursion is at most as deep as the island.

class Solution {
    public:
        bool vis[105][105];
        vector<pair<int, int>> direction = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        int n, m;
        int perimeter = 0;

        bool valid(int i, int j){
            if(i < 0 || i >= n || j < 0 || j >= m){
                return false;
            }
            return true;
        }

        void dfs(vector<vector<int>> &grid, int Ai, int Aj){
            vis[Ai][Aj] = true;

            // (Ai, Aj) is surely land here: count each side facing water or
            // falling off the grid.
            for(int i=0; i<4; i++){
                int ci = Ai + direction[i].first;
                int cj = Aj + direction[i].second;
                if(!valid(ci, cj) || grid[ci][cj] == 0){
                    perimeter++;
                }
            }

            // Continue only into land neighbours not yet visited.
            for(int i=0; i<4; i++){
                int ci = Ai + direction[i].first;
                int cj = Aj + direction[i].second;
                if(valid(ci, cj) && !vis[ci][cj] && grid[ci][cj] == 1){
                    dfs(grid, ci, cj);
                }
            }
        }




        int islandPerimeter(vector<vector<int>>& grid) {
            n = grid.size();
            m = grid[0].size();
            perimeter = 0;
            memset(vis, false, sizeof(vis));

            // Start dfs from land (the problem has exactly one island, so this
            // fires once; the loop form would also add up several islands).
            for(int i=0; i<n; i++){
                for(int j=0; j<m; j++){
                    if(!vis[i][j] && grid[i][j] == 1){
                        dfs(grid, i, j);
                    }
                }
            }

            return perimeter;     // Cost: O(n * m)
        }
    };
