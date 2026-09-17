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
    int T;
    cin >> T;

    while(T--){
        int N;
        cin >> N;

        int a[100];
        for(int i=0; i<N; i++){
            cin >> a[i];
        }

        int min_ai_minus_i = INT_MAX;
        int smallest_sum = INT_MAX;

        for(int j=0; j<N; j++){
            if(j > 0){
                smallest_sum = min(smallest_sum, min_ai_minus_i + a[j] + j);
            }
            min_ai_minus_i = min(min_ai_minus_i, a[j] - j);
        }

        cout << smallest_sum << endl;
    }

    return 0;
}
