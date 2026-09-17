#include <iostream>
#include <vector>
#include <algorithm>    
#include <string>
#include <stack>

using namespace std;

int main(){
    int n, e;
    cin >> n >> e; // n = number of vertices, e = number of edges

    int adj_mat[n][n];
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            adj_mat[i][j] = 0;
        }
    }

    for(int i=0; i<e; i++){
        adj_mat[i][i] = 1;
    }

    /*
    
    // Shortcut for setting all elements to 0
    memset(adj_mat, 0, sizeof(adj));
    
    */

    for(int i=0; i<e; i++){
        int a, b;
        cin >> a >> b;
        adj_mat[a][b] = 1;
    }

    
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cout << adj_mat[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}