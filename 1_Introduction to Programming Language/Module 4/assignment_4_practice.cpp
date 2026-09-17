#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int main(){
    int M;
    cin >> M;

    vector<int> A(M);
    for(int i=0; i<M; i++){
        cin >> A[i];
    }

    int N;
    cin >> N;

    vector<int> B(N);
    for(int i=0; i<N; i++){
        cin >> B[i];
    }

    int X;
    cin >> X;

    for(int i=0; i<N; i++){
        A.insert(A.begin() + X, B[i]);
        X++;
    }

    for(int i=0; i<M+N; i++){
        cout << A[i] << " ";
    }

    return 0;
}