#include <stdio.h>

int main()
{
    /* a belongs to Memo, b to Momo, and the question is whose number is
       divisible by k. long long because the values can be large (%lld reads
       them). */
    long long a, b, k;
    scanf("%lld %lld %lld", &a, &b, &k);
    
    /* "x is divisible by k" is x % k == 0 (nothing left over).
       The order of the ladder matters: the "both" case must be tested
       first. If "a divisible" came first, it would also catch the case
       where both are divisible, and "Both" would never be printed. */
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
