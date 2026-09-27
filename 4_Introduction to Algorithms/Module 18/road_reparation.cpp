/*

Road Reparation   (CSES 1675)

There are n cities and m roads. Repairing a road costs some amount, and a
repaired road can be used in both directions. Repair the cheapest set of
roads such that every city can be reached from every other city, and print
what that costs. If no set of roads can join all the cities, print
IMPOSSIBLE.

Keeping every city reachable with the smallest total cost is exactly a
minimum spanning tree, so this is Kruskal's algorithm from this module:
sort the roads by cost and take a road whenever its two cities are still in
different groups, using DSU to tell the groups apart.

Constraints
    1 <= n <= 10^5
    1 <= m <= 2 * 10^5
    1 <= a, b <= n
    1 <= c <= 10^9

Because 10^5 roads can each cost 10^9, the total does not fit in an int.
Keep it in a long long.

Input
    first line: n and m
    next m lines: a b c, a road between cities a and b costing c

Output
    the smallest total cost, or IMPOSSIBLE

Example

input
5 6
1 2 3
2 3 5
2 4 2
3 4 8
5 1 7
5 4 4

output
14

    Sorted by cost the roads are 2-4 (2), 1-2 (3), 5-4 (4), 2-3 (5),
    5-1 (7), 3-4 (8). The first four are taken and already join all five
    cities: 2 + 3 + 4 + 5 = 14. The last two would close a cycle, so they
    are skipped.

Example

input
3 1
1 2 5

output
IMPOSSIBLE

    City 3 has no road at all, so it can never be reached.

*/

// DSU reminder: every group of cities has a LEADER. par[x] points one step
// towards it, and par[x] == -1 means x is the leader. Same leader = already
// connected.

// <bits/stdc++.h>: g++'s "include the whole standard library" header.
#include <bits/stdc++.h>
using namespace std;    // no std:: prefix

vector<int> par;          // par[x] = parent of city x; -1 = x is a leader
vector<int> group_size;   // group_size[L] = cities in leader L's group

// One road: joins a and b, costs c.
class Edge {
    public:              // usable from outside the class
        int a, b, c;     // ends and cost (c <= 10^9 fits in an int)
        // Constructor; this->a is the member, plain a the parameter.
        Edge(int a, int b, int c) {
            this->a = a;
            this->b = b;
            this->c = c;
        }
};

// Sorting rule: true when road l should come before road r (l is cheaper).
bool cmp(Edge l, Edge r) {
    return l.c < r.c;
}

// Leader of node's group. Base case: par == -1 means node leads.
int find(int node) {
    if (par[node] == -1) {
        return node;
    }
    // Point the node straight at its leader, so the next find is short.
    int leader = find(par[node]);
    par[node] = leader;
    return leader;
}

// Merge the groups of node1 and node2 (main calls it only when they differ).
void dsu_union(int node1, int node2) {
    int leader1 = find(node1);
    int leader2 = find(node2);

    // Hang the smaller group under the bigger one to keep the tree flat.
    if (group_size[leader1] >= group_size[leader2]) {
        par[leader2] = leader1;
        group_size[leader1] += group_size[leader2];
    } else {
        par[leader1] = leader2;
        group_size[leader2] += group_size[leader1];
    }
}

int main() {
    int n, m;                    // cities, roads
    cin >> n >> m;

    // assign(count, value): resize to count elements, all equal to value.
    // n + 1 so cities keep their numbers 1..n.
    par.assign(n + 1, -1);       // everyone is their own leader
    group_size.assign(n + 1, 1); // every group has one city

    vector<Edge> edge_list;      // all roads
    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        edge_list.push_back(Edge(a, b, c));
    }

    // Cheapest road first: that is the whole idea of Kruskal's algorithm.
    sort(edge_list.begin(), edge_list.end(), cmp);

    long long total_cost = 0;    // can reach about 10^14: needs long long
    int taken = 0;               // how many roads we kept

    for (int i = 0; i < (int)edge_list.size(); i++) {   // cheapest to dearest
        Edge edge = edge_list[i];
        int parA = find(edge.a);   // group of one city
        int parB = find(edge.b);   // group of the other

        // Same leader means the two cities are already joined, so this road
        // would only close a cycle and add cost for nothing.
        if (parA != parB) {
            dsu_union(edge.a, edge.b);   // join the two groups
            total_cost += edge.c;        // pay for this road
            taken++;
        }
    }

    // A tree over n cities needs exactly n-1 roads. Fewer means the roads
    // left the cities in two or more separate pieces.
    if (taken != n - 1) {
        cout << "IMPOSSIBLE" << endl;
    } else {
        cout << total_cost << endl;
    }

    return 0;   // success
}
