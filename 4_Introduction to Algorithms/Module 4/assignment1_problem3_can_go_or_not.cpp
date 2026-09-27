/*

Problem Statement

You are given an N X M sized 2D matrix that represents a map of a building. Each cell
represents a wall, a floor or a room. You will be given two rooms A and B. You need to
tell if you can go from room A to B by passing through the floors. You can walk left,
right, up, and down through the floor cells. You can't pass through walls.

Input Format

- The first input line has two integers N and M: the height and width of the map.
- Then there are N lines of M characters describing the map. Each character is .(floor),
#(wall), A or B (rooms).

Constraints

1. 1 <= N, M <= 1000

Output Format

- Output YES if you can go from room  to , NO otherwise.

Sample Input 0

5 8
########
#.A#...#
#.##.#B#
#......#
########

Sample Output 0

YES

*/

// Idea: a grid is a graph (Module 3). Each cell is a node, its neighbours are
// the 4 cells up/down/left/right, and '#' cells simply do not exist as nodes.
// Find where A and B are, run a BFS from A over non-wall cells, and answer YES
// if B is ever taken out of the queue.
//
// Example: in the sample, A at (1,2) goes left, down to row 3, right along the
// open corridor and up to B at (2,6) -> YES.

#include <iostream>     // cin / cout
#include <vector>       // vector (used for the direction list)
#include <queue>        // queue: first-in first-out line, the heart of BFS
#include <cstring>      // memset

using namespace std;    // write queue, pair, cin ... without std::

// Globals live outside main: big arrays here do not overflow the stack, and
// global arrays start zeroed (grid all '\0', vis all false).
char grid[1005][1005];          // the map, one character per cell
bool vis[1005][1005];           // vis[i][j] = has cell (i, j) been queued?
// The 4 moves as {row change, column change}: right, left, up, down.
// This is the "dx/dy" direction array: adding direction[k] to a cell gives
// its k-th neighbour, so one small loop replaces four copied if-blocks.
// Example: from (1,2), {0,1} -> (1,3), {0,-1} -> (1,1), {-1,0} -> (0,2), {1,0} -> (2,2).
// pair<int,int> holds two ints; .first = row change, .second = column change.
vector<pair<int, int>> direction = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};
int n, m;                       // global so valid() can see the grid size

// Is (i, j) inside the map?
// Rows go 0..n-1 and columns 0..m-1; anything outside would read past the map.
bool valid(int i, int j){
    if(i < 0 || i >= n || j < 0 || j >= m){   // off any of the four edges
        return false;
    }
    return true;                // inside the map
}

// BFS from A; returns true as soon as B leaves the queue.
// Parameters: (Ai, Aj) = start cell A, (Bi, Bj) = target cell B.
// BFS works in waves: the queue hands out cells in the order they were found,
// so all cells 1 step from A come out before cells 2 steps away, and so on.
// The vis array makes sure no cell is ever queued twice (no endless loops).
bool bfs(int Ai, int Aj, int Bi, int Bj){
    queue<pair<int, int>> q;    // the queue now holds cells: (row, col) pairs
    q.push({Ai, Aj});           // start the search at room A
    vis[Ai][Aj] = true;         // mark A when it is queued, not when it is popped

    // One pass takes the oldest cell out of the queue and queues its unseen,
    // walkable neighbours. The loop stops when no cell is left to explore.
    while(!q.empty()){
        pair<int, int> par = q.front();   // front() = oldest cell in the queue ("parent")
        q.pop();                          // remove it from the queue
        int par_i = par.first;            // its row
        int par_j = par.second;           // its column

        if(par_i == Bi && par_j == Bj){
            return true;        // reached room B: stop early, the answer is known
        }

        // Try all 4 directions from the current cell.
        for(int i=0; i<4; i++){
            int ci = par_i + direction[i].first;    // the child cell
            int cj = par_j + direction[i].second;
            // Step only onto cells inside the map, not yet queued and not a wall.
            // valid() comes first so grid[ci][cj] is never read out of range.
            // (&& stops at the first false test, so the later tests are skipped.)
            // (Floor '.', and the rooms 'A' and 'B', all count as walkable.)
            if(valid(ci, cj) && vis[ci][cj] == false && grid[ci][cj] != '#'){
                q.push({ci, cj});   // explore it later
                vis[ci][cj] = true; // and never queue it again
            }
        }
    }
    return false;               // the queue ran dry without meeting B
}

int main(){
    cin >> n >> m;              // n rows (height), m columns (width)

    // -999 = "not seen yet"; the map is promised to contain both rooms.
    int Ai = -999, Aj = -999, Bi = -999, Bj = -999;

    // Read the map cell by cell (cin >> char skips the line breaks) and note
    // where A and B are while we are at it.
    // Outer loop: row i. Inner loop: column j of that row.
    for(int i=0; i < n; i++){
        for(int j=0; j<m; j++){
            cin >> grid[i][j];          // one character: '.', '#', 'A' or 'B'
            if(grid[i][j] == 'A'){      // remember where room A is
                Ai = i;
                Aj = j;
            } else if(grid[i][j] == 'B'){   // remember where room B is
                Bi = i;
                Bj = j;
            }
        }
    }

    // memset fills the whole vis array, byte by byte, with false (0).
    // sizeof(vis) = its size in bytes. It is already false (global), so this
    // is just a safety reset.
    memset(vis, false, sizeof(vis));
    bool result = bfs(Ai, Aj, Bi, Bj);  // can A reach B?

    if(result){
        cout << "YES" << endl;          // endl = newline + flush
    } else {
        cout << "NO" << endl;
    }
    // Cost: O(N * M), each cell is queued at most once.
    // (main without "return 0;" is allowed in C++: it returns 0 by itself.)
}
