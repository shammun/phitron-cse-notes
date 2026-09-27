// Extra practice: store ONE graph in all three ways and print each of them.
//
// The graph (from the module's extra practice sheet) has 6 nodes numbered 1..6
// and 10 undirected edges:
//
//   edges: 1-2  1-5  2-3  2-4  2-5  3-4  3-6  4-5  4-6  5-6
//
// Input: n e, then e lines "a b". Output: the edge list, the adjacency matrix and
// the adjacency list of the same graph, so the three shapes can be compared.
//
// Example: with the 6-node graph above, row 1 of the matrix is "0 1 0 0 1 0"
// and the list line for node 4 is "4 -> 2 3 5 6".

#include <iostream>
#include <vector>

using namespace std;

int main(){
    int n, e;
    cin >> n >> e;

    // Nodes are numbered from 1 here, not 0. The easy way to cope: make every
    // array one bigger (size n+1) and simply never use index 0.
    vector<pair<int, int>> edge_list;          // 1) edge list: the pairs as read
    int adj_mat[n + 1][n + 1];                 // 2) adjacency matrix
    vector<int> adj_list[n + 1];               // 3) adjacency list

    // A local matrix starts with garbage in it, so clear every cell first.
    for(int i = 0; i <= n; i++){
        for(int j = 0; j <= n; j++){
            adj_mat[i][j] = 0;
        }
    }

    // Read each edge ONCE and write it into all three storages.
    for(int i = 0; i < e; i++){
        int a, b;
        cin >> a >> b;

        edge_list.push_back({a, b});   // edge list: stored once, as typed

        adj_mat[a][b] = 1;             // matrix: undirected, so both cells
        adj_mat[b][a] = 1;

        adj_list[a].push_back(b);      // list: each end learns about the other
        adj_list[b].push_back(a);
    }

    // 1) Edge list: e lines, one pair each.
    cout << "Edge list:" << endl;
    for(auto p : edge_list){
        cout << p.first << " " << p.second << endl;
    }

    // 2) Matrix: n rows of n numbers (index 0 skipped). It must come out
    //    symmetric, because every edge was written in both directions.
    cout << "Adjacency matrix:" << endl;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            cout << adj_mat[i][j] << " ";
        }
        cout << endl;
    }

    // 3) List: each node followed by its neighbours, in the order edges came in.
    //    The length of each line is that node's degree.
    cout << "Adjacency list:" << endl;
    for(int i = 1; i <= n; i++){
        cout << i << " -> ";
        for(int x : adj_list[i]){
            cout << x << " ";
        }
        cout << endl;
    }

    return 0;
}
