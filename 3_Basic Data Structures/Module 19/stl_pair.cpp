/*

STL Pair

*/

#include <iostream>
#include <utility>
#include <string>
#include <vector>
using namespace std;

int main(){
    pair<int, int> p1;
    p1 = make_pair(2, 3);
    cout << p1.first << " " << p1.second << endl;

    // we can also do the following
    pair<int, int> p2;
    p2 = {2, 3};
    cout << p2.first << " " << p2.second << endl;

    pair<string, int> p3;
    p3 = {"Hello", 3};
    cout << p3.first << " " << p3.second << endl;

    // vector of pairs
    vector<pair<int, int>> v;
    v.push_back(make_pair(1, 2));
    v.push_back(make_pair(3, 4));
    for(int i=0; i<v.size(); i++){
        cout << v[i].first << " " << v[i].second << endl;
    }

    // Take input from user to create vector of pairs of integers of the size n
    int n;
    cin >> n;
    vector<pair<int, int>> v(n);
    for(int i=0; i<n; i++){
        cin >> v[i].first >> v[i].second;
    }

    return 0;
}