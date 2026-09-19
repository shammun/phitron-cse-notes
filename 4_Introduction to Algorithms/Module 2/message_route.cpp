/*

Message Route   (CSES 1667)

Syrjala has n computers and m connections between them. Every connection joins
two computers and can be used in both directions. Uolevi wants to send a
message from computer 1 to computer n, and he wants the message to pass
through as few computers as possible. Print how many computers the route
visits and the route itself. If computer n cannot be reached from computer 1
at all, print IMPOSSIBLE.

Every connection costs the same, so "fewest computers" is just "fewest edges",
and that is exactly what BFS measures. BFS gives the levels; a parent array
remembers which computer put each computer into the queue, so the route can be
walked backwards from n.

Input
The first line has two numbers n and m: the number of computers and the number
of connections. The computers are numbered 1, 2, ..., n.
Then m lines follow, each with two numbers a and b: there is a connection
between computers a and b.
Both n and m can be large (hundreds of thousands), so the graph is kept as an
adjacency list and BFS touches every computer and every connection once.

Output
If there is no route, print the single word IMPOSSIBLE.
Otherwise print on the first line k, the number of computers on the route, and
on the second line the k computers in order, starting with 1 and ending with n.

Examples

input
5 5
1 2
1 3
1 4
2 3
5 4

output
3
1 4 5

input
4 2
1 2
3 4

output
IMPOSSIBLE

*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    /* n can be in the hundreds of thousands, so the adjacency list is a
       vector of size n+1 instead of a fixed-size global array. Index 0 stays
       unused because the computers are numbered from 1. */
    vector<vector<int>> adj_list(n + 1);

    while(m--) {
        int a, b;
        cin >> a >> b;
        adj_list[a].push_back(b);
        adj_list[b].push_back(a);   // the connection works both ways
    }

    vector<bool> visited(n + 1, false);
    vector<int> level(n + 1, -1);
    /* parent[x] is the computer that first reached x. The source has no
       parent, so it is left at -1 and that is what stops the walk back. */
    vector<int> parent(n + 1, -1);

    queue<int> q;
    q.push(1);
    visited[1] = true;
    level[1] = 0;

    while(!q.empty()) {
        int par = q.front();
        q.pop();

        for(int child : adj_list[par]) {
            if(!visited[child]) {
                visited[child] = true;
                level[child] = level[par] + 1;
                parent[child] = par;
                q.push(child);
            }
        }
    }

    if(!visited[n]) {
        cout << "IMPOSSIBLE" << endl;
        return 0;
    }

    /* Walk back from n through the parents. That gives the route in reverse,
       so it is collected in a vector and turned around. */
    vector<int> path;
    int node = n;
    while(node != -1) {
        path.push_back(node);
        node = parent[node];
    }
    reverse(path.begin(), path.end());

    /* level[n] counts edges; the number of computers is one more than that,
       and it is also the size of the path we just built. */
    cout << path.size() << endl;
    for(int i = 0; i < (int)path.size(); i++) {
        if(i > 0) cout << " ";   // one space between computers, none at the end
        cout << path[i];
    }
    cout << endl;

    return 0;
}
