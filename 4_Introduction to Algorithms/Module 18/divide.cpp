#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

void divide(int a[], int l, int r){
    if(l >= r){
        return;
    }
    int mid = (l+r)/2;
    divide(a, l, mid);
    divide(a, mid+1, r);

}

int main(){
    // First we will take the input for two arrays

    int n, m;
    cin >> n >> m;

    int a[n];
    for(int i=0; i<n; i++){
        cin >> a[i];
    }

    divide(a, 0, n-1);

    return 0;
}