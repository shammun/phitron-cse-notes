#include<stdio.h>

int main() {
    int a, b, c;
    scanf("%d %d %d", &a, &b, &c);

    // minimum
    if(a<=b && a<=c){
        printf("%d\n", a);
    } else if (b<=a && b<=c) {
        printf("%d\n", b);
    } else {
        printf("%d\n", c);
    }

    // maximum
    if(a>=b && a>=c){
        printf("%d\n", a);
    } else if (b>=a && b>=c) {
        printf("%d\n", b);
    } else {
        printf("%d\n", c);
    }
}