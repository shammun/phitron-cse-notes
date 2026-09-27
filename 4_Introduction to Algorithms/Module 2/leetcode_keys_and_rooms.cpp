
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
//
// Example 1 traced: queue {0} -> room 0 gives key 1 -> queue {1} -> key 2 ->
// queue {2} -> key 3 -> queue {3} -> no keys -> queue {} ; vis[0..3] all true -> true.
//
// Note: on LeetCode there are no #include lines. The judge already includes the
// standard headers (vector, queue, cstring, ...) and "using namespace std" for us,
// so the class below can use vector, queue and memset directly.

// LeetCode asks for a class named Solution with a method canVisitAllRooms.
class Solution {
public:   // members below can be used from outside the class (the judge calls them)
    bool vis[1005];   // vis[r] = has room r been reached (n is at most 1000)

    // Plain BFS from src, with rooms[par] playing the part of adj_list[par].
    // Parameters: src = starting room; rooms = the key lists. The "&" means
    // rooms is passed by reference: no copy of the big 2D vector is made.
    // vector<vector<int>> is a vector whose elements are vectors: a 2D list.
    void bfs(int src, vector<vector<int>>& rooms){
        queue<int> q;      // rooms we can open but have not walked into yet (FIFO line)
        q.push(src);       // start with room src waiting
        vis[src] = true;   // mark it at once so it is never queued twice

        // One pass = walk into one room and collect its keys. Stops when no
        // unlocked-but-unexplored room is left.
        while(!q.empty()){
            int par = q.front();   // the room we are standing in
            q.pop();               // remove it from the line

            // Every key found here opens one room: that room is a "child".
            // Range-for: key takes each number in rooms[par] in turn.
            for(int key : rooms[par]){
                if(!vis[key]){           // a room we have not opened before
                    q.push(key);         // go into it later
                    vis[key] = true;   // mark when pushed, as always
                }
            }
        }
    }

    // Returns true if every room can be visited, false otherwise.
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        // vis is a class member, not a global, so it is NOT zeroed for us:
        // clear it before the search.
        // memset(array, value, bytes) fills every byte; sizeof(vis) = bytes in vis.
        memset(vis, false, sizeof(vis));
        bfs(0, rooms);          // room 0 is the only one open at the start

        // Any room still unvisited was never unlocked.
        // rooms.size() = n, the number of rooms; i walks rooms 0..n-1.
        for(int i=0; i<rooms.size(); i++){
            if(!vis[i]) return false;   // found a room we could never enter
        }

        return true;            // Cost: O(n + total number of keys)
    }
};   // a class definition must end with a semicolon
