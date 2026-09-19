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

#include <bits/stdc++.h>
using namespace std;

vector<int> par;
vector<int> group_size;

class Edge {
    public:
        int a, b, c;
        Edge(int a, int b, int c) {
            this->a = a;
            this->b = b;
            this->c = c;
        }
};

bool cmp(Edge l, Edge r) {
    return l.c < r.c;
}

int find(int node) {
    if (par[node] == -1) {
        return node;
    }
    // Point the node straight at its leader, so the next find is short.
    int leader = find(par[node]);
    par[node] = leader;
    return leader;
}

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
    int n, m;
    cin >> n >> m;

    par.assign(n + 1, -1);
    group_size.assign(n + 1, 1);

    vector<Edge> edge_list;
    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        edge_list.push_back(Edge(a, b, c));
    }

    // Cheapest road first: that is the whole idea of Kruskal's algorithm.
    sort(edge_list.begin(), edge_list.end(), cmp);

    long long total_cost = 0;
    int taken = 0;

    for (int i = 0; i < (int)edge_list.size(); i++) {
        Edge edge = edge_list[i];
        int parA = find(edge.a);
        int parB = find(edge.b);

        // Same leader means the two cities are already joined, so this road
        // would only close a cycle and add cost for nothing.
        if (parA != parB) {
            dsu_union(edge.a, edge.b);
            total_cost += edge.c;
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

    return 0;
}
