#include <iostream>
#include <algorithm> // This header file is used to use the min, max, and swap functions
using namespace std; // This line allows us to use names for objects and variables from the standard library without the 'std::' prefix

int main(){
    int a, b, c;
    cin >> a >> b >> c;

    /*
    In C++, min and max can be found using if else statements
    if(a <b){
        cout << a << endl;
    } else {
        cout << b << endl;
    }
    */

    // In C++, min and max can be found using built-in functions
    cout << min(a, b) << endl;
    cout << max(a, b) << endl;

    // min and max can find minimum and maximum among more than two numbers
    // In this case, the numbers have to be passed within second or curly braces
    cout << min({a, b, c}) << endl;
    cout << min({20, -100, 40, 65}) << endl;

    cout << max({a, b, c}) << endl;
    cout << max({20, -100, 40, 65}) << endl;

    cout << endl;

    // swap function swaps the values of two variables
    swap(a, b);
    cout << a << " " << b << endl;

    return 0;
}