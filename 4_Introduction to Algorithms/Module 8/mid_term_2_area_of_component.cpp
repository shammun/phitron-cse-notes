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

#include <iostream>
#include <vector>
#include <string>
#include <climits>
#include <cstring>

using namespace std;

char grid[1005][1005];
bool vis[1005][1005];
vector<pair<int, int>> direction = {{0,1},{0,-1},{-1,0},{1,0}};
int n, m;
int area;

bool valid(int i, int j){
    if(i <0 || i >= n || j <0 || j >= m){
        return false;
    }
    return true;
}

void dfs(int si, int sj){
    vis[si][sj] = true;
    area++;

    for(int i=0; i<4; i++){
        int ci = si + direction[i].first;
        int cj = sj + direction[i].second;

        if(valid(ci, cj) && !vis[ci][cj] && grid[ci][cj] == '.'){
            dfs(ci, cj);
        }
    }
}

int main(){
    cin >> n >> m;

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin >> grid[i][j];
        }
    }

    memset(vis, false, sizeof(vis));
    int min_area = INT_MAX;
    bool flag = false;

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(!vis[i][j] && grid[i][j] == '.'){
                area = 0;
                dfs(i, j);
                min_area = min(min_area, area);
                flag = true;
            }        
        }
    }

    if(flag){
        cout << min_area << endl;
    }
    else{
        cout << -1 << endl;
    }

    return 0;
}
