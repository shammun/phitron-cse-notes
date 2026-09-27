/*

Maze

Problem Statement

Rezia is trapped in a 2D maze of N X M size, starting at position R, and her goal is to reach the exit marked by D. The maze 
contains blocks represented by #, and she can only traverse through cells marked with dots (.). As she need to escape as early 
as possible, we need to determine the path she will follow.

Place an X in each cell representing Rezia's route to exit the maze. If there is no viable path for her to exit, leave the 
maze unchanged.

Note: Rezia can move in four directions – right, left, up, and down. It is crucial to adhere to the specified order: 
attempting right first, then left, followed by up, and finally down.

Input Format

- First line will contain N and M.
- Next you will be given the 2D matrix.

Constraints
1. 1 <= N, M <= 10^3

Output Format

- Output the final maze with marked X indicating the path she will follow.

Sample Input 0
5 6
...D.#
.##..#
....#.
.R#...
.#.##.

Sample Output 0
...D.#
.##X.#
.XXX#.
.R#...
.#.##.

Sample Input 1
5 6
...D.#
.R...#
....#.
..#...
.#.##.

Sample Output 1
...D.#
.RXX.#
....#.
..#...
.#.##.

Sample Input 2
5 6
...D.#
.....#
.##.#.
.R#...
.#.##.

Sample Output 2
...D.#
XXXX.#
X##.#.
XR#...
.#.##.

Sample Input 3
5 6
...D.#
.....#
###.#.
.R#...
.#.##.

Sample Output 3
...D.#
.....#
###.#.
.R#...
.#.##.

*/

// Mid-term question 4. "Escape as early as possible" = a shortest route in a
// grid where every step costs the same, so it is BFS (Module 2 + Module 3's grid
// BFS). To draw the route we also need path printing (Module 2's
// path_printing.cpp): while BFS runs, remember for each cell which cell it was
// discovered from. Afterwards, walk those parent links backwards from D to R and
// put an 'X' on every cell in between.
//
// The fixed move order (right, left, up, down) matters because several shortest
// routes can exist; trying the directions in the order the problem states makes
// BFS pick the same one the judge expects.
//
// Sample 1 trace: R is at (1,1), D at (0,3). BFS reaches (1,2) (right of R),
// then (1,3), then D = (0,3) from (1,3) by moving up. Parent links:
// D <- (1,3) <- (1,2) <- R. Walking back from D marks (1,3) and (1,2) with X,
// giving the row ".RXX.#" in the output.

#include <iostream>     // cin / cout
#include <cstring>      // memset (clears vis)
#include <vector>       // vector (the list of directions)
#include <queue>        // queue: the BFS "to do" list, first in first out
#include <algorithm>    // reverse, min ... (not actually used here)

using namespace std;    // lets us write queue, pair, cout without std::

// Globals: shared by bfs() and main(); big arrays live in static memory
// (too big for the stack) and start filled with 0 / false.
int n, m;               // n rows, m columns
char maze[1005][1005];  // the maze: '.', '#', 'R', 'D' (and later 'X')
bool vis[1005][1005];   // vis[i][j] = true once BFS has put (i, j) in the queue
// right, left, up, down: exactly the order the problem demands
// Each pair is {row change, column change}: {0,1} = same row, one column right.
vector<pair<int, int>> direction = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};
// path[i][j] = the cell BFS came from when it first reached (i, j)
// (the "parent" array of path printing, but for a grid: each parent is a
//  {row, column} pair instead of one node number)
pair<int, int> path[1005][1005];

// true if (i, j) is inside the maze, false if it is off the edge.
bool valid(int i, int j){
    if(i <0 || i>=n || j<0 || j>=m){
        return false;
    }
    return true;
}

// An earlier attempt, kept for comparison. DFS marks cells with 'X' on the way
// in and rubs them out when it backtracks, so it does find A route, but DFS
// does not find the SHORTEST route. That is why the solution below uses BFS.
// (It would also need a global "bool flag = false;" before it could compile.)
/*

void dfs(int si, int sj, int di, int dj){
    if(si == di && sj == dj){
        flag = true;
        return;
    }

    vis[si][sj] = true;

    for(int i=0; i<4; i++){
        int ci = si + direction[i].first;
        int cj = sj + direction[i].second;

        if(valid(ci, cj) && !vis[ci][cj] && maze[ci][cj] != '#'){
            if(maze[ci][cj] == '.'){
                maze[ci][cj] = 'X';
            }

            dfs(ci, cj, di, dj);

            if(flag){
                return;
            }

            if(maze[ci][cj] == 'X'){
                maze[ci][cj] = '.';
            }
        }
    }
}

*/

