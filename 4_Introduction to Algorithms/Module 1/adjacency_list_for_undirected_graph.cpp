#include <iostream>
#include <vector>
#include <algorithm>    
#include <string>
#include <stack>

using namespace std;

int main(){
    int n, e;
    cin >> n >> e; // n = number of vertices, e = number of edges
    vector<int> adj_list[n];

    while(e--){
        int a, b;
        cin >> a >> b;
        adj_list[a].push_back(b);
        adj_list[b].push_back(a); // directed graph will not have this line
    }

    for(int i=0; i<n; i++){
        cout << i << " -> ";
        for(int x : adj_list[i]){
            cout << x << " ";
        }
        cout << endl;
    }

    return 0;
}