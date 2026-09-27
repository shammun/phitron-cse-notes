/*

Give Current Min

Problem Statement

You will be given a list A of size N. Then you will be given Q queries, for each
query there will be some commands. Commands are given below -

1. 0 X -> Insert X into the list. Then print the current minimum value from the
list.
2. 1 -> Print the current minimum value from the list.
3. 2 -> Delete the current minimum value from the list and print the minimum value
from the list after deletion.

Note: If the list is empty and you can't print anything then you should print
"Empty".

Input Format

- First line will contain .
- Second line will contain the list  of size .
- Third line will contain .
- Next Q lines will contain the commands.

Constraints
1. 1 <= N + Q <= 10^5
2. -10^9 <= A[i] <= 10^9; Here A[i] means the values of the list.
3. -10^9 <= X <= 10^9

Output Format
- For each command, print as asked from the list.

Sample Input 0
4
10 -10 -5 -20
10
1
2
2
2
2
0 10
1
2
0 20
1

Sample Output 0
-20
-10
-5
10
Empty
10
10
Empty
20
20

Sample Input 1
6
45 -30 83 -99 19 75
9
1
2
2
0 32
0 6
2
2
0 -86
1

Sample Output 1
-99
-30
19
19
6
19
32
-86
-86

*/

#include <bits/stdc++.h>    // GCC shortcut: includes the whole standard library (queue, vector, string, ...)

using namespace std;        // write priority_queue, cout ... without std::



/*
 * Idea: keep the numbers in a min-heap (a priority_queue with greater<int>).
 * Its top() is always the current smallest value, whatever has been added
 * or removed, and push/pop cost only O(log n). No re-sorting is needed.
 *
 * The one trap: before every top() or pop() the heap may be empty, and the
 * question wants "Empty" printed then. A delete (command 2) must check twice:
 * before popping, and again before printing the new minimum.
 */
int main()
{
    int N;
    cin >> N;               // size of the starting list

    // greater<int> turns the default max-heap into a min-heap.
    // Template arguments: stored type, the container the heap lives in, the comparison.
    priority_queue<int, vector<int>, greater<int>> pq;

    // The starting list goes straight into the heap.
    for(int i=0; i<N; i++){
        int x;
        cin >> x;
        pq.push(x);         // O(log n)
    }

    int Q;
    cin >> Q;               // number of commands

    // while(Q--) runs the body Q times; one pass = one command.
    while(Q--){
        // x is the command number: 0, 1 or 2.
        int x;
        cin >> x;

        if(x == 0){
            // 0 X: insert X, then show the minimum. The heap cannot be empty
            // right after a push, so no check is needed.
            int val;
            cin >> val;
            pq.push(val);
            cout << pq.top() << endl;   // top() = the smallest value (endl = newline + flush)
        } else if(x == 1){
            // 1: just show the minimum (or Empty).
            if(pq.empty()){
                cout << "Empty" << endl;
                continue;       // skip the rest of this pass, go to the next command
            }
            cout << pq.top() <<endl;
        } else if(x == 2){
            // 2: delete the minimum. Nothing to delete -> Empty.
            if(pq.empty()){
                cout << "Empty" << endl;
                continue;
            }
            pq.pop();           // remove the smallest value
            // Show the new minimum; the pop may have removed the last value.
            if(pq.empty()){
                cout << "Empty" << endl;
            } else {
                cout << pq.top() << endl;
            }
        }
    }

    return 0;               // program finished normally
}
