/*

Printing X

Problem Statement

You will be given an positive odd integer N, you need to print the pattern for it. See sample 
input and output for understanding the pattern.

Input Format

Input will contain only N.
Constraints

1 <= N <= 20 and N is odd.
Output Format

Output the pattern.
Sample Input 0

5
Sample Output 0

\   /
 \ / 
  X  
 / \ 
/   \
Sample Input 1

7
Sample Output 1

\     /
 \   / 
  \ /  
   X   
  / \  
 /   \ 
/     \
Sample Input 2

3
Sample Output 2

\ /
 X 
/ \
Sample Input 3

1
Sample Output 3

X

*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int main() {
    int N;
    cin >> N;

    if(N == 1){
        cout << "X" << endl;
        return 0;
    }

    int spaces = N - 2;

    for(int i=0; i < N/2; i++){
        for(int j=0; j <i; j++){
            cout << " ";
        }
        cout << "\\";

        for(int j=0; j< spaces; j++){
            cout << " ";
        }
        cout << "/";

        for(int k=0; k<i; k++){
            cout << " ";
        }
        cout << endl;

        spaces -= 2;
    }

    for(int i=0; i<N/2; i++){
        cout << " ";
    }
    cout << "X" << endl;

    int space_before_after = N/2 - 1;
    int space_between = 1;
    for(int i=N/2 + 1; i < N; i++){
        for(int j=0; j<space_before_after; j++){
            cout << " ";
        }
        cout << "/";

        for(int k=0; k<space_between; k++){
            cout << " ";
        } 
        cout << "\\";

        for(int l=0; l<space_before_after; l++){
            cout << " ";
        }
        cout << endl;
        space_before_after--;
        space_between += 2;
    }

    return 0;
}