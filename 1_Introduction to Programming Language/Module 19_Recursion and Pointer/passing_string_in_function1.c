#include <stdio.h>
#include <string.h>

void length(char x[]){
    int n = strlen(x);
    printf("Length of string: %d\n", n);
}

int main(){
    char a[] = "programmer";
    length(a);
    return 0;
}