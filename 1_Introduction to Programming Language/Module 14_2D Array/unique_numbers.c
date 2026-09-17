#include<stdio.h>

int main(){
    int n;
    scanf("%d", &n);

    int arr[n];
    int freq[100001] = {0};
    int unique_count = 0;

    for(int i=0; i<n; i++){
        scanf("%d", &arr[i]);
    }

    for(int i=0; i<n; i++){
        if(freq[arr[i]] == 0){
            freq[arr[i]] = 1;
            unique_count++;
        }
    }

    printf("%d", unique_count);

    return 0;

}