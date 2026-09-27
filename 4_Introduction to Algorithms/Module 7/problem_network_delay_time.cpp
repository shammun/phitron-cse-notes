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
//
// Example: times = [[2,1,1],[2,3,1],[3,4,1]], n = 4, k = 2.
//   dis[2]=0, dis[1]=1, dis[3]=1, dis[4]=2  -> answer max = 2.
//
// No #include or main: LeetCode's hidden driver provides them and calls
// networkDelayTime.

class Solution {        // LeetCode wants the answer inside class Solution
    public:             // public: the driver may call these members
        // Nodes are numbered 1..n (n <= 100), so size 105 leaves room for index n.
        // These are member variables: a fresh Solution object is made for each
        // test, so adj_list starts empty every time.
        vector<pair<int, int>> adj_list[105];   // adj_list[a] = {b, time} edges out of a
        int dis[105];                            // dis[x] = fastest time from k to x

        // dijkstra(src, n): fill dis[1..n] with the fastest arrival times from src.
        void dijkstra(int src, int n){
            // Min-heap of {time, node}. The default priority_queue is a max-heap;
            // greater<pair<int,int>> makes the SMALLEST pair come out on top.
            priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

            // Start every node at "unreached". A loop, not memset, because
            // INT_MAX is not a value memset can write byte by byte.
            for(int i=1; i<=n; i++){
                dis[i] = INT_MAX;
            }

            pq.push({0, src});   // {time, node}
            dis[src] = 0;        // the signal starts at src at time 0

            // One pass = take the node that heard the signal earliest (among the
            // waiting ones) and pass the signal along each of its edges.
            while(!pq.empty()){
                pair<int, int> par = pq.top();   // the earliest node to hear the signal
                pq.pop();                        // remove it from the heap

                int par_node = par.second;       // heap pairs are {time, node}
                int par_dist = par.first;

                // Each outgoing edge: {neighbour, travel time}.
                for(auto child : adj_list[par_node]){
                    int child_node = child.first;
                    int child_dist = child.second;

                    // Relax the edge par_node -> child_node.
                    // If arriving via par_node is earlier, record it and push.
                    if(par_dist + child_dist < dis[child_node]){
                        dis[child_node] = par_dist + child_dist;
                        pq.push({dis[child_node], child_node});
                    }
                }
            }
        }

        // The function LeetCode calls. times is passed by reference (&) so the
        // big list is not copied.
        int networkDelayTime(vector<vector<int>>& times, int n, int k) {
            // Each entry of times is {from, to, time}. The edges are DIRECTED:
            // a signal sent from a to b cannot travel back, so push only one way.
            for(auto v: times){        // v is one edge, a vector of 3 ints
                int a = v[0];          // from
                int b = v[1];          // to
                int c = v[2];          // travel time
                adj_list[a].push_back({b, c});
            }

            dijkstra(k, n);            // fastest arrival time at every node from k

            // The slowest node decides the answer; an unreached node makes it -1.
            int max_time = 0;
            for(int i=1; i<=n; i++){
                if(dis[i] == INT_MAX) return -1;       // still "infinity": never reached
                max_time = max(max_time, dis[i]);      // max() returns the larger of the two
            }

            return max_time;   // O((V + E) log V)
        }
    };
