// DFS on a 2D grid.
//
// Two ideas you already have, put together: the recursion of dfs.cpp and the
// cell-is-a-node trick of bfs_on_2d_grid.cpp. A cell's neighbours are still the
// four cells around it, computed with the direction list rather than looked up,
// and valid() still keeps the arithmetic inside the map.
//
// Only the order of visiting differs. BFS spread out evenly in rings; DFS runs as
// far as it can in the first direction of the list before it ever tries the
// second. With the directions in the order right, left, up, down, that comes out
// looking like a snake: along the top row to the wall, down one, back along the
// second row, and so on.
//
// Tiny trace on a 2x3 grid from (0,0):
//   (0,0) -> right (0,1) -> right (0,2) -> right is off the map, left/up fail,
//   down (1,2) -> right off map, left (1,1) -> left (1,0).
// Output lines: 0 0 / 0 1 / 0 2 / 1 2 / 1 1 / 1 0   (the snake)

#include <iostream>     // cin and cout
#include <vector>       // vector, used for the direction list
#include <algorithm>    // not used here; part of the usual template
#include <string>       // not used here; part of the usual template
#include <stack>        // not used: recursion provides the stack
#include <queue>        // not used: DFS needs no queue
// NOTE: memset (used in main) lives in <cstring>, which is not included here.
// Some compilers reach it through <iostream>; GCC 8 (MinGW) reports "'memset'
// was not declared". Fix: add #include <cstring>.

using namespace std;    // write vector, pair, cout... without std::

char grid[105][105];    // the map as typed; up to 100x100 with a little spare room
bool vis[105][105];     // vis[i][j] = dfs has already entered cell (i, j)
// right, left, up, down; the order here decides the shape of the walk
// Each pair is {row change, column change}; rows grow downwards, so up = -1.
vector<pair<int, int>> direction = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};
int n, m;               // rows and columns; global so valid() can see them

// Is (i, j) inside the n x m grid? Row must be 0..n-1, column 0..m-1.
bool valid(int i, int j){
    if(i < 0 || i >= n || j < 0 || j >= m){   // any coordinate out of range
        return false;                         // -> not a real cell
    }
    return true;                              // a real cell of the grid
}

// Enter cell (si, sj), then go deep into each unvisited neighbour in turn.
// Base case: when no neighbour is valid and unvisited the loop does nothing and
// the call returns (that return is the "back up one step").
void dfs(int si, int sj){
    cout << si << " " << sj << endl;   // printed on entry, like the graph DFS
    vis[si][sj] = true;                // mark before recursing so we never come back

    for(int i=0; i<4; i++){                     // i = which of the four directions
        int ci = si + direction[i].first;       // neighbour's row
        int cj = sj + direction[i].second;      // neighbour's column
        // valid() first, then the visited test, because vis[ci][cj] may only be
        // read once we know (ci, cj) is really a cell of the grid.
        if(valid(ci, cj) && !vis[ci][cj]){
            dfs(ci, cj);   // step into it now; the rest of this loop waits
        }
    }
}

int main(){
    cin >> n >> m;                   // grid size
    for(int i=0; i<n; i++){          // each row
        for(int j=0; j<m; j++){      // each column
            cin >> grid[i][j];       // one character; cin >> char skips whitespace
        }
    }

    int si, sj;
    cin >> si >> sj;                    // starting cell
    memset(vis, false, sizeof(vis));    // clear every vis entry to false
    dfs(si, sj);                        // walk from the start

    // Like the plain grid BFS, this version ignores the characters it read, so
    // walls do not stop it. To make them stop it, add grid[ci][cj] != '#' to the
    // if above, exactly as bfs_on_grid_with_obstacles.cpp does.
    //
    // Worth knowing: the recursion can go as deep as the number of cells, so a
    // full 1000x1000 grid means a million nested calls. That is a lot of stack.

    return 0;   // normal end of program
}