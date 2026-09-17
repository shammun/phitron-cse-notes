#include <iostream>
using namespace std;

int main() {
    int n; // O(1)
    cin >> n; // O(1)

    // O(log n)
    for(int i = 1; i <= n; i *= 2) {
        cout << i << " ";
    }

    // O(log n) -- log 3 base n
    for(int i=n; i>=1; i/=3){
        cout << i << " ";
    }

    // O(log n) -- log 2 base n
    for(int i=1; i<n; i++){
        cout  << i << " ";
        i *= 2;
    }

    // O(log n) -- log k base n
    int k = 3;
    for(int i=1; i<n; i++){
        cout  << i << " ";
        i *= k;
    }

    return 0;
}