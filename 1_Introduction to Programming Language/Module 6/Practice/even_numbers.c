#include <stdio.h>
#include <stdbool.h>

// Given a number N. Print all even numbers between 1 and N inclusive in separate lines

int main() {

    int n;
    scanf("%d", &n);
    bool flag = false;
    for(int i = 1; i <= n; i++){
        if(i % 2 == 0){
            flag=true;
            printf("%d\n", i);
        }
    }
    if(flag==false){
        printf("-1");
    }
}