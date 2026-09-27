#include <stdio.h>

int maxFrom(int *a, int i, int n){
    if(i == n-1){
        return a[i];
    }

    int rest = maxFrom(a, i+1, n);

    if(a[i] > rest){
        return a[i];
    } else{
        return rest;
    }
}

int main(){
    int n;
    scanf("%d", &n);

    int a[n];

    for(int i=0; i<n; i++){
        scanf("%d", &a[i]);
    }

    printf("%d\n", maxFrom(a, 0, n));

    return 0;
}