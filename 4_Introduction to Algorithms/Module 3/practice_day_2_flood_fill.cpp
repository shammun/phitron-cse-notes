/*

https://leetcode.com/problems/flood-fill/description/

733. Flood Fill

You are given an image represented by an m x n grid of integers image, where image[i][j] represents 
the pixel value of the image. You are also given three integers sr, sc, and color. Your task is to 
perform a flood fill on the image starting from the pixel image[sr][sc].

To perform a flood fill:

1. Begin with the starting pixel and change its color to color.
2. Perform the same process for each pixel that is directly adjacent (pixels that share a side with the 
original pixel, either horizontally or vertically) and shares the same color as the starting pixel.
3. Keep repeating this process by checking neighboring pixels of the updated pixels and modifying their 
color if it matches the original color of the starting pixel.
4. The process stops when there are no more adjacent pixels of the original color to update.
Return the modified image after performing the flood fill.

 

Example 1:

Input: image = [[1,1,1],[1,1,0],[1,0,1]], sr = 1, sc = 1, color = 2

Output: [[2,2,2],[2,2,0],[2,0,1]]

From the center of the image with position (sr, sc) = (1, 1) (i.e., the red pixel), all pixels 
connected by a path of the same color as the starting pixel (i.e., the blue pixels) are colored with 
the new color.

Note the bottom corner is not colored 2, because it is not horizontally or vertically connected to 
the starting pixel.

Example 2:

Input: image = [[0,0,0],[0,0,0]], sr = 0, sc = 0, color = 0

Output: [[0,0,0],[0,0,0]]

Explanation:

The starting pixel is already colored with 0, which is the same as the target color. Therefore, no 
changes are made to the image.

Constraints:

m == image.length
n == image[i].length
1 <= m, n <= 50
0 <= image[i][j], color < 2^16
0 <= sr < m
0 <= sc < n

*/

// Idea: the picture is a grid, each pixel a node, and its neighbours are the 4
// pixels sharing a side (DFS on a 2D grid, as in dfs_on_2d_grid.cpp). Start a
// DFS at (sr, sc) and repaint every pixel it can reach through pixels of the
// ORIGINAL colour. No vis array is needed: once a pixel is repainted it no
// longer has the original colour, so the colour test itself stops a revisit.
//
// Trace on Example 1 (origColor 1, newColor 2), start (1,1):
//   paint (1,1); right (1,2) is 0 -> skip; left (1,0) is 1 -> paint, go deep:
//   from (1,0): up (0,0) is 1 -> paint; from (0,0): right (0,1) -> paint;
//   from (0,1): right (0,2) -> paint ... The corner (2,2) touches only 0-pixels,
//   so it is never reached and stays 1.
//
// LeetCode style: there is no main() and no #include lines. LeetCode's own
// judge includes the standard headers (vector, etc.), adds "using namespace std",
// creates a Solution object and calls floodFill() with its test data. So this
// file does not compile on its own; it is meant to be pasted into LeetCode.

// A class groups data and functions. LeetCode requires the answer to be the
// member function floodFill of a class named Solution.
class Solution {
public:     // members below can be used from outside the class (LeetCode calls them)
    // The 4 moves: right, left, up, down, as {row change, column change}.
    // vector<pair<int,int>>: a list of int pairs; .first = row change, .second = column change.
    vector<pair<int, int>> direction = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};

    // Is (i, j) inside an n x m picture?
    // n = number of rows, m = number of columns (passed in, since there are no globals).
    bool valid(int i, int j, int n, int m){
        if(i < 0 || i >= n || j < 0 || j >= m){   // row or column out of range
            return false;                         // not a pixel of the picture
        }
        return true;                              // a real pixel
    }

    // Repaint (row, col) and, recursively, every connected pixel of origColor.
    // image is passed by reference (&), so the changes are made to the caller's
    // picture itself, not to a copy. vector<vector<int>> is a 2D table: a vector
    // of rows, each row a vector of ints.
    // Base case: when no neighbour is inside and still origColor, the loop does
    // nothing and the call returns.
    void dfs(vector<vector<int>>& image, int row, int col, int origColor, int newColor){
        image[row][col] =  newColor;    // paint first: this doubles as "visited"

        // Try each of the 4 sides.
        for(int i = 0; i < 4; i++){
            int newRow = row + direction[i].first;    // neighbour's row
            int newCol = col + direction[i].second;   // neighbour's column

            // Only step onto pixels inside the picture that still carry the
            // original colour; valid() is checked first so image[][] is never
            // read out of range. image.size() = number of rows, image[0].size() =
            // number of columns (length of the first row). && stops at the first
            // false, so image[newRow][newCol] is only read for an inside pixel.
            if(valid(newRow, newCol, image.size(), image[0].size()) && image[newRow][newCol] == origColor){
                dfs(image, newRow, newCol, origColor, newColor);   // go deep from that pixel
            }
        }
    }

    // The function LeetCode calls. Parameters: the picture, the start pixel
    // (sr = start row, sc = start column) and the new colour. Returns the picture.
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        // If the start pixel already has the new colour there is nothing to do.
        // This check matters: with origColor == newColor a painted pixel would
        // still "match", and the DFS would bounce between pixels forever.
        if(image[sr][sc] != color){
            // image[sr][sc] is read BEFORE any painting, so it is the original colour.
            dfs(image, sr, sc, image[sr][sc], color);
        }
        return image;     // Cost: O(n * m), each pixel painted at most once
    }
};
