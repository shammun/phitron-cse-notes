#include <iostream>
#include <vector>
#include <algorithm>    
#include <string>
#include <stack>

using namespace std;

int main(){
    int n, e;
    cin >> n >> e; // n = number of vertices, e = number of edges
    vector<pair<int, int>> edge_list;

    while(e--){
        int a,b;
        cin >> a >> b;
        edge_list.push_back({a, b});
    }

    for(pair<int, int> p : edge_list){
        cout << p.first << " <- " << p.second << endl;
    }

    /*
    
    // Instead we can also write the above loop as:

    for(auto p : edge_list){
        cout << p.first << " <- " << p.second << endl;
    }

    */

    return 0;
}