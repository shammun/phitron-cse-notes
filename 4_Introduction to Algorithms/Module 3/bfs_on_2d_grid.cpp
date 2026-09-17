#include <iostream>
#include <vector>
#include <algorithm>    
#include <string>
#include <stack>
#include <queue>

using namespace std;

char grid[105][105];
bool vis[105][105];
int level[105][105];
vector<pair<int, int>> direction = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};
int n, m;

bool valid(int i, int j){
    if(i < 0 || i >= n || j < 0 || j >= m){
        return false;
    }
    return true;
}

void bfs(int si, int sj){
    queue<pair<int, int>> q;
    q.push({si, sj});
    vis[si][sj] = true;
    level[si][sj] = 0;

    while(!q.empty()){
        pair<int, int> par = q.front();
        q.pop();
        int par_i = par.first;
        int par_j = par.second;

        for(int i=0; i<4; i++){
            int ci = par_i + direction[i].first;
            int cj = par_j + direction[i].second;
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
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin >> grid[i][j];
        }
    }

    // si and sj source and di and dj destination
    int si, sj, di, dj;
    cin >> si >> sj >> di >> dj;
    memset(vis, false, sizeof(vis));
    memset(level, -1, sizeof(level));
    bfs(si, sj);
    cout << level[di][dj] << endl;
    return 0;
}