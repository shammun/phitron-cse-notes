
/*

https://www.geeksforgeeks.org/problems/disjoint-set-union-find/1?utm_source=geeksforgeeks&utm_medium=ml_article_practice_tab&utm_campaign=article_practice_tab
*/

// Practice Day problem 1. GFG supplies the driver (main) and wants us to write
// find() and unionSet(). One thing is different from this module's lessons:
// the judge starts every node as its OWN parent (a[i] = i), not -1. So here a
// leader is a node whose parent is itself, par[x] == x.
//
// Example: n = 5, commands "UNION 1 3", "FIND 3", "UNION 2 3", "FIND 1".
//   UNION 1 3 -> par[1] = 3          (leader of {1,3} is 3)
//   FIND 3    -> prints 3
//   UNION 2 3 -> par[2] = 3          ({1,2,3}, leader 3)
//   FIND 1    -> prints 3

#include <iostream>   // cin, cout, endl
#include <queue>      // not used here
#include <cstring>    // not used here
#include <vector>     // not used here
using namespace std;  // no std:: prefix

// Driver Code Starts
// #include <bits/stdc++.h>
// (commented out because the individual headers above are enough; <string>
// for the "string s" below comes in through <iostream> with g++)
using namespace std;  // repeated by the judge's template; harmless
// Declared here, written below: main can call them before their bodies appear.
// These are "prototypes": return type, name and parameter types only.
int find(int a[], int x);
void unionSet(int a[], int x, int z);

// The judge's harness: T tests. Each has n nodes and k commands, either
// "UNION x z" or "FIND x"; each FIND prints the leader of x.
int main() {
    int t;                            // number of test cases
    cin >> t;
    while (t--) {                     // one pass per test case
        int n;                        // number of nodes
        cin >> n;
        int a[n + 1];                 // the parent array, nodes 1..n
        // (a[n+1] is a variable length array: g++ allows it, standard C++ not)
        for (int i = 1; i <= n; i++)
            a[i] = i;                 // everyone starts as their own leader
        int k;                        // number of commands
        cin >> k;
        for (int i = 0; i < k; i++) { // handle command i
            string s;                 // "UNION" or "FIND"
            cin >> s;                 // cin >> reads one word (stops at space)
            if (s == "UNION") {       // == compares string contents
                int x, z;
                cin >> x >> z;
                unionSet(a, x, z);    // merge x's group with z's group
            } else {                  // a FIND command
                int x;
                cin >> x;
                int parent = find(a, x);     // leader of x's group
                cout << parent << " ";
            }
        }
        cout << endl;                 // end the line of FIND answers

        cout << ","                   // the judge's separator line
             << "\n";
    }
}
// Driver Code Ends
// (main has no "return 0;": in C++ main alone is allowed to omit it, and it
// then returns 0 automatically.)

/*Complete the functions below*/
// Return the leader of x's group, with path compression (find_optimized.cpp):
// on the way back up, every node on the path is pointed straight at the leader,
// so the next find on any of them takes a single step.
// "int par[]" as a parameter is really a pointer to the caller's array, so
// writing par[x] here changes main's array a.
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
    int leader1 = find(par, x);       // leader of x's group
    int leader2 = find(par, z);       // leader of z's group

    // Already in one group: nothing to do. Otherwise hang x's leader under z's
    // leader. No union by size here on purpose: the judge prints leaders, and
    // it expects x's group to join z's group exactly this way round.
    if(leader1 != leader2){
        par[leader1] = leader2;       // z's leader now leads both groups
    }
}