// BFS from R (si, sj). Returns true if D (di, dj) can be reached, and fills
// path[][] with parent links along the way.
// Because BFS reaches cells in order of distance (all 1-step cells, then all
// 2-step cells, ...), the parent links it records always describe a SHORTEST
// route back to R.
bool bfs(int si, int sj, int di, int dj){
    // {-1, -1} = "no parent yet"
    // Outer loop = rows, inner loop = columns: every cell of the maze.
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            path[i][j] = {-1, -1};   // {a, b} builds a pair
        }
    }

    queue<pair<int, int>> q;   // cells found but not yet expanded, {row, col}
    q.push({si, sj});          // start from R
    vis[si][sj] = true;        // R is seen; never push it again

    // One pass: take the oldest cell, push each new walkable neighbour.
    // Ends when the queue is empty (D unreachable) or D is taken out.
    while(!q.empty()){
        pair<int, int> par = q.front();   // oldest cell in the queue
        q.pop();                          // remove it

        int par_i = par.first;            // its row
        int par_j = par.second;           // its column

        if(par_i == di && par_j == dj){
            return true;   // reached the exit; the parent links are complete
        }

        // Try the 4 moves in the required order: right, left, up, down.
        for(int i=0; i<4; i++){
            int ci = par_i + direction[i].first;    // neighbour's row
            int cj = par_j + direction[i].second;   // neighbour's column

            // Anything but a wall '#' is walkable ('.', and 'D' itself).
            // valid() first: && stops early, so no out-of-range reads.
            if(valid(ci, cj) && !vis[ci][cj] && maze[ci][cj] != '#'){
                q.push({ci, cj});                 // expand it later
                vis[ci][cj] = true;               // mark when pushed, so no duplicates
                path[ci][cj] = {par_i, par_j};   // remember where we came from
            }
        }
    }

    return false;   // D is walled off from R
}



int main(){
    cin >> n >> m;       // maze size

    int s_i=0, s_j=0, d_i=0, d_j=0;   // R = (s_i, s_j), D = (d_i, d_j)

    // Read the maze and note where R (start) and D (exit) are.
    // cin >> char skips newlines, so each row gives m separate characters.
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin >> maze[i][j];
            if(maze[i][j] == 'R'){
                s_i = i;         // remember the start
                s_j = j;
            } else if(maze[i][j] == 'D'){
                d_i = i;         // remember the exit
                d_j= j;
            }
        }
    }

    // Set every byte of vis to 0 (false). Already false as a global; a habit.
    memset(vis, false, sizeof(vis));


    // A guard for a maze without R or D. (It never fires as written, because
    // s_i and d_i start at 0, not -1; the problem always gives both cells.)
    if(s_i == -1 || d_i == -1) {
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                cout << maze[i][j];      // print the maze unchanged
            }
            cout << endl;
        }
        return 0;
    }

    if(bfs(s_i, s_j, d_i, d_j)){
        // Walk back from D along the parent links until we get to R.
        // (d2_i, d2_j) = the cell we are standing on during the walk; it
        // starts at D, and D itself is never overwritten with X.
        int d2_i = d_i;
        int d2_j = d_j;
        // Keep going while we are not yet standing on R.
        while(!(s_i == d2_i && s_j == d2_j)){
            pair<int, int> par = path[d2_i][d2_j];   // one step back towards R
            if(par.first == s_i && par.second == s_j){
                break;   // the next cell is R itself: R keeps its letter
            }
            if(maze[par.first][par.second] == '.'){
                maze[par.first][par.second] = 'X';   // this cell is on the route
            }
            d2_i = par.first;    // step back onto the parent cell
            d2_j = par.second;
        }
    }
    // If BFS failed, nothing was marked: the maze is printed unchanged.

    // Print the maze row by row, one character per cell, no spaces.
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cout << maze[i][j];
        }
        cout << endl;            // end of the row
    }

    // O(N * M) for the BFS, plus at most N * M steps to walk the route back.
    return 0;
}
