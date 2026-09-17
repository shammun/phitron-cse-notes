#include<stdio.h>

// Find if d can be achieved by either addition, subtraction or multiplication
// between a, b and class

int main(){
    long long a, b, c, d;
    scanf("%lld %lld %lld %lld", &a, &b, &c, &d);

    if(a + b + c == d || a + b - c == d || a + b * c == d || 
    a - b + c == d || a - b - c == d || a - b * c == d ||
    a * b + c == d || a * b - c == d || a - b * c == d) {
        printf("YES");
    } else {
        printf("NO");
    }
    
    return 0;
}