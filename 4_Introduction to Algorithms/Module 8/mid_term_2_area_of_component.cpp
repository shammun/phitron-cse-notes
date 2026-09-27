/*

Area of component

Problem Statement

You will be given a 2D matrix of size N X M which will contain only dot(.) and minus(-) where 
dot(.) means you can go in that cell and minus(-) means you can't.

You can move in only 4 directions (Up, Down, Left and Right).

The area of a component is the number of dots(.) in that component that can be accessible. You 
need to tell the minimum area of all available components.

Note: If there are no components, print -1.

Input Format

- First line will contain N and M.
- Next you will be given the 2D matrix.

Constraints

1. 1 <= N, M <= 10^3

Output Format

- Output the minimum area.

Sample Input 0
6 5
..-..
..-..
-----
.-...
.----
.....

Sample Output 0
3

Sample Input 1
3 3
---
---
---

Sample Output 1
-1

*/

// Mid-term question 2. Every group of touching '.' cells is a component, and
// its area is how many cells it has. So: flood each component with DFS once,
// counting cells as the DFS visits them, and keep the smallest count.
// If no '.' exists at all there is no component, and the answer is -1.
//
// Sample 0 has 4 components: top-left 2x2 block (area 4), top-right 2x2 block
// (area 4), the "..." in row 3 (area 3), and the '.' at (3,0) joined to (4,0)
// and all of row 5 (area 1 + 1 + 5 = 7). The smallest is 3.

#include <iostream>     // cin / cout
#include <vector>       // vector (the list of directions)
#include <string>       // std::string (not used here; template line)
#include <climits>      // INT_MAX
#include <cstring>      // memset

using namespace std;    // lets us write cout, vector, min without std::

// Global arrays: they live in static memory (too big for a local array on the
// stack) and start filled with 0 / false.
char grid[1005][1005];  // the map: '.' open, '-' blocked
bool vis[1005][1005];   // vis[i][j] = true once the DFS has counted cell (i, j)
// The 4 moves as {row change, column change}: right, left, up, down.
vector<pair<int, int>> direction = {{0,1},{0,-1},{-1,0},{1,0}};
int n, m;               // n rows, m columns
int area;   // cells counted in the component being flooded right now
// (area is global so every recursive dfs call adds to the SAME counter.)

// true if (i, j) is inside the n x m grid, false if it is off the edge.
bool valid(int i, int j){
    if(i <0 || i >= n || j <0 || j >= m){
        return false;
    }
    return true;
}

// Flood one component, adding 1 to area for every cell stood on.
// DFS: mark this cell, count it, then recurse into every open, unvisited
// neighbour. There is no explicit base case: when no neighbour qualifies the
// loop simply ends and the call returns. Because every cell is marked before
// we move on, no cell is counted twice.
void dfs(int si, int sj){
    vis[si][sj] = true;   // never enter this cell again
    area++;               // one more cell in this component

    for(int i=0; i<4; i++){                      // try the 4 directions
        int ci = si + direction[i].first;        // neighbour's row
        int cj = sj + direction[i].second;       // neighbour's column

        // valid() first, so vis/grid are only read for real cells (&& stops early).
        if(valid(ci, cj) && !vis[ci][cj] && grid[ci][cj] == '.'){
            dfs(ci, cj);  // count everything reachable from the neighbour too
        }
    }
}

int main(){
    cin >> n >> m;                   // grid size

    // Read the grid character by character (cin >> char skips newlines).
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin >> grid[i][j];
        }
    }

    // Clear vis (all bytes to 0 = false). Already false as a global; a habit.
    memset(vis, false, sizeof(vis));
    int min_area = INT_MAX;   // start above any real area, so the first min() wins
    // INT_MAX (from <climits>) is the largest int, 2147483647.
    bool flag = false;        // did we find at least one component?

    // Each unvisited '.' is the first cell we meet of a new component.
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(!vis[i][j] && grid[i][j] == '.'){
                area = 0;                        // reset the counter for this component
                dfs(i, j);                       // now area = its size
                min_area = min(min_area, area);  // min() returns the smaller of the two
                flag = true;
            }
        }
    }

    // flag tells "no components" apart from a real answer. (Checking
    // min_area == INT_MAX would work too.)
    if(flag){
        cout << min_area << endl;    // endl = newline
    }
    else{
        cout << -1 << endl;          // the grid had no '.' at all
    }

    // O(N * M): each cell is flooded once.
    return 0;
}
