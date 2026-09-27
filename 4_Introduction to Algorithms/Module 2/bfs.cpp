// Breadth-first search (BFS): walk a graph layer by layer, out from one node.
//
// The whole idea is a waiting line. Put the starting node in the line. Take the
// node at the front out, look at its neighbours, and put the new ones at the back.
// Because newcomers always join at the back, every node one edge away leaves the
// line before any node two edges away, so the graph is swept in rings around the
// source. That ring order is what makes BFS useful later for shortest distances.
//
// Input format: first line "n e" (number of nodes, number of edges), then e lines
// "a b", each an undirected edge between nodes a and b (nodes numbered from 0).
// Output: the nodes in the order BFS visits them, starting from node 0.
//
// Tiny trace: edges 0-1, 0-2, 1-3, 2-3.
//   queue {0}        -> pop 0, print 0, push 1 and 2   -> queue {1,2}
//   queue {1,2}      -> pop 1, print 1, push 3          -> queue {2,3}
//   queue {2,3}      -> pop 2, print 2, 3 already marked -> queue {3}
//   queue {3}        -> pop 3, print 3, nothing new      -> queue {}   (stop)
//   printed: 0 1 2 3

#include <iostream>     // cin (read input) and cout (print output)
#include <vector>       // vector: an array that can grow with push_back
#include <algorithm>    // sort, reverse, ... (not used in this file, kept as a habit)
#include <string>       // std::string (not used here)
#include <stack>        // std::stack (not used here)
#include <queue>        // queue: push at the back, pop from the front (FIFO)

using namespace std;    // lets us write cout, vector, queue instead of std::cout, std::vector, ...

// These two live outside main so bfs() can use them without being handed them,
// and because a global array starts out all zero / all false on its own.
// 1005 is a safe fixed size: the course problems keep n under about a thousand.
vector<int> adj_list[1005];   // adjacency list: an ARRAY of 1005 vectors; adj_list[x] = the neighbours of x (Module 1)
bool visited[1005];           // visited[x] = has x already been put in the queue? (so no node is queued twice)

// Visit every node reachable from src, printing each one as it leaves the queue.
// Parameter: src = the starting node. Returns nothing (void); it prints and fills visited[].
void bfs(int src){
    queue<int> q;          // the waiting line of nodes that are found but not yet explored
    q.push(src);           // the search begins with one node waiting
    visited[src] = true;   // mark it at once, so it can never be queued again

    // Keep working while somebody is still waiting in the line.
    // One pass of this loop = take one node out and queue its unseen neighbours.
    while(!q.empty()){         // empty() is true when the queue has nothing left
        int par = q.front();   // the node explored in this round; call it the parent
        q.pop();               // front() only looks at it, pop() removes it

        cout << par << " ";    // printing here gives the BFS visiting order

        // Every neighbour of par is one edge further out; call it a child.
        // Range-for: child takes each value stored in adj_list[par], one by one.
        for(int child : adj_list[par]){
            if(!visited[child]){   // only nodes we have never seen before
                q.push(child);     // join the back of the line, to be explored later
                // Marked here, when it is pushed, NOT when it is later popped.
                // The same node is often a neighbour of several nodes in the
                // layer we are standing on. If the mark waited until the node
                // was popped, each of those neighbours would push it again, and
                // it would be printed two or three times and explored as often.
                // Marking at push time shuts that door the moment it opens.
                visited[child] = true;
            }
        }
    }
    // The loop ends when the queue runs dry: every node reachable from src has
    // been printed exactly once. Nodes in a separate piece are never touched.
}

int main(){
    int n, e;        // n = number of nodes, e = number of edges
    cin >> n >> e;   // cin >> skips spaces/newlines and reads the next two whole numbers

    // Read the e edges into the adjacency list, exactly as in Module 1.
    // while(e--) tests e, then lowers it by one: the body runs exactly e times.
    while(e--){
        int a, b;                   // the two ends of this edge
        cin >> a >> b;
        adj_list[a].push_back(b);   // b is a neighbour of a (push_back adds at the end of the vector)
        adj_list[b].push_back(a);   // undirected: the edge is walkable both ways
    }

    // Clear visited before the search. A global bool array is already all false,
    // so this changes nothing today, but it is the habit that saves you as soon
    // as a program runs a second BFS.
    // BUG: memset is declared in <cstring>, which this file never includes. Some
    // compilers pull it in through <iostream> or <string>, but others (e.g. MinGW
    // g++ 8.1) stop with "'memset' was not declared". Fix: add #include <cstring>.
    // memset(array, value, number_of_bytes) writes value into every byte;
    // sizeof(visited) is the size of the whole array in bytes.
    memset(visited, false, sizeof(visited));

    bfs(0);   // start the search at node 0

    // Cost: each node is pushed once and each edge is looked at once from each
    // end, so BFS is O(V + E) in time and O(V) in extra memory.

    return 0;   // 0 tells the operating system the program finished normally
}
