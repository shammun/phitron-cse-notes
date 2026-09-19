#include<stdio.h>

// Find if d can be achieved by either addition, subtraction or multiplication
// between a, b and c
//
// There are two operator slots, a ? b ? c, and three operators to choose
// from, so 3 * 3 = 9 combinations in all. With only nine of them, the
// simplest honest answer is to write them all out and join them with ||,
// which is true as soon as any one of them is true.
//
// long long rather than int: a, b and c can each be large, and a product of
// three of them grows fast enough to pass what a 32-bit int can hold.
//
// C's usual precedence applies inside each expression, so `a + b * c` means
// a + (b * c) - the multiplication is done first. That is exactly what the
// problem asks for, so no brackets are needed.

int main(){
    long long a, b, c, d;
    scanf("%lld %lld %lld %lld", &a, &b, &c, &d);

    // BUG, left here on purpose: the list below is meant to hold all nine
    // combinations, but `a - b * c == d` is written twice and
    // `a * b * c == d` is missing altogether. So an input such as
    // `2 3 4 24` prints NO even though 2 * 3 * 4 = 24.
    // The fix is to replace the repeated test with `a * b * c == d`.

    if(a + b + c == d || a + b - c == d || a + b * c == d || 
    a - b + c == d || a - b - c == d || a - b * c == d ||
    a * b + c == d || a * b - c == d || a - b * c == d) {
        printf("YES");
    } else {
        printf("NO");
    }
    
    return 0;
}