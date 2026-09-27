/*

Knight Moves

Problem Statement

You will be given a chessboard of N X M size. You can move anywhere in the chessboard freely. You 
will be given two cells - the knight's cell  (K_i and K_j), and the queen's cell  Q(Q_i and Q_j). 
You need to tell the minimum number of steps for the knight to attack the queen if the queen 
doesn't move.

A knight moves in 8 directions: two cells one way (up/down/left/right) and
then one cell sideways, like the letter L. (The picture from the original
statement is not reproduced here.)

Input Format

- First line will contain T, the number of test cases.
- First line of each test case will contain N and M.
- Second line of each test case will contain K_i and K_j.
- Third line of each test case will contain Q_i and Q_j.

Constraints

1. 1 <= T <= 100
2. 1 <= N, M <= 100
3. 0 <= K_i, Q_i < N
4. 0 <= K_j, Q_j < M

Output Format

- Output the minimum number of steps for the knight to reach the queen. If you can't reach to 
queen, print -1.

Sample Input 0
4
8 8
0 0
7 7
5 6
0 1
0 1
4 4
0 0
0 1
2 2
0 0
0 1

Sample Output 0

6
0
3
-1
Explanation 0

For the first test case, one possible answer takes 6 jumps, for example:
(0,0) -> (1,2) -> (2,4) -> (3,6) -> (4,4) -> (5,6) -> (7,7)
No shorter route exists; the BFS below proves it by finding 6 as the minimum.

*/

// Mid-term question 3. Every knight jump counts as one step, whatever its
// shape, so this is a shortest-path question on an unweighted graph: BFS
// (Module 2). The cells are the nodes, and each cell has up to 8 neighbours,
// one per knight jump. The BFS level of the queen's cell is the answer.
//
// Why BFS and not DFS? BFS uses a queue (first in, first out), so it finishes
// ALL cells 1 jump away before any cell 2 jumps away, then all 2-jump cells,
// and so on, like ripples spreading out. So the first time we meet a cell, we
// have met it by the fewest jumps. DFS dives down one path and gives no such
// promise.
//
// Sample test 4: a 2 x 2 board, knight at (0,0). Every knight jump from any
// cell of a 2 x 2 board lands off the board, so the queen at (0,1) is never
// reached and the answer is -1.

#include <iostream>     // cin / cout
#include <queue>        // queue: the BFS "to do" list (first in, first out)
#include <cstring>      // memset (fills dist with -1)
#include <vector>       // vector (the list of the 8 jumps)

using namespace std;    // lets us write queue, pair, cout without std::

int n, m;   // board size
// (n rows 0..n-1, m columns 0..m-1; global so valid() can see them.)
// The 8 knight jumps: two squares one way and one square the other way.
// Each pair is {row change, column change}; e.g. {1, 2} = 1 row down,
// 2 columns right. From (0,0) only {1,2} -> (1,2) and {2,1} -> (2,1) stay on board.
vector<pair<int, int>> direction = {{1, 2}, {1, -2}, {2, 1}, {2, -1}, {-1, 2}, {-1, -2}, {-2, 1}, {-2, -1}};
// dist[i][j] = fewest jumps from the knight to (i, j); -1 = not reached yet.
// One array does two jobs: it is also the "visited" mark (-1 means unvisited).
// This is the "level" array of BFS: level of the start is 0, its neighbours 1...
int dist[105][105];

// true if (i, j) is on the board, false if the jump went off the edge.
bool valid(int i, int j){
    if(i <0 || i>=n || j<0 || j>=m){
        return false;
    }
    return true;
}

// BFS from the knight (k_i, k_j); returns the jumps needed to reach (q_i, q_j).
// Returns -1 if the queen's cell can never be reached.
int bfs(int k_i, int k_j, int q_i, int q_j){
    // Reset for every test case: the same board array is reused.
    // memset fills every BYTE with -1 (0xFF); an int made of four 0xFF bytes
    // is -1, so every cell becomes -1. (This trick works only for 0 and -1.)
    memset(dist, -1, sizeof(dist));

    queue<pair<int, int>> q;    // cells waiting to be expanded, as {row, col}
    q.push({k_i, k_j});         // start with the knight's own cell
    dist[k_i][k_j]=0;   // zero jumps to stay where it is

    // Each pass takes the oldest cell out of the queue and puts in every new
    // cell one jump away from it. The loop ends when nothing is left to expand
    // (or earlier, by return, when the queen's cell is taken out).
    while(!q.empty()){
        pair<int, int> par = q.front();   // front() = the oldest cell ("parent")
        q.pop();                          // pop() removes it from the queue
        int par_i = par.first;            // its row
        int par_j = par.second;           // its column

        // BFS pops cells in order of distance, so the first time the queen's
        // cell comes out, its distance is already the smallest possible.
        if(par_i == q_i && par_j == q_j){
            return dist[par_i][par_j];
        }

        // Try all 8 jumps from the current cell.
        for(int i=0; i<8; i++){
            int ci = par_i + direction[i].first;    // landing row
            int cj = par_j + direction[i].second;   // landing column

            // Stay on the board, and only take cells not reached before.
            // (valid() first: && stops early, so dist is never read off-board.)
            if(valid(ci, cj) && dist[ci][cj] == -1){
                q.push({ci, cj});                         // expand it later
                dist[ci][cj] = dist[par_i][par_j] + 1;   // one jump further
                // Setting dist here also marks it visited, so it is never
                // pushed twice.
            }
        }
    }

    // The queue ran dry without meeting the queen: on a tiny board (such as
    // 2 x 2) some cells cannot be reached by knight jumps at all.
    return -1;
}

int main(){
    int t;
    cin >> t;   // number of test cases

    // while(t--) runs the body t times (test t, then subtract 1).
    while(t--){
        cin >> n >> m;       // this board's size (sets the globals)
        int k_i, k_j, q_i, q_j;
        cin >> k_i >> k_j;   // knight
        cin >> q_i >> q_j;   // queen

        // Run BFS and print its answer; endl ends the line.
        // Knight and queen on the same cell: BFS returns 0 on the first pop.
        cout << bfs(k_i, k_j, q_i, q_j) << endl;
    }

    // Each test: O(N * M * 8) at most.
    return 0;
}
