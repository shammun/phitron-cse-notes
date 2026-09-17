#include<stdio.h>

// Given a character, print the next alphabet

// First way to do it

// int main() {
//     char ch;
//     scanf("%c", &ch);
//     int ch_val;
    
//     if (ch >= 'a' && ch <= 'z') {
//         ch_val = ((ch - 'a' + 1) % 26) + 'a';
//         printf("%c", (char)ch_val);
//     }

//     return 0;
// }

// Second way to do it

int main() {
    char ch;
    scanf("%c", &ch);
    
    if (ch >= 'a' && ch <= 'z') {
        printf("%c", ((ch - 'a' + 1) % 26) + 'a');
    }

    return 0;
}