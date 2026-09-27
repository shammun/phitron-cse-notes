/*

https://leetcode.com/problems/network-delay-time/description/

743. Network Delay Time

You are given a network of n nodes, labeled from 1 to n. You are also given times, a 
list of travel times as directed edges times[i] = (ui, vi, wi), where ui is the source 
node, vi is the target node, and wi is the time it takes for a signal to travel from 
source to target.

We will send a signal from a given node k. Return the minimum time it takes for all the 
n nodes to receive the signal. If it is impossible for all the n nodes to receive the 
signal, return -1.

*/

// Network Delay Time is Dijkstra from node k, plus one question at the end.
// Each node hears the signal the moment the shortest route to it finishes, and
// the signal spreads along all routes at once. So the time until EVERY node has
// it is the LARGEST shortest distance. If some node is never reached: -1.

class Solution {
    public:
        // Nodes are numbered 1..n (n <= 100), so size 105 leaves room for index n.
        vector<pair<int, int>> adj_list[105];   // adj_list[a] = {b, time} edges out of a
        int dis[105];                            // dis[x] = fastest time from k to x

        void dijkstra(int src, int n){
            priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

            // Start every node at "unreached". A loop, not memset, because
            // INT_MAX is not a value memset can write byte by byte.
            for(int i=1; i<=n; i++){
                dis[i] = INT_MAX;
            }

            pq.push({0, src});   // {time, node}
            dis[src] = 0;

            while(!pq.empty()){
                pair<int, int> par = pq.top();   // the earliest node to hear the signal
                pq.pop();

                int par_node = par.second;
                int par_dist = par.first;

                for(auto child : adj_list[par_node]){
                    int child_node = child.first;
                    int child_dist = child.second;

                    // Relax the edge par_node -> child_node.
                    if(par_dist + child_dist < dis[child_node]){
                        dis[child_node] = par_dist + child_dist;
                        pq.push({dis[child_node], child_node});
                    }
                }
            }
        }

        int networkDelayTime(vector<vector<int>>& times, int n, int k) {
            // Each entry of times is {from, to, time}. The edges are DIRECTED:
            // a signal sent from a to b cannot travel back, so push only one way.
            for(auto v: times){
                int a = v[0];
                int b = v[1];
                int c = v[2];
                adj_list[a].push_back({b, c});
            }

            dijkstra(k, n);

            // The slowest node decides the answer; an unreached node makes it -1.
            int max_time = 0;
            for(int i=1; i<=n; i++){
                if(dis[i] == INT_MAX) return -1;
                max_time = max(max_time, dis[i]);
            }

            return max_time;   // O((V + E) log V)
        }
    };
