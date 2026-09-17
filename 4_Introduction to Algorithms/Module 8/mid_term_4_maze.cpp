/*

Maze

Problem Statement

Rezia is trapped in a 2D maze of N X M size, starting at position R, and her goal is to reach the exit marked by D. The maze 
contains blocks represented by #, and she can only traverse through cells marked with dots (.). As she need to escape as early 
as possible, we need to determine the path she will follow.

Place an X in each cell representing Rezia's route to exit the maze. If there is no viable path for her to exit, leave the 
maze unchanged.

Note: Rezia can move in four directions – right, left, up, and down. It is crucial to adhere to the specified order: 
attempting right first, then left, followed by up, and finally down.

Input Format

- First line will contain N and M.
- Next you will be given the 2D matrix.

Constraints
1. 1 <= N, M <= 10^3

Output Format

- Output the final maze with marked X indicating the path she will follow.

Sample Input 0
5 6
...D.#
.##..#
....#.
.R#...
.#.##.

Sample Output 0
...D.#
.##X.#
.XXX#.
.R#...
.#.##.

Sample Input 1
5 6
...D.#
.R...#
....#.
..#...
.#.##.

Sample Output 1
...D.#
.RXX.#
....#.
..#...
.#.##.

Sample Input 2
5 6
...D.#
.....#
.##.#.
.R#...
.#.##.

Sample Output 2
...D.#
XXXX.#
X##.#.
XR#...
.#.##.

Sample Input 3
5 6
...D.#
.....#
###.#.
.R#...
.#.##.

Sample Output 3
...D.#
.....#
###.#.
.R#...
.#.##.

*/

#include <iostream>
#include <cstring>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int n, m;
char maze[1005][1005];
bool vis[1005][1005];
vector<pair<int, int>> direction = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};
pair<int, int> path[1005][1005];

bool valid(int i, int j){
    if(i <0 || i>=n || j<0 || j>=m){
        return false;
    }
    return true;
}

/*

void dfs(int si, int sj, int di, int dj){
    if(si == di && sj == dj){
        flag = true;
        return;
    }

    vis[si][sj] = true;

    for(int i=0; i<4; i++){
        int ci = si + direction[i].first;
        int cj = sj + direction[i].second;

        if(valid(ci, cj) && !vis[ci][cj] && maze[ci][cj] != '#'){
            if(maze[ci][cj] == '.'){
                maze[ci][cj] = 'X';
            }

            dfs(ci, cj, di, dj);

            if(flag){
                return;
            }

            if(maze[ci][cj] == 'X'){
                maze[ci][cj] = '.';
            }
        }
    }
}

*/

bool bfs(int si, int sj, int di, int dj){
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            path[i][j] = {-1, -1};
        }
    }

    queue<pair<int, int>> q;
    q.push({si, sj});
    vis[si][sj] = true;

    while(!q.empty()){
        pair<int, int> par = q.front();
        q.pop();

        int par_i = par.first;
        int par_j = par.second;

        if(par_i == di && par_j == dj){
            return true;
        }

        for(int i=0; i<4; i++){
            int ci = par_i + direction[i].first;
            int cj = par_j + direction[i].second;

            if(valid(ci, cj) && !vis[ci][cj] && maze[ci][cj] != '#'){
                q.push({ci, cj});
                vis[ci][cj] = true;
                path[ci][cj] = {par_i, par_j};
            }
        }
    }

    return false;
}



int main(){
    cin >> n >> m;

    int s_i=0, s_j=0, d_i=0, d_j=0;

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin >> maze[i][j];
            if(maze[i][j] == 'R'){
                s_i = i;
                s_j = j;
            } else if(maze[i][j] == 'D'){
                d_i = i;
                d_j= j;
            }
        }
    }

    memset(vis, false, sizeof(vis));


    if(s_i == -1 || d_i == -1) {
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                cout << maze[i][j];
            }
            cout << endl;
        }
        return 0;
    }

    if(bfs(s_i, s_j, d_i, d_j)){
        int d2_i = d_i;
        int d2_j = d_j;
        while(!(s_i == d2_i && s_j == d2_j)){
            pair<int, int> par = path[d2_i][d2_j];
            if(par.first == s_i && par.second == s_j){
                break;
            }
            if(maze[par.first][par.second] == '.'){
                maze[par.first][par.second] = 'X';
            }
            d2_i = par.first;
            d2_j = par.second;
        }
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cout << maze[i][j];
        }
        cout << endl;
    }

    return 0;
}
