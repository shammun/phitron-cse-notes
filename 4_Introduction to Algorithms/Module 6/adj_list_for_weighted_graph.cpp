// An adjacency list when the edges have a cost.
//
// Until now an edge was just "these two nodes are joined", and adj_list[a] held
// plain node numbers. Real roads have a length, calls have a price, pipes have a
// capacity. So each entry has to carry two facts instead of one: which neighbour,
// and what the edge to it costs.
//
// A pair<int,int> is the smallest way to say that. Nothing else about the storage
// changes: still one list per node, still both directions for an undirected edge,
// still O(n + e) memory. This is the exact shape Dijkstra will read in Module 7.

#include <iostream>
#include <vector>
#include <algorithm>    
#include <string>
#include <stack>
#include <queue>

using namespace std;

int main(){
    int n, e;
    cin >> n >> e;
    // Read one entry as {neighbour, weight}. The neighbour goes in .first and the
    // cost in .second. Keep that order in mind: Module 7 deliberately flips it
    // when the pair goes into a priority queue, and mixing the two up is the most
    // common bug in Dijkstra code.
    vector<pair<int, int>> adj_list[n];

    while(e--){
        int a, b, c;
        cin >> a >> b >> c;   // c is the weight of the edge between a and b
        // Both endpoints must know the cost, so the weight is written twice, the
        // same way the neighbour was written twice in Module 1.
        adj_list[a].push_back({b, c});
        adj_list[b].push_back({a, c});
    }

    for(int i=0; i<n; i++){
        cout << i << " -> ";
        for(pair<int, int> p : adj_list[i]){
            // p.first is the neighbour, p.second is what it costs to get there.
            // There is no space after the ')', so entries run into each other in
            // the output: read 1 (5)2 (3) as "1 with cost 5, 2 with cost 3".
            cout << p.first << " (" << p.second << ")";
        }
        cout << endl;
    }

    return 0;
}