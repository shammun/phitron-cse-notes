#include <stdio.h>

// A number of two digits is lucky if one of its digits is divisible by the other.

// For example, 39, 82, and 55 are lucky, while 79 and 43 are not.

// Given a number between 10 and 99, determine whether it is lucky or not.


int main() {
    int n;
    scanf("%d", &n);
    int first = n / 10;
    int second = n % 10;

    if(first % second == 0 || second % first == 0){
        printf("YES");
    } else {
        printf("NO");
    }

    return 0;
}