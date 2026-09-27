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

// Same solution as leetcode_number_of_closed_islands.cpp, with the flood done
// by BFS (a queue of cells) instead of recursive DFS. The rule is unchanged:
// 0 is land, and an island whose flood tries to step off the grid touches the
// border, so it is not closed. BFS has one advantage on big grids: no deep
// recursion, so no risk of running out of stack.
//
// BFS in one sentence: a queue is first-in-first-out, so cells are handled in
// the order they were discovered, and the flood spreads out ring by ring
// from the start cell.
//
// Tiny trace, grid = [[1,1,1,1],
//                     [1,0,0,1],
//                     [1,1,1,1]]
//   (1,1) is new land: flag = true, bfs: queue {(1,1)}
//     take (1,1): neighbours all inside; (1,2) is land -> push. queue {(1,2)}
//     take (1,2): neighbours all inside, nothing new.       queue {}
//   flag still true -> cnt = 1.
//
// No #include or "using namespace std;": LeetCode's hidden driver code
// already includes the standard library and opens namespace std.

// LeetCode creates an object of this class and calls closedIsland() on it.
class Solution {
    public:                                   // members below are usable from outside the class
        bool vis[105][105];                   // vis[i][j] = cell (i, j) already pushed into a queue; grid is at most 100 x 100
        // Direction array: {row change, column change} for up, down, left, right.
        vector<pair<int, int>> d = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        int n, m;                             // number of rows, number of columns
        bool flag;                // is the current island still closed?

        // valid(i, j): is (i, j) inside the grid?
        bool valid(int i, int j){
            if(i<0 || i >= n || j<0 || j>=m){ // off any edge
                return false;
            }
            return true;
        }

        // bfs(si, sj): flood the island of 0s containing (si, sj) using a queue,
        // switching flag off if any of its cells lies on the border.
        void bfs(vector<vector<int>>& grid, int si, int sj){
            queue<pair<int, int>> q;              // queue of cells, each a pair {row, column}
            q.push({si, sj});                     // start cell goes in first
            vis[si][sj] = true;                   // mark when PUSHED so no cell is queued twice

            // One pass = handle the oldest cell in the queue. Stops when the
            // queue is empty = the whole island has been handled.
            while(!q.empty()){
                pair<int, int> par = q.front();   // front() reads the oldest cell ("parent")
                q.pop();                          // pop() removes it
                int par_i = par.first;            // its row
                int par_j = par.second;           // its column

                for(int i=0; i<4; i++){           // i = which of the 4 neighbours
                    int ci = par_i + d[i].first;  // neighbour row
                    int cj = par_j + d[i].second; // neighbour column

                    // Off the grid: this island touches the border.
                    if(!valid(ci, cj)){
                        flag = false;
                    }

                    // Queue land neighbours not yet seen (mark when pushed).
                    // (valid() first, so grid is never read out of range.)
                    if(valid(ci, cj) && !vis[ci][cj] && grid[ci][cj]==0){
                        q.push({ci, cj});
                        vis[ci][cj] = true;
                    }
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

            // Scan every cell; each unvisited 0 starts a new island.
            for(int i=0; i<n; i++){
                for(int j=0; j<m; j++){
                    if(!vis[i][j] && grid[i][j]==0){
                        flag = true;              // closed until proven otherwise
                        bfs(grid, i, j);          // flood it; may clear flag
                        if(flag==true){
                            cnt++;                // never touched the border -> closed
                        }
                    }
                }
            }
            return cnt;           // Cost: O(n * m)
        }
    };                                        // a class definition ends with ;
