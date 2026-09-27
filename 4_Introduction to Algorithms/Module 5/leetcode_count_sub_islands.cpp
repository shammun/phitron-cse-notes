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
//
// Grid as a graph: every cell (i, j) is a node, and it has an edge to its 4
// side neighbours (up, down, left, right). An "island" is then one connected
// component of land cells, and a DFS started on one land cell visits exactly
// that island.
//
// Tiny trace (one island of grid2 made of cells (0,0) and (0,1)):
//   grid1 row 0 = 1 0 ...   grid2 row 0 = 1 1 ...
//   dfs(0,0): grid1[0][0] = 1 -> fine; step right to (0,1)
//   dfs(0,1): grid1[0][1] = 0 -> flag = false -> this island is NOT counted.
//
// No #include or "using namespace std;" here: this is a LeetCode solution, and
// LeetCode's hidden driver code already includes the standard library (vector,
// queue, memset, ...) and opens namespace std before our class is compiled.

// LeetCode calls the member function countSubIslands() on an object of this
// class. "class" groups data (the member variables) and functions together.
class Solution {
    public:                                   // everything below can be used from outside the class (LeetCode needs that)
        // vis[i][j] = true once cell (i, j) has been entered by a DFS.
        // 505 x 505 because the grids are at most 500 x 500 (a little spare room).
        bool vis[505][505];
        // Direction array: the 4 moves as {row change, column change}:
        // {-1,0} = up, {1,0} = down, {0,-1} = left, {0,1} = right.
        // Adding d[i] to a cell gives its i-th neighbour, so one small loop
        // replaces four copy-pasted if-blocks.
        vector<pair<int, int>> d = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        int n, m;                 // n = number of rows, m = number of columns (members, so valid() can see them)
        bool flag;                // still a sub-island? (for the island being flooded)

        // valid(i, j): is (i, j) inside the grid? Rows go 0..n-1, columns 0..m-1.
        bool valid(int i, int j){
            if(i<0 || i >= n || j<0 || j>=m){ // any coordinate off the edge ...
                return false;                 // ... -> outside the grid
            }
            return true;                      // otherwise it is a real cell
        }

        // dfs: flood (visit) the whole grid2 island that contains (si, sj).
        // Parameters: both grids are passed by reference (&) so they are not
        // copied on every call; (si, sj) = the current land cell of grid2.
        // No explicit base case: the recursion stops by itself when no
        // unvisited land neighbour is left (the for loop then calls nothing).
        void dfs(vector<vector<int>>& grid1, vector<vector<int>>& grid2, int si, int sj){
            vis[si][sj] = true;                   // mark first, so we never come back here
            // This cell is land in grid2; is it land in grid1 as well?
            if(grid1[si][sj] == 0){               // 0 = water in grid1
                flag = false;     // no -> the whole island fails
            }
            // Keep flooding anyway, even after a failure: if we stopped here,
            // the rest of this island would stay unvisited and later be taken
            // for a separate island.
            // One pass = look at one of the 4 neighbours (i = direction index 0..3).
            for(int i=0; i<4; i++){
                int ci = si + d[i].first;         // neighbour's row    (.first  = row change)
                int cj = sj + d[i].second;        // neighbour's column (.second = column change)
                // Go there only if: inside the grid (checked FIRST, so grid2[ci][cj]
                // is never read out of range - && stops at the first false),
                // not visited yet, and land in grid2.
                if(valid(ci, cj) && !vis[ci][cj] && grid2[ci][cj]==1){
                    dfs(grid1, grid2, ci, cj);    // trust it to flood everything reachable from (ci, cj)
                }
            }
        }

        // Called by LeetCode. Returns how many islands of grid2 are sub-islands.
        int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
            int cnt = 0;                          // number of sub-islands found
            n = grid1.size();                     // .size() of the outer vector = number of rows
            m = grid1[0].size();                  // size of row 0 = number of columns
            // memset fills the raw bytes of vis with 0 (= false). sizeof(vis) is
            // the array's total size in bytes (505 * 505 here). It is needed
            // because vis is a class member, which is NOT zeroed automatically.
            memset(vis, false, sizeof(vis));

            // Scan every cell in reading order: row i, then column j.
            for(int i=0; i<n; i++){
                for(int j=0; j<m; j++){
                    // A new island of grid2.
                    // (land in grid2 that no earlier flood has reached)
                    if(!vis[i][j] && grid2[i][j]==1){
                        flag = true;                 // innocent until a cell fails
                        dfs(grid1, grid2, i, j);     // flood the whole island, checking grid1 under it
                        if(flag==true){
                            cnt++;                   // every cell sat on grid1 land
                        }
                    }
                }
            }
            return cnt;           // Cost: O(n * m) - every cell is entered at most once
        }
    };                                        // a class definition must end with ;
