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
//
// Why counting sides works: the perimeter is made of unit edges. A side of a
// land cell is on the perimeter exactly when the cell on the other side is
// water or does not exist (off the grid). Two land cells sharing a side hide
// that side, so it is not counted.
//
// Tiny trace, Example 2: grid = [[1]] - the one land cell has all 4 sides
// off the grid -> perimeter 4.
//
// DFS (depth-first search) goes as deep as it can along one path before
// backing up; the "stack" of pending work is the chain of recursive calls.
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

        // dfs(Ai, Aj): enter cell (Ai, Aj), count its sides if it is land,
        // then recurse into every unvisited neighbour (land or water).
        // No explicit base case: a call ends when all 4 neighbours are either
        // off the grid or already visited.
        void dfs(vector<vector<int>> &grid, int Ai, int Aj){
            vis[Ai][Aj] = true;                       // mark on entry so we never re-enter
            // Land cell: count its sides that touch water or the border.
            if(grid[Ai][Aj] == 1){
                for(int i=0; i<4; i++){                        // i = which side
                    int ci = Ai + direction[i].first;          // neighbour row
                    int cj = Aj + direction[i].second;         // neighbour column
                    // !valid first: if off the grid, || stops and grid is not read out of range.
                    if(!valid(ci, cj) || grid[ci][cj] == 0){
                        perimeter++;                           // coastline side
                    }
                }
            }

            // Go deeper into every unvisited neighbour, water included. So one
            // call ends up walking the whole grid, and the recursion can get as
            // deep as n * m (V2 avoids that by walking land only).
            for(int i=0; i<4; i++){
                int ci = Ai + direction[i].first;
                int cj = Aj + direction[i].second;
                if(valid(ci, cj) && !vis[ci][cj]){             // inside and not seen yet
                    dfs(grid, ci, cj);                         // trust it to handle everything reachable from there
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

            // Start dfs from land -- that's why we are using for loop to find land
            // (Because this dfs also walks water, the first call already visits the
            // whole grid, and the !vis test stops any second call.)
            for(int i=0; i<n; i++){
                for(int j=0; j<m; j++){
                    // the following line detects land
                    // (land that no dfs has entered yet)
                    if(!vis[i][j] && grid[i][j] == 1){
                        dfs(grid, i, j);
                    }
                }
            }

            return perimeter;     // Cost: O(n * m)
        }
    };                                        // a class definition ends with ;
