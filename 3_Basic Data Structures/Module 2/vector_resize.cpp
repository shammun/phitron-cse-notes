#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> v;
    v.push_back(10);
    v.push_back(20);
    v.push_back(30);

    //  resize() function changes the size of the vector
    // size is decrreased
    v.resize(2);
    for(int i=0; i<v.size(); i++){
        cout << v[i] << " ";
    }

    // size is increased
    // new elements are initialized with 0
    v.resize(5); // {10, 20, 0, 0, 0}
    for(int i=0; i<v.size(); i++){
        cout << v[i] << " ";
    }

    // When increasing size, we can also set the value of the new elements
    v.resize(7, 100); // {10, 20, 0, 0, 0, 100, 100}
    for(int i=0; i<v.size(); i++){
        cout << v[i] << " ";
    }

    return 0;
}