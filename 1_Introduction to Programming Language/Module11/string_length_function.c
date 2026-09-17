#include <stdio.h>
#include <string.h>

int main() {
    char str[10] = "abcd ab?";

    int length = strlen(str);
    printf("%d", length);

    return 0;
}