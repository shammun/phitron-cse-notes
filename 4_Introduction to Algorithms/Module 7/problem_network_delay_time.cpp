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

class Solution {
    public:
        vector<pair<int, int>> adj_list[105];
        int dis[105];
    
        void dijkstra(int src, int n){
            priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    
            for(int i=1; i<=n; i++){
                dis[i] = INT_MAX;
            }
    
            pq.push({0, src});
            dis[src] = 0;
    
            while(!pq.empty()){
                pair<int, int> par = pq.top();
                pq.pop();
    
                int par_node = par.second;
                int par_dist = par.first;
    
                for(auto child : adj_list[par_node]){
                    int child_node = child.first;
                    int child_dist = child.second;
    
                    if(par_dist + child_dist < dis[child_node]){
                        dis[child_node] = par_dist + child_dist;
                        pq.push({dis[child_node], child_node});
                    }
                }
            }
        }
    
        int networkDelayTime(vector<vector<int>>& times, int n, int k) {
            for(auto v: times){
                int a = v[0];
                int b = v[1];
                int c = v[2];
                adj_list[a].push_back({b, c});
            }
    
            dijkstra(k, n);
    
            int max_time = 0;
            for(int i=1; i<=n; i++){
                if(dis[i] == INT_MAX) return -1;
                max_time = max(max_time, dis[i]);
            }
    
            return max_time;
        }
    };