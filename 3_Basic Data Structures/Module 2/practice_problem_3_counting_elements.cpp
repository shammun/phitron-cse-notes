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

#include <iostream>  // cin and cout
#include <vector>    // vector: a resizable array
#include <algorithm> // find()
#include <string>    // string type (not used here)
using namespace std; // lets us drop the std:: prefix

int main() { // the program starts running here
    int n; // number of elements
    cin >> n; // read n
    vector<int> a(n); // a vector with n slots, all 0 for now
    // Read the elements: pass i fills a[i].
    for(int i=0; i<n; i++){
        cin >> a[i]; // read one number into slot i
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
    // (An iterator is like a pointer to one slot of the vector; a.begin() is the
    // first slot and a.end() is the position just AFTER the last slot, so getting
    // a.end() back means "not found".)
    // With 4 4 5: for each 4, find(5) succeeds -> count 2; for 5, find(6)
    // fails. Answer 2. Duplicates are counted separately, as the task asks.
    int count2 = 0; // how many elements have their "+1 partner" in the array
    for(int i=0; i<n; i++){ // check every element a[i]
        if(find(a.begin(), a.end(), a[i] + 1) != a.end()){ // is a[i] + 1 anywhere in a?
            count2++;   // a[i] + 1 exists, so a[i] counts
        }
    }
    // find() still walks the vector, so this is also O(n^2); fine for n <= 1000.
    cout << count2 << endl; // print the answer; endl = new line + flush

    return 0; // program finished successfully
}
