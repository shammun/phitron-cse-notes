/*

Problem Statement: Given a string of length N. Print the unique characters in the string in increasing alphabetical order.

Sample Input:
3
abc

Sample Output:
abc


Sample Input:
5
apple

Sample Output:
aelp

Sample Input:
7
abbgaab

Sample Output:
abg
*/

#include <stdio.h>
#include <string.h>

int main() {
    int length;
    scanf("%d", &length);
    char str[length +1];
    int freq[26] = {0};

    scanf("%s", str);
    int len = strlen(str);

    /*
    while(str[i] != '\0'){
        if(str[i] >= 'a' && str[i] <= 'z'){
            freq[str[i] - 'a'] = 1;
        }
        i++;
    }
    */
    
    for(int i=0; i<len; i++){
        if(str[i] >= 'a' && str[i] <= 'z'){
            freq[str[i] - 'a'] = 1;
        }
    }


    for(int i=0; i < 26; i++){
        if(freq[i] == 1){
            printf("%c", i + 'a');
        }
    }

    printf("\n");
    
    return 0;
}

