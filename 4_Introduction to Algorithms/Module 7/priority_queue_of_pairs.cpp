// A small warm-up before Dijkstra: a min-heap that holds pairs.
//
// An ordinary queue hands things back in the order they arrived. A priority_queue
// hands back the biggest one first, whatever order it arrived in. Dijkstra needs
// the opposite, the SMALLEST first, and it needs each item to carry two numbers,
// a distance and a node. This file checks both of those in six lines.
//
// Output of this program:
//     1 4
// ({1, 4} is the pair with the smallest .first among {10,2}, {5,3}, {1,4}, {3,5}.)

#include <iostream>     // cout, for printing
#include <vector>       // vector: the container the heap is built on
#include <algorithm>    // not needed here, left from a template
#include <string>       // not needed here, left from a template
#include <stack>        // not needed here, left from a template
#include <queue>        // priority_queue is declared in <queue>
using namespace std;    // so we can write priority_queue instead of std::priority_queue

// Left over from the Dijkstra files this one was copied from; nothing here uses
// them. Harmless, but do not go looking for a graph in this program.
vector<pair<int, int>> adj_list[105];
int dis[105];

int main(){
    // Read the three template arguments as: what is stored, where it is stored,
    // and how two items are compared.
    //   pair<int,int>                 one item
    //   vector<pair<int,int>>         the container underneath
    //   greater<pair<int,int>>        compare with >, which flips the heap round
    // Without that third argument the default is less<>, and the LARGEST item
    // comes out on top. With greater<> the smallest does, which is what we want.
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({10, 2});   // {a, b} builds a pair; push puts it in the heap
    pq.push({5, 3});
    pq.push({1, 4});    // smallest .first so far: this one will be on top
    pq.push({3, 5});

    // Two pairs are compared on .first, and only if those tie on .second. So the
    // order here is decided entirely by 10, 5, 1, 3 and the second numbers just
    // come along for the ride. That is the whole reason Dijkstra stores its pairs
    // as {distance, node} and not the more natural-looking {node, distance}: it
    // wants the heap to sort by distance.
    //
    // top() only looks at the smallest item; pop() would remove it. Pushing and
    // popping each cost O(log n), and top() is free.
    // If we kept popping, the pairs would come out as {1,4}, {3,5}, {5,3}, {10,2}.
    cout << pq.top().first << " " << pq.top().second << endl;   // prints "1 4"

    return 0;   // program finished normally
}
