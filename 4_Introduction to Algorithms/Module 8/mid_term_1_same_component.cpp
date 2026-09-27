/*

Problem Statement

You will be given a 2D matrix of size N X M which will contain only dot(.) and minus(-) where 
dot(.) means you can go in that cell and minus(-) means you can't.

You can move in only 4 directions (Up, Down, Left and Right).

You will be given the indexes of two cells - S(S_i,S_j) and D(D_i,D_j). You need to tell if these 
S and D cells are in the same component or not. Same component means you can go from S to D.

Input Format

- First line will contain N and M.
- Next you will be given the 2D matrix.
- Next line will contain S_i and S_j.
- Last line will contain D_i and D_j.

Constraints
1. 1 <= N, M <= 10^3
2. 0 <= S_i, D_i < N
3. 0 <= S_j, D_j < M

Output Format

- Output "YES" if those cell are in the same component, "NO" otherwise.

Sample Input 0
5 4
..-.
---.
..-.
--..
....
0 1
3 2

Sample Output 0
NO

Sample Input 1
5 4
....
---.
..-.
--..
....
0 1
3 2

Sample Output 1
YES

*/

// Mid-term question 1. "Same component" on a grid just means: starting at S
// and stepping only on '.', can we reach D? That is a reachability search, so
// one DFS from S (Module 3's dfs_on_2d_grid.cpp) answers it. This version stops
// early: the moment the DFS stands on D it returns true all the way up.

#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

char grid[1005][1005];   // the map: '.' open, '-' blocked
bool vis[1005][1005];    // cells the DFS has already stood on
// right, left, up, down as {row change, column change}
vector<pair<int, int>> direction = {{0,1}, {0,-1}, {-1,0}, {1, 0}};
int n, m;

// Is (i, j) inside the grid?
bool valid(int i, int j){
    if(i<0 || i>=n || j<0 || j>=m){
        return false;
    }
    return true;
}

// DFS from (si, sj). Returns true as soon as the destination (di, dj) is reached.
bool dfs(int si, int sj, int di, int dj){
    vis[si][sj] = true;

    if(si == di && sj == dj){
        return true;   // standing on D: found it
    }

    for(int i=0; i<4; i++){
        int ci = si + direction[i].first;
        int cj = sj + direction[i].second;

        if(valid(ci, cj) && !vis[ci][cj] && grid[ci][cj] == '.'){
            // Explore from the neighbour. If that search found D, there is no
            // need to try the other directions: pass true straight back up.
            bool found = dfs(ci, cj, di, dj);
            if(found){
                return true;
            }
        }
    }

    return false;   // every open cell around here explored, no D
}

int main(){
    cin >> n >> m;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin >> grid[i][j];
        }
    }

    int si, sj, di, dj;

    cin >> si >> sj;   // start cell S
    cin >> di >> dj;   // destination cell D

    memset(vis, false, sizeof(vis));

    // A blocked S or D cannot be part of any component of '.' cells.
    if(grid[si][sj] == '-' || grid[di][dj] == '-'){
        cout << "NO" << endl;
        return 0;
    }

    // S and D are the same open cell: trivially the same component.
    if(si == di && sj==dj){
        cout << "YES" << endl;
        return 0;
    }

    bool found_or_not = dfs(si, sj, di, dj);

    if(found_or_not){
        cout << "YES" << endl;
    } else{
        cout << "NO" << endl;
    }

    // At most every cell is visited once: O(N * M).
    return 0;
}
