// Is the array already sorted?
//
// A re-typing of assignment_3_sorted.cpp, with the same logic. The problem
// statement and the samples are at the top of that file.
// (In short: T test cases; each gives N and an array of N numbers. Print
// YES if the array is in ascending order - equal neighbours allowed -
// otherwise NO. e.g. 2 4 6 7 10 -> YES,  100 1 102 12 -> NO.)
//
// The idea: an array is in ascending order exactly when no element is
// smaller than the one just before it. So there is no need to compare
// everything with everything - one pass comparing each neighbouring pair
// settles it.
//
// The C++ pieces used here:
//   #include <iostream>   cin >> x reads a value into x (no & or %d
//                         needed); cout << x prints x; endl ends the line.
//   #include <vector>     vector<int> A(N) = an array of N ints, A[0] to
//                         A[N-1], whose size N can come from the input.
//   <algorithm>, <string> are included out of habit and not used.
//   using namespace std;  lets us write cin/cout/vector instead of
//                         std::cin/std::cout/std::vector.
//   bool                  a type with only two values, true and false.

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int main(){         // the program starts here
    int T;          // number of test cases
    cin >> T;       // read it

    // T independent test cases, each with its own N and its own array, so
    // the whole job runs once per test case. i is only a counter; it is not
    // used inside.
    for(int i=0; i<T; i++){
        int N;                      // size of this test's array
        cin >> N;
        vector<int> A(N);           // N boxes for the numbers
        for(int j=0; j<N; j++){     // read them one by one
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
        // Trace 100 1 102 12: j=1 compares 1 < 100 -> true -> NO.
        for(int j=1; j<N; j++){
            if(A[j] < A[j-1]){
                flag = false;       // found a step down: not sorted
                // One out-of-order pair settles it, and the rest of the
                // array cannot change the answer. break leaves only this
                // inner loop, so the next test case still runs - that is
                // exactly what is wanted here, but it is the classic trap
                // when a break is meant to end both loops.
                break;
            }
        }

        // if(flag) is short for if(flag == true).
        if(flag){
            cout << "YES" << endl;  // no step down was found
        } else{
            cout << "NO" << endl;
        }
    }

    return 0;       // 0 = the program finished normally
}