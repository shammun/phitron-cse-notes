/*

https://www.geeksforgeeks.org/problems/implementing-dijkstra-set-1-adjacency-matrix/1?utm_source=geeksforgeeks&utm_medium=article_practice_tab&utm_campaign=article_practice_tab

Given a weighted, undirected and connected graph where you have given adjacency list adj. You 
have to find the shortest distance of all the vertices from the source vertex src, and return a 
list of integers denoting the shortest distance between each node and source vertex src.

Note: The Graph doesn't contain any negative weight edge.

*/

// dijkstra_optimized.cpp in the shape GFG asks for. The judge builds the graph
// for us (adj[u] holds {v, weight} pairs) and wants the distance list back
// instead of printed, so the function owns its own dist vector and returns it.
// There is no main and no #include here: on GFG they live in the hidden driver.

vector<int> dijkstra(vector<vector<pair<int, int>>>& adj, int src) {
    int n = adj.size();                 // number of vertices
    vector<int> dist(n, INT_MAX);       // INT_MAX = "no route found yet"

    // Min-heap of {distance, node}: the closest waiting node is always on top.
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, src});
    dist[src] = 0;                      // the source is 0 away from itself

    while(!pq.empty()){
        pair<int, int> par = pq.top();  // closest node not yet expanded
        pq.pop();
        int par_node = par.second;
        int par_dist = par.first;

        // Here adj[par_node] holds {neighbour, weight}: node first, weight
        // second (the opposite order to the heap's pairs).
        for(auto child : adj[par_node]){
            int child_node = child.first;
            int child_dist = child.second;   // the weight of this edge

            // Relax: is going through par_node better than the best route so far?
            if(child_dist + par_dist < dist[child_node]){
                dist[child_node] = par_dist + child_dist;
                pq.push({dist[child_node], child_node});   // offer the new, better distance
            }
        }
    }

    return dist;   // O((V + E) log V)
}
