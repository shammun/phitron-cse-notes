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

// Idea: the same side-counting rule as leetcode_island_perimeter_bfs.cpp, with
// DFS instead of BFS: every land cell adds 1 for each side that faces water or
// the border. This version first searches for a land cell to start from, but
// then its DFS still steps into water cells too (only land cells add sides).

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
            // Land cell: count its sides that touch water or the border.
            if(grid[Ai][Aj] == 1){
                for(int i=0; i<4; i++){
                    int ci = Ai + direction[i].first;
                    int cj = Aj + direction[i].second;
                    if(!valid(ci, cj) || grid[ci][cj] == 0){
                        perimeter++;
                    }
                }
            }

            // Go deeper into every unvisited neighbour, water included. So one
            // call ends up walking the whole grid, and the recursion can get as
            // deep as n * m (V2 avoids that by walking land only).
            for(int i=0; i<4; i++){
                int ci = Ai + direction[i].first;
                int cj = Aj + direction[i].second;
                if(valid(ci, cj) && !vis[ci][cj]){
                    dfs(grid, ci, cj);
                }
            }
        }




        int islandPerimeter(vector<vector<int>>& grid) {
            n = grid.size();
            m = grid[0].size();
            perimeter = 0;
            memset(vis, false, sizeof(vis));

            // Start dfs from land -- that's why we are using for loop to find land
            for(int i=0; i<n; i++){
                for(int j=0; j<m; j++){
                    // the following line detects land
                    if(!vis[i][j] && grid[i][j] == 1){
                        dfs(grid, i, j);
                    }
                }
            }

            return perimeter;     // Cost: O(n * m)
        }
    };
