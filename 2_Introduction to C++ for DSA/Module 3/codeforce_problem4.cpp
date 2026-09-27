/*

Smallest Pair
time limit per test: 1 second
memory limit per test: 256 megabytes

Given a number N and an array A of N numbers. Print the smallest possible result of Ai + Aj + j - i , where 1  ≤  i < j  ≤  N.

Input
The first line contains a number T (1 ≤ T ≤ 100) number of test cases.

Each test case contains two lines:

The first line consists a number N (2 ≤ N ≤ 100) number of elements.
The second line contains N numbers ( - 106 ≤ Ai ≤ 106).
Output
For each test case print a single line contains the smallest possible sum for the corresponding test case.

Example

Input
1
4
20 1 9 4
Output
7

Note
First Case :

All possibles (i,j) where (1  ≤  i < j  ≤  N) are :

i = 1 , j = 2 then result = a1 + a2 + j - i = 20 + 1 + 2-1 = 22.

i = 1 , j = 3 then result = a1 + a3 + j - i = 20 + 9 + 3-1 = 31.

i = 1 , j = 4 then result = a1 + a4 + j - i = 20 + 4 + 4-1 = 27.

i = 2 , j = 3 then result = a2 + a3 + j - i = 1 + 9 + 3-2 = 11.

i = 2 , j = 4 then result = a2 + a4 + j - i = 1 + 4 + 4-2 = 7.

i = 3 , j = 4 then result = a3 + a4 + j - i = 9 + 4 + 4-3 = 14.

So the smallest possible result is 7.

*/

#include <iostream> // Include the iostream library for input/output operations
#include <climits> // Include the climits library for integer limits
using namespace std; // Use the standard namespace to avoid prefixing 'std::' before standard library components

int main(){
    int T; // number of test cases
    cin >> T;

    // while(T--) runs the body exactly T times: it tests the current T (non-zero = true),
    // then lowers it by 1. T=2 -> runs with T becoming 1, then 0, then the test sees 0 and stops.
    while(T--){
        int N; // number of elements in this test case
        cin >> N;

        int a[100]; // N is at most 100, so a fixed array of 100 boxes is always big enough
        // Read the N numbers into a[0] .. a[N-1].
        for(int i=0; i<N; i++){
            cin >> a[i];
        }

        // Checking every pair (i, j) would work for N <= 100, but there is a
        // neater way. Regroup the formula:
        //     a[i] + a[j] + j - i  =  (a[i] - i)  +  (a[j] + j)
        // For a fixed j, the best i is simply the one before j with the
        // smallest a[i] - i. So one pass is enough: remember the smallest
        // a[i] - i seen so far, and try it with every new j.
        // Indexes here start at 0 instead of the problem's 1, but j - i is the same either way.
        // INT_MAX (from <climits>) is the largest value an int can hold, 2147483647.
        // Starting a "minimum so far" at INT_MAX means the first real value always replaces it.
        // Values stay safe: |a| <= 10^6 and index <= 100, so no sum comes near INT_MAX.
        int min_ai_minus_i = INT_MAX; // smallest a[i] - i among indexes before j
        int smallest_sum = INT_MAX;   // best answer so far (INT_MAX = "nothing yet")

        // Trace with 20 1 9 4 (0-based):
        //   j=0: no i yet; min_ai_minus_i = 20-0 = 20
        //   j=1: try 20 + (1+1) = 22 -> best 22; min_ai_minus_i = min(20, 1-1=0) = 0
        //   j=2: try 0 + (9+2) = 11 -> best 11; min_ai_minus_i = min(0, 9-2=7) = 0
        //   j=3: try 0 + (4+3) = 7  -> best 7                      -> prints 7
        for(int j=0; j<N; j++){
            if(j > 0){ // j needs at least one i before it
                // min() keeps the smaller of the old best and this pair's value
                smallest_sum = min(smallest_sum, min_ai_minus_i + a[j] + j);
            }
            // now index j can itself act as an i for the later indexes
            min_ai_minus_i = min(min_ai_minus_i, a[j] - j);
        }

        cout << smallest_sum << endl; // one answer per test case
    }

    return 0; // program finished normally
}
