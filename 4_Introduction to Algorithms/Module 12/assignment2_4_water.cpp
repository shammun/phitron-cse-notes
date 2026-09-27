/*

https://www.hackerrank.com/contests/assignment-02-a-introduction-to-algorithms-a-batch-06/challenges/water-4-1

Water

Problem Statement

You are given an array H representing the heights of N vertical lines positioned at equally spaced intervals 
along a two-dimensional plane. The i-th line's height is represented by the integer Hi where 0<=i<N and the 
height will be unique.

You need to find the two lines, such that together with the x-axis forms a container that can hold the most water 
in term of height.

Note: Print the left index first, then the right index.

Input Format
- First line will contain T, the number of test cases.
- First line of each test case will contain N.
- Second line of each test case will contain the array H.

Constraints
1. 1 <= T <= 10^3
2. 2 <= N <= 10^5
3. 0 <= H[i] <= 10^9

Output Format
Ouptut two integers, the index of those two lines that can contain the most water in term of height.

Sample Input 0
2
9
1 8 3 4 0 7 6 5 2
5
5 2 1 6 3

Sample Output 0
1 5
0 3

Explanation 0
In the first test case, you can choose index 1 and 5 that can hold the most water in height which is 7.



*/

// Solution idea: only height counts here, and a container is as tall as its
// SHORTER wall. So the best pair is simply the two tallest lines. One pass
// keeps the index of the tallest (max1) and of the second tallest (max2).
//
// Trace with 5 2 1 6 3: start max1=0 (5), max2=-1.
//   i=1 (2): not > 5; max2 empty -> max2=1
//   i=2 (1): not > 5, not > 2    -> no change
//   i=3 (6): > 5 -> max2=0, max1=3
//   i=4 (3): not > 6, not > 5    -> no change
// Answer: min(3,0)=0, max(3,0)=3 -> "0 3".

#include <iostream>     // cin, cout, endl
#include <vector>       // vector
#include <algorithm>    // min, max

using namespace std;    // no std:: prefix

// Returns {left index, right index} of the two tallest lines.
// "vector<int> &arr" passes the array by reference: no copy is made.
vector<int> area(vector<int> &arr, int n){
    int max1 = 0;    // start by assuming line 0 is the tallest
    int max2 = -1;   // -1 = no second-tallest chosen yet

    for(int i=1; i<n; i++){          // look at every other line once
        if(arr[i] > arr[max1]){
            // A new tallest: the old tallest slides down to second place.
            max2 = max1;
            max1 = i;
        } else if(max2 == -1 || arr[i] > arr[max2]){
            // Not the tallest, but beats the current second (or fills it).
            // (max2 == -1 is tested first, so arr[-1] is never read.)
            max2 = i;
        }
    }

    // The answer must list the left index first, whatever order we found them in.
    int leftIndex = min(max1, max2);
    int rightIndex = max(max1, max2);

    return {leftIndex, rightIndex};   // builds a 2-element vector
}

int main(){
    int t;                 // number of test cases
    cin >> t;

    while(t--){            // one pass per test case
        int n;             // number of lines
        cin >> n;

        vector<int> arr;   // the heights
        for(int i=0; i<n; i++){
            int x;
            cin >> x;
            arr.push_back(x);   // append at the end
        }

        vector<int> indices = area(arr, n);
        cout << indices[0] << " " << indices[1] << endl;   // left right
    }

    // Cost: O(N) per test case, one pass, no sorting.
    return 0;
}
