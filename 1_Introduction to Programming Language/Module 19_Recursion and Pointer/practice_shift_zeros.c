#include <stdio.h>

void shift_zeros(int arr[], int n){
    int nonZeroIndex = 0;

    for(int i=0; i<n; i++){
        if(arr[i] != 0){
            arr[nonZeroIndex] = arr[i];
            nonZeroIndex++;
        }
    }

    for(int i=nonZeroIndex; i<n; i++){
        arr[i] = 0;
    }
}

int main(){
    int n;
    scanf("%d", &n);

    int arr[n];

    for(int i=0; i<n; i++){
        scanf("%d", &arr[i]);
    }

    shift_zeros(arr, n);

    for(int i=0; i<n; i++){
        printf("%d", arr[i]);
    }
    printf("\n");

    return 0;
}