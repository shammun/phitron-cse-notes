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

#include <iostream>
#include <vector>
#include <algorithm>    
#include <string>
#include <stack>
#include <queue>

using namespace std;

bool vis[105];              // ever seen, in any search
vector<int> adj_list[105];
bool pathvisit[105];        // on the chain of calls that is open right now
bool cycle;

void dfs(int src){
    vis[src] = true;
    pathvisit[src] = true;      // we have entered src and have not left it yet

    for(int child : adj_list[src]){
        // Seen before AND still on the current route: the arrow leads back into
        // the chain we are standing on, which closes a loop.
        if(vis[child] && pathvisit[child]){
            cycle = true;
        }
        if(!vis[child]){
            dfs(child);
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
    int n, e;
    cin >> n >> e;
    while(e--){
        int a, b;
        cin >> a >> b;
        adj_list[a].push_back(b);   // directed: stored once, a -> b only
    }
    memset(vis, false, sizeof(vis));
    memset(pathvisit, false, sizeof(pathvisit));

    cycle = false;

    // We are running for loop as there could be disconnected 
    // components
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
    // from 3 finds 1, which is still open three calls up the stack. Cycle.
    // Note that a directed graph with no cycle is exactly what can be sorted into
    // an order where every arrow points forwards; that is topological sort, and
    // it is the next use of this same pathvisit idea.

    return 0;
}