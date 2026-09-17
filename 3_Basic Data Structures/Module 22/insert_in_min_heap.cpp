#include<iostream>
#include <vector>

using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> v(n);

    for(int i=0; i<n; i++){
        cin >> v[i];
    }

    int val;
    cin >> val;
    v.push_back(val);
    int cur_idx = v.size() - 1;
    while(cur_idx != 0){
        int par_idx = (cur_idx - 1) / 2;
        if(v[cur_idx] < v[par_idx]){
            swap(v[cur_idx], v[par_idx]);
            cur_idx = par_idx;
        } else{
            break;
        }
    }

    for(int x : v){
        cout << x << " ";
    }
    cout << endl;

    return 0;
}