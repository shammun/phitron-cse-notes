/*

https://www.hackerrank.com/contests/final-exam-a-introduction-to-algorithms-a-batch-06/challenges/make-it-2

Make it

Problem Statement

You will be given a positive integer N. You will start from 1 and do some steps (possibly zero).

In each step you can choose one of the following:

1. Add 3 with the current value
2. Multiply by 2 with the current value

Can you tell if you can reach N by using any number of steps you want.

Input Format
- First line will contain , the number of test cases.
- In each test case you will be given .

Constraints
1. 1 <= T <= 10^3
2. 1 <= N <= 10^5

Output Format
- Print "YES" if you can reach , "NO" otherwise.

Sample Input 0
5
1
3
5
15
16

Sample Output 0
YES
NO
YES
NO
YES

*/

// Solution idea: treat every number as a node of a graph. From a node x there
// are two edges: to x + 3 and to x * 2. "Can we reach N from 1?" is then the
// question Module 2 answered with BFS: start the queue at 1 and see whether N
// is ever visited. Both moves only make the number bigger, so any value above
// N is a dead end and is never pushed, which keeps the graph at most N nodes.
//
// Trace for N = 5: queue [1] -> pop 1, push 4 and 2 -> pop 4 (7 and 8 are
// > 5, skipped) -> pop 2, push 5 (2*2 = 4 already seen) -> pop 5 = N -> YES.

#include <iostream>     // cin, cout, endl
#include <vector>       // not used here
#include <algorithm>    // not used here
#include <string>       // not used here
#include <stack>        // not used here
#include <queue>        // queue
// (memset below comes from <cstring>, which is not included; it compiles only
// because one of the headers above pulls it in with g++.)

using namespace std;    // no std:: prefix

bool vis[100005];   // vis[x] = has x already been put in the queue? (N <= 10^5)

// BFS from 1: returns true if n can be produced.
bool make_it(int n){
    queue<int> q;       // numbers waiting to be expanded (first in, first out)
    q.push(1);          // every attempt starts from the value 1

    vis[1] = true;      // 1 is already in the queue

    // One pass: take the oldest number and push its two unseen children.
    while(!q.empty()){
        int par = q.front();   // oldest number in the queue
        q.pop();               // remove it

        // We have produced n: it is reachable.
        if(par == n){
            return true;
        }

        // The two "children" of par, one per allowed move.
        int option1 = par + 3;
        int option2 = par * 2;

        // Push a child only if it does not overshoot n (both moves grow the
        // value, so an overshoot can never come back down) and it is new.
        if(option1 <= n && vis[option1] == false){
            q.push(option1);
            vis[option1] = true;
        }

        if(option2 <= n && vis[option2] == false){
            q.push(option2);
            vis[option2] = true;
        }
    }

    // The queue ran dry without meeting n: no sequence of moves gives n.
    // Example: 3 is impossible, because 1 leads to 4 or 2, and both only grow.
    return false;
}

int main(){
    int t;              // number of test cases
    cin >> t;

    while(t--){         // one pass per test case
        int n;          // the target N
        cin >> n;
        // Fresh visited marks for every test case, or the previous case's marks
        // would block numbers this case still needs to explore.
        memset(vis, false, sizeof(vis));

        if(make_it(n)){
            cout << "YES" << endl;
        }
        else{
            cout << "NO" << endl;
        }
    }

    // Each value 1..N is pushed at most once: O(N) per test case.
    return 0;

}
