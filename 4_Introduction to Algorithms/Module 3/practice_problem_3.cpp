/*

Question: You will be given an undirected graph as input. You need to tell the number 
of nodes in each component in ascending order.

Input:
6 5
0 1
0 2
0 3
2 3
4 5

Output:
2 4

Input:
9 7
0 1
0 2
0 3
2 3
4 5
6 8
7 6

Output:
2 3 4

Input:
7 7
0 1
1 2
2 3
1 3
4 0
0 5
5 6

Output:
7

Input:
10 5
1 2
2 3
1 3

Output:
1 1 1 2 2 3

*/

// NOTE on the 4th sample above: its first line says 5 edges but only 3 are
// listed. The expected output "1 1 1 2 2 3" matches the full edge list
// 1 2 / 2 3 / 1 3 / 4 0 / 5 6 (pieces {1,2,3} {0,4} {5,6} {7} {8} {9}); add the
// missing "4 0" and "5 6" lines when testing.

// Idea: the component loop of practice_problem_2.cpp, but instead of only
// counting the pieces we measure each one. A counter is set to 0 before each
// new DFS and dfs() adds 1 for every node it enters; when the DFS returns, the
// counter is that piece's size. Collect the sizes, sort them, print them.
//
// Example 1: pieces {0,1,2,3} and {4,5} -> sizes 4 and 2 -> "2 4".

#include <iostream>     // cin and cout
#include <vector>       // vector, for adjacency lists and the list of sizes
#include <algorithm>    // sort
#include <cstring>      // memset

using namespace std;    // write vector, sort, cout... without std::

vector<int> adj_list[1005];   // adj_list[u] = neighbours of u (array of vectors)
bool vis[1005];               // vis[u] = u was entered by some dfs
int component_size;     // nodes entered by the CURRENT dfs

// Enter src, add it to the current piece's size, go deep into unvisited neighbours.
// Base case: no unvisited neighbour -> nothing happens in the loop, we return.
void dfs(int src){
    vis[src] = true;    // mark so it is never counted again
    component_size++;   // this node belongs to the piece being measured

    for(int child : adj_list[src]){   // each neighbour
        if(!vis[child]){              // not entered yet?
            dfs(child);               // enter it; it adds itself (and its branch) to the size
        }
    }
}

int main(){
    int n, e;
    cin >> n >> e;             // n nodes (0..n-1), e edges

    while(e--){                // repeat e times
        int a, b;
        cin >> a >> b;         // edge a - b
        adj_list[a].push_back(b);   // b is a neighbour of a
        adj_list[b].push_back(a);   // and a of b (undirected)
    }

    memset(vis, false, sizeof(vis));   // all entries false

    vector<int> sizes;  // one entry per component

    for(int i=0; i<n; i++){                   // every node, even ones with no edges
        if(!vis[i]){                          // i starts a piece not measured yet
            component_size = 0;               // a new piece starts from zero
            dfs(i);                           // walks the piece, adding 1 per node
            sizes.push_back(component_size);  // its final size
        }
    }

    // sort(begin, end) arranges the elements between the two positions in
    // ascending order; begin() and end() cover the whole vector.
    sort(sizes.begin(), sizes.end());         // ascending, as asked
    // e.g. sizes {4, 2} -> {2, 4}

    // Separate the numbers with a space, but put none after the last one.
    // (sizes.size() is unsigned; comparing it with int i gives a compiler warning
    // but works here. sizes is never empty since n >= 1, so size() - 1 is safe.)
    for(int i=0; i<sizes.size(); i++){
        cout << sizes[i];                          // the i-th smallest size
        if(i < sizes.size() - 1) cout << " ";      // a space unless it is the last one
    }
    cout << endl;                                  // finish the line

    return 0;                                      // normal end of program
}
