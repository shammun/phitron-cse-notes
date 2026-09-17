#include <iostream>
#include <string>
using namespace std;

int main(){
    char s[100];
    // cin >> s; // cin is like scanf in C, can't take string with spaces as input. It just takes the first word.
    // cin and scanf can't take string with spaces as input. It just takes the first word.
    // In C, we can use fgets to take string with spaces as input.
    // In C, this is fgets(s, 100, stdin);

    // In C++, we can use getline to take string with spaces as input
    // In C++, this is cin.getline(s, 100);

    // Reading a line of text from the user
    cin.getline(s, 100);
    cout << s << endl;

    return 0;
}