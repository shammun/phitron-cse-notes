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

/* Trace of example 1 (edges 1-2, 1-3, 1-4, 2-3, 5-4):
     BFS from 1: level 0 = {1}; level 1 = {2, 3, 4} (parent 1 each);
     level 2 = {5}, found from 4, so parent[5] = 4.
     Walk back from 5: 5 -> parent 4 -> parent 1 -> parent -1 (stop)
     gives 5 4 1; reversed: 1 4 5, size 3. */

// <bits/stdc++.h> is a GCC-only header that pulls in the whole standard library
// (iostream, vector, queue, algorithm, ...) in one line. Handy in contests; it is
// not portable to every compiler and makes compiling a bit slower.
#include <bits/stdc++.h>
using namespace std;   // use cout, vector, queue, ... without writing std:: each time

int main() {
    int n, m;          // n = number of computers, m = number of connections
    cin >> n >> m;     // cin >> reads whitespace-separated numbers

    /* n can be in the hundreds of thousands, so the adjacency list is a
       vector of size n+1 instead of a fixed-size global array. Index 0 stays
       unused because the computers are numbered from 1. */
    // vector<vector<int>> adj_list(n + 1) = n+1 empty inner vectors, one per computer.
    vector<vector<int>> adj_list(n + 1);

    // Read the m connections. while(m--) runs the body exactly m times.
    while(m--) {
        int a, b;                   // the two computers joined by this connection
        cin >> a >> b;
        adj_list[a].push_back(b);   // b is a neighbour of a
        adj_list[b].push_back(a);   // the connection works both ways
    }

    // vector<T> v(size, value) makes size copies of value.
    vector<bool> visited(n + 1, false);   // visited[x] = x has already been queued
    vector<int> level(n + 1, -1);         // level[x] = edges from computer 1 to x; -1 = unreached
    /* parent[x] is the computer that first reached x. The source has no
       parent, so it is left at -1 and that is what stops the walk back. */
    vector<int> parent(n + 1, -1);

    // BFS from computer 1. The queue holds found-but-unexplored computers
    // in first-in, first-out order, so they come out ring by ring.
    queue<int> q;
    q.push(1);           // the message starts at computer 1
    visited[1] = true;   // mark on push so it is never queued again
    level[1] = 0;        // computer 1 is 0 edges from itself

    // One pass = explore one computer's connections. Stops when the queue is empty.
    while(!q.empty()) {
        int par = q.front();   // the computer being explored (the "parent")
        q.pop();               // remove it from the front of the queue

        // child takes every neighbour of par in turn.
        for(int child : adj_list[par]) {
            if(!visited[child]) {                  // first time we meet child
                visited[child] = true;             // mark it now (never queue it twice)
                level[child] = level[par] + 1;     // one ring further than par
                parent[child] = par;               // remember who found it: this is the route back
                q.push(child);                     // explore child later
            }
        }
    }

    // BFS reached everything connected to 1. If n was not among them, no route exists.
    if(!visited[n]) {
        cout << "IMPOSSIBLE" << endl;   // endl = newline + flush
        return 0;                       // stop the program here; nothing else to print
    }

    /* Walk back from n through the parents. That gives the route in reverse,
       so it is collected in a vector and turned around. */
    vector<int> path;          // the route, filled backwards first
    int node = n;              // start the walk at the destination
    while(node != -1) {        // -1 = parent of computer 1, so we stop after adding 1
        path.push_back(node);  // record this computer
        node = parent[node];   // step one computer closer to 1
    }
    // reverse(begin, end) (from <algorithm>) flips the vector in place: n..1 becomes 1..n.
    reverse(path.begin(), path.end());

    /* level[n] counts edges; the number of computers is one more than that,
       and it is also the size of the path we just built. */
    cout << path.size() << endl;   // size() = how many elements the vector holds
    // Print the route. (int) turns size() (an unsigned type) into int so the
    // comparison i < size is between two ints and the compiler does not warn.
    for(int i = 0; i < (int)path.size(); i++) {
        if(i > 0) cout << " ";   // one space between computers, none at the end
        cout << path[i];         // the i-th computer on the route
    }
    cout << endl;   // finish the output line

    return 0;   // success
}
