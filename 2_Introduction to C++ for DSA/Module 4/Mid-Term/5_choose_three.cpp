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

#include <iostream>
#include <string.h>
using namespace std;

int main() {
    int T;
    cin >> T;

    string results[100000];

    for(int i=0; i<T; i++){
        int N, S;
        cin >> N >> S;

        int A[100];
        for(int i=0; i<N; i++){
            cin >> A[i];
        }

        string answer = "NO";

        for(int i=0; i<N; i++){
            for(int j=0; j<N; j++){
                for(int k=0; k<N; k++){
                    if(i != j && i != k && j != k){
                        if(A[i] + A[j] + A[k] == S){
                            answer = "YES";
                        }
                    }
                }
            }
        }

        results[i] = answer;
    }

    for(int i=0; i<T; i++){
        cout << results[i] << endl;
    }

    return 0;
}