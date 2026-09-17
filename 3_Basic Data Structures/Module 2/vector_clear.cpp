#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> v = {10, 20, 30};
    cout << v.size() << endl; // 3

    // clear() function removes all the elements from the vector and the size remains 0
    // But vector's value is still there
    // It doesn't delete the values from the memory, just makes the size equal to 0
    // But, if we insert any value in the vector now, it will be inserted at index 0
    v.clear();
    cout << v.size() << endl; // 0
    cout << v[0] << endl; // 10
    cout << v[1] << endl; // 20
    cout << v[2] << endl; // 30

    v.push_back(40);
    cout << v[0] << endl; // 40
    cout << v[1] << endl; // 20
    cout << v[2] << endl; // 30

    v.push_back(50);
    cout << v[0] << endl; // 40
    cout << v[1] << endl; // 50
    cout << v[2] << endl; // 30 

    v.push_back(60);
    cout << v[0] << endl; // 40
    cout << v[1] << endl; // 50
    cout << v[2] << endl; // 60

    return 0;
}