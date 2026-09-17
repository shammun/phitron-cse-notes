#include <stdio.h>

int main(){
    int a = 5, b = 8;
    int *x = &a, *y = &b;
    printf("Before swapping: a = %d, b = %d\n", a, b);

    int temp = *x; // dereferencing x and storing the value in temp
    *x = *y; // dereferencing y and storing the value in x
    *y = temp; // dereferencing temp and storing the value in y

    printf("After swapping: a = %d, b = %d\n", a, b);
    return 0;
}