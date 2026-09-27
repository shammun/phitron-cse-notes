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

#include <iostream>
#include <vector>
#include <queue>
#include <cstring>      // memset

using namespace std;

char grid[1005][1005];          // the map, one character per cell
bool vis[1005][1005];           // vis[i][j] = has cell (i, j) been queued?
// The 4 moves as {row change, column change}: right, left, up, down.
vector<pair<int, int>> direction = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};
int n, m;                       // global so valid() can see the grid size

// Is (i, j) inside the map?
bool valid(int i, int j){
    if(i < 0 || i >= n || j < 0 || j >= m){
        return false;
    }
    return true;
}

// BFS from A; returns true as soon as B leaves the queue.
bool bfs(int Ai, int Aj, int Bi, int Bj){
    queue<pair<int, int>> q;    // the queue now holds cells: (row, col) pairs
    q.push({Ai, Aj});
    vis[Ai][Aj] = true;

    while(!q.empty()){
        pair<int, int> par = q.front();
        q.pop();
        int par_i = par.first;
        int par_j = par.second;

        if(par_i == Bi && par_j == Bj){
            return true;        // reached room B: stop early, the answer is known
        }

        for(int i=0; i<4; i++){
            int ci = par_i + direction[i].first;    // the child cell
            int cj = par_j + direction[i].second;
            // Step only onto cells inside the map, not yet queued and not a wall.
            // valid() comes first so grid[ci][cj] is never read out of range.
            // (Floor '.', and the rooms 'A' and 'B', all count as walkable.)
            if(valid(ci, cj) && vis[ci][cj] == false && grid[ci][cj] != '#'){
                q.push({ci, cj});
                vis[ci][cj] = true;
            }
        }
    }
    return false;               // the queue ran dry without meeting B
}

int main(){
    cin >> n >> m;

    // -999 = "not seen yet"; the map is promised to contain both rooms.
    int Ai = -999, Aj = -999, Bi = -999, Bj = -999;

    // Read the map cell by cell (cin >> char skips the line breaks) and note
    // where A and B are while we are at it.
    for(int i=0; i < n; i++){
        for(int j=0; j<m; j++){
            cin >> grid[i][j];
            if(grid[i][j] == 'A'){
                Ai = i;
                Aj = j;
            } else if(grid[i][j] == 'B'){
                Bi = i;
                Bj = j;
            }
        }
    }

    memset(vis, false, sizeof(vis));
    bool result = bfs(Ai, Aj, Bi, Bj);

    if(result){
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
    // Cost: O(N * M), each cell is queued at most once.
}
