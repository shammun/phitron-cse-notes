#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main(){
    // First we will take the input for two arrays

    int n, m;
    cin >> n >> m;

    int a[n];
    for(int i=0; i<n; i++){
        cin >> a[i];
    }

    int b[m];
    for(int i=0; i<m; i++){
        cin >> b[i];
    }

    // Now, declare an array to store the result for the merging of two arrays
    int c[n+m];

    // Now, take the two pointers for the two arrays and pointer for the result array
    int i=0, j=0, curr=0;

    while(i < n && j < m){
        if(a[i] < b[j]){
            c[curr] = a[i];
            i++;
            curr++;
        } else{
            c[curr] = b[j];
            j++;
            curr++;
        }
    }

    while(i < n){
        c[curr] = a[i];
        i++;
        curr++;
    }

    while(j < m){
        c[curr] = b[j];
        j++;
        curr++;
    }

    for(int i=0; i<n+m; i++){
        cout << c[i] << " ";
    }

    return 0;
}