#include <iostream>
using namespace std;

int main() {
    int n, m; // O(1)
    cin >> n >> m; // O(1)

    // O(n^2)
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cout << i << " " << j << endl;
        }
    }

    // O(n^2)
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cout << "Hello" << endl;
        }
    }

    // O(nxm)
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cout << "Hello" << endl;
        }
    }

    // O(n^3)
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            for(int k = 0; k < n; k++) {
                cout << "Hello" << endl;
            }
        }
    }

    return 0;
}