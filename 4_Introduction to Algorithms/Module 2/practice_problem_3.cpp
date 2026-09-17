/*

You will be given an undirected graph as input. Then you will be given a node N. You 
need to print the number of nodes that are directly connected to the node N.

Sample Input
6 5
0 1
0 2
0 3
2 3
4 5
2

Sample Output
2

Sample Input
6 5
0 1
0 2
0 3
2 3
4 5
0

Sample Output
3

Sample Input
7 7
0 1
1 2
2 3
1 3
4 0
0 5
5 6
1

Sample Output
3

*/

#include <iostream>
#include <vector>
#include <algorithm>    
#include <string>
#include <stack>
#include <queue>

using namespace std;

vector<int> adj_list[1005];

int main(){
    int n, e;
    cin >> n >> e;

    while(e--){
        int a, b;
        cin >> a >> b;
        adj_list[a].push_back(b);
        adj_list[b].push_back(a);
    }

    int node;
    cin >> node;

    cout << adj_list[node].size() << endl;

    return 0;
}