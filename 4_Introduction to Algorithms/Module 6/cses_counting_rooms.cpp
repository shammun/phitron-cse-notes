
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

#include <iostream>
#include <vector>
#include <string>
#include <cstring>      // memset
using namespace std;

char grid[1005][1005];   // the map, one character per square
bool vis[1005][1005];    // vis[i][j] = has this floor square been reached yet?
// The four moves: right, left, up, down (row change, column change).
vector<pair<int, int>> direction = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};
int n, m;                // height and width, global so valid() can see them

// Is (i, j) inside the map? Stepping off the edge must be refused before we
// ever read grid[i][j], or we would read memory that is not part of the map.
bool valid(int i, int j){
    if(i < 0 || i >= n || j < 0 || j >= m){
        return false;
    }
    return true;
}

// Flood one room: mark (si, sj) and every floor square reachable from it.
void dfs(int si, int sj){
    vis[si][sj] = true;

    for(int i=0; i<4; i++){
        int ci= si + direction[i].first;    // neighbour's row
        int cj = sj + direction[i].second;  // neighbour's column
        // Go there only if it is on the map, not seen yet, and floor ('#' is
        // a wall and splits rooms apart).
        if(valid(ci, cj) && !vis[ci][cj] && grid[ci][cj] == '.'){
            dfs(ci, cj);
        }
    }
}

int main(){
    cin >> n >> m;
    // cin >> char skips whitespace, so reading square by square works even
    // though each row arrives as one string like "#..#...#".
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin >> grid[i][j];
        }
    }

    memset(vis, false, sizeof(vis));
    int cnt = 0;   // rooms found so far

    // Scan every square. A floor square that no earlier DFS reached must belong
    // to a room we have not met yet: count it, then flood the whole room so
    // none of its other squares gets counted again.
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(!vis[i][j] && grid[i][j] == '.'){
                dfs(i, j);
                cnt++;
            }
        }
    }

    cout << cnt << endl;

    // Each square is visited once and looks at 4 neighbours: O(n * m).
    // Watch out: a 1000 x 1000 room of floor makes the recursion a million
    // calls deep, which needs a big stack (the CSES judge gives one).
    return 0;
}