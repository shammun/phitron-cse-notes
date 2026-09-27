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

// Practice Day problem 2: floyd-warshall.cpp applied to the matrix the judge
// hands over. The only twist is the judge's "no edge" mark, which is -1.
// Floyd-Warshall would read -1 as a real (negative!) edge, so we translate
// -1 into our own infinity first, run the triple loop, and translate back.

#include <iostream>     // cin, cout
#include <queue>        // not used here
#include <cstring>      // not used here
#include <vector>       // vector - the matrix
#include <climits>      // INT_MAX

using namespace std;    // no std:: prefix needed

// User function template for C++
class Solution {
    public:   // callable from main (the judge's code)
        // mat is changed in place (it arrives by reference); nothing is returned.
        // The & in vector<vector<int>>& means "work on the caller's matrix
        // itself", so changes made here are seen by main afterwards.
        void shortestDistance(vector<vector<int>>& mat) {
            int n = mat.size();   // number of vertices = number of rows

            // Step 1: "no edge" -1 becomes INT_MAX, meaning "no route known".
            for(int i=0; i<n; i++){
                for(int j=0; j<n; j++){
                    if(mat[i][j] == -1){
                        mat[i][j] = INT_MAX;
                    }
                }
            }

            // Step 2: Floyd-Warshall. Round k allows node k as a stop in the
            // middle: is going i -> k -> j cheaper than the best i -> j so far?
            // k is outermost so that when round k runs, every route that only
            // uses stops 0..k-1 is already the best possible.
            for(int k=0; k<n; k++){
                for(int i=0; i<n; i++){
                    for(int j=0; j<n; j++){
                        // Both halves must exist; INT_MAX + something would
                        // overflow into a negative number.
                        // Example 2: k=1, i=0, j=2: mat[0][1]+mat[1][2] = 1+6 = 7
                        // < 43, so mat[0][2] becomes 7.
                        if(mat[i][k] != INT_MAX && mat[k][j] != INT_MAX &&
                        mat[i][k] + mat[k][j] < mat[i][j]){
                            mat[i][j] = mat[i][k] + mat[k][j];
                        }
                    }
                }
            }

            // Step 3: pairs still without a route go back to the judge's -1.
            for(int i=0; i<n; i++){
                for(int j=0; j<n; j++){
                    if(mat[i][j] == INT_MAX){
                        mat[i][j] = -1;
                    }
                }
            }
            // O(n^3) time, no extra memory.
        }
};


// Driver Code Starts.
// The judge's own harness: tc test cases, each an n x n matrix; it prints the
// matrix after the call and a "~" line after each case.
int main() {
    int tc;                 // number of test cases
    cin >> tc;
    while (tc--) {          // runs tc times
        int n;              // matrix size
        cin >> n;
        // n x n matrix, every cell -1 until it is read.
        vector<vector<int>> matrix(n, vector<int>(n, -1));
        for (int i = 0; i < n; i++) {          // read row i
            for (int j = 0; j < n; j++) {      // column j
                cin >> matrix[i][j];
            }
        }

        Solution obj;                       // object to call the method on
        obj.shortestDistance(matrix);       // changes matrix in place
        for (int i = 0; i < n; i++) {       // print the result row by row
            for (int j = 0; j < n; j++) {
                cout << matrix[i][j] << " ";
            }
            cout << "\n";                   // end of row ("\n" does not flush)
        }

        cout << "~\n";                      // the judge's separator line
    }
    return 0;                               // success
}
// Driver Code Ends.
