/*

You have already solved a problem where you had to find minimum and maximum value among 3 integer numbers.

Now you will be given 3 strings you have to find lexicographically minimum and maximum string among them.

Input Format

The first line will contain 3 strings, S1, S2, S3 containing only lowercase letters.

Constraints

1 <= |S1|, |S2|, |S3| <= 1000

Output Format

In the first line print the lexicographically minimum string.

In the second line print the lexicographically maximum string.

Sample Input 0

abc def ghi
Sample Output 0

abc
ghi

*/



#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    
    char S1[1001], S2[1001], S3[1001], min[1001], max[1001];
    scanf("%s %s %s", S1, S2, S3);
    
    strcpy(min, S1), strcpy(max, S1);
    
    if(strcmp(S2, min) < 0){
        strcpy(min, S2);
    }
    if(strcmp(S3, min) < 0){
        strcpy(min, S3);
    }
    if(strcmp(S2, max) > 0){
        strcpy(max, S2);
    }
    if(strcmp(S3, max) > 0){
        strcpy(max, S3);
    }
    
    printf("%s\n", min);
    printf("%s\n", max);
    
    return 0;
}