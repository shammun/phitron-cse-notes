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

#include <iostream>
#include <cstring>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int n, m;
char maze[1005][1005];
bool vis[1005][1005];
// right, left, up, down: exactly the order the problem demands
vector<pair<int, int>> direction = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};
// path[i][j] = the cell BFS came from when it first reached (i, j)
pair<int, int> path[1005][1005];

bool valid(int i, int j){
    if(i <0 || i>=n || j<0 || j>=m){
        return false;
    }
    return true;
}

// An earlier attempt, kept for comparison. DFS marks cells with 'X' on the way
// in and rubs them out when it backtracks, so it does find A route, but DFS
// does not find the SHORTEST route. That is why the solution below uses BFS.
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
bool bfs(int si, int sj, int di, int dj){
    // {-1, -1} = "no parent yet"
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            path[i][j] = {-1, -1};
        }
    }

    queue<pair<int, int>> q;
    q.push({si, sj});
    vis[si][sj] = true;

    while(!q.empty()){
        pair<int, int> par = q.front();
        q.pop();

        int par_i = par.first;
        int par_j = par.second;

        if(par_i == di && par_j == dj){
            return true;   // reached the exit; the parent links are complete
        }

        for(int i=0; i<4; i++){
            int ci = par_i + direction[i].first;
            int cj = par_j + direction[i].second;

            // Anything but a wall '#' is walkable ('.', and 'D' itself).
            if(valid(ci, cj) && !vis[ci][cj] && maze[ci][cj] != '#'){
                q.push({ci, cj});
                vis[ci][cj] = true;
                path[ci][cj] = {par_i, par_j};   // remember where we came from
            }
        }
    }

    return false;   // D is walled off from R
}



int main(){
    cin >> n >> m;

    int s_i=0, s_j=0, d_i=0, d_j=0;

    // Read the maze and note where R (start) and D (exit) are.
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin >> maze[i][j];
            if(maze[i][j] == 'R'){
                s_i = i;
                s_j = j;
            } else if(maze[i][j] == 'D'){
                d_i = i;
                d_j= j;
            }
        }
    }

    memset(vis, false, sizeof(vis));


    // A guard for a maze without R or D. (It never fires as written, because
    // s_i and d_i start at 0, not -1; the problem always gives both cells.)
    if(s_i == -1 || d_i == -1) {
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                cout << maze[i][j];
            }
            cout << endl;
        }
        return 0;
    }

    if(bfs(s_i, s_j, d_i, d_j)){
        // Walk back from D along the parent links until we get to R.
        int d2_i = d_i;
        int d2_j = d_j;
        while(!(s_i == d2_i && s_j == d2_j)){
            pair<int, int> par = path[d2_i][d2_j];   // one step back towards R
            if(par.first == s_i && par.second == s_j){
                break;   // the next cell is R itself: R keeps its letter
            }
            if(maze[par.first][par.second] == '.'){
                maze[par.first][par.second] = 'X';   // this cell is on the route
            }
            d2_i = par.first;
            d2_j = par.second;
        }
    }
    // If BFS failed, nothing was marked: the maze is printed unchanged.

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cout << maze[i][j];
        }
        cout << endl;
    }

    // O(N * M) for the BFS, plus at most N * M steps to walk the route back.
    return 0;
}
