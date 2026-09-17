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

#include <iostream>
#include <vector>
#include <algorithm>    
#include <string>
#include <stack>
#include <queue>

using namespace std;

bool vis[100005];

bool make_it(int n){
    queue<int> q;
    q.push(1);

    vis[1] = true;

    while(!q.empty()){
        int par = q.front();
        q.pop();

        if(par == n){
            return true;
        }

        int option1 = par + 3;
        int option2 = par * 2;

        if(option1 <= n && vis[option1] == false){
            q.push(option1);
            vis[option1] = true;
        }

        if(option2 <= n && vis[option2] == false){
            q.push(option2);
            vis[option2] = true;
        }
    }

    return false;
}

int main(){
    int t;
    cin >> t;

    while(t--){
        int n;
        cin >> n;
        memset(vis, false, sizeof(vis));

        if(make_it(n)){
            cout << "YES" << endl;
        }
        else{
            cout << "NO" << endl;
        }
    }

    return 0;

}
