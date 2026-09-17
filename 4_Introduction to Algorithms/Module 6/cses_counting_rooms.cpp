
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

#include <iostream>
#include <vector>
#include <string>
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

void dfs(int si, int sj){
    vis[si][sj] = true;

    for(int i=0; i<4; i++){
        int ci= si + direction[i].first;
        int cj = sj + direction[i].second;
        if(valid(ci, cj) && !vis[ci][cj] && grid[ci][cj] == '.'){
            dfs(ci, cj);
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

    memset(vis, false, sizeof(vis));
    int cnt = 0;

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(!vis[i][j] && grid[i][j] == '.'){
                dfs(i, j);
                cnt++;
            }
        }
    }

    cout << cnt << endl;

    return 0;
}