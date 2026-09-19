// Breadth-first search (BFS): walk a graph layer by layer, out from one node.
//
// The whole idea is a waiting line. Put the starting node in the line. Take the
// node at the front out, look at its neighbours, and put the new ones at the back.
// Because newcomers always join at the back, every node one edge away leaves the
// line before any node two edges away, so the graph is swept in rings around the
// source. That ring order is what makes BFS useful later for shortest distances.

#include <iostream>
#include <vector>
#include <algorithm>    
#include <string>
#include <stack>
#include <queue>        // queue: push at the back, pop from the front (FIFO)

using namespace std;

// These two live outside main so bfs() can use them without being handed them,
// and because a global array starts out all zero / all false on its own.
// 1005 is a safe fixed size: the course problems keep n under about a thousand.
vector<int> adj_list[1005];   // adj_list[x] = the neighbours of x (Module 1)
bool visited[1005];           // visited[x] = has x already been put in the queue?

// Visit every node reachable from src, printing each one as it leaves the queue.
void bfs(int src){
    queue<int> q;
    q.push(src);           // the search begins with one node waiting
    visited[src] = true;   // mark it at once, so it can never be queued again

    // Keep working while somebody is still waiting in the line.
    while(!q.empty()){
        int par = q.front();   // the node explored in this round; call it the parent
        q.pop();               // front() only looks at it, pop() removes it

        cout << par << " ";    // printing here gives the BFS visiting order

        // Every neighbour of par is one edge further out; call it a child.
        for(int child : adj_list[par]){
            if(!visited[child]){
                q.push(child);
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
    int n, e;
    cin >> n >> e;   // n = how many nodes, e = how many edges follow

    // Read the e edges into the adjacency list, exactly as in Module 1.
    while(e--){
        int a, b;
        cin >> a >> b;
        adj_list[a].push_back(b);
        adj_list[b].push_back(a);   // undirected: the edge is walkable both ways
    }

    // Clear visited before the search. A global bool array is already all false,
    // so this changes nothing today, but it is the habit that saves you as soon
    // as a program runs a second BFS. (memset comes from <cstring>; here another
    // header happens to pull it in, which is not true on every compiler.)
    memset(visited, false, sizeof(visited));

    bfs(0);   // start the search at node 0

    // Cost: each node is pushed once and each edge is looked at once from each
    // end, so BFS is O(V + E) in time and O(V) in extra memory.

    return 0;
}