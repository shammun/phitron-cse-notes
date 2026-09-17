/*

Sorting
time limit per test: 1 second
memory limit per test: 64 megabytes

Given a number N and an array A of N numbers. Print the numbers after sorting them.

Note:

Don't use built-in-functions.
try to solve it with bubble sort algorithm or Selection Sort.
for more information watch : https://www.youtube.com/watch?v=EnodMqJuQEo.
Input
First line contains a number N (0 < N < 103) number of elements.

Second line contains N numbers ( - 100 ≤ Ai ≤ 100).

Output
Print the numbers after sorting them.

Examples
Input
3
3 1 2
Output
1 2 3 

Input
4
5 2 7 3
Output
2 3 5 7 

solve using sort() function

*/

#include <iostream> // Include the iostream library for input/output operations
#include <algorithm> // Include the algorithm library for sorting
using namespace std; // Use the standard namespace to avoid prefixing 'std::' before cin, cout, etc.

int main(){
    int N;
    cin >> N;

    int A[N];
    for(int i=0; i<N; i++){
        cin >> A[i];
    }

    sort(A, A+N);

    for(int i=0; i<N; i++){
        cout << A[i] << " ";
    }

    cout << endl;

    return 0;
}