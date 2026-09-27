/*

https://leetcode.com/problems/pascals-triangle/description/

118. Pascal's Triangle

Given an integer numRows, return the first numRows of Pascal's triangle.

In Pascal's triangle, each number is the sum of the two numbers directly above it as shown:

Example 1:

Input: numRows = 5
Output: [[1],[1,1],[1,2,1],[1,3,3,1],[1,4,6,4,1]]
Example 2:

Input: numRows = 1
Output: [[1]]
 

Constraints:

1 <= numRows <= 30

*/

// Solution idea (bottom-up DP, building each row from the one above).
// Every row starts and ends with 1. Each inside number is the sum of the two
// numbers just above it: row[j] = previous[j-1] + previous[j].
// The finished rows are the table, and each new row reads only the last one.

#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>

using namespace std;


class Solution {
    public:
        vector<vector<int>> generate(int numRows) {
            vector<vector<int>> result;   // result[i] = row i of the triangle

            for(int i=0; i<numRows; i++){
                // Row i has i+1 numbers. Start them all at 1: that already
                // makes both ends right, and rows 0 and 1 are then finished.
                vector<int> row(i+1, 1);

                // Fill the inside positions 1..i-1 from the row above.
                for(int j=1; j<i; j++){
                    row[j] = result[i-1][j-1] + result[i-1][j];
                }
                result.push_back(row);
            }
            return result;
            // Cost: O(numRows^2), one step per number in the triangle.
        }
    };

    // The file's own test: build 5 rows and print one row per line.
    int main() {
        Solution sol;
        int numRows = 5;

        auto triangle = sol.generate(numRows);

        // Print the result
        for (const auto& row : triangle) {
            for (int num : row) {
                cout << num << " ";
            }
            cout << endl;
        }

        return 0;
    }
