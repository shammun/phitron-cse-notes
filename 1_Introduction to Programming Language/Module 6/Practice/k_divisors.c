#include <stdio.h>

// Find the number of k divisors of number n
int main() {

    int n;
    scanf("%d", &n);

    for(int i = 1; i <= n; i++) {
        if(n % i == 0){
            printf("%d\n", i);
        }
    }

}