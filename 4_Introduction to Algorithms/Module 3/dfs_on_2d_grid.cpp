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

#include <iostream>
#include <vector>
#include <algorithm>    
#include <string>
#include <stack>
#include <queue>

using namespace std;

char grid[105][105];
bool vis[105][105];
// right, left, up, down; the order here decides the shape of the walk
vector<pair<int, int>> direction = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};
int n, m;

bool valid(int i, int j){
    if(i < 0 || i >= n || j < 0 || j >= m){
        return false;
    }
    return true;
}

void dfs(int si, int sj){
    cout << si << " " << sj << endl;   // printed on entry, like the graph DFS
    vis[si][sj] = true;

    for(int i=0; i<4; i++){
        int ci = si + direction[i].first;
        int cj = sj + direction[i].second;
        // valid() first, then the visited test, because vis[ci][cj] may only be
        // read once we know (ci, cj) is really a cell of the grid.
        if(valid(ci, cj) && !vis[ci][cj]){
            dfs(ci, cj);   // step into it now; the rest of this loop waits
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

    int si, sj;
    cin >> si >> sj;
    memset(vis, false, sizeof(vis));
    dfs(si, sj);

    // Like the plain grid BFS, this version ignores the characters it read, so
    // walls do not stop it. To make them stop it, add grid[ci][cj] != '#' to the
    // if above, exactly as bfs_on_grid_with_obstacles.cpp does.
    //
    // Worth knowing: the recursion can go as deep as the number of cells, so a
    // full 1000x1000 grid means a million nested calls. That is a lot of stack.

    return 0;
}