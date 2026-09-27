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
//
// Grid as a graph: each cell is a node with edges to its 4 side neighbours;
// an island is a connected component of 0-cells, and one DFS floods one island.
//
// Tiny trace, grid = [[1,1,1],
//                     [1,0,1],
//                     [1,1,1]]  (n = m = 3)
//   (1,1) is new land: flag = true, dfs(1,1): all 4 neighbours are inside the
//   grid (and are water), so flag stays true -> cnt = 1.
//   With grid [[0,1],[1,1]] instead: dfs(0,0) looks up to (-1,0) -> off the
//   grid -> flag = false -> not counted.
//
// No #include or "using namespace std;": LeetCode's hidden driver code
// already includes the standard library and opens namespace std.

// LeetCode creates an object of this class and calls closedIsland() on it.
class Solution {
    public:                                   // members below are usable from outside the class
        bool vis[105][105];                   // vis[i][j] = DFS already entered (i, j); grid is at most 100 x 100
        // Direction array: {row change, column change} for up, down, left, right.
        vector<pair<int, int>> d = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        int n, m;                             // number of rows, number of columns
        bool flag;                // is the island being flooded still closed?

        // valid(i, j): is (i, j) inside the grid?
        bool valid(int i, int j){
            if(i<0 || i >= n || j<0 || j>=m){ // off any edge
                return false;
            }
            return true;
        }

        // dfs(si, sj): flood the island of 0s containing (si, sj), switching
        // flag off if any of its cells lies on the border. The recursion ends
        // by itself when no unvisited land neighbour is left.
        void dfs(vector<vector<int>>& grid, int si, int sj){
            vis[si][sj] = true;                   // mark on entry so we never re-enter
            for(int i=0; i<4; i++){               // i = which of the 4 neighbours
                int ci = si + d[i].first;         // neighbour row
                int cj = sj + d[i].second;        // neighbour column
                // A neighbour outside the grid means this land cell sits on the
                // border: the island leaks out, so it is not closed.
                if(!valid(ci, cj)){
                    flag = false;
                }
                // Keep flooding the land (0) regardless, so the whole island is
                // marked and never counted again as a new one.
                // (valid() first, so grid is never read out of range.)
                if(valid(ci, cj) && !vis[ci][cj] && grid[ci][cj]==0){
                    dfs(grid, ci, cj);            // trust it to flood the rest of the island
                }
            }
        }

        // Called by LeetCode. Returns the number of closed islands.
        int closedIsland(vector<vector<int>>& grid) {
            int cnt = 0;                          // closed islands found so far
            n = grid.size();                      // rows
            m = grid[0].size();                   // columns (length of row 0)
            // memset sets every byte of vis to 0 (false); sizeof(vis) = its size in
            // bytes. Class members are not zeroed automatically.
            memset(vis, false, sizeof(vis));

            // Scan every cell in reading order.
            for(int i=0; i<n; i++){
                for(int j=0; j<m; j++){
                    if(!vis[i][j] && grid[i][j]==0){    // a new island of land (0)
                        flag = true;                    // closed until proven otherwise
                        dfs(grid, i, j);                // flood it; may clear flag
                        if(flag==true){
                            cnt++;                      // never touched the border
                        }
                    }
                }
            }
            return cnt;           // Cost: O(n * m)
        }
    };                                        // a class definition ends with ;
