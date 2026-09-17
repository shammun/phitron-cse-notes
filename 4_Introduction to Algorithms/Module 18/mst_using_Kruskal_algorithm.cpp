#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int par[1005];
int group_size[1005];

class Edge{
    public:
        int a, b, c;
        Edge(int a, int b, int c){
            this->a = a;
            this->b = b;
            this->c = c;
        }
};

bool cmp(Edge l, Edge r){
    return l.c < r.c;
}

int find(int node){
    if(par[node] == -1){
        return node;
    }
    int leader = find(par[node]);
    par[node] = leader;
    return leader;
}

int dsu_union(int node1, int node2){
    int leader1 = find(node1);
    int leader2 = find(node2);

    if(group_size[leader1] >= group_size[leader2]){
        par[leader2] = leader1;
        group_size[leader1] += group_size[leader2];
    } else{
        par[leader1] = leader2;
        group_size[leader2] += group_size[leader1];
    }
}

int main(){
    memset(par, -1, sizeof(par));
    memset(group_size, 1, sizeof(group_size));

    int n, e;
    cin >> n >> e;
    vector<Edge> edge_list;

    while(e--){
        int a, b, c;
        cin >> a >> b >> c;
        edge_list.push_back(Edge(a, b, c));
    }

    sort(edge_list.begin(), edge_list.end(), cmp);

    /*
    for(auto edge : edge_list){
        cout << edge.a << " " << edge.b << " " << edge.c << endl;
    }
    */
    
    int total_cost = 0;

    // Check if the edges are connected or not
    for(auto edge : edge_list){
        int parA = find(edge.a);
        int parB = find(edge.b);
        if(parA != parB){
            dsu_union(edge.a, edge.b);
            total_cost += edge.c;
        }
    }

    cout << total_cost << endl;

    return 0;
}
