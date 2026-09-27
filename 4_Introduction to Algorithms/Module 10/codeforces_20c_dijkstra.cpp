/*

C. Dijkstra?   (Codeforces 20C)

A country has n cities, numbered 1 .. n, joined by m two-way roads. Each road
has a positive length. Print the shortest route from city 1 to city n as the
list of cities you pass through, first 1 and last n. If city n cannot be
reached, print -1. If several routes are equally short, any of them is
accepted.

This is plain Dijkstra with one addition: besides the distance we remember,
for every city, which city we came from when its distance was last improved.
Walking those parents back from n gives the route.

Input
The first line has n and m.
The next m lines each have three numbers a, b and w: a road of length w
between cities a and b. There may be several roads between the same pair, and
a road may start and end in the same city. Both n and m can be around 10^5.

Output
The cities of a shortest route from 1 to n, in order, separated by spaces, or
-1 if there is no route.

Examples

input
5 6
1 2 2
2 5 5
2 3 4
1 4 1
4 3 3
3 5 1

output
1 4 3 5

The route 1 -> 4 -> 3 -> 5 costs 1 + 3 + 1 = 5. Going 1 -> 2 -> 5 would cost
2 + 5 = 7.

input
3 1
1 2 5

output
-1

*/

// <bits/stdc++.h> is a g++ shortcut header that pulls in the whole standard
// library at once: iostream (cin/cout), vector, queue (priority_queue),
// algorithm (reverse), utility (pair) and the rest. Handy in contests; it is
// not standard C++, so other compilers may not have it.
#include <bits/stdc++.h>
// Lets us write cout, vector, pair ... instead of std::cout, std::vector ...
using namespace std;

/* The lengths are positive but there can be about 10^5 roads, so a route can
   be far longer than an int holds. Everything that stores or adds a distance
   is long long, and INF is a large value that still leaves room for one
   addition. */
// 1e18 is a double literal (1 followed by 18 zeros); dividing by 4 gives
// 2.5e17, which is converted to long long. "const" means it can never change.
// INF stands for "no route found yet".
const long long INF = 1e18 / 4;

int main() {
    int n, m;          // n = number of cities, m = number of roads
    cin >> n >> m;     // cin >> skips spaces/newlines and reads the next number

    /* vector<pair<int, long long>>: for each city, the list of (neighbour,
       road length) pairs. Size n+1 so the cities keep their own numbers. */
    // adj_list[a] is a vector; each element is a pair whose .first is the city
    // at the other end and whose .second is the road length. This is an
    // "adjacency list": for every city, only the roads that touch it.
    vector<vector<pair<int, long long>>> adj_list(n + 1);

    // Read the m roads. "while(m--)" tests m and THEN subtracts 1, so the body
    // runs exactly m times (m, m-1, ..., 1 are all true; 0 stops it).
    while(m--) {
        int a, b;      // the two cities at the ends of this road
        long long w;   // its length (long long so sums never overflow)
        cin >> a >> b >> w;
        // push_back adds one element at the end of the vector. {b, w} builds a
        // pair on the spot: "from a you can reach b with cost w".
        adj_list[a].push_back({b, w});
        adj_list[b].push_back({a, w});   // the roads are two-way
    }

    // dis[v] = the cheapest known cost from city 1 to city v. Every entry
    // starts at INF ("unknown"); the vector(n+1, INF) constructor makes n+1
    // copies of INF.
    vector<long long> dis(n + 1, INF);
    vector<int> parent(n + 1, -1);   // -1 means "no city came before this one"

    /* The pair is (distance, city) in that order, because the priority queue
       compares the first member first, and greater<> turns the max-heap into
       a min-heap so the closest city comes out on top. */
    // priority_queue<T, Container, Compare>:
    //   T         = pair<long long,int>, the (distance, city) pair
    //   Container = vector<...>, the storage it uses inside
    //   Compare   = greater<...>; by default a priority_queue keeps the
    //               LARGEST element on top, greater flips that so the
    //               SMALLEST distance is on top.
    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;

    dis[1] = 0;        // the start city is 0 away from itself
    pq.push({0, 1});   // and it is the first city to process

    // Main Dijkstra loop. One pass takes the closest not-yet-final city out of
    // the queue and tries to improve its neighbours through it. It stops when
    // the queue is empty, i.e. no city has a pending improvement.
    while(!pq.empty()) {
        pair<long long, int> par = pq.top();   // top() = the smallest distance
        pq.pop();                              // pop() removes that element
        long long par_dist = par.first;        // its distance when pushed
        int par_node = par.second;             // which city it is

        /* An old, worse copy of this city may still be sitting in the queue
           from an earlier improvement. It is cheaper to skip it here than to
           search the queue and remove it. */
        // "continue" jumps straight to the next pass of the while loop.
        if(par_dist > dis[par_node]) continue;

        // Range-for: "child" takes each (neighbour, length) pair of par_node in
        // turn. auto lets the compiler work out the type, pair<int,long long>.
        for(auto child : adj_list[par_node]) {
            int child_node = child.first;          // the neighbour city
            long long child_dist = child.second;   // the road length to it

            // Relaxation: is "go to par_node, then take this road" cheaper
            // than the best way to child_node known so far?
            if(par_dist + child_dist < dis[child_node]) {
                dis[child_node] = par_dist + child_dist;   // yes: record it
                parent[child_node] = par_node;   // remember how we got here
                pq.push({dis[child_node], child_node});    // process it later
            }
        }
    }

    // Still INF means no road chain ever reached city n.
    if(dis[n] == INF) {
        cout << -1 << endl;   // endl prints a newline and flushes the output
        return 0;             // end the program early; nothing more to print
    }

    /* Walk back from n; parent[1] is still -1, so the walk stops at the
       start. The cities come out reversed, so the list is turned around. */
    // Trace with the first example: parent[5]=3, parent[3]=4, parent[4]=1,
    // parent[1]=-1, so path = {5,3,4,1}, and after reverse {1,4,3,5}.
    vector<int> path;
    int node = n;                   // start at the destination
    while(node != -1) {             // stop after adding city 1
        path.push_back(node);       // record this city
        node = parent[node];        // step one city back along the route
    }
    // reverse(begin, end) turns the vector around in place.
    reverse(path.begin(), path.end());

    // Print the route with single spaces between cities. (int) turns size(),
    // which is unsigned, into an int so the comparison with i is clean.
    for(int i = 0; i < (int)path.size(); i++) {
        if(i > 0) cout << " ";   // a space before every city except the first
        cout << path[i];
    }
    cout << endl;   // finish the line

    return 0;       // 0 tells the operating system the program succeeded
}
