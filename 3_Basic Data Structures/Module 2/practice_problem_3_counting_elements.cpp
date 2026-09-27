/*

Counting Elements

time limit per test: 1 second
memory limit per test: 256 megabytes

You are given an array a of n integers, count the number of element ai in the array 
such that ai+1 is also exists in the array a.

If there're duplicates in a, count them separately.

Input
The first line contains an integer n(1≤n≤10^3) the number of elements in the array a

The second line contains n integers ai(0≤Xi≤10^3) the elements of the array a.

Output
output the number of elements as descriped above.

Examples
Input
3
4 4 5
Output
2

Input
3
1 2 3
Output
2

Input
8
1 1 3 3 5 5 7 7
Output
0

Input
6
1 3 2 3 5 0
Output
3

*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i=0; i<n; i++){
        cin >> a[i];
    }

    /*
    First try (kept for comparison): for every a[i], a second loop checks
    every a[j] to see whether it equals a[i] + 1. Two nested loops: O(n^2).
    It is also wrong with duplicates: it adds 1 for EVERY copy of a[i] + 1,
    so 4 5 5 would give 2 instead of 1.

    int count = 0;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(a[j] == a[i] + 1){
                count++;
            }
        }
    }

    cout << count << endl;
    */
    

    // Same idea with the built-in find() doing the inner search.
    // find(begin, end, x) returns an iterator to the first x it meets,
    // or a.end() when x is not in the vector at all.
    // With 4 4 5: for each 4, find(5) succeeds -> count 2; for 5, find(6)
    // fails. Answer 2. Duplicates are counted separately, as the task asks.
    int count2 = 0;
    for(int i=0; i<n; i++){
        if(find(a.begin(), a.end(), a[i] + 1) != a.end()){
            count2++;   // a[i] + 1 exists, so a[i] counts
        }
    }
    // find() still walks the vector, so this is also O(n^2); fine for n <= 1000.
    cout << count2 << endl;

    return 0;
}