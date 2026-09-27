// Can node dest be reached from node src?
//
// No new algorithm at all: it is the BFS of bfs.cpp, unchanged. The answer is
// already sitting in the visited array when the search finishes. BFS marks every
// node it can get to, so after one run visited[dest] means "yes, there is a path",
// and false means dest lies in a different piece of the graph.
//
// (The file name has a typo: it is meant to read "if_a_node_can_be_visited_or_not".)
//
// Input: "n e", then e undirected edges "a b", then "src dest".
// Output: the BFS order from src on one line, then YES or NO.
//
// Tiny example: edges 0-1, 2-3; query src=0 dest=3.
//   BFS from 0 marks only 0 and 1, so visited[3] stays false -> prints "0 1 NO".

#include <iostream>     // cin, cout
#include <vector>       // vector (growable array) for the adjacency list
#include <algorithm>    // not used here, kept as a habit
#include <string>       // not used here
#include <stack>        // not used here
#include <queue>        // queue: first in, first out -- the heart of BFS

using namespace std;    // write cout / vector / queue without the std:: prefix

// Globals: visible to every function, and automatically zero/false at start.
vector<int> adj_list[1005];   // adj_list[x] = list of x's neighbours (1005 = safe max node count)
bool visited[1005];           // visited[x] = true once x has been put into the queue

// Exactly the traversal from bfs.cpp: queue, mark on push, print on pop.
// src = the node the search starts from. Afterwards visited[] shows everything reachable.
void bfs(int src){
    queue<int> q;          // nodes found but not yet explored
    q.push(src);           // start with the source waiting in line
    visited[src] = true;   // mark it now so it is never pushed again

    // Each pass: take the front node out and queue its not-yet-seen neighbours.
    // Stops when the queue is empty = nothing left that we can reach.
    while(!q.empty()){
        int par = q.front();   // look at the node at the front of the line
        q.pop();               // and remove it

        cout << par << " ";    // print nodes in the order BFS explores them

        // Go through every neighbour (child) of par.
        for(int child : adj_list[par]){
            if(!visited[child]){       // not seen yet?
                q.push(child);         // queue it for later
                visited[child] = true; // mark at push time so no duplicates enter the queue
            }
        }
    }
}


int main(){
    int n, e;         // number of nodes, number of edges
    cin >> n >> e;

    // Build the undirected graph: e lines, each one edge a-b.
    while(e--){                     // runs exactly e times (e counts down to 0)
        int a, b;
        cin >> a >> b;
        adj_list[a].push_back(b);   // b is next to a
        adj_list[b].push_back(a);   // and a is next to b (undirected)
    }

    // Set every visited[] entry to false (0). memset(array, value, bytes)
    // fills memory byte by byte; sizeof(visited) = total bytes of the array.
    // BUG: memset is declared in <cstring>, which this file never includes. Some
    // compilers pull it in through <iostream> or <string>, but others (e.g. MinGW
    // g++ 8.1) stop with "'memset' was not declared". Fix: add #include <cstring>.
    memset(visited, false, sizeof(visited));

    int src, dest;          // the question: can we get from src to dest?
    cin >> src >> dest;

    bfs(src);   // this fills visited[] for the whole piece that holds src

    // visited[dest] is the whole answer: BFS from src marked every node in the
    // same piece of the graph, so a marked dest is reachable, an unmarked one not.
    // (Keep the quotes around the word only: "YES" << endl. Writing "YES << endl"
    // would print the text  << endl  instead of ending the line.)
    // endl prints a newline and flushes the output right away.
    if(visited[dest]){
        cout << "YES" << endl;   // dest was reached
    } else {
        cout << "NO" << endl;    // dest is in a different piece of the graph
    }

    return 0;   // program ended normally
}
