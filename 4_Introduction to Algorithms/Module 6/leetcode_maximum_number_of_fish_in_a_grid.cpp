/*

https://leetcode.com/problems/maximum-number-of-fish-in-a-grid/description/

2658. Maximum Number of Fish in a Grid

You are given a 0-indexed 2D matrix grid of size m x n, where (r, c) represents:

A land cell if grid[r][c] = 0, or
A water cell containing grid[r][c] fish, if grid[r][c] > 0.
A fisher can start at any water cell (r, c) and can do the following operations any number of
times:

- Catch all the fish at cell (r, c), or
- Move to any adjacent water cell.
Return the maximum number of fish the fisher can catch if he chooses his starting cell
optimally, or 0 if no water cell exists.

An adjacent cell of the cell (r, c), is one of the cells (r, c + 1), (r, c - 1), (r + 1, c) or
(r - 1, c) if it exists.

*/

// A second go at the Module 5 problem, now as Practice Day revision. The water
// cells that touch form "ponds" (components on a grid). The fisher can walk
// anywhere inside one pond but can never cross land, so the best he can do is
// empty the richest pond. Answer = the largest total of fish over all ponds.
// So: one DFS per pond, adding up fish as it goes, and keep the biggest sum.
//
// There is no #include, no using namespace std and no main(): LeetCode wraps
// this class in its own code that supplies them and calls findMaxFish().
//
// Tiny trace: grid = {{0,2,1,0},
//                     {4,0,0,3},
//                     {1,0,0,4},
//                     {0,3,2,0}}
// Ponds: {2,1} = 3, {4,1} = 5, {3,4} = 7, {3,2} = 5. Answer 7.

class Solution {
    public:             // LeetCode's code must be able to call findMaxFish
        // The data below are members of the class: every member function
        // (valid, dfs, findMaxFish) can read and change them directly.
        bool vis[55][55];   // the grid is at most 10 x 10, so 55 is plenty
            // left, right, up, down  (row change, column change)
            // The direction trick: adding d[i] to (si, sj) gives the i-th
            // neighbour, so one loop replaces four copied if-blocks.
            vector<pair<int, int>> d = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}};
            // n, m = grid size; total = fish in the pond being flooded now;
            // mx = best pond seen so far. Members, so dfs() can update them.
            int n, m, total, mx;

            // Is (i, j) inside the grid? Returns true if 0 <= i < n and 0 <= j < m.
            bool valid(int i, int j){
                if(i<0 || i >= n || j<0 || j >= m){   // off any edge
                    return false;
                } else{
                    return true;
                }
            }

            // Flood one pond from (si, sj), collecting its fish into total.
            // grid is passed by reference (&) so the 2D vector is not copied on
            // every recursive call. Recursion stops on its own when no
            // neighbour is new water; each call then returns to its caller.
            void dfs(int si, int sj, vector<vector<int>> &grid){
                vis[si][sj] = true;             // mark first so we never come back here
                total = total + grid[si][sj];   // catch the fish in this cell

                for(int i=0; i<4; i++){          // try each of the 4 directions
                    int ci = si + d[i].first;    // neighbour's row
                    int cj = sj + d[i].second;   // neighbour's column
                    // Only water (> 0) is walkable; 0 is land and stops us.
                    // valid() comes first, so grid[ci][cj] is never read off the grid.
                    if(valid(ci, cj) && !vis[ci][cj] && grid[ci][cj] > 0){
                        dfs(ci, cj, grid);       // keep flooding from there
                    }
                }
            }

        // Entry point called by LeetCode. Returns the most fish in one pond.
        int findMaxFish(vector<vector<int>>& grid) {
            n = grid.size();           // number of rows (how many inner vectors)
                m = grid[0].size();    // number of columns (length of row 0)
                mx = 0;   // 0 is also the right answer when there is no water

                // LeetCode reuses one Solution object for many tests, so wipe
                // the member array every call. memset(array, value, bytes)
                // fills every byte; sizeof(vis) = total bytes of the array.
                memset(vis, false, sizeof(vis));

                // Every unvisited water cell starts a new pond.
                for(int i=0; i<n; i++){
                    for(int j=0; j<m; j++){
                        if(!vis[i][j] && grid[i][j] > 0){
                            total = 0;            // fresh counter for this pond
                            dfs(i, j, grid);      // total = fish in the pond
                            mx = max(total, mx);  // keep the richest one
                        }
                    }
                }

                return mx;   // O(n * m): each cell is flooded at most once
        }
    };   // a class definition must end with a semicolon