#include <stdio.h>

// A number of two digits is lucky if one of its digits is divisible by the other.

// For example, 39, 82, and 55 are lucky, while 79 and 43 are not.

// Given a number between 10 and 99, determine whether it is lucky or not.


int main() {
    int n;
    scanf("%d", &n);

    // Splitting a two-digit number into its digits:
    //   n / 10  drops the last digit    (39 / 10 = 3, the tens digit)
    //   n % 10  keeps only the last one (39 % 10 = 9, the units digit)
    int first = n / 10;
    int second = n % 10;

    // "x is divisible by y" means x % y == 0. Either direction counts, so the
    // two tests are joined with ||.
    //
    // second == 0 comes first on purpose. For 10, 20, ..., 90 the units digit
    // is 0, and `first % second` would then divide by zero, which crashes
    // the program. || stops at the first true test, so when second is 0 the
    // two % tests are never reached. And such a number is lucky anyway:
    // 0 is divisible by any digit (0 % 3 == 0).
    // (first can never be 0, because n is at least 10.)
    if(second == 0 || first % second == 0 || second % first == 0){
        printf("YES");
    } else {
        printf("NO");
    }

    return 0;
}
