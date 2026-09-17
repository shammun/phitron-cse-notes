#include <stdio.h>
#include <math.h>

int main() {
    printf("%d\n", 5%3);

    // int a = 100000;
    // int b = 100000;
    // // int a = 100000, b = 100000;
    // long long result = (long long) a * b;  
    // printf("%lld", result);

    // Another way to do the same thing
    int a = 100000, b = 100000;
    long long result = 1LL * a * b;  
    printf("%lld", result);

    // Another way to do the same thing
    
    // int a = 100000;
    // long long b = 100000;
    // long long result = a * b;
    // printf("%lld", result);
    
    // Another way to do the same thing
    // long long a = 100000;
    // long long b = 100000;
    // long long result = a * b;
    // printf("%lld", result);
    
    return 0;
}