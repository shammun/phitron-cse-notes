#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> v;
    v.push_back(10);
    v.push_back(20);
    v.push_back(30);

    // empty() function returns true if the vector is empty
    if(v.empty() == true){
        cout << "Vector is empty" << endl;
    }
    else{
        cout << "Vector is not empty" << endl;
    }

    return 0;
}    