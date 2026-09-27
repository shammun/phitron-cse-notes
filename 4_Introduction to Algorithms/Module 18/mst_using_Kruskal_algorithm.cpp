// KRUSKAL'S ALGORITHM: the cheapest set of roads that still connects every city.
//
// A minimum spanning tree of a connected graph with n nodes is a set of n-1
// edges that joins everything together for the least total weight. Kruskal finds
// one by being greedy in the simplest possible way:
//     sort every edge by weight, then walk through them cheapest first and keep
//     an edge whenever its two ends are not already connected.
//
// "Not already connected" is exactly the question DSU answers (Module 11), so
// find() and dsu_union() are copied in from there. If the two ends already share
// a leader, they are already joined by edges no dearer than this one, and adding
// it would only close a cycle - so it is skipped.
//
// Example input (5 nodes, 7 edges "a b cost"):
//   0 1 2 / 0 2 3 / 0 3 3 / 3 4 6 / 2 4 4 / 2 1 7 / 1 4 5
// Sorted: 0-1(2) 0-2(3) 0-3(3) 2-4(4) 1-4(5) 3-4(6) 2-1(7).
// Kept: 0-1, 0-2, 0-3, 2-4 -> total 2+3+3+4 = 12 (once the BUG below is fixed;
// as written, the program crashes).

#include <iostream>     // cin, cout, endl
#include <vector>       // vector
#include <algorithm>    // sort
#include <string>       // not used here

using namespace std;    // no std:: prefix

// The DSU arrays from Module 11: par[x] == -1 means x is a leader.
int par[1005];
int group_size[1005];   // group_size[L] = members in leader L's group

// One edge: it joins a and b and costs c. Kruskal works on the list of edges
// rather than on an adjacency list, because the edges have to be sorted as a
// single pile, regardless of which node they hang off.
class Edge{
    public:              // members usable from outside the class
        int a, b, c;     // ends a, b and cost c
        // Constructor. this->a is the member; plain a is the parameter.
        Edge(int a, int b, int c){
            this->a = a;
            this->b = b;
            this->c = c;
        }
};

// The rule sort() is given: an edge comes first if it is cheaper. Without this
// comparator sort() would not know how to order two Edge objects.
// It must answer "should l come before r?" - true when l is cheaper.
bool cmp(Edge l, Edge r){
    return l.c < r.c;
}

// Leader of node's group, with path compression (Module 11).
// Base case: par == -1 -> node is the leader.
int find(int node){
    if(par[node] == -1){
        return node;
    }
    int leader = find(par[node]);   // the parent's leader is ours
    par[node] = leader;             // shortcut for next time
    return leader;
}

// BUG, left in place - and the reason this program crashes without printing
// anything. The function is declared to return int, but no branch ever returns a
// value. In C++ falling off the end of a non-void function is undefined
// behaviour; the compiler only warns ("no return statement in function returning
// non-void") and the program dies with an access violation on the first union.
// The fix is one word: void dsu_union(int node1, int node2).
// The body itself is the correct union-by-size from Module 11.
int dsu_union(int node1, int node2){ // BUG: should be void - no value is ever returned
    int leader1 = find(node1);
    int leader2 = find(node2);

    // Hang the smaller group under the bigger group's leader.
    if(group_size[leader1] >= group_size[leader2]){
        par[leader2] = leader1;
        group_size[leader1] += group_size[leader2];
    } else{
        par[leader1] = leader2;
        group_size[leader2] += group_size[leader1];
    }
}

int main(){
    // Every node starts alone and is its own leader.
    // memset fills every byte with 0xFF, and four such bytes make the int -1.
    memset(par, -1, sizeof(par));
    // BUG, left in place, the same one as Module 11's union.cpp: memset fills
    // BYTES, so setting each byte to 1 makes every int 0x01010101 = 16843009, not
    // 1. Only the >= comparison is ever read here, and all the sizes are wrong by
    // the same amount, so the answer survives - but the recorded group sizes are
    // nonsense. Use a loop, or fill(group_size, group_size + 1005, 1).
    // (memset lives in <cstring>, which this file does not include.)
    memset(group_size, 1, sizeof(group_size)); // BUG: sizes become 16843009, not 1

    int n, e;                // nodes, edges
    cin >> n >> e;
    vector<Edge> edge_list;  // every edge, in one flat list

    // Read all e edges into one flat list. Direction does not matter: an MST is
    // defined on an undirected graph.
    while(e--){
        int a, b, c;
        cin >> a >> b >> c;
        edge_list.push_back(Edge(a, b, c));   // build an Edge and append it
    }

    // Cheapest first. This sort is the expensive part, O(E log E), and it is what
    // makes the greedy rule below correct.
    // sort(begin, end, cmp) orders the whole vector using our cmp rule.
    sort(edge_list.begin(), edge_list.end(), cmp);

    // Debug print of the sorted edges (commented out so the output is only the
    // answer):
    /*
    for(auto edge : edge_list){
        cout << edge.a << " " << edge.b << " " << edge.c << endl;
    }
    */

    // BUG in waiting: an int. With up to n-1 edges of weight a billion each, an
    // MST cost can run past the int limit of about 2.1 billion and wrap round to
    // a negative number, silently. long long is the safe type for a total like
    // this - the small sample input here never gets near the limit.
    int total_cost = 0;   // BUG (latent): should be long long for big weights

    // Check if the edges are connected or not
    // Walk the edges cheapest first and keep the ones that join two separate
    // groups. Each kept edge merges two groups into one, so a connected graph
    // with n nodes ends up keeping exactly n-1 edges.
    for(auto edge : edge_list){      // edge = each Edge in sorted order
        int parA = find(edge.a);     // group of one end
        int parB = find(edge.b);     // group of the other end
        if(parA != parB){
            // Different groups: this edge connects something new, so keep it.
            dsu_union(edge.a, edge.b);
            total_cost += edge.c;
        }
        // Same group: skip it. Its two ends are already linked by edges that came
        // earlier and so cost no more, and adding it would just make a cycle.
    }

    // Note this prints a total even when the graph is not connected - it would
    // then be the cost of a forest, not a spanning tree. Counting the kept edges
    // and checking for n-1 would catch that case.

    cout << total_cost << endl;   // the MST's total weight

    return 0;   // success
}
