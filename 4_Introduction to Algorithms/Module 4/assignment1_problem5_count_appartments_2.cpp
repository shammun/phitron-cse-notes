/*

Problem Statement

You are given an n X M sized 2D matrix that represents a map of a building. Each cell 
represents a wall or a room. The connected rooms are called apartments. Your task is to 
count the number rooms in each of the apartments in that building. You can walk left, 
right, up, and down through the room cells. You can't pass through walls.

You need to print the count of the rooms in ascending order. If there are no apartments 
available in that building, then you should print 0.

Input Format

- The first input line has two integers N and M: the height and width of the map.
- Then there are N lines of M characters describing the map. Each character is either 
.(room) or #(wall).

Constraints

1. 1 <= N, M <= 1000

Output Format

- Output the number of rooms in each of the apartments in ascending order.

Sample Input 0

5 8
########
#..#...#
####.#.#
#..#...#
########

Sample Output 0

2 2 8

Sample Input 1

6 8
.#.#####
.#.###..
#..#...#
#.##....
..##.###
#.#.##.#

Sample Output 1

1 1 2 8 10

*/

/*

Problem Statement

You are given an  sized 2D matrix that represents a map of a building. Each cell represents a wall or a room. The connected rooms are called apartments. Your task is to count the number of apartments in that building. You can walk left, right, up, and down through the room cells. You can't pass through walls.

Input Format

The first input line has two integers  and : the height and width of the map.
Then there are  lines of  characters describing the map. Each character is either .(room) or #(wall).

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

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

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

int bfs(int Ai, int Aj){
    queue<pair<int, int>> q;
    q.push({Ai, Aj});
    vis[Ai][Aj] = true;
    int room_count = 1;

    while(!q.empty()){
        pair<int, int> par = q.front();
        q.pop();
        int par_i = par.first;
        int par_j = par.second;

        for(int i=0; i<4; i++){
            int ci = par_i + direction[i].first;
            int cj = par_j + direction[i].second;

            if(valid(ci, cj) && !vis[ci][cj] && grid[ci][cj] == '.'){
                q.push({ci, cj});
                vis[ci][cj] = true;
                room_count++;
            }
        }
    }
    return room_count;
}

int main(){
    cin >> n >> m;

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin >> grid[i][j];
        }
    }

    vector<int> apartments;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(!vis[i][j] && grid[i][j] == '.'){
                int room_count = bfs(i, j);
                apartments.push_back(room_count);
            }
        }
    }

    sort(apartments.begin(), apartments.end());

    if(apartments.size() == 0){
        cout << 0 << endl;
    } else {
        for(int i = 0; i<apartments.size(); i++){
            cout << apartments[i] << " ";
        }
        cout << endl;
    }

    return 0;
}