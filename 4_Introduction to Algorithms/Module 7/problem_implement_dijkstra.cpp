/*

https://www.geeksforgeeks.org/problems/implementing-dijkstra-set-1-adjacency-matrix/1?utm_source=geeksforgeeks&utm_medium=article_practice_tab&utm_campaign=article_practice_tab

Given a weighted, undirected and connected graph where you have given adjacency list adj. You 
have to find the shortest distance of all the vertices from the source vertex src, and return a 
list of integers denoting the shortest distance between each node and source vertex src.

Note: The Graph doesn't contain any negative weight edge.

*/

vector<int> dijkstra(vector<vector<pair<int, int>>>& adj, int src) {
    int n = adj.size();
    vector<int> dist(n, INT_MAX);

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, src});
    dist[src] = 0;

    while(!pq.empty()){
        pair<int, int> par = pq.top();
        pq.pop();
        int par_node = par.second;
        int par_dist = par.first;

        for(auto child : adj[par_node]){
            int child_node = child.first;
            int child_dist = child.second;

            if(child_dist + par_dist < dist[child_node]){
                dist[child_node] = par_dist + child_dist;
                pq.push({dist[child_node], child_node});
            }
        }
    }

    return dist;
}