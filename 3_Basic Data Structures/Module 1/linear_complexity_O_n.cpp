
#include <iostream>
using namespace std;

int main() {
    int n; // O(1)
    cin >> n; // O(1)

    // O(n)
    for(int i = 0; i < n; i++) {
        cout << i << " ";
    }

    // O(n)
    for(int i = 0; i < n-5; i++) {
        cout << i << " ";
    }

    // O(n)
    for(int i = 0; i < n/2; i++) {
        cout << i << " ";
    }

    // O(n)
    for(int i = 0; i < 2*n; i++) {
        cout << i << " ";
    }

    // O(n)
    for(int i = 0; i <= n; i+=2) {
        cout << i << " ";
    }

    return 0;
}

// Time complexity: O(n) -- consider the worst case scenario and ignore the constants 
// or consider the most dominant term