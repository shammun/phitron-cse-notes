#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

void conquer(int c[], int l, int mid, int r){
    int n = mid - l + 1;
    int a[n];
    for(int i=0; i<n; i++){
        a[i] = c[l+i];
    }

    int m = r - mid;
    int b[m];
    for(int i=0; i<m; i++){
        b[i] = c[mid+1+i];
    }

    // Now, take the two pointers for the two arrays and pointer for the result array
    int i=0, j=0, curr=l;

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
}

void divide(int a[], int l, int r){ // O(nlogn) -- this does the merge sort
    if(l >= r){
        return;
    }
    int mid = (l+r)/2;
    divide(a, l, mid); // merge sort the left half
    divide(a, mid+1, r); // merge sort the right half
    conquer(a, l, mid, r); // merge the two sorted arrays
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

    for(int i=0; i<n; i++){
        cout << a[i] << " ";
    }

    return 0;
}