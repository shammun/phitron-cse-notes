
/*

https://www.geeksforgeeks.org/problems/disjoint-set-union-find/1?utm_source=geeksforgeeks&utm_medium=ml_article_practice_tab&utm_campaign=article_practice_tab
*/

// Practice Day problem 1. GFG supplies the driver (main) and wants us to write
// find() and unionSet(). One thing is different from this module's lessons:
// the judge starts every node as its OWN parent (a[i] = i), not -1. So here a
// leader is a node whose parent is itself, par[x] == x.

#include <iostream>
#include <queue>
#include <cstring>
#include <vector>
using namespace std;

// Driver Code Starts
// #include <bits/stdc++.h>
using namespace std;
// Declared here, written below: main can call them before their bodies appear.
int find(int a[], int x);
void unionSet(int a[], int x, int z);

// The judge's harness: T tests. Each has n nodes and k commands, either
// "UNION x z" or "FIND x"; each FIND prints the leader of x.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n + 1];                 // the parent array, nodes 1..n
        for (int i = 1; i <= n; i++)
            a[i] = i;                 // everyone starts as their own leader
        int k;
        cin >> k;
        for (int i = 0; i < k; i++) {
            string s;
            cin >> s;
            if (s == "UNION") {
                int x, z;
                cin >> x >> z;
                unionSet(a, x, z);
            } else {
                int x;
                cin >> x;
                int parent = find(a, x);
                cout << parent << " ";
            }
        }
        cout << endl;

        cout << ","
             << "\n";
    }
}
// Driver Code Ends

/*Complete the functions below*/
// Return the leader of x's group, with path compression (find_optimized.cpp):
// on the way back up, every node on the path is pointed straight at the leader,
// so the next find on any of them takes a single step.
int find(int par[], int x) {
    // add code here
    if(par[x] != x){                  // x is not a leader: ask its parent
        par[x] = find(par, par[x]);   // ...and remember the answer
    }
    return par[x];                    // for a leader, par[x] is x itself
}

// Join the groups of x and z.
void unionSet(int par[], int x, int z) {
    // add code here.
    int leader1 = find(par, x);
    int leader2 = find(par, z);

    // Already in one group: nothing to do. Otherwise hang x's leader under z's
    // leader. No union by size here on purpose: the judge prints leaders, and
    // it expects x's group to join z's group exactly this way round.
    if(leader1 != leader2){
        par[leader1] = leader2;
    }
}
