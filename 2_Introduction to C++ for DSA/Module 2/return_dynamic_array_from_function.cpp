#include <bits/stdc++.h>
using namespace std;

/*

// As the following fun() declares a static array, it's memory will be deleted 
// after the function returns and thus main will print segmentation fault

int* fun(){
    int a[5]; // declaring a static array
    for(int i=0; i<5; i++){
        cin >> a[i];
    }
    return a; // returning pointer to the static array
}

int main(){
    int * x = fun(); // receiving array from function as a ponter
    for(int i=0; i<5; i++){
        cout << x[i] << " ";
    }
    return 0;
}

*/

// So, we will use dynamic array

int* fun(){
    int *a = new int[5]; // declaring a dynamic array
    for(int i=0; i<5; i++){
        cin >> a[i];
    }
    return a; // returning pointer to the dynamic array
}

int main(){
    int * x = fun(); // receiving array from function as a ponter
    for(int i=0; i<5; i++){
        cout << x[i] << " ";
    }
    return 0;
}

