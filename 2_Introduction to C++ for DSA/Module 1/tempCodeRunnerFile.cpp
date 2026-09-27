#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    int a,b;
    cin >> a >> b;
    // if(a < b) cout << a << " " << b << endl;
    // else cout << b << " " << a << endl;
    
    cout << min(a,b) << " " << max(a,b) << endl;
    
    // if more than two numbers
    cout << min({2,3,4,5,6,7,8}) << " " << max({2,3,4,5,6,7,8}) << endl;
    
    // swap in C
    // int temp = a;
    // a = b;
    // b = temp;
    // cout << a << " " << b << endl;

    // swap
    swap(a,b);
    cout << a << " " << b << endl;
    
    return 0;
}