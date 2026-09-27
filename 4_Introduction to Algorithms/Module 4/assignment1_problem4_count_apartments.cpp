/*

Problem Statement

You are given an N X M sized 2D matrix that represents a map of a building. Each cell represents a
wall or a room. The connected rooms are called apartments. Your task is to count the number of
apartments in that building. You can walk left, right, up, and down through the room cells. You
can't pass through walls.

Input Format

The first input line has two integers  and : the height and width of the map.
Then there are  lines of  characters describing the map. Each character is either .(room) or
#(wall).

Constraints

1. 1 <= N, M <= 1000

Output Format

Output the number of apartments

Sample Input 0

5 8
########
#..#...#
####.#.#
#..#...#
########

Sample Output 0

3

Sample Input 1

6 8
.#.#####
.#.###..
#..#...#
#.##....
..##.###
#.#.##.#

Sample Output 1

5

*/

// Idea: an apartment is a connected group of '.' cells, i.e. a component of
// the grid graph. Count components exactly as in number_of_components.cpp
// (Module 3): scan every cell; an unvisited room cell starts a new apartment,
// so count it and let a BFS mark all the rooms joined to it.
//
// Example: sample 0 has rooms {(1,1),(1,2)}, the big block on the right, and
// {(3,1),(3,2)} -> 3 apartments.

#include <iostream>     // cin / cout
#include <vector>       // vector (the direction list)
#include <queue>        // queue for BFS (first in, first out)
#include <algorithm>    // not really needed here (no sort is used)

using namespace std;    // skip the std:: prefix

char grid[1005][1005];   // the map: '.' = room, '#' = wall (N, M <= 1000)
bool vis[1005][1005];    // global, so it starts all false
// Direction array {row change, column change}: right, left, up, down.
// Adding direction[k] to (i, j) gives the k-th neighbour of that cell.
vector<pair<int, int>> direction = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};
int n, m;                // rows and columns, global so valid() can see them

// Is (i, j) inside the map? Rows 0..n-1, columns 0..m-1.
bool valid(int i, int j){
    if(i < 0 || i >= n || j < 0 || j >= m){   // outside on some side
        return false;
    }
    return true;
}

// Grid BFS from (Ai, Aj): marks every room cell of this apartment.
// Nothing is returned; the useful result is the vis marks it leaves behind,
// so the main loop will not start this apartment again.
void bfs(int Ai, int Aj){
    queue<pair<int, int>> q;    // cells waiting to be explored, as (row, col)
    q.push({Ai, Aj});           // start cell
    vis[Ai][Aj] = true;         // mark on push so it is never queued twice

    // Each pass: take the oldest cell, queue its unvisited room neighbours.
    // Stops when the whole apartment has been explored (queue empty).
    while(!q.empty()){
        pair<int, int> par = q.front();   // oldest cell ("parent")
        q.pop();                          // remove it
        int par_i = par.first;            // its row
        int par_j = par.second;           // its column

        for(int i=0; i<4; i++){           // look in all 4 directions
            int ci = par_i + direction[i].first;    // child row
            int cj = par_j + direction[i].second;   // child column

            // Spread only into room cells ('.') inside the map, not yet seen.
            // valid() is checked first so the arrays are never read out of range.
            if(valid(ci, cj) && !vis[ci][cj] && grid[ci][cj] == '.'){
                q.push({ci, cj});
                vis[ci][cj] = true;
            }
        }
    }
}

int main(){
    cin >> n >> m;              // height and width

    // Read the map one character at a time; cin >> char skips the newlines.
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin >> grid[i][j];
        }
    }

    int count = 0;              // apartments found so far
    // Visit every cell once, row by row.
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            // A room nobody has reached yet = the first cell of a new apartment.
            if(!vis[i][j] && grid[i][j] == '.'){
                bfs(i, j);     // swallow the whole apartment
                count++;       // and count it once
            }
        }
    }

    cout << count << endl;     // Cost: O(N * M)

    return 0;                  // normal end
}
