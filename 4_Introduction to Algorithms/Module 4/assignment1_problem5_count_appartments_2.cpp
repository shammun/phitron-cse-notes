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

// Idea: the same component scan as assignment1_problem4_count_apartments.cpp,
// but now each BFS also counts the cells it queues, which is the size of that
// apartment. Collect the sizes, sort them ascending and print them; if the map
// has no room at all the list stays empty and the answer is 0.
//
// Example: sample 0 has apartments of 2, 8 and 2 rooms -> "2 2 8".

#include <iostream>     // cin / cout
#include <vector>       // vector: direction list and the list of apartment sizes
#include <queue>        // queue for BFS
#include <algorithm>    // sort

using namespace std;    // skip the std:: prefix

char grid[1005][1005];  // the map: '.' = room, '#' = wall
bool vis[1005][1005];   // vis[i][j] = cell already counted? (global -> starts false)
// Direction array {row change, column change}: right, left, up, down.
vector<pair<int, int>> direction = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};
int n, m;               // rows and columns, global so valid() can use them

// Is (i, j) inside the map? Rows 0..n-1, columns 0..m-1.
bool valid(int i, int j){
    if(i < 0 || i >= n || j < 0 || j >= m){
        return false;           // off the map
    }
    return true;
}

// Grid BFS that returns how many rooms this apartment has.
// (Ai, Aj) is an unvisited room cell; every room reachable from it is marked.
int bfs(int Ai, int Aj){
    queue<pair<int, int>> q;    // cells waiting to be explored
    q.push({Ai, Aj});
    vis[Ai][Aj] = true;
    int room_count = 1;         // the starting room itself

    // Each pass: pop the oldest cell and queue (and count) its new room neighbours.
    // Ends when the queue is empty, i.e. the whole apartment is marked.
    while(!q.empty()){
        pair<int, int> par = q.front();   // oldest cell
        q.pop();
        int par_i = par.first;            // row
        int par_j = par.second;           // column

        for(int i=0; i<4; i++){           // the 4 neighbours
            int ci = par_i + direction[i].first;
            int cj = par_j + direction[i].second;

            // Inside the map, not seen yet, and a room (walls are skipped).
            if(valid(ci, cj) && !vis[ci][cj] && grid[ci][cj] == '.'){
                q.push({ci, cj});
                vis[ci][cj] = true;
                room_count++;   // each cell is queued exactly once, so count it here
            }
        }
    }
    return room_count;          // size of this apartment
}

int main(){
    cin >> n >> m;              // height and width

    // Read the map; cin >> char skips the line breaks between rows.
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin >> grid[i][j];
        }
    }

    vector<int> apartments;     // one size per apartment
    // Scan every cell; an unvisited room is the first cell of a new apartment.
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(!vis[i][j] && grid[i][j] == '.'){
                int room_count = bfs(i, j);          // mark it and get its size
                apartments.push_back(room_count);    // add the size to the end of the list
            }
        }
    }

    // sort with no third argument = ascending order. Example: {2, 8, 2} -> {2, 2, 8}.
    sort(apartments.begin(), apartments.end());   // smallest first

    if(apartments.size() == 0){
        cout << 0 << endl;      // all walls: no apartment at all
    } else {
        // Print the sizes separated by spaces, then one newline.
        for(int i = 0; i<apartments.size(); i++){
            cout << apartments[i] << " ";
        }
        cout << endl;
    }

    return 0;                   // normal end
}
