#include <stdio.h>

void print_1_to_N(int x, int n){
    if(x > n){
        return;
    }
    printf("%d ", x);
    print_1_to_N(x+1, n);
}

int main(){
    int n;
    printf("Enter the value of n: ");
    scanf("%d", &n);
    print_1_to_N(1, n);
    return 0;
}