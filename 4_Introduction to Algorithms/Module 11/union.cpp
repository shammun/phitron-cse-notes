// The other half of DSU: joining two groups. find() (with path compression, as in
// find_optimized.cpp) is copied in unchanged; the new part is dsu_union.
//
// Merging is cheap because of how the groups are stored: to fold group B into
// group A you do not touch B's members at all - you just make B's leader point at
// A's leader. One assignment, and every node that used to climb to B now climbs
// one step further and reaches A.
//
// The only real decision is which leader goes under which. That is UNION BY SIZE:
// hang the smaller group under the bigger one. Then only the smaller group's
// nodes get one step deeper, so the tree can never grow taller than about log n.
// That is what keeps find fast even before path compression helps.

#include <iostream>
#include <queue>
#include <cstring>
#include <vector>
using namespace std;
int par[1005];
int group_size[1005];   // group_size[L] = how many nodes are in leader L's group

int find(int node){
    if(par[node] == -1){
        return node;
    }
    int leader = find(par[node]);
    par[node] = leader;
    return leader;
}

// Put the groups of node1 and node2 together.
// Only the LEADERS matter; the two nodes themselves are never touched.
// Missing check: if leader1 == leader2 the two were already in one group, and
// this code would then hang a leader under itself and double the recorded size.
// Callers in this module must test for that first - see
// detect_cycle_in_undirected_graph_using_DSU.cpp, where the equal case is exactly
// the cycle it is hunting for.
void dsu_union(int node1, int node2){
    int leader1 = find(node1);
    int leader2 = find(node2);
    // The bigger group keeps its leader; the smaller one is hung underneath and
    // its members are added to the winner's count. On a tie either side may win -
    // here leader1 does, because of the >=.
    if(group_size[leader1] >= group_size[leader2]){
        par[leader2] = leader1;
        group_size[leader1] += group_size[leader2];
    } else{
        par[leader1] = leader2;
        group_size[leader2] += group_size[leader1];
    }
}

int main(){
    // Everyone starts alone: no parent, group of one.
    memset(par, -1, sizeof(par));

    // BUG, left in place on purpose. memset fills BYTES, not ints. Setting every
    // byte to 1 makes each int 0x01010101 = 16843009, not 1. So every group is
    // recorded as holding 16843009 members. The program still prints the right
    // thing, because all the sizes are equally wrong and only the comparison
    // group_size[leader1] >= group_size[leader2] is ever read - but the moment a
    // program prints a group size, or adds sizes up, the numbers are nonsense.
    // Correct ways: a loop `for(int i=0; i<1005; i++) group_size[i] = 1;`
    // or `fill(group_size, group_size + 1005, 1);`
    // (memset(par, -1, ...) above is fine only because the byte 11111111 happens
    // to make the int -1 as well.)
    memset(group_size, 1, sizeof(group_size));
    
    // 1 and 2 are both alone, so each is its own leader and the sizes tie.
    // The >= sends 2 under 1: par[2] becomes 1.
    dsu_union(1, 2);

    // A leader still has par == -1. Only node 2 has a parent now, so the output
    // is -1, -1, 1, -1 for nodes 0, 1, 2, 3.
    for(int i=0; i<4; i++){
        cout << i << " -> " << par[i] << endl;
    }

    return 0;
}