// Insert one whole array into another at index X.
//
// A re-typing of assignment_4_insert_it.cpp, with the same logic. The
// problem statement and the samples are at the top of that file.
//
// Watch the names in this version: the array read FIRST is A, of size M, and
// the array inserted into it is B, of size N. That is the other way round
// from the original file, where A had size N. Nothing else differs, but it
// is worth noticing, because M and N no longer mean what the problem
// statement says they mean.
//
// The idea: vector's insert puts one value at a given position and shifts
// everything from that position onwards one step to the right. Do that once
// per element of B, moving the target position forward each time, and B
// lands inside A in its original order.
//
// Cost: every insert has to shift the tail of A, so inserting N values costs
// roughly N * (M + N) moves. That is fine for the limits here, where both
// sizes are at most 1000.
//
// The C++ pieces used here (cin, cout, vector, using namespace std) are
// explained in assignment_2_practice.cpp.

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

    // A.begin() is the position of A's first element, so A.begin() + X is
    // the position X steps along. insert drops B[i] in there and pushes the
    // rest of A one place to the right.
    // X++ is essential: without it every element of B would go to the same
    // position, and B would come out reversed inside A.
    for(int i=0; i<N; i++){
        A.insert(A.begin() + X, B[i]);
        X++;
    }

    // A has grown from M elements to M + N, so print that many. The line
    // ends with a trailing space and no newline.
    for(int i=0; i<M+N; i++){
        cout << A[i] << " ";
    }

    return 0;
}