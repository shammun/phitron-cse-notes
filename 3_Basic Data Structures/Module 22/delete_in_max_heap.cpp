#include<iostream>
#include <vector>

using namespace std;

void insert_heap(vector<int> &v, int x){
    v.push_back(x);
    int cur_idx = v.size() - 1;
    while(cur_idx != 0){
        int par_idx = (cur_idx -1) / 2;
        if(v[cur_idx] > v[par_idx]){
            swap(v[cur_idx], v[par_idx]);
            cur_idx = par_idx;
        } else{
            break;
        }
    }
}

void heap_input(vector<int> &v, int n){
    for(int i=0; i<n; i++){
        int x;
        cin >> x;
        insert_heap(v, x);
    }
}

void print_heap(vector<int> &v){
    for(int x : v){
        cout << x << " ";
    }
    cout << endl;
}


/*

void delete_heap_mine(vector<int> &v){
    v[0] = v.back(); // v[0] = v[v.size() - 1];
    v.pop_back();

    int cur_idx = 0;

    while(true){
        int left_idx = (2 * cur_idx) + 1;
        int right_idx = (2 * cur_idx) + 2;
        if(left_idx >= v.size()){
            break;
        }
        if(right_idx >= v.size()){
            break;
        }
        if(left_idx < v.size() && right_idx < v.size()){
            if(v[left_idx] > v[right_idx] && v[left_idx] > v[cur_idx]){
                swap(v[left_idx], v[cur_idx]);
                cur_idx = left_idx;
            } else if(v[right_idx] > v[left_idx] && v[right_idx] > v[cur_idx]){
                swap(v[right_idx], v[cur_idx]);
                cur_idx = right_idx;
            } else{
                break;
            }
        }
    }
}

*/

void delete_heap(vector<int> &v){
    v[0] = v.back();
    v.pop_back();

    int cur_idx = 0;
    
    while(true){
        int left_idx = (2 * cur_idx) + 1;
        int right_idx = (2 * cur_idx) + 2;



        int left_val = INT_MIN;
        int right_val = INT_MIN;

        if(left_idx < v.size()){
            left_val = v[left_idx];
        }
        if(right_idx < v.size()){
            right_val = v[right_idx];
        }

        if(left_val >= right_val && left_val > v[cur_idx]){
            swap(v[left_idx], v[cur_idx]);
            cur_idx = left_idx;
        } else if(right_val > left_val && right_val > v[cur_idx]){
            swap(v[right_idx], v[cur_idx]);
            cur_idx = right_idx;
        } else{
            return;
        }
    }


int main(){
    vector<int> v;
    int n;
    cin >> n;
    
    heap_input(v, n);

    print_heap(v);

    delete_heap(v);

    return 0;
}