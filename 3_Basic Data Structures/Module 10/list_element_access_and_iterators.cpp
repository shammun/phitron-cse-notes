#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <list>
using namespace std; 

int main(){
    list<int> l = {10, 20,30, 40, 50};
    // Accessing the first element of the list using the front() function
    cout << l.front() << endl;
    // Accessing the last element of the list using the back() function
    cout << l.back() << endl;

    // Accessing any element of the list using next function
    // Acccessing the thrird element or index 2 of the list using the next function
    cout << *next(l.begin(), 2) << endl;

    // Accessing the first lement using begin() function
    cout << *l.begin() << endl;

    // Accessing the last element using end() function
    cout << *(--l.end()) << endl;
    // coout << l.back() << endl;





    return 0;
}