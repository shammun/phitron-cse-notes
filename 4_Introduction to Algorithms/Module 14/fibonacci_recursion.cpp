#include <iostream>
#include <vector>
#include <algorithm>    
#include <string>

using namespace std;

int fib(int n){
    if(n == 0 || n == 1){ // or, we can also write if(n < 2)
        return n;
    }
    return fib(n-1) + fib(n-2);
}

int main(){
    int n;
    cin >> n;
    cout << fib(n) << endl;

    return 0;
}