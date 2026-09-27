
/*

https://cses.fi/problemset/task/1192/

Counting Rooms

You are given a map of a building, and your task is to count the number of its rooms. The
size of the map is n \times m squares, and each square is either floor or wall. You can walk
left, right, up, and down through the floor squares.

Input
The first input line has two integers n and m: the height and width of the map.
Then there are n lines of m characters describing the map. Each character is either . (floor)
or # (wall).

Output
Print one integer: the number of rooms.

Constraints
1 <= n, m <= 1000

Example
Input:

5 8
########
#..#...#
####.#.#
#..#...#
########
Output:

3

*/

// Counting Rooms is "number of components" (Module 3) drawn on a grid instead
// of an adjacency list. Every '.' is a node, and two floor squares that touch
// side by side are joined by an edge. A room is one connected piece of floor,
// so the answer is: how many times do we have to START a new DFS before every
// floor square has been visited?
//
// Note: there is no adjacency list at all. The "neighbours" of square (i, j)
// are worked out on the fly by adding the four direction steps to (i, j).
//
// Trace on the example: the scan meets (1,1) first -> DFS floods (1,1),(1,2):
// room 1. Next unvisited '.' is (1,4) -> DFS floods the right-hand block
// (1,4..6),(2,4),(2,6),(3,4..6): room 2. Last is (3,1) -> floods (3,1),(3,2):
// room 3. Output 3.

#include <iostream>     // cin, cout
#include <vector>       // vector (used for the list of four directions)
#include <string>       // std::string (not needed here, harmless)
#include <cstring>      // memset
using namespace std;    // so we can write cin/cout/vector without the std:: prefix

// Globals live outside main. Two reasons: (1) dfs() and valid() can use them
// without passing them as parameters, and (2) a 1005 x 1005 array is about a
// million bytes, too big to sit safely on the stack inside main; globals are
// stored elsewhere and are automatically filled with 0 / false.
char grid[1005][1005];   // the map, one character per square
bool vis[1005][1005];    // vis[i][j] = has this floor square been reached yet?
// The four moves: right, left, up, down (row change, column change).
// This is the "dx/dy" (here: direction) trick: instead of writing four near-identical
// if-blocks, loop over these four pairs and add them to the current square.
// Example: from (2, 5), {0,1} -> (2,6) right; {-1,0} -> (1,5) up.
vector<pair<int, int>> direction = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};
int n, m;                // height and width, global so valid() can see them

// Is (i, j) inside the map? Stepping off the edge must be refused before we
// ever read grid[i][j], or we would read memory that is not part of the map.
// Parameters: a row i and a column j. Returns true if 0 <= i < n and 0 <= j < m.
bool valid(int i, int j){
    if(i < 0 || i >= n || j < 0 || j >= m){   // any one coordinate out of range is enough to fail
        return false;
    }
    return true;                               // both coordinates are inside the map
}

// Flood one room: mark (si, sj) and every floor square reachable from it.
// Recursion: each call marks its own square, then calls itself on every new
// floor neighbour. There is no explicit base case: a call simply stops when
// none of its four neighbours qualifies, and returns to the square that called
// it (the call stack remembers the way back, like a trail of breadcrumbs).
void dfs(int si, int sj){
    vis[si][sj] = true;   // mark FIRST, so no neighbour can walk back in here and loop forever

    // Try the four directions; i picks which step from the direction list.
    for(int i=0; i<4; i++){
        int ci= si + direction[i].first;    // neighbour's row
        int cj = sj + direction[i].second;  // neighbour's column
        // Go there only if it is on the map, not seen yet, and floor ('#' is
        // a wall and splits rooms apart). valid() is checked first: && stops
        // at the first false, so grid[ci][cj] is never read off the map.
        if(valid(ci, cj) && !vis[ci][cj] && grid[ci][cj] == '.'){
            dfs(ci, cj);   // flood onward from that neighbour; comes back here when done
        }
    }
}

int main(){
    cin >> n >> m;   // number of rows, then number of columns
    // cin >> char skips whitespace, so reading square by square works even
    // though each row arrives as one string like "#..#...#".
    for(int i=0; i<n; i++){          // i = row
        for(int j=0; j<m; j++){      // j = column
            cin >> grid[i][j];       // one character: '.' or '#'
        }
    }

    // memset(array, value, bytes) fills every byte of the array with value.
    // sizeof(vis) is the size of the whole array in bytes. Globals already start
    // false, so this is only a safety habit (it matters if the code is ever reused).
    memset(vis, false, sizeof(vis));
    int cnt = 0;   // rooms found so far

    // Scan every square. A floor square that no earlier DFS reached must belong
    // to a room we have not met yet: count it, then flood the whole room so
    // none of its other squares gets counted again.
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(!vis[i][j] && grid[i][j] == '.'){   // unvisited floor = start of a new room
                dfs(i, j);   // mark the whole room as visited
                cnt++;       // one more room
            }
        }
    }

    cout << cnt << endl;   // print the number of rooms; endl = newline + flush

    // Each square is visited once and looks at 4 neighbours: O(n * m).
    // Watch out: a 1000 x 1000 room of floor makes the recursion a million
    // calls deep, which needs a big stack (the CSES judge gives one).
    return 0;   // normal exit
}