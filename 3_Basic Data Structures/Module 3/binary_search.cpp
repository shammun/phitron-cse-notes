/*

This is a simple program to find a value in an array using 
linear search and binary search.

If a value is found, print "found", otherwise print "not found".

*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int main() {
    int n;
    cin >> n;
    int a[n];

    for(int i=0; i<n; i++){
        cin >> a[i];
    }

    int val;
    cin >> val;

    // O(n)  ---> linear search
    int flag = 0;
    for(int i=0; i<n; i++){
        if(a[i] == val){
            flag = 1;
            break;
        }
    }
    if(flag == 1){
        cout << "found" << endl;
    }
    else{
        cout << "not found" << endl;
    }

    /*
    If not sorted, first sort the array, then apply binary search
    sort(a, a+n);
    */
    // O(logn)  ---> binary search
    
    // We are assuming the array is sorted

    int flag2 = 0;
    int l = 0, r = n-1;
    while(l <= r){
        int mid = (l + r) / 2;
        if(a[mid] == val){
            flag2 = 1;
            break;
        }
        else if(a[mid] < val){
            l = mid + 1;
        }
        else{
            r = mid - 1;
        }
    }


    return 0;
}