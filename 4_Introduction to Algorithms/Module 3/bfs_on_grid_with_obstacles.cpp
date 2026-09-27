// The same grid BFS as bfs_on_2d_grid.cpp, with walls that actually block.
//
// Everything below is unchanged apart from one extra test when a neighbour is
// pushed: the cell must not be a '#'. That single condition is what finally makes
// the grid characters mean something. Compare the two files side by side; the
// difference is one line.
//
// Reminder of the model: every cell (i, j) is a node of a graph; its neighbours
// are the (up to) four cells sharing a side with it; BFS from the source visits
// cells in order of distance, so level[][] ends up holding the fewest moves.
//
// Sample input (source (0,0), destination (0,2)):
//   3 3
//   .#.
//   .#.
//   ...
//   0 0 0 2
// Output: 6   (the wall in column 1 forces the route down, across, and back up:
//              (0,0)->(1,0)->(2,0)->(2,1)->(2,2)->(1,2)->(0,2))

#include <iostream>     // cin and cout
#include <vector>       // vector, used for the direction list
#include <algorithm>    // not used here; part of the usual template
#include <string>       // not used here; part of the usual template
#include <stack>        // not used here; part of the usual template
#include <queue>        // std::queue, the first-in first-out line that BFS needs
// NOTE: memset (used in main) lives in <cstring>, which is missing here. Some
// compilers find it through <iostream> anyway; GCC 8 (MinGW) reports "'memset'
// was not declared". Fix: add #include <cstring>. (The site's runner adds it.)

using namespace std;    // write queue, pair, cin... without the std:: prefix

// Globals: not limited by the small function stack, and zero-filled at start.
char grid[105][105];    // '.' is open floor, '#' is a wall
bool vis[105][105];     // vis[i][j] = cell (i, j) has already been put in the queue
int level[105][105];    // level[i][j] = fewest moves from the source; -1 = unreachable
// The four moves as {row change, column change}: right, left, up, down.
// Row numbers grow downwards, so "up" is -1.
vector<pair<int, int>> direction = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};
int n, m;               // rows and columns; global so valid() can read them

// Same in-bounds guard as before: is (i, j) still on the map?
// Returns false for any row outside 0..n-1 or column outside 0..m-1.
bool valid(int i, int j){
    if(i < 0 || i >= n || j < 0 || j >= m){   // one bad coordinate is enough
        return false;                         // outside: must not be read
    }
    return true;                              // inside the grid
}

// BFS from (si, sj). Each pass of the while loop takes the oldest waiting cell
// (the parent) and pushes every neighbour that is on the map, not yet queued, and
// not a wall. The loop ends when the queue is empty: nothing new is reachable.
void bfs(int si, int sj){
    queue<pair<int, int>> q;   // waiting cells, each as {row, column}
    q.push({si, sj});          // start with the source
    vis[si][sj] = true;        // mark on push so no cell enters the queue twice
    level[si][sj] = 0;         // the source is 0 moves from itself

    while(!q.empty()){                   // until no cell is waiting
        pair<int, int> par = q.front();  // oldest cell in the queue
        q.pop();                         // remove it
        int par_i = par.first;           // its row
        int par_j = par.second;          // its column

        // Try the four directions; i indexes the direction list.
        for(int i=0; i<4; i++){
            int ci = par_i + direction[i].first;    // neighbour's row
            int cj = par_j + direction[i].second;   // neighbour's column
            // Three tests, and the order is deliberate:
            //   valid   - is the cell on the map? (must come first, the other
            //             two read the arrays at that position)
            //   !vis    - have we already queued it?
            //   != '#'  - is it floor rather than wall?
            // A wall is simply never pushed, so it is never part of any path.
            // Nothing else about BFS needs to know that walls exist.
            // && stops at the first false, which is what keeps the reads safe.
            if(valid(ci, cj) == true && vis[ci][cj] == false && grid[ci][cj] != '#'){
                q.push({ci, cj});                          // queue it
                vis[ci][cj] = true;                        // mark it right away
                level[ci][cj] = level[par_i][par_j] + 1;   // parent's distance + 1
            }
        }
    }
}

int main(){
    cin >> n >> m;                   // rows, columns
    for(int i=0; i<n; i++){          // row by row
        for(int j=0; j<m; j++){      // column by column
            cin >> grid[i][j];       // cin >> char skips spaces/newlines, reads one symbol
        }
    }

    // si and sj source and di and dj destination
    int si, sj, di, dj;
    cin >> si >> sj >> di >> dj;        // read source and destination coordinates
    memset(vis, false, sizeof(vis));    // every byte of vis set to 0 = false
    memset(level, -1, sizeof(level));   // every byte 0xFF, which makes each int -1
    bfs(si, sj);                        // search outward from the source
    // With walls in the way the answer can be larger than the straight-line
    // distance, because the route has to go round. And if the walls seal the
    // destination off completely, level stays -1, which is the right answer.
    cout << level[di][dj] << endl;      // print the distance; endl = newline + flush
    return 0;                           // normal end of program
}