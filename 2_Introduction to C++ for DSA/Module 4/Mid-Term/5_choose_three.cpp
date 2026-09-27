/*

Choose Three

Problem Statement

You will be given an array A and the size of that array N. Additionally, you will be given a sum S. Your task is to determine whether it is possible to select three distinct indexed values from the array such that their summation equals S.

Input Format

First line will contain T, the number of test cases.
First line of each test case will contain N and S.
Second line of each test case will contain the array A.
Constraints

1 <= T <= 100
1 <= N <= 100
1 <= S <= 1000
1 <= A[i] <= 1000 Where 0 <= i < N
Output Format

Output "YES" if it is possible, otherwise output "NO".
Sample Input 0

5
5 10
1 2 3 4 5
5 6
4 2 3 5 4
3 6
2 2 2
4 4
2 8 1 5
1 3
1
Sample Output 0

YES
NO
YES
NO
NO
Explanation 0

In the first test case, we can make 10 by adding 5+4+1. There are other ways too.
In the second test case, it is not possible to make 6 by adding three different indexed values from the array.
In the third case, it is possible to make 6 by using three different indexed values.

*/

#include <iostream> // cin and cout
// <string.h> is the C header for char-array functions (strlen, strcpy...); it does NOT
// declare the C++ `string` type. `string` is available here only because <iostream>
// happens to include it on this compiler; #include <string> is the proper header.
#include <string.h> // (string itself comes in with iostream on this compiler)
using namespace std; // write cin/cout/string instead of std::cin/std::cout/std::string

int main() { // program starts here
    int T;     // number of test cases
    cin >> T;  // read T

    // CAUTION: 100000 strings is far more than T <= 100 needs, and as a local
    // array it takes about 3 MB of stack (each string object is 32 bytes here).
    // That is fine on Linux (8 MB stack) and on this site's runner, but on Windows'
    // default 1 MB stack the program crashes at start. results[100] would be enough.
    string results[100000]; // "YES" or "NO" for each test case, printed at the end

    // One pass of this loop = one whole test case
    for(int i=0; i<T; i++){
        int N, S;        // array size and target sum
        cin >> N >> S;   // read both from the first line of the test case

        int A[100]; // N <= 100, so 100 slots are always enough
        // Read the N values (this loop's i hides the outer i until it ends)
        for(int i=0; i<N; i++){
            cin >> A[i];
        }

        // Assume NO until three values that add up to S are found
        string answer = "NO";

        // Try every choice of three positions i, j, k. N is at most 100, so
        // 100 * 100 * 100 = 10^6 checks per test case is fast enough.
        // (These loops reuse the name i; inside them it hides the outer i.)
        for(int i=0; i<N; i++){           // first position
            for(int j=0; j<N; j++){       // second position
                for(int k=0; k<N; k++){   // third position
                    // "three distinct indexed values": the positions must differ,
                    // the values may be equal (2 2 2 can make 6)
                    if(i != j && i != k && j != k){ // && = and: all three differences must hold
                        if(A[i] + A[j] + A[k] == S){ // these three add up to S?
                            answer = "YES"; // found one (the loops keep going, but the answer stays YES)
                        }
                    }
                }
            }
        }
        // Trace, test 1: A={1,2,3,4,5}, S=10 -> i=0,j=3,k=4 gives 1+4+5=10 -> YES
        // Test 5: N=1, so i,j,k can never all differ -> stays NO

        results[i] = answer; // the inner loops are over, so this i is the test-case number again
    }

    // Print all answers, one per line, in input order
    for(int i=0; i<T; i++){
        cout << results[i] << endl;
    }

    return 0; // program ended normally
}