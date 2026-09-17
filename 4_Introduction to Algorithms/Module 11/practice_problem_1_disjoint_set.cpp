
/*

https://www.geeksforgeeks.org/problems/disjoint-set-union-find/1?utm_source=geeksforgeeks&utm_medium=ml_article_practice_tab&utm_campaign=article_practice_tab
*/

#include <iostream>
#include <queue>
#include <cstring>
#include <vector>
using namespace std;

// Driver Code Starts
// #include <bits/stdc++.h>
using namespace std;
int find(int a[], int x);
void unionSet(int a[], int x, int z);

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n + 1];
        for (int i = 1; i <= n; i++)
            a[i] = i;
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
int find(int par[], int x) {
    // add code here
    if(par[x] != x){
        par[x] = find(par, par[x]);
    }
    return par[x];
}

void unionSet(int par[], int x, int z) {
    // add code here.
    int leader1 = find(par, x);
    int leader2 = find(par, z);

    if(leader1 != leader2){
        par[leader1] = leader2;
    }
}