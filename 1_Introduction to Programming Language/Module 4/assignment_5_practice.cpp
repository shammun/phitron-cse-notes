#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int main(){
    int N;
    cin >> N;

    if(N == 1){
        cout << "X" << endl;
        return 0;
    }

    int spaces = N - 2;

    for(int i=0; i<N/2; i++){
        for(int j=0; j<i; j++){
            cout << " ";
        }

        cout << "\\";;

        for(int j=0; j<spaces; j++){
            cout << " ";
        }

        cout << "/";

        for(int k=0; k<i; k++){
            cout << " ";
        }

        cout << endl;

        spaces -= 2;
    }

    for(int i=0; i < N/2; i++){
        cout << " ";
    }

    cout << "X" << endl;

    // Lower half of the X

    int space_before_after = N/2 - 1;
    int space_between = 1;

    for(int i=N/2 + 1; i <N; i++){
        for(int j=0; j<space_before_after; j++){
            cout << " ";
        }
        
        cout << "/";

        for(int k=0;k<space_between; k++){
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
}