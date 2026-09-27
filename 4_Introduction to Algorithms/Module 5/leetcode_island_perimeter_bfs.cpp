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

// Idea: the perimeter is the number of land-cell SIDES that touch water or the
// edge of the grid. So visit cells, and for every land cell look at its 4 sides:
// each side that is outside the grid or is a 0 adds 1 to the perimeter.
//
// This BFS version starts at (0, 0), which may be water, and walks EVERY cell
// of the grid (land and water alike), only counting sides for land cells.
// Example 1: the island of 7 cells has 16 sides facing water or the border.

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

        void bfs(vector<vector<int>> &grid, int Ai, int Aj){
            queue<pair<int, int>> q;
            q.push({Ai, Aj});
            vis[Ai][Aj] = true;

            while(!q.empty()){
                pair<int, int> par = q.front();
                q.pop();
                int par_i = par.first;
                int par_j = par.second;

                // Step 1: if this is land, count its sides that face water or
                // fall off the grid. !valid() is tested first, so grid[ci][cj]
                // is only read when (ci, cj) is inside.
                if(grid[par_i][par_j] == 1){
                    for(int i=0; i<4; i++){
                        int ci = par_i + direction[i].first;
                        int cj = par_j + direction[i].second;

                        if(!valid(ci, cj) || grid[ci][cj] == 0){
                            perimeter++;
                        }
                    }
                }

                // Step 2: spread to every neighbour, land OR water. That is how
                // a search started on water still reaches the island; it also
                // means the whole grid gets visited.
                for(int i=0; i < 4; i++){
                    int ci = par_i + direction[i].first;
                    int cj = par_j + direction[i].second;

                    if(valid(ci, cj) && !vis[ci][cj]){
                        q.push({ci, cj});
                        vis[ci][cj] = true;
                    }
                }


            }
        }


        int islandPerimeter(vector<vector<int>>& grid) {
            n = grid.size();
            m = grid[0].size();
            perimeter = 0;
            memset(vis, false, sizeof(vis));

            bfs(grid, 0, 0);      // any start works, since every cell is walked

            return perimeter;     // Cost: O(n * m)
        }
    };
