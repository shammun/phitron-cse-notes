#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    // O(sqrt(n))
    for(int i=0; i<=sqrt(n); i++){
        cout << i << endl;
    }

    // find all the divisors of n
    // O(n))
    for(int i=1; i<=n; i++){
        if(n%i == 0){
            cout << i << " ";
        }
    }

    // O(sqrt(n))
    for(int i=1; i<=sqrt(n); i++){
        if(n%i == 0){
            cout << i << " " << n /i << " ";
        }
    }

    // O(sqrt(n))
    for(int i=1; i*i<=n; i++){
        if(n%i == 0){
            cout << i << " " << n /i << " ";
        }
    }

    return 0;
}