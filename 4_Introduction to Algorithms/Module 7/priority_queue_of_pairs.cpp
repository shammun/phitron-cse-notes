#include <iostream>
#include <vector>
#include <algorithm>    
#include <string>
#include <stack>
#include <queue>
using namespace std;

vector<pair<int, int>> adj_list[105];
int dis[105];

int main(){
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({10, 2});
    pq.push({5, 3});
    pq.push({1, 4});
    pq.push({3, 5});

    cout << pq.top().first << " " << pq.top().second << endl;

    return 0;
}