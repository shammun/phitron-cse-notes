/*

Sorted

Problem Statement

You will given an array A of size N. You need to tell if the array is already
sorted or not. If the array is sorted in ascending order print "YES", otherwise
print "NO".

Input Format

First line will contain T, the number of test cases.
The first line of each test case will contain N.
The second line of each test case will contain the array A.
Constraints

1 <= T <= 1000
1 <= N <= 1000
0 <= A[i] <= 1000; Where 0 <= i < N
Output Format

Output "YES" or "NO" without the quotation marks according to the problem statement.
Sample Input 0

3
5
2 4 6 7 10
8
1 100 101 120 120 121 1000 1000
4
100 1 102 12
Sample Output 0

YES
YES
NO

*/

/*
 * The idea: an array is in ascending order exactly when no element is
 * smaller than the element just before it. So check each neighbouring
 * pair once; a single "step down" means NO.
 *
 * C++ pieces used:
 *   #include <iostream>  cin >> x reads into x; cout << x prints x;
 *                        endl ends the line.
 *   #include <vector>    vector<int> A(N): N ints A[0]..A[N-1], size
 *                        chosen while the program runs.
 *   <algorithm>, <string> - not used here, kept from a template.
 *   using namespace std; - lets us drop the std:: prefix.
 *   bool                 - a type holding only true or false.
 */
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int main() {        // the program starts here
    int T;          // number of test cases
    cin >> T;

    // Solve each test case completely, one after another; i just counts.
    for(int i=0; i<T; i++){
        int N;                      // size of this array
        cin >> N;
        vector<int> A(N);           // storage for it
        for(int j=0; j<N; j++){     // read the N numbers
            cin >> A[j];
        }

        /* Start by assuming the array IS sorted; one bad pair will switch
           the flag off. Declared inside the loop, so each test case gets a
           fresh true. */
        bool flag = true;
        /* j from 1: each round compares A[j] with the one before it,
           A[j-1] (j = 0 would read A[-1], outside the array). */
        for(int j=1; j<N; j++){
            if(A[j] < A[j-1]){      // smaller than its left neighbour
                flag = false;       // so the array is not sorted
                break;              // no need to look further; leave this loop
            }
        }

        if(flag){                   // same as flag == true
            cout << "YES" << endl;
        }
        else{
            cout << "NO" << endl;
        }
    }

    return 0;       // 0 = finished normally
}