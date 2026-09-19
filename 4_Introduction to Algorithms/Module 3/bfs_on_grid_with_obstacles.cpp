// The same grid BFS as bfs_on_2d_grid.cpp, with walls that actually block.
//
// Everything below is unchanged apart from one extra test when a neighbour is
// pushed: the cell must not be a '#'. That single condition is what finally makes
// the grid characters mean something. Compare the two files side by side; the
// difference is one line.

#include <iostream>
#include <vector>
#include <algorithm>    
#include <string>
#include <stack>
#include <queue>

using namespace std;

char grid[105][105];    // '.' is open floor, '#' is a wall
bool vis[105][105];
int level[105][105];
vector<pair<int, int>> direction = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};
int n, m;

// Same in-bounds guard as before: is (i, j) still on the map?
bool valid(int i, int j){
    if(i < 0 || i >= n || j < 0 || j >= m){
        return false;
    }
    return true;
}

void bfs(int si, int sj){
    queue<pair<int, int>> q;
    q.push({si, sj});
    vis[si][sj] = true;
    level[si][sj] = 0;

    while(!q.empty()){
        pair<int, int> par = q.front();
        q.pop();
        int par_i = par.first;
        int par_j = par.second;

        for(int i=0; i<4; i++){
            int ci = par_i + direction[i].first;
            int cj = par_j + direction[i].second;
            // Three tests, and the order is deliberate:
            //   valid   - is the cell on the map? (must come first, the other
            //             two read the arrays at that position)
            //   !vis    - have we already queued it?
            //   != '#'  - is it floor rather than wall?
            // A wall is simply never pushed, so it is never part of any path.
            // Nothing else about BFS needs to know that walls exist.
            if(valid(ci, cj) == true && vis[ci][cj] == false && grid[ci][cj] != '#'){
                q.push({ci, cj});
                vis[ci][cj] = true;
                level[ci][cj] = level[par_i][par_j] + 1;
            }
        }
    }
}

int main(){
    cin >> n >> m;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin >> grid[i][j];
        }
    }

    // si and sj source and di and dj destination
    int si, sj, di, dj;
    cin >> si >> sj >> di >> dj;
    memset(vis, false, sizeof(vis));
    memset(level, -1, sizeof(level));
    bfs(si, sj);
    // With walls in the way the answer can be larger than the straight-line
    // distance, because the route has to go round. And if the walls seal the
    // destination off completely, level stays -1, which is the right answer.
    cout << level[di][dj] << endl;
    return 0;
}