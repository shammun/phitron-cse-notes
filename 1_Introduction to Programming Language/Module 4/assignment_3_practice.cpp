// Is the array already sorted?
//
// A re-typing of assignment_3_sorted.cpp, with the same logic. The problem
// statement and the samples are at the top of that file.
//
// The idea: an array is in ascending order exactly when no element is
// smaller than the one just before it. So there is no need to compare
// everything with everything - one pass comparing each neighbouring pair
// settles it.
//
// The C++ pieces used here (cin, cout, vector, using namespace std) are
// explained in assignment_2_practice.cpp.

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int main(){
    int T;
    cin >> T;

    // T independent test cases, each with its own N and its own array, so
    // the whole job runs once per test case. i is only a counter; it is not
    // used inside.
    for(int i=0; i<T; i++){
        int N;
        cin >> N;
        vector<int> A(N);
        for(int j=0; j<N; j++){
            cin >> A[j];
        }

        // "Assume sorted until proved otherwise."
        // flag is declared inside the outer loop, so it is fresh for every
        // test case. Declaring it outside would let a NO from one test stick
        // to all the tests after it.
        bool flag = true;
        // j starts at 1, because the comparison looks back at A[j-1];
        // starting at 0 would read A[-1], outside the vector.
        // The test is strictly smaller. Equal neighbours are still sorted,
        // so 1 1 2 2 counts as YES.
        for(int j=1; j<N; j++){
            if(A[j] < A[j-1]){
                flag = false;
                // One out-of-order pair settles it, and the rest of the
                // array cannot change the answer. break leaves only this
                // inner loop, so the next test case still runs - that is
                // exactly what is wanted here, but it is the classic trap
                // when a break is meant to end both loops.
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