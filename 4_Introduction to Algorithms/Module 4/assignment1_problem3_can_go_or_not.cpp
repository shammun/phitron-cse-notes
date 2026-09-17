/*

Problem Statement

You are given an N X M sized 2D matrix that represents a map of a building. Each cell 
represents a wall, a floor or a room. You will be given two rooms A and B. You need to 
tell if you can go from room A to B by passing through the floors. You can walk left, 
right, up, and down through the floor cells. You can't pass through walls.

Input Format

- The first input line has two integers N and M: the height and width of the map.
- Then there are N lines of M characters describing the map. Each character is .(floor), 
#(wall), A or B (rooms).

Constraints

1. 1 <= N, M <= 1000

Output Format

- Output YES if you can go from room  to , NO otherwise.

Sample Input 0

5 8
########
#.A#...#
#.##.#B#
#......#
########

Sample Output 0

YES

*/

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

char grid[1005][1005];
bool vis[1005][1005];
vector<pair<int, int>> direction = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};
int n, m;

bool valid(int i, int j){
    if(i < 0 || i >= n || j < 0 || j >= m){
        return false;
    }
    return true;
}

bool bfs(int Ai, int Aj, int Bi, int Bj){
    queue<pair<int, int>> q;
    q.push({Ai, Aj});
    vis[Ai][Aj] = true;

    while(!q.empty()){
        pair<int, int> par = q.front();
        q.pop();
        int par_i = par.first;
        int par_j = par.second;

        if(par_i == Bi && par_j == Bj){
            return true;
        }

        for(int i=0; i<4; i++){
            int ci = par_i + direction[i].first;
            int cj = par_j + direction[i].second;
            if(valid(ci, cj) && vis[ci][cj] == false && grid[ci][cj] != '#'){
                q.push({ci, cj});
                vis[ci][cj] = true;
            }
        }
    }
    return false;
}

int main(){
    cin >> n >> m;

    int Ai = -999, Aj = -999, Bi = -999, Bj = -999;

    for(int i=0; i < n; i++){
        for(int j=0; j<m; j++){
            cin >> grid[i][j];
            if(grid[i][j] == 'A'){
                Ai = i;
                Aj = j;
            } else if(grid[i][j] == 'B'){
                Bi = i;
                Bj = j;
            }
        }
    }

    memset(vis, false, sizeof(vis));
    bool result = bfs(Ai, Aj, Bi, Bj);

    if(result){
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
}
