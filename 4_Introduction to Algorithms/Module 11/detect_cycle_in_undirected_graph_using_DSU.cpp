// The first real use of DSU: does an undirected graph contain a cycle?
//
// Module 6 answered this with DFS or BFS. DSU answers it without walking the
// graph at all, by reading the edges one at a time and asking one question of
// each: "were these two nodes already connected before this edge arrived?"
//
//   * No  -> the edge joins two separate groups. Merge them and move on.
//   * Yes -> there is already a path between a and b, so this edge closes a loop.
//            That is a cycle.
//
// find() and dsu_union() are exactly the versions built up in find_optimized.cpp
// and union.cpp; only main() is new.
//
// Time: about O(E) - one almost-constant find per edge. Space O(n).

#include <iostream>
#include <queue>
#include <cstring>
#include <vector>
using namespace std;

int par[1005];
int group_size[1005];

int find(int node){ // O(logn)
    if(par[node] == -1){
        return node;
    }
    int leader = find(par[node]);
    par[node] = leader;
    return leader;
}

void dsu_union(int node1, int node2){
    int leader1 = find(node1);
    int leader2 = find(node2);
    if(group_size[leader1] >= group_size[leader2]){
        par[leader2] = leader1;
        group_size[leader1] += group_size[leader2];
    } else{
        par[leader1] = leader2;
        group_size[leader2] += group_size[leader1];
    }
}

int main(){
    memset(par, -1, sizeof(par));
    // Same memset-fills-bytes bug as union.cpp: every size becomes 16843009
    // instead of 1. Harmless here, because only the >= comparison is used and all
    // the starting sizes are wrong by the same amount. See union.cpp.
    memset(group_size, 1, sizeof(group_size));

    int n, e;             // n nodes (0..n-1) and e undirected edges
    cin >> n >> e;
    bool cycle = false;   // stays false until some edge closes a loop

    // Read the edges one by one. The order they come in does not matter.
    while(e--){
        int a, b;
        cin >> a >> b;
        int leader1 = find(a);
        int leader2 = find(b);
        if(leader1 == leader2){
            // Same leader means a and b could already reach each other, so this
            // edge is a second route between them: a cycle. The two groups are
            // deliberately NOT merged here - they are already one group, and
            // dsu_union assumes two different leaders.
            cycle = true;
        } else{
            // Different groups, no loop yet. Join them, so that later edges see
            // a and b as connected.
            dsu_union(a, b);
        }
    }

    // Why this works only for UNDIRECTED graphs: DSU remembers that two nodes are
    // connected, not which way the edges point. In a directed graph 1->2, 1->3,
    // 2->3 would share a leader and be reported as a cycle, even though you can
    // never walk back to where you started.

    if(cycle){
        cout << "Cycle Detected" << endl;
    } else{
        cout << "No Cycle Detected" << endl;
    }

    return 0;
}