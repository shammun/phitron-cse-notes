// Can node dest be reached from node src?
//
// No new algorithm at all: it is the BFS of bfs.cpp, unchanged. The answer is
// already sitting in the visited array when the search finishes. BFS marks every
// node it can get to, so after one run visited[dest] means "yes, there is a path",
// and false means dest lies in a different piece of the graph.
//
// (The file name has a typo: it is meant to read "if_a_node_can_be_visited_or_not".)

#include <iostream>
#include <vector>
#include <algorithm>    
#include <string>
#include <stack>
#include <queue>

using namespace std;

vector<int> adj_list[1005];
bool visited[1005];

// Exactly the traversal from bfs.cpp: queue, mark on push, print on pop.
void bfs(int src){
    queue<int> q;
    q.push(src);
    visited[src] = true;

    while(!q.empty()){
        int par = q.front();
        q.pop();

        cout << par << " ";

        for(int child : adj_list[par]){
            if(!visited[child]){
                q.push(child);
                visited[child] = true;
            }   
        }
    }
}


int main(){
    int n, e;
    cin >> n >> e;

    while(e--){
        int a, b;
        cin >> a >> b;
        adj_list[a].push_back(b);
        adj_list[b].push_back(a);
    }

    memset(visited, false, sizeof(visited));

    int src, dest;
    cin >> src >> dest;

    bfs(src);   // this fills visited[] for the whole piece that holds src

    // Careful, this does not print what it looks like. The closing quote is in
    // the wrong place: the string is "YES << endl", so the program prints the
    // words YES << endl and never ends the line. It should be:
    //     cout << "YES" << endl;
    // The same slip is in the else branch. The code is left as it is on purpose,
    // so you can see how a misplaced quote turns code into text.
    if(visited[dest]){
        cout << "YES << endl";
    } else {
        cout << "NO << endl";
    }

    return 0;
}