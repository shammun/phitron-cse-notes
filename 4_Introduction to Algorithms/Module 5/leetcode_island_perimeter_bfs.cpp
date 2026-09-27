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
//
// Tiny trace, Example 3: grid = [[1,0]] (n = 1 row, m = 2 columns)
//   cell (0,0) is land: up = off grid (+1), down = off grid (+1),
//   left = off grid (+1), right = (0,1) is water (+1)  -> perimeter 4.
//   cell (0,1) is water: adds nothing.                  -> answer 4.
//
// BFS (breadth-first search) uses a queue: first in, first out. Cells are
// taken out in the order they were put in, so the search spreads outward
// from the start in rings. Here the order does not matter for the answer;
// BFS is simply one way to visit every cell once.
//
// No #include or "using namespace std;": LeetCode's hidden driver code
// already includes the standard library and opens namespace std.

// LeetCode creates an object of this class and calls islandPerimeter() on it.
class Solution {
    public:                                   // members below are usable from outside the class
        bool vis[105][105];                   // vis[i][j] = cell (i, j) already put in the queue (grid is at most 100 x 100)
        // Direction array: the 4 moves as {row change, column change}:
        // {0,1} = right, {0,-1} = left, {1,0} = down, {-1,0} = up.
        // cell + direction[i] = its i-th neighbour.
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

        // bfs: visit every cell reachable from (Ai, Aj) - here that is the whole
        // grid, because the search moves through water too - and add up the
        // perimeter contribution of each land cell.
        void bfs(vector<vector<int>> &grid, int Ai, int Aj){
            // queue of cells; each cell is a pair {row, column}.
            queue<pair<int, int>> q;
            q.push({Ai, Aj});                 // the start cell goes in first
            vis[Ai][Aj] = true;               // mark when PUSHED, so no cell is queued twice

            // One pass = take the oldest cell out and handle it.
            // Stops when the queue is empty = every reachable cell handled.
            while(!q.empty()){
                pair<int, int> par = q.front();   // front() reads the oldest cell ("parent")
                q.pop();                          // pop() removes it from the queue
                int par_i = par.first;            // its row
                int par_j = par.second;           // its column

                // Step 1: if this is land, count its sides that face water or
                // fall off the grid. !valid() is tested first, so grid[ci][cj]
                // is only read when (ci, cj) is inside.
                // (|| stops as soon as one side is true: off-grid -> +1 without reading grid.)
                if(grid[par_i][par_j] == 1){
                    for(int i=0; i<4; i++){                    // i = which of the 4 sides
                        int ci = par_i + direction[i].first;   // neighbour row
                        int cj = par_j + direction[i].second;  // neighbour column

                        if(!valid(ci, cj) || grid[ci][cj] == 0){
                            perimeter++;                       // this side is part of the coastline
                        }
                    }
                }

                // Step 2: spread to every neighbour, land OR water. That is how
                // a search started on water still reaches the island; it also
                // means the whole grid gets visited.
                for(int i=0; i < 4; i++){
                    int ci = par_i + direction[i].first;
                    int cj = par_j + direction[i].second;

                    if(valid(ci, cj) && !vis[ci][cj]){         // inside and not queued yet
                        q.push({ci, cj});                      // handle it later
                        vis[ci][cj] = true;                    // and remember it is queued
                    }
                }


            }
        }


        // Called by LeetCode. Returns the island's perimeter.
        int islandPerimeter(vector<vector<int>>& grid) {
            n = grid.size();                  // rows = number of inner vectors
            m = grid[0].size();               // columns = length of row 0
            perimeter = 0;                    // reset (the object could be reused)
            // memset fills vis byte by byte with 0 = false; sizeof(vis) = its size
            // in bytes. Class members are not zeroed automatically.
            memset(vis, false, sizeof(vis));

            bfs(grid, 0, 0);      // any start works, since every cell is walked

            return perimeter;     // Cost: O(n * m)
        }
    };                                        // a class definition ends with ;
