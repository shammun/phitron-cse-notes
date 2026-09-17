#include <stdio.h>

int main() {
    // Demonstrating post-increment (a++)
    int a = 15;
    printf("Post-increment: a++ \n");
    printf("Value of a during print: %d\n", a++);
    printf("Value of a after increment: %d\n\n", a);

    // Demonstrating pre-increment (++b)
    int b = 30;
    printf("Pre-increment: ++b \n");
    printf("Value of b after increment: %d\n", ++b);
    printf("Value of b in next statement: %d\n\n", b);

    // Demonstrating post-decrement (c--)
    int c = 40;
    printf("Post-decrement: c-- \n");
    printf("Value of c during print: %d\n", c--);
    printf("Value of c after decrement: %d\n\n", c);

    // Demonstrating pre-decrement (--d)
    int d = 40;
    printf("Pre-decrement: --d \n");
    printf("Value of d after decrement: %d\n", --d);
    printf("Value of d in next statement: %d\n", d);

    return 0;
}