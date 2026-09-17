#include <iostream>
using namespace std; // Allows us to avoid prefixing standard library objects with `std::`.

void recursion_1_to_n(int i, int n){
    if(i > n){
        return;
    }
    cout << i << endl;
    recursion_1_to_n(i+1, n);
}

void recursion_n_to_1(int i, int n){
    if(i > n){
        return;
    }
    recursion_n_to_1(i+1, n);
    cout << i << endl;
}

int main(){
    // Print 1 to 5
    recursion_1_to_n(1, 5);

    // Print 5 to 1
    recursion_n_to_1(1, 5);

    return 0;
}