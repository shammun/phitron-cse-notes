// Does an undirected graph contain a cycle? BFS version.
//
// A cycle means there are two different ways to reach the same node. So while
// exploring node par, meeting a neighbour that is ALREADY visited looks like the
// answer: somebody else got there first, by another route.
//
// Except for one case, and it is the case that happens on every single edge. The
// graph is undirected, so the edge that brought us to par is stored in par's list
// too. Standing on par we will always see our own discoverer sitting there,
// already visited, and that is not a second route, it is the same road looked at
// backwards. So the node that discovered par, parent[par], must be excused.
//
// That gives the rule: a visited neighbour that is NOT par's parent means a cycle.
//
// Note this is why a parent array is needed here at all, and why the same rule
// cannot be used on a directed graph (see detect_cycle_in_directed_graph_dfs.cpp):
// there, arrows 0->2 and 1->2 make 2 visited twice with no cycle anywhere.
//
// Tiny trace, triangle 0-1, 0-2, 1-2:
//   pop 0: 1 and 2 are new -> push both, parent[1] = parent[2] = 0
//   pop 1: neighbour 0 is visited but is parent[1] -> excused;
//          neighbour 2 is visited and is NOT parent[1] -> cycle!
// Output: Cycle Detected

#include <iostream>     // cin, cout
#include <vector>       // vector, for the adjacency lists
#include <algorithm>    // not used here (class template)
#include <string>       // not used here
#include <stack>        // not used here
#include <queue>        // queue: first-in first-out line, the heart of BFS
// BUG: memset (used in main) is declared in <cstring>, which is not included.
// Some compilers pull it in through <iostream> by accident, but many (including
// the g++ this repo is checked with) stop with "'memset' was not declared in this
// scope". Fix: add #include <cstring> here.

using namespace std;    // write cin/cout/queue without std::

bool vis[105];              // vis[x] = has x been discovered (put in the queue) yet?
vector<int> adj_list[105];  // adj_list[x] = all neighbours of x
int parent[105];   // parent[x] = the node that discovered x; -1 for a start node
bool cycle;        // global so bfs() can raise the flag from anywhere

// Breadth-first search from src: visits every node of src's component, layer
// by layer, filling parent[] and raising cycle if a second route is found.
void bfs(int src){
    queue<int> q;       // nodes discovered but not yet explored, oldest first
    q.push(src);        // start with src waiting in line
    vis[src] = true;    // mark when PUSHED, so no node enters the queue twice

    // One pass = take the oldest waiting node and look at all its neighbours.
    // Stops when the queue is empty: the whole component has been explored.
    while(!q.empty()){
        int par = q.front();   // front() reads the oldest node...
        q.pop();               // ...and pop() removes it (pop returns nothing)

        for(int child : adj_list[par]){   // each neighbour of par in turn
            // Already seen, and not the node we came from: a second way in.
            if(vis[child] && parent[par] != child){
                cycle = true;
                // No break: the search is allowed to finish. The flag is enough,
                // and the rest of the graph still has to be marked for the loop
                // in main to work out which components are left.
            }
            // The ordinary BFS step, unchanged from Module 2 except for the one
            // extra line that remembers who did the discovering.
            if(!vis[child]){
                q.push(child);          // child joins the back of the line
                vis[child] = true;      // discovered now
                parent[child] = par;    // par is the one who found it
            }
        }
    }
}

int main(){
    int n, e;                       // n nodes (0..n-1), e edges
    cin >> n >> e;
    while(e--){                     // body runs e times, once per edge
        int a, b;
        cin >> a >> b;              // an edge between a and b
        adj_list[a].push_back(b);
        adj_list[b].push_back(a);   // undirected, so both lists hold the edge
    }
    // memset fills bytes. false is byte 0, fine. -1 also works for int because
    // -1 is the byte 0xFF repeated (0xFFFFFFFF = -1); memset with 5 would NOT give 5.
    memset(vis, false, sizeof(vis));
    memset(parent, -1, sizeof(parent));

    cycle = false;                  // innocent until proven guilty
    // Start a search from every node that is still unvisited, because the cycle
    // may sit in a piece of the graph that node 0 cannot reach at all.
    for(int i=0; i<n; i++){
        if(!vis[i]){
            bfs(i);
        }
    }
    if(cycle){
        cout << "Cycle Detected" << endl;
    }
    else{
        cout << "No Cycle" << endl;
    }

    // Cost: one BFS over the whole graph, O(V + E).

    return 0;   // normal exit
}