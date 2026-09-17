#include <stdio.h>

int main() {
    int i;
    int j;
    i = 1;
    j = 10;
    while(i <= 5) {
        printf("i = %d\n", i);
        i+=1;
    }

    do {
        printf("j = %d\n", j);
        j -= 1;
    } while(j > 0);

    return 0;
}