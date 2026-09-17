#include <iostream>
using namespace std;

int main() {
    int n; // O(1)
    cin >> n; // O(1)

    // O(n^2)
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cout << i << "Hello" << j << endl;
        }
    }

    // O(n*log n)
    for(int i = 0; i < n; i++) {
        for(int j = 1; j < n; j *= 2) {
            cout << i << "Hello" << j << endl;
        }
    }

    return 0;
}