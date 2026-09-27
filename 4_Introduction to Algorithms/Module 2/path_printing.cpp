// Print the shortest path itself, not just its length.
//
// Same BFS again, now with a parent array as well as level. Every node except the
// source is discovered by exactly one other node: the one that pushed it. Writing
// that discoverer down gives a chain of single steps, and following the chain back
// from the destination walks a shortest path in reverse.
//
// So the search never stores paths. It stores one number per node, and the path is
// rebuilt afterwards from those numbers.
//
// Input: "n e", e undirected edges "a b", then "src dest".
// Output: BFS order, then the path backwards, then the path forwards.
//
// Tiny trace: edges 0-1, 1-2, 0-3, 3-2 ; src 0, dest 2.
//   BFS from 0: pop 0 -> parent[1]=0, parent[3]=0 ; pop 1 -> parent[2]=1 ;
//   pop 3 -> 2 already visited, parent[2] stays 1 ; pop 2.
//   Walk back: 2 -> parent 1 -> parent 0 -> parent -1 stop  => "2 1 0"
//   Reversed: "0 1 2".

#include <iostream>     // cin, cout
#include <vector>       // vector: growable array (adjacency list, path)
#include <algorithm>    // reverse()
#include <string>       // not used here
#include <stack>        // not used here
#include <queue>        // queue for BFS (first in, first out)

using namespace std;    // no need to write std:: before cout, vector, queue, ...

// Global arrays: shared by bfs() and main(), and zero-filled automatically.
vector<int> adj_list[1005];   // adj_list[x] = neighbours of x
bool visited[1005];           // visited[x] = x has been put in the queue
int level[1005];              // level[x] = edges from src to x (-1 = not reached)
int parent[1005];   // parent[x] = the node that first reached x; -1 for the source

// BFS from src that fills visited[], level[] and parent[] and prints the visit order.
void bfs(int src){
    queue<int> q;          // found-but-unexplored nodes, in FIFO order
    q.push(src);           // start at the source
    visited[src] = true;   // mark on push
    level[src] = 0;        // source is 0 edges from itself
    // parent[src] = -1;
    // The line above is commented out because main already set the whole parent
    // array to -1. The source keeps that -1, and that is what stops the walk back.

    // One pass = explore one node. Ends when no node is waiting.
    while(!q.empty()){
        int par = q.front();   // node at the front of the line
        q.pop();               // remove it

        cout << par << " ";    // print BFS order

        for(int child : adj_list[par]){   // every neighbour of par
            if(!visited[child]){           // seen for the first time
                q.push(child);             // explore it later
                visited[child] = true;     // mark now so it is not pushed twice
                level[child] = level[par] + 1;   // one edge further than par
                // Recorded at the same moment as the mark, so it records the
                // first discovery. Any later edge into child is ignored, which
                // is right: the first one came along a shortest route.
                parent[child] = par;
            }
        }
    }
}


int main(){
    int n, e;          // nodes, edges
    cin >> n >> e;

    // Read e undirected edges.
    while(e--){                     // body runs exactly e times
        int a, b;
        cin >> a >> b;
        adj_list[a].push_back(b);   // a -> b
        adj_list[b].push_back(a);   // b -> a (undirected)
    }

    // memset(array, value, bytes) fills every BYTE with value.
    // false = 0 bytes; -1 works for int because -1 is all bytes 0xFF.
    // BUG: memset is declared in <cstring>, which this file never includes. Some
    // compilers pull it in through <iostream> or <string>, but others (e.g. MinGW
    // g++ 8.1) stop with "'memset' was not declared". Fix: add #include <cstring>.
    memset(visited, false, sizeof(visited));
    memset(level, -1, sizeof(level));
    memset(parent, -1, sizeof(parent));   // -1 means "nobody discovered this node"

    int src, dest;         // path wanted from src to dest
    cin >> src >> dest;

    bfs(src);       // fill parent[] (and print the BFS order)
    cout << endl;   // end the BFS-order line so each print gets its own line

    // Useful while learning: see who discovered each node.
    // (Commented out; if switched on it prints "i parent -> parent[i]" for every node.)
    /*
    for(int i=0; i<n; i++){
        cout << i << " parent -> " << parent[i] << endl;
    }
    */

    // First way to print path -- prints in reverse order
    // Start at the destination and keep stepping to the parent. The source has
    // parent -1, so that value is the signal to stop. What comes out is the path
    // read backwards, from dest to src.
    int node = dest;             // current node on the walk back

    while(node != -1){           // stop after printing the source
        cout << node << " ";     // print this node
        node = parent[node];     // move one step toward the source
    }
    cout << endl;

    // Second way to print path -- prints in correct order
    // Same walk, but collect the nodes into a vector instead of printing them,
    // then turn the vector round. reverse() comes from <algorithm>.
    vector<int> path;            // will hold dest ... src, then be flipped
    int node2 = dest;            // a second walker (node already reached -1)
    while(node2 != -1){
        path.push_back(node2);   // add to the end of the vector
        node2 = parent[node2];   // step back
    }
    reverse(path.begin(), path.end());   // begin()/end() mark the whole vector; now src ... dest
    for(int x : path){           // range-for: x is each node of the path in order
        cout << x << " ";
    }
    cout << endl;

    // Both walks are printed one after the other, so the output shows the path
    // backwards and then forwards. In a real solution you would keep only one.
    //
    // A trap worth knowing: if dest was never reached, parent[dest] is still -1
    // and this prints just dest, which looks like a path but is not one. Check
    // visited[dest] first before trusting the walk.

    return 0;   // normal end
}
