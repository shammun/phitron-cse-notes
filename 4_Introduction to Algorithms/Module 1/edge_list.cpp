// The simplest way to store a graph: the edge list.
//
// No table, no per-node lists: just every edge, written down as the pair (a, b)
// in the order it was read. It is small (one pair per edge) and it is exactly the
// shape wanted by algorithms that sweep over all edges again and again, such as
// Bellman-Ford later in the course. Its weakness: to find the neighbours of one
// node you must read the whole list.

#include <iostream>
#include <vector>
#include <algorithm>    
#include <string>
#include <stack>

using namespace std;

int main(){
    int n, e;
    cin >> n >> e; // n = number of vertices, e = number of edges

    // One growable list of pairs. p.first is one end of an edge, p.second the other.
    vector<pair<int, int>> edge_list;

    while(e--){
        int a,b;
        cin >> a >> b;
        edge_list.push_back({a, b});   // {a, b} builds the pair in place
    }

    // Walk the list and print each edge. The "<-" is only decoration: the pair
    // is simply the edge (a, b), in the order it was typed.
    for(pair<int, int> p : edge_list){
        cout << p.first << " <- " << p.second << endl;
    }

    /*
    
    // Instead we can also write the above loop as:

    for(auto p : edge_list){
        cout << p.first << " <- " << p.second << endl;
    }

    */

    return 0;
}
