// BFS on a 2D grid: the same search, on a graph nobody built.
//
// A grid of cells is already a graph in disguise. Cell (i, j) is a node, and its
// neighbours are the four cells sharing a side with it. The only difference from
// Module 2 is that there is no adj_list to look the neighbours up in: they are
// worked out by arithmetic, by adding a small offset to the row and the column.
// Nothing else about BFS changes. Queue, mark on push, level = parent's level + 1.
//
// A node is now two numbers instead of one, so the queue holds pair<int,int>, and
// vis and level become 2D arrays indexed the same way as the grid.

#include <iostream>
#include <vector>
#include <algorithm>    
#include <string>
#include <stack>
#include <queue>

using namespace std;

char grid[105][105];    // the map as read; 105 leaves room for a 100x100 grid
bool vis[105][105];     // vis[i][j] = has cell (i, j) already been queued?
int level[105][105];    // level[i][j] = fewest steps from the source to (i, j)

// The four moves, written as (row change, column change):
//   {0, 1}  same row, one column right
//   {0, -1} same row, one column left
//   {-1, 0} one row up   (row numbers grow downwards, so up is -1)
//   {1, 0}  one row down
// Keeping them in a list means the code says "for each of the four directions"
// once, instead of repeating almost the same four blocks. Add {1,1}, {1,-1},
// {-1,1}, {-1,-1} to this list and the same code walks diagonally too.
vector<pair<int, int>> direction = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};
int n, m;   // rows and columns; global so valid() can see them

// The guard that makes the arithmetic safe. Adding an offset to a cell on the
// edge of the map produces a row or column outside the grid, and reading such a
// cell is undefined behaviour. So every computed neighbour is checked first:
// the row must be in 0..n-1 and the column in 0..m-1.
bool valid(int i, int j){
    if(i < 0 || i >= n || j < 0 || j >= m){
        return false;
    }
    return true;
}

void bfs(int si, int sj){
    queue<pair<int, int>> q;
    q.push({si, sj});
    vis[si][sj] = true;    // marked on push, for the same reason as in Module 2
    level[si][sj] = 0;

    while(!q.empty()){
        pair<int, int> par = q.front();
        q.pop();
        int par_i = par.first;     // unpacked into two plain ints, easier to read
        int par_j = par.second;

        // Instead of "for each neighbour in adj_list[par]", here it is "for each
        // of the four directions", and the neighbour is computed on the spot.
        for(int i=0; i<4; i++){
            int ci = par_i + direction[i].first;    // child row
            int cj = par_j + direction[i].second;   // child column

            // Order matters: valid() must be asked first, because the second test
            // reads vis[ci][cj], and that read is only safe inside the grid.
            if(valid(ci, cj) == true && vis[ci][cj] == false){
                q.push({ci, cj});
                vis[ci][cj] = true;
                level[ci][cj] = level[par_i][par_j] + 1;
            }
        }
    }
}

int main(){
    cin >> n >> m;
    // cin >> a char skips spaces and newlines, so a row typed as .... is read one
    // character at a time and the line breaks look after themselves.
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin >> grid[i][j];
        }
    }

    // si and sj source and di and dj destination
    int si, sj, di, dj;
    cin >> si >> sj >> di >> dj;
    memset(vis, false, sizeof(vis));
    memset(level, -1, sizeof(level));   // -1 = never reached
    bfs(si, sj);
    // Every step costs one, so the BFS level is the fewest moves. A -1 here means
    // the destination could not be reached at all.
    cout << level[di][dj] << endl;

    // Note what this version does NOT do: it reads the grid characters but never
    // looks at them, so a wall is walked straight through. The next file,
    // bfs_on_grid_with_obstacles.cpp, adds the one test that fixes that.
    //
    // Cost: n*m cells, four neighbours each, so O(n*m) time and memory.
    return 0;
}