#include <bits/stdc++.h>
using namespace std;

void print_forward(list<int> &l){
    cout << "L -> ";
    for(auto it=l.begin(); it!=l.end(); it++){
        cout << *it << " ";
    }
    cout << endl;
}

void print_backward(list<int> &l){
    cout << "R -> ";
    if(l.empty()){
        cout << endl;
        return;
    }
    
    auto it = next(l.begin(), l.size()-1);
    while(true){
        cout << *it << " ";
        if(it == l.begin()){
            break;
        }
        it--;
    }
    cout << endl;
}

void (list<int> &l, int X, int V){
    int size = l.size();
    if(X < 0 || X > size){
        cout << "Invalid" << endl;
        return;
    }

    auto it = l.begin();
    for(int i=0; i < X; i++){
        it++;
    }
    l.insert(it, V);
    
    print_forward(l);
    print_backward(l);
}

int main(){
    int Q;
    cin >> Q;
    list<int> l;
    while(Q--){
        int X, V;
        cin >> X >> V;
        insert_at_any_position(l, X, V);
    }
    return 0;
}