// Does a DIRECTED graph contain a cycle?
//
// The undirected rule does not survive the move to one-way edges. Take 0 -> 2 and
// 1 -> 2. Searching from 0 marks 2; later, standing on 1, node 2 is already
// visited and is certainly not 1's parent, so the old rule shouts "cycle" when
// there is plainly none. Two arrows can meet at a node without any way back.
//
// A cycle in a directed graph means something stricter: following arrows, you can
// return to a node you have not finished leaving yet. So the question to ask
// about a neighbour is not "has it ever been visited?" but "is it still on the
// path I am standing on right now?".
//
// That needs a second array. vis[] remembers everything ever seen, for all time.
// pathvisit[] remembers only the chain of calls currently open, the route from
// the node this search started at down to where we are now. It is switched on
// when a node is entered and switched off again at the very end of dfs, when that
// node is finished and the recursion steps back out of it. An edge into a node
// whose pathvisit is still true is an edge pointing backwards along our own
// route: a cycle.
//
// Miss that final unset and a node stays "on the path" long after we have left
// it, and the program reports cycles that do not exist.
//
// Sample input (n e, then e lines "a b" meaning an arrow a -> b):
//   4 4
//   0 1
//   1 2
//   2 3
//   3 1
// Output: Cycle Detected

#include <iostream>     // cin, cout
#include <vector>       // vector, for the adjacency lists
#include <algorithm>    // not used here (class template)
#include <string>       // not used here
#include <stack>        // not used here
#include <queue>        // not used here
// BUG: memset (used in main) is declared in <cstring>, which is not included.
// Some compilers pull it in through <iostream> by accident, but many (including
// the g++ this repo is checked with) stop with "'memset' was not declared in this
// scope". Fix: add #include <cstring> here.

using namespace std;    // write cin/cout/vector without std::

// Globals: the graph and the marks are shared by dfs() and main(). 105 slots
// because the course problems have at most about 100 nodes.
bool vis[105];              // ever seen, in any search
vector<int> adj_list[105];  // adj_list[a] = every b with an arrow a -> b
bool pathvisit[105];        // on the chain of calls that is open right now
bool cycle;                 // set to true the moment any cycle is found

// Depth-first search from src. Marks src as seen and as "on the current path",
// explores every arrow out of it, then removes it from the path on the way out.
// Returns nothing; its result is the global flag cycle.
void dfs(int src){
    vis[src] = true;            // seen, forever
    pathvisit[src] = true;      // we have entered src and have not left it yet

    // Look at every node src points to.
    for(int child : adj_list[src]){
        // Seen before AND still on the current route: the arrow leads back into
        // the chain we are standing on, which closes a loop.
        if(vis[child] && pathvisit[child]){
            cycle = true;
        }
        if(!vis[child]){
            dfs(child);         // brand-new node: go deeper; returns when child is fully explored
        }
        // A child that is visited but NOT on the path is deliberately ignored:
        // it belongs to a branch already finished, so it is a shortcut forwards,
        // never a way back. That is the whole difference from the undirected file.
    }

    // Leaving src for good. Take it off the current route, so a later branch that
    // merely points at src does not look like a loop.
    pathvisit[src] = false;
}

int main(){
    int n, e;                       // n nodes (0..n-1), e arrows
    cin >> n >> e;
    while(e--){                     // runs e times, once per arrow
        int a, b;
        cin >> a >> b;              // one arrow a -> b
        adj_list[a].push_back(b);   // directed: stored once, a -> b only
    }
    // memset(array, value, bytes) sets every byte; sizeof gives the array's total bytes.
    memset(vis, false, sizeof(vis));
    memset(pathvisit, false, sizeof(pathvisit));

    cycle = false;                  // no cycle found yet

    // We are running for loop as there could be disconnected
    // components
    // (Also: in a directed graph, even a connected one, node 0 may not be able
    // to REACH every node along the arrows, so we start again from any node
    // still unvisited.)
    for(int i=0; i<n; i++){
        if(!vis[i]){
            dfs(i);
        }
    }
    if(cycle){
        cout << "Cycle Detected" << endl;
    }
    else{
        cout << "No Cycle" << endl;
    }

    // With the sample edges 0->1, 1->2, 2->3, 3->1 the search goes 0, 1, 2, 3 and
    // from 3 finds 1, which is still open on the call stack (the open calls are
    // dfs(0), dfs(1), dfs(2), dfs(3)), so pathvisit[1] is true. Cycle.
    // Note that a directed graph with no cycle is exactly what can be sorted into
    // an order where every arrow points forwards; that is topological sort, and
    // it is the next use of this same pathvisit idea.

    return 0;   // normal exit
}