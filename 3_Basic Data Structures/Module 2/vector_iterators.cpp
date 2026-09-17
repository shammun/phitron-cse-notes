/*

In this tutorial, we will learn about vector iterators.

*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    vector<int> v = {1,2,3,4,5,3,25};

    // Using iterator, we can access the elements of the vector
    for(vector<int>::iterator it = v.begin(); it != v.end(); it++){
        cout << *it << " ";
    }

    // We can also use auto keyword to declare the iterator
    for(auto it = v.begin(); it != v.end(); it++){
        cout << *it << " ";
    }


    return 0;
}