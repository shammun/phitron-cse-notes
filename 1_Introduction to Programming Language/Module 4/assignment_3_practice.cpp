#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int main(){
    int T;
    cin >> T;

    for(int i=0; i<T; i++){
        int N;
        cin >> N;
        vector<int> A(N);
        for(int j=0; j<N; j++){
            cin >> A[j];
        }

        bool flag = true;
        for(int j=1; j<N; j++){
            if(A[j] < A[j-1]){
                flag = false;
                break;
            }
        }

        if(flag){
            cout << "YES" << endl;
        } else{
            cout << "NO" << endl;
        }
    }

    return 0;
}