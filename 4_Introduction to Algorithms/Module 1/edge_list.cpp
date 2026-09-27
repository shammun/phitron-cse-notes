// The simplest way to store a graph: the edge list.
//
// No table, no per-node lists: just every edge, written down as the pair (a, b)
// in the order it was read. It is small (one pair per edge) and it is exactly the
// shape wanted by algorithms that sweep over all edges again and again, such as
// Bellman-Ford later in the course. Its weakness: to find the neighbours of one
// node you must read the whole list.
//
// Example input (4 nodes, 3 edges):      Output:
//   4 3                                  0 <- 1
//   0 1                                  1 <- 2
//   1 2                                  2 <- 3
//   2 3

#include <iostream>     // cin (read from keyboard/input) and cout (print to screen)
#include <vector>       // vector: an array that can grow with push_back
#include <algorithm>    // sort, max, min ... (not used here; kept from the course template)
#include <string>       // std::string (not used here; template line)
#include <stack>        // std::stack (not used here; template line)

// Every standard name (cin, cout, vector, pair, endl) lives inside the "std"
// namespace. This line lets us write cout instead of std::cout.
using namespace std;

// Program starts here. main returns an int: 0 tells the system "finished fine".
int main(){
    int n, e;          // n = how many vertices (nodes), e = how many edges
    // cin >> skips any spaces/newlines, then reads a number into n, then into e.
    cin >> n >> e; // n = number of vertices, e = number of edges
    // Note: n is read but never needed below. An edge list does not need to
    // know the node count, it only stores pairs. (A matrix or list would.)

    // One growable list of pairs. p.first is one end of an edge, p.second the other.
    // pair<int, int> is a tiny struct holding two ints, named .first and .second.
    // vector<pair<int,int>> is therefore "a growable array of such pairs".
    // It starts empty (size 0).
    vector<pair<int, int>> edge_list;

    // Read the e edges. while(e--) checks e (is it non-zero?) and THEN lowers it
    // by one, so the body runs exactly e times: with e = 3 it runs for e = 3, 2, 1
    // and stops when it sees 0. (After the loop e is -1, so e is used up.)
    while(e--){
        int a,b;                       // the two ends of this one edge
        cin >> a >> b;                 // read them, e.g. "0 1" -> a = 0, b = 1
        edge_list.push_back({a, b});   // {a, b} builds the pair in place
        // push_back adds the pair at the END of the vector, so the size grows by 1
        // and the edges stay in the order they were typed.
    }

    // Walk the list and print each edge. The "<-" is only decoration: the pair
    // is simply the edge (a, b), in the order it was typed.
    // Range-for: "for each element p in edge_list, in order". p is a COPY of the
    // current pair, which is fine for reading.
    for(pair<int, int> p : edge_list){
        // p.first = a, p.second = b. endl prints a newline and flushes the output.
        cout << p.first << " <- " << p.second << endl;
    }

    /*
    
    // Instead we can also write the above loop as:
    // (auto lets the compiler work out the type of p: here pair<int, int>.
    //  The loop is commented out so the edges are not printed twice.)

    for(auto p : edge_list){
        cout << p.first << " <- " << p.second << endl;
    }

    */

    return 0;          // 0 = the program ended normally
}
