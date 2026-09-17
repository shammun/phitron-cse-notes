#include <stdio.h>

int main()
{
    int a[5];
    
    for (int i = 0; i < 5; i++) {
        // i
        scanf("%d", &a[i]);
    }
    
    // printf("%d", a[1]);
    
    for (int i = 0; i < 5; i++) {
        printf("%d ", a[i]);
    }
    
    return 0;
}