/*

Problem Statement

You will be given an array A of size N. Print "YES" if there is any duplicate
value in the array, "NO" otherwise.

Input Format

First line will contain N.
Second line will contain the array A.
Constraints

1 <= N <= 100000
0 <= A[i] <= 10^9; Where 0 <= i < N
Output Format

Output "YES" or "NO" without the quotation marks according to the problem
statement.

Sample Input 0

5
1 2 3 4 5

Sample Output 0

NO

Sample Input 1

6
2 1 3 5 2 1
Sample Output 1

YES

*/

/*
 * The idea: SORT first. After sorting, equal values end up right next to
 * each other, so a duplicate exists exactly when some element equals the
 * one just before it. One pass over neighbours answers the question.
 *
 *   2 1 3 5 2 1   --sort-->   1 1 2 2 3 5
 *                             ^ ^  A[1] == A[0]  -> YES
 *
 * Comparing every pair instead would be about N*N/2 = 5e9 comparisons for
 * N = 100000 - far too slow. Sorting costs about N*log2(N), roughly 1.7e6.
 *
 * This is C++, not C. The C++ pieces used:
 *   #include <iostream>   cin (read) and cout (print)
 *   #include <vector>     vector, a resizable array
 *   #include <algorithm>  sort
 *   #include <string>     the string type (not used here; habit)
 *   using namespace std;  lets us write cin, cout, vector, sort instead of
 *                         std::cin, std::cout, ... (std is the "namespace",
 *                         the family name, of the standard library)
 */
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int main() {        // the program starts here
    int n;          // how many numbers are in the array
    /* cin >> n reads one value from the keyboard into n. No %d and no &
       as in C's scanf: cin works out the type from the variable itself.
       It skips spaces and newlines before the value. */
    cin >> n;

    /* vector<int> A(n): an array of n ints named A, all starting at 0.
       Unlike a plain C array, its size can come from input at run time,
       and it lives in the big "heap" memory, so 100000 ints are no
       problem. A[0] .. A[n-1] are its elements, same as an array. */
    vector<int> A(n);
    // Read the n numbers: one pass per index i = 0, 1, ..., n-1.
    for(int i=0; i<n; i++){
        cin >> A[i];    // store the next typed number in box i
    }

    /* sort(first, last) puts the elements in ascending order.
       A.begin() = position of the first element, A.end() = the position
       just PAST the last one, so together they mean "the whole vector". */
    sort(A.begin(), A.end());

    /* Compare each element with its left neighbour. i starts at 1 because
       A[i-1] with i = 0 would be A[-1], outside the vector. */
    for(int i=1; i<n; i++){
        if(A[i] == A[i-1]){     // two equal neighbours = a duplicate
            /* cout << prints; << chains several things left to right.
               endl ends the line (and flushes the output to the screen). */
            cout << "YES" << endl;
            return 0;   // answer found: end the whole program right here
        }
    }

    /* Only reached if the loop finished without finding any equal pair. */
    cout << "NO" << endl;
    return 0;           // 0 = the program finished normally
}