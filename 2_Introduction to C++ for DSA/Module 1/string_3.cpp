#include <iostream>
using namespace std;

int main(){
    int x;
    cin >> x;

    // C++ has a string type called 'string'
    // Thus we don't need to declare a character
    // array

    // String class is a built-in class
    string s = "Hello World!"; // String literal
    cout << s << endl;

    string s2;
    // But it can't take input with spaces
    cin >> s2;
    cout << s2 << endl;

    return 0;
}