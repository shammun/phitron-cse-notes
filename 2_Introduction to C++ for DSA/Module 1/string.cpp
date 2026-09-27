#include <iostream>
using namespace std;

int main(){
    char s[100];
    // cin >> s;
    // In C, when there are spaces or space
    // between inputs, it reads only the first word
    // To overcome this in C, we use 
    // fgets(s, 100, stdin);

    // We can also use this in C++
    // But C++ has a better way
    cin.getline(s, 100);

    // But if there were no spaces, we could
    // have used just cin
    // cin >> s;

    cout << s << endl;

    return 0;
}