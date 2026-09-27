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
//
// Sample input (4 nodes, 4 edges, each line "a b cost"):
//   4 4
//   0 1 5
//   0 2 3
//   1 3 2
//   2 3 7
// Output:
//   0 -> 1 (5)2 (3)
//   1 -> 0 (5)3 (2)
//   2 -> 0 (3)3 (7)
//   3 -> 1 (2)2 (7)

#include <iostream>     // cin (read from keyboard) and cout (print to screen)
#include <vector>       // vector: an array that can grow with push_back
#include <algorithm>    // sort, max, min ... (not used here, kept from the class template)
#include <string>       // std::string (not used here)
#include <stack>        // std::stack (not used here)
#include <queue>        // std::queue / priority_queue (not used here; Dijkstra will need it)

// Lets us write cin, cout, vector, pair instead of std::cin, std::cout, ...
using namespace std;

// Program starts here. It reads a weighted undirected graph, stores it as an
// adjacency list of (neighbour, cost) pairs, then prints each node's list.
int main(){
    int n, e;           // n = number of nodes (numbered 0..n-1), e = number of edges
    cin >> n >> e;      // cin >> skips spaces/newlines, so "4 4" on one line or two lines both work
    // Read one entry as {neighbour, weight}. The neighbour goes in .first and the
    // cost in .second. Keep that order in mind: Module 7 deliberately flips it
    // when the pair goes into a priority queue, and mixing the two up is the most
    // common bug in Dijkstra code.
    //
    // vector<pair<int,int>> adj_list[n] is an ARRAY of n vectors: adj_list[0] is
    // node 0's list, adj_list[1] is node 1's list, and so on. Each list starts
    // empty. (An array whose size n is only known at run time is a g++ extension
    // called a VLA; standard C++ would write vector<vector<pair<int,int>>> adj_list(n).)
    vector<pair<int, int>> adj_list[n];

    // e-- tests the current e (non-zero = true) and then subtracts 1, so the body
    // runs exactly e times: once per edge line in the input.
    while(e--){
        int a, b, c;          // the two endpoints of this edge, and its cost
        cin >> a >> b >> c;   // c is the weight of the edge between a and b
        // Both endpoints must know the cost, so the weight is written twice, the
        // same way the neighbour was written twice in Module 1.
        adj_list[a].push_back({b, c});   // in a's list: "b, reached at cost c". {b, c} builds a pair
        adj_list[b].push_back({a, c});   // in b's list: "a, reached at cost c" (undirected edge)
    }

    // Print the whole list: one output line per node i.
    for(int i=0; i<n; i++){
        cout << i << " -> ";            // the node whose neighbours follow
        // Range-for: p takes each pair in adj_list[i] in turn, in the order it was added.
        for(pair<int, int> p : adj_list[i]){
            // p.first is the neighbour, p.second is what it costs to get there.
            // There is no space after the ')', so entries run into each other in
            // the output: read 1 (5)2 (3) as "1 with cost 5, 2 with cost 3".
            cout << p.first << " (" << p.second << ")";
        }
        cout << endl;                   // endl = newline + flush the output
    }

    return 0;   // 0 tells the operating system the program finished normally
}