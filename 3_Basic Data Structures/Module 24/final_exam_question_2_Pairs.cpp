/*

Pairs

Problem Statement

You will be given a list A of type pairs. Each pair will contain one string S and 
one unique integer I. The string will contain only English lowercase alphabets and 
no spaces.

You need to sort the pairs according to the string values in ascending order. If 
there are multiple pairs with the same string, you need to sort them according to 
the integer value in descending order.

Input Format

- First line will contain , the size of the list .
- Next  lines will contain pairs of string  and integer .

Constraints
1. 1 <= N <= 10^5
2. 1 <= |S| <= 10^5
3. _10^9 <= I <= 10^9

Output Format

Output the final list after sorting according to the question.
Sample Input 0

5
sakib 1
rakib 2
tasfia 3
asfia 4
afia 5

Sample Output 0
afia 5
asfia 4
rakib 2
sakib 1
tasfia 3

Sample Input 1
6
sakib 5
rakib 3
tasfia 2
sakib 6
afia 1
sakib 4

Sample Output 1
afia 1
rakib 3
sakib 6
sakib 5
sakib 4
tasfia 2

*/


#include <bits/stdc++.h>

using namespace std;



class Pair{
    public:
        string name;
        int val;

        Pair(string name, int val){
            this->name = name;
            this->val = val;
        }
};


class cmp{
    public:
        bool operator()(Pair &l, Pair &r){
            if(l.name > r.name){
                return true;
            } else if(l.name < r.name){
                return false;
            } else {
                return l.val < r.val;
            } 
        }
};

int main(){
    priority_queue<Pair, vector<Pair>, cmp> pq;
    int N;
    cin >> N;

    for(int i=0; i<N; i++){
        string name;
        int val;
        cin >> name >> val;
        Pair obj(name, val);
        pq.push(obj);
    }

    while(!pq.empty()){
        cout << pq.top().name << " " << pq.top().val << endl;
        pq.pop();
    }

}