#include <stdio.h>

void print_N_to_1(int x, int n){
    if(x > n){
        return;
    }
    print_N_to_1(x+1, n);
    printf("%d ", x);
}

int main(){
    int n;
    printf("Enter the value of n: ");
    scanf("%d", &n);
    print_N_to_1(1, n);
    return 0;
}