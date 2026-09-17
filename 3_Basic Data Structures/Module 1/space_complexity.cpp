#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n >> m;
    int sum = 0; // memory space complexity O(1)
    int x; // memory space complexity O(1)
    double d = 3.14; // memory space complexity O(1)
    // time complexity depends on the number of loops while
    // space complexity depends on the number of variables or the array size

    // time complexity O(n)
    // space complexity O(1)
    for(int i = 0; i < n; i++) {
        sum += i;
    }

    // space complexity O(n)
    int a[n]; 
    // time complexity O(n)
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    // space complexity O(n^2)
    int a[n][n]; 
    
    // time complexity O(n)
    for(int i = 0; i < n; i++) {
        cin >> a[i][i];
    }

    // space complexity O(n*m)
    int a[n][m];
    // time complexity O(n)
    for(int i = 0; i < n; i++) {
        cin >> a[i][i];
    }

    return 0;
}