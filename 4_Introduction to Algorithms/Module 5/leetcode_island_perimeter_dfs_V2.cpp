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
//
// Why counting sides works: a side of a land cell belongs to the perimeter
// exactly when the other side is water or off the grid; a side shared by two
// land cells is inside the island and is not counted.
//
// Tiny trace, a 1 x 2 island grid = [[1,1]]:
//   dfs(0,0): up off(+1) down off(+1) left off(+1) right (0,1) is land(+0) -> 3
//             then recurse into (0,1)
//   dfs(0,1): up off(+1) down off(+1) left (0,0) land(+0) right off(+1)   -> 3
//   total 6 = the perimeter of a 1 x 2 rectangle.
//
// No #include or "using namespace std;": LeetCode's hidden driver code
// already includes the standard library and opens namespace std.

// LeetCode creates an object of this class and calls islandPerimeter() on it.
class Solution {
    public:                                   // members below are usable from outside the class
        bool vis[105][105];                   // vis[i][j] = DFS already entered cell (i, j); grid is at most 100 x 100
        // Direction array: {row change, column change} for right, left, down, up.
        vector<pair<int, int>> direction = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        int n, m;                             // number of rows, number of columns
        int perimeter = 0;                    // running total of counted sides

        // valid(i, j): is (i, j) inside the grid?
        bool valid(int i, int j){
            if(i < 0 || i >= n || j < 0 || j >= m){   // off any edge
                return false;
            }
            return true;
        }

        // dfs(Ai, Aj): (Ai, Aj) is a land cell. Count its coastline sides, then
        // recurse into unvisited LAND neighbours. The recursion ends by itself
        // when no such neighbour is left.
        void dfs(vector<vector<int>> &grid, int Ai, int Aj){
            vis[Ai][Aj] = true;                       // mark on entry so we never re-enter

            // (Ai, Aj) is surely land here: count each side facing water or
            // falling off the grid.
            for(int i=0; i<4; i++){                            // i = which side
                int ci = Ai + direction[i].first;              // neighbour row
                int cj = Aj + direction[i].second;             // neighbour column
                // !valid first: off-grid -> || stops, grid is not read out of range.
                if(!valid(ci, cj) || grid[ci][cj] == 0){
                    perimeter++;                               // coastline side
                }
            }

            // Continue only into land neighbours not yet visited.
            for(int i=0; i<4; i++){
                int ci = Ai + direction[i].first;
                int cj = Aj + direction[i].second;
                if(valid(ci, cj) && !vis[ci][cj] && grid[ci][cj] == 1){
                    dfs(grid, ci, cj);                         // trust it to cover the rest of the island from there
                }
            }
        }




        // Called by LeetCode. Returns the island's perimeter.
        int islandPerimeter(vector<vector<int>>& grid) {
            n = grid.size();                  // rows
            m = grid[0].size();               // columns (length of row 0)
            perimeter = 0;                    // reset the total
            // memset sets every byte of vis to 0 (false); sizeof(vis) = its size in
            // bytes. Class members are not zeroed automatically.
            memset(vis, false, sizeof(vis));

            // Start dfs from land (the problem has exactly one island, so this
            // fires once; the loop form would also add up several islands).
            for(int i=0; i<n; i++){
                for(int j=0; j<m; j++){
                    if(!vis[i][j] && grid[i][j] == 1){   // land not reached by any dfs yet
                        dfs(grid, i, j);
                    }
                }
            }

            return perimeter;     // Cost: O(n * m)
        }
    };                                        // a class definition ends with ;
