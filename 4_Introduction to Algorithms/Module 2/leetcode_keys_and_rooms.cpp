
/*

https://leetcode.com/problems/keys-and-rooms/description/

841. Keys and Rooms

There are n rooms labeled from 0 to n - 1 and all the rooms are locked except for room 0. Your goal is to visit all the rooms. However, you cannot enter a locked room without having its key.

When you visit a room, you may find a set of distinct keys in it. Each key has a number on it, denoting which room it unlocks, and you can take all of them with you to unlock the other rooms.

Given an array rooms where rooms[i] is the set of keys that you can obtain if you visited room i, return true if you can visit all the rooms, or false otherwise.

 

Example 1:

Input: rooms = [[1],[2],[3],[]]
Output: true
Explanation: 
We visit room 0 and pick up key 1.
We then visit room 1 and pick up key 2.
We then visit room 2 and pick up key 3.
We then visit room 3.
Since we were able to visit every room, we return true.
Example 2:

Input: rooms = [[1,3],[3,0,1],[2],[0]]
Output: false
Explanation: We can not enter room number 2 since the only key that unlocks it is in that room.
 

Constraints:

n == rooms.length
2 <= n <= 1000
0 <= rooms[i].length <= 1000
1 <= sum(rooms[i].length) <= 3000
0 <= rooms[i][j] < n
All the values of rooms[i] are unique.

*/

// Idea: this is a graph problem in disguise. Each room is a node, and a key for
// room b lying in room a is a one-way edge a -> b. rooms[a] is therefore already
// an adjacency list. "Can we visit every room?" becomes "does a BFS from room 0
// reach every node?", the reachability check of this module.
//
// Example 2: from room 0 we get keys 1 and 3, from those rooms keys 0, 1 and 3
// again. Nobody outside room 2 holds key 2, so room 2 is never visited -> false.

class Solution {
public:
    bool vis[1005];   // vis[r] = has room r been reached (n is at most 1000)

    // Plain BFS from src, with rooms[par] playing the part of adj_list[par].
    void bfs(int src, vector<vector<int>>& rooms){
        queue<int> q;
        q.push(src);
        vis[src] = true;

        while(!q.empty()){
            int par = q.front();   // the room we are standing in
            q.pop();

            // Every key found here opens one room: that room is a "child".
            for(int key : rooms[par]){
                if(!vis[key]){
                    q.push(key);
                    vis[key] = true;   // mark when pushed, as always
                }
            }
        }
    }

    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        // vis is a class member, not a global, so it is NOT zeroed for us:
        // clear it before the search.
        memset(vis, false, sizeof(vis));
        bfs(0, rooms);          // room 0 is the only one open at the start

        // Any room still unvisited was never unlocked.
        for(int i=0; i<rooms.size(); i++){
            if(!vis[i]) return false;
        }

        return true;            // Cost: O(n + total number of keys)
    }
};
