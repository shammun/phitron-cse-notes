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
// and union.cpp (repeated with comments below); only main() is new.
//
// Time: about O(E) - one almost-constant find per edge. Space O(n).
//
// Trace: edges 0-1, 1-2, 2-0.
//   0-1: leaders 0 and 1 differ -> merge, now {0,1}
//   1-2: leaders differ         -> merge, now {0,1,2}
//   2-0: both have the same leader -> "Cycle Detected" (0-1-2-0).

#include <iostream>   // cin, cout, endl
#include <queue>      // not used here
#include <cstring>    // memset
#include <vector>     // not used here
using namespace std;  // no std:: prefix needed

// DSU storage, one slot per node (up to 1005 nodes). Global arrays start as 0.
int par[1005];          // par[x] = parent of x; -1 means x is a leader
int group_size[1005];   // group_size[L] = members in leader L's group

// find(node): return the leader of node's group, flattening the path on the
// way (path compression). Base case: a node with no parent is the leader. The
// recursive call trusts that find(par[node]) returns the leader of the parent,
// which is also node's leader.
int find(int node){ // O(logn)
    if(par[node] == -1){          // no parent: node is the leader
        return node;
    }
    int leader = find(par[node]); // leader of the parent = our leader
    par[node] = leader;           // point node straight at it for next time
    return leader;
}

// dsu_union(node1, node2): merge the two groups. Only the leaders move: the
// smaller group's leader is hung under the bigger group's leader (union by
// size), which keeps the trees short. Assumes the leaders differ (main checks).
void dsu_union(int node1, int node2){
    int leader1 = find(node1);    // leader of node1's group
    int leader2 = find(node2);    // leader of node2's group
    if(group_size[leader1] >= group_size[leader2]){   // group 1 is bigger (or tie)
        par[leader2] = leader1;                       // hang group 2 under it
        group_size[leader1] += group_size[leader2];   // and add its members
    } else{                                           // group 2 is bigger
        par[leader1] = leader2;
        group_size[leader2] += group_size[leader1];
    }
}

int main(){
    // memset(ptr, byte, count) writes the same byte into every byte of the
    // block. sizeof(par) = the array's size in bytes. The byte 0xFF makes each
    // int -1, so every node starts as its own leader.
    memset(par, -1, sizeof(par));
    // Same memset-fills-bytes bug as union.cpp: every size becomes 16843009
    // instead of 1. Harmless here, because only the >= comparison is used and all
    // the starting sizes are wrong by the same amount. See union.cpp.
    // BUG: memset sets bytes, so each int is 0x01010101 = 16843009, not 1. The
    // cycle answer is still right, but after about 128 merges a sum of these
    // sizes overflows int (16843009 * 128 > 2^31 - 1) and turns negative, which
    // spoils the union-by-size balance. Fix: a loop setting group_size[i] = 1.
    memset(group_size, 1, sizeof(group_size));

    int n, e;             // n nodes (0..n-1) and e undirected edges
    cin >> n >> e;
    bool cycle = false;   // stays false until some edge closes a loop

    // Read the edges one by one. The order they come in does not matter.
    while(e--){                   // runs exactly e times
        int a, b;                 // the edge a - b
        cin >> a >> b;
        int leader1 = find(a);    // whose group is a in?
        int leader2 = find(b);    // whose group is b in?
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
        cout << "Cycle Detected" << endl;      // endl = newline + flush
    } else{
        cout << "No Cycle Detected" << endl;
    }

    return 0;   // success
}