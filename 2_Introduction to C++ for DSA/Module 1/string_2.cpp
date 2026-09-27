#include <iostream>
using namespace std;

int main(){
    int x;
    cin >> x;

    cin.ignore(); 
    // Ignore the newline character or
    // ignore the space after the integer
    // in input.txt in first line
    
    char s[100];
    cin.getline(s, 100); 
    // if the second line has more than one 
    // words

    cout << x << endl <<s << endl;

    return 0;
}