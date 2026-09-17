#include <stdio.h>

int main()
{
    long long a, b, k;
    scanf("%lld %lld %lld", &a, &b, &k);
    
    if (a % k == 0 && b % k == 0) {          // a divisible by k and b divisible by k
        printf("Both\n");
    }
    else if (a % k == 0) {                   // a divisible by k
        printf("Memo\n");
    }
    else if (b % k == 0) {                   // b divisible by k
        printf("Momo\n");
    }
    else {                                   // a and b both are not divisible by k
        printf("No One\n");
    }
    
    return 0;
}