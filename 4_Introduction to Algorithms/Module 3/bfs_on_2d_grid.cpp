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
//
// Sample input (3 rows, 4 columns, source (0,0), destination (2,3)):
//   3 4
//   ....
//   ....
//   ....
//   0 0 2 3
// Output: 5   (2 steps down + 3 steps right; no shorter route exists)

#include <iostream>     // cin (read input) and cout (print output)
#include <vector>       // vector: a growable array; used for the direction list
#include <algorithm>    // general algorithms (sort, min, max...); not actually used here
#include <string>       // std::string; not used here, part of the usual template
#include <stack>        // std::stack; not used here, part of the usual template
#include <queue>        // std::queue: first-in first-out line, the heart of BFS
// NOTE: memset (used in main) is declared in <cstring>, which is NOT included.
// Some compilers happen to pull it in through <iostream>; others (e.g. GCC 8 on
// Windows/MinGW) stop with "'memset' was not declared". The fix is to add
// #include <cstring> above. (The revision site's runner adds it automatically.)

using namespace std;    // lets us write cin, queue, pair... instead of std::cin, std::queue, std::pair

// Global arrays live outside every function. Two reasons: they can be big without
// overflowing the (small) function stack, and globals start out filled with zeros.
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
// pair<int, int> is two ints glued together; .first is the row change and
// .second the column change. The {{...}, {...}} braces fill the vector at once.
vector<pair<int, int>> direction = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};
int n, m;   // rows and columns; global so valid() can see them

// The guard that makes the arithmetic safe. Adding an offset to a cell on the
// edge of the map produces a row or column outside the grid, and reading such a
// cell is undefined behaviour. So every computed neighbour is checked first:
// the row must be in 0..n-1 and the column in 0..m-1.
// Parameters: i = row, j = column. Returns true if (i, j) is on the map.
bool valid(int i, int j){
    if(i < 0 || i >= n || j < 0 || j >= m){   // || = "or": any one failure is enough
        return false;                         // off the map (e.g. row -1 or column m)
    }
    return true;                              // all four tests passed: inside the grid
}

// BFS from the source cell (si, sj). Fills vis[][] and level[][] for every cell
// it can reach. One pass of the while loop takes the oldest cell out of the
// queue and pushes its not-yet-seen neighbours; because the queue is FIFO, all
// cells at distance d come out before any cell at distance d+1.
void bfs(int si, int sj){
    queue<pair<int, int>> q;   // the waiting line of cells, each stored as {row, column}
    q.push({si, sj});          // {si, sj} builds a pair on the spot; the source goes in first
    vis[si][sj] = true;    // marked on push, for the same reason as in Module 2:
                           // so the same cell is never put into the queue twice
    level[si][sj] = 0;     // the source is 0 steps away from itself

    while(!q.empty()){                 // keep going while some cell is still waiting
        pair<int, int> par = q.front();  // look at the oldest cell (the "parent")...
        q.pop();                         // ...and remove it from the queue
        int par_i = par.first;     // unpacked into two plain ints, easier to read
        int par_j = par.second;    // par_j = its column

        // Instead of "for each neighbour in adj_list[par]", here it is "for each
        // of the four directions", and the neighbour is computed on the spot.
        // i is the index into direction (0 = right, 1 = left, 2 = up, 3 = down).
        for(int i=0; i<4; i++){
            int ci = par_i + direction[i].first;    // child row
            int cj = par_j + direction[i].second;   // child column
            // e.g. parent (0,0) with direction[2] = {-1,0} gives (-1,0): off the map.

            // Order matters: valid() must be asked first, because the second test
            // reads vis[ci][cj], and that read is only safe inside the grid.
            // && stops at the first false, so vis is never read for an outside cell.
            if(valid(ci, cj) == true && vis[ci][cj] == false){
                q.push({ci, cj});                          // queue the new cell
                vis[ci][cj] = true;                        // mark it now, not when popped
                level[ci][cj] = level[par_i][par_j] + 1;   // one step further than its parent
            }
        }
    }
}

int main(){
    cin >> n >> m;   // number of rows, number of columns (fills the globals)
    // cin >> a char skips spaces and newlines, so a row typed as .... is read one
    // character at a time and the line breaks look after themselves.
    for(int i=0; i<n; i++){          // i = current row
        for(int j=0; j<m; j++){      // j = current column
            cin >> grid[i][j];       // one character: '.' floor or '#' wall
        }
    }

    // si and sj source and di and dj destination
    int si, sj, di, dj;                 // source row/column, destination row/column
    cin >> si >> sj >> di >> dj;        // read all four numbers
    // memset(array, value, bytes) fills every byte of the array with value.
    // sizeof(vis) is the whole array's size in bytes, so every cell becomes false.
    memset(vis, false, sizeof(vis));
    // -1 works with memset because -1 is the byte 0xFF repeated, and an int made of
    // four 0xFF bytes is exactly -1. (memset with, say, 5 would NOT give 5.)
    memset(level, -1, sizeof(level));   // -1 = never reached
    bfs(si, sj);                        // run the search from the source
    // Every step costs one, so the BFS level is the fewest moves. A -1 here means
    // the destination could not be reached at all.
    cout << level[di][dj] << endl;      // endl prints a newline and flushes the output

    // Note what this version does NOT do: it reads the grid characters but never
    // looks at them, so a wall is walked straight through. The next file,
    // bfs_on_grid_with_obstacles.cpp, adds the one test that fixes that.
    //
    // Cost: n*m cells, four neighbours each, so O(n*m) time and memory.
    return 0;   // 0 tells the operating system the program ended normally
}