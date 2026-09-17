/*

https://www.geeksforgeeks.org/problems/implementing-floyd-warshall2042/1

Floyd Warshall

The problem is to find the shortest distances between every pair of vertices in a given 
edge-weighted directed graph. The graph is represented as an adjacency matrix. mat[i][j] 
denotes the weight of the edge from i to j. If mat[i][j] = -1, it means there is no edge 
from i to j.
Note: Modify the distances for every pair in place.

Examples :
Input: mat = [[0, 25], [-1, 0]]
Output: [[0, 25], [-1, 0]]
Explanation: The shortest distance between every pair is already given(if it exists).

Input: mat = [[0, 1, 43],[1, 0, 6], [-1, -1, 0]]
Output: [[0, 1, 7], [1, 0, 6], [-1, -1, 0]]
Explanation: We can reach 2 from 0 as 0->1->2 and the cost will be 1+6=7 which is less than 
43.

Constraints:
1 <= mat.size() <= 100
-1 <= mat[ i ][ j ] <= 1000

*/

#include <iostream>
#include <queue>
#include <cstring>
#include <vector>

using namespace std;

// User function template for C++
class Solution {
    public:
        void shortestDistance(vector<vector<int>>& mat) {
            int n = mat.size();

            for(int i=0; i<n; i++){
                for(int j=0; j<n; j++){
                    if(mat[i][j] == -1){
                        mat[i][j] = INT_MAX;
                    }
                }
            }

            for(int k=0; k<n; k++){
                for(int i=0; i<n; i++){
                    for(int j=0; j<n; j++){
                        if(mat[i][k] != INT_MAX && mat[k][j] != INT_MAX && 
                        mat[i][k] + mat[k][j] < mat[i][j]){
                            mat[i][j] = mat[i][k] + mat[k][j];
                        }
                    }
                }
            }

            for(int i=0; i<n; i++){
                for(int j=0; j<n; j++){
                    if(mat[i][j] == INT_MAX){
                        mat[i][j] = -1;
                    }
                }
            }
        }    
};


// Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n;
        cin >> n;
        vector<vector<int>> matrix(n, vector<int>(n, -1));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> matrix[i][j];
            }
        }

        Solution obj;
        obj.shortestDistance(matrix);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cout << matrix[i][j] << " ";
            }
            cout << "\n";
        }

        cout << "~\n";
    }
    return 0;
}
// Driver Code Ends.